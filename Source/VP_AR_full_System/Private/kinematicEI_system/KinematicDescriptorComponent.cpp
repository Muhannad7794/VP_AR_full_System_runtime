#include "kinematicEI_system/KinematicDescriptorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetMaterialLibrary.h" 
#include "Kismet/GameplayStatics.h"

UKinematicDescriptorComponent::UKinematicDescriptorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsEIActive = true;

    // Initialize filters tuned to ZED 2i baseline noise profile
    FilterSpine = FOneEuroFilterVector(1.0f, 0.05f);
    FilterLWrist = FOneEuroFilterVector(1.0f, 0.05f);
    FilterRWrist = FOneEuroFilterVector(1.0f, 0.05f);

    CurrentEffort = 0.0f;
    CurrentExpansiveness = 0.0f;
    CurrentWeight = 0.0f;
    CurrentFlow = 0.0f;
}

void UKinematicDescriptorComponent::BeginPlay()
{
    Super::BeginPlay();

    // Store the initial world locations of the AR cubes as their "Home" anchor
    for (AActor* Cube : ARCubes)
    {
        if (Cube)
        {
            CubeHomeLocations.Add(Cube, Cube->GetActorLocation());
        }
    }
}

void UKinematicDescriptorComponent::ToggleSystemMode()
{
    bIsEIActive = !bIsEIActive;

    if (GlobalMPC)
    {
        UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), GlobalMPC, FName("SystemMode"), bIsEIActive ? 1.0f : 0.0f);
    }
}

void UKinematicDescriptorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bIsEIActive || !TrackedSkeleton) return;

    FVector CleanSpine, CleanLWrist, CleanRWrist;

    ReadAndFilterKinematics(DeltaTime, CleanSpine, CleanLWrist, CleanRWrist);
    ComputeLMADescriptors(DeltaTime, CleanSpine, CleanLWrist, CleanRWrist);

    // Pass the raw (or filtered) pelvis location to the GPU for distance calculations
    FVector PelvisLoc = TrackedSkeleton->GetSocketLocation(FName("PELVIS"));
    UpdateRenderSubsystems(PelvisLoc);

    ExecuteKinematicPhysics();
}

void UKinematicDescriptorComponent::ReadAndFilterKinematics(float DeltaTime, FVector& OutSpine, FVector& OutLWrist, FVector& OutRWrist)
{
    // Extract raw positions from the ZED LiveLink skeleton
    FVector RawSpine = TrackedSkeleton->GetSocketLocation(FName("SPINE_2"));
    FVector RawLWrist = TrackedSkeleton->GetSocketLocation(FName("LEFT_WRIST"));
    FVector RawRWrist = TrackedSkeleton->GetSocketLocation(FName("RIGHT_WRIST"));

    // Apply the 1 Euro Filter geometrically
    OutSpine = FilterSpine.Filter(DeltaTime, RawSpine);
    OutLWrist = FilterLWrist.Filter(DeltaTime, RawLWrist);
    OutRWrist = FilterRWrist.Filter(DeltaTime, RawRWrist);
}

void UKinematicDescriptorComponent::ComputeLMADescriptors(float DeltaTime, const FVector& Spine, const FVector& LWrist, const FVector& RWrist)
{
    if (DeltaTime <= 0.0f) return;

    // 1. SPACE (Expansiveness): Maximum boundary of the Kinesphere
    float DistL = FVector::Dist(Spine, LWrist);
    float DistR = FVector::Dist(Spine, RWrist);
    float RawExpansiveness = FMath::Max(DistL, DistR);

    // Normalize based on an assumed arm span (e.g., 800mm max extension). Map to 0.0 - 1.0
    CurrentExpansiveness = FMath::Clamp(RawExpansiveness / 800.0f, 0.0f, 1.0f);

    // 2. TIME (Effort): Velocity Magnitude of the dominant effector
    FVector CurrentVelocity = (RWrist - PrevFilteredRWrist) / DeltaTime;
    float VelocityMag = CurrentVelocity.Size();

    // Normalize (e.g., 3000 mm/s is a very fast punch)
    CurrentEffort = FMath::Clamp(VelocityMag / 3000.0f, 0.0f, 1.0f);

    // 3. WEIGHT: Acceleration Magnitude
    FVector CurrentAcceleration = (CurrentVelocity - PrevRWristVelocity) / DeltaTime;
    float AccelMag = CurrentAcceleration.Size();

    // Normalize (e.g., 10000 mm/s^2 is high acceleration)
    CurrentWeight = FMath::Clamp(AccelMag / 10000.0f, 0.0f, 1.0f);

    // 4. FLOW: Inversely proportional to rapid acceleration shifts. Bound vs Free.
    CurrentFlow = 1.0f - CurrentWeight;

    // Update States
    PrevFilteredRWrist = RWrist;
    PrevRWristVelocity = CurrentVelocity;
}

void UKinematicDescriptorComponent::UpdateRenderSubsystems(const FVector& PelvisLocation)
{
    // Update GPU Variables for World Position Offset (WPO) Surface Deformation
    if (GlobalMPC)
    {
        UWorld* World = GetWorld();
        UKismetMaterialLibrary::SetScalarParameterValue(World, GlobalMPC, FName("EffortLevel"), CurrentEffort);
        UKismetMaterialLibrary::SetScalarParameterValue(World, GlobalMPC, FName("ExpansivenessLevel"), CurrentExpansiveness);
        UKismetMaterialLibrary::SetScalarParameterValue(World, GlobalMPC, FName("WeightLevel"), CurrentWeight);
        UKismetMaterialLibrary::SetScalarParameterValue(World, GlobalMPC, FName("FlowLevel"), CurrentFlow);

        // Convert FVector (X, Y, Z) into FLinearColor (R, G, B, A) for the Material Pipeline
        FLinearColor PelvisColor(PelvisLocation.X, PelvisLocation.Y, PelvisLocation.Z, 1.0f);
        UKismetMaterialLibrary::SetVectorParameterValue(World, GlobalMPC, FName("PelvisWorldLocation"), PelvisColor);
    }

    // Update Particle System overrides
    if (ParticleSystem)
    {
        ParticleSystem->SetFloatParameter(FName("User.EffortLevel"), CurrentEffort);
        ParticleSystem->SetFloatParameter(FName("User.FlowLevel"), CurrentFlow);
    }
}

void UKinematicDescriptorComponent::ExecuteKinematicPhysics()
{
    FVector PelvisLoc = TrackedSkeleton ? TrackedSkeleton->GetSocketLocation(FName("PELVIS")) : FVector::ZeroVector;

    for (AActor* Cube : ARCubes)
    {
        if (!Cube) continue;

        UPrimitiveComponent* PrimComp = Cube->FindComponentByClass<UPrimitiveComponent>();
        if (!PrimComp || !PrimComp->IsSimulatingPhysics()) continue;

        FVector CurrentLoc = Cube->GetActorLocation();
        FVector HomeLoc = CubeHomeLocations.Contains(Cube) ? CubeHomeLocations[Cube] : CurrentLoc;
        FVector CubeVelocity = PrimComp->GetComponentVelocity();

        // 1. Attractor Force: Pulls cubes back to formation. Stronger when Flow is Bound (Low).
        FVector ToHome = HomeLoc - CurrentLoc;
        FVector AttractorForce = ToHome * AttractorSpringConstant * (1.0f - CurrentFlow);

        // 2. Repulsor Force: Pushes cubes outward from the performer based on Effort and Expansiveness.
        FVector OutwardDir = (CurrentLoc - PelvisLoc).GetSafeNormal();
        FVector RepulsorForce = OutwardDir * RepulsorForceMultiplier * CurrentEffort * CurrentExpansiveness;

        // 3. Dynamic Drag Override: Freezes cubes in place when Effort drops to 0.
        FVector DragForce = -CubeVelocity * BaseDragCoefficient * (1.0f - CurrentEffort);

        // Apply net forces as acceleration (ignoring mass for uniform AR response)
        FVector NetForce = AttractorForce + RepulsorForce + DragForce;
        PrimComp->AddForce(NetForce, NAME_None, true);
    }
}