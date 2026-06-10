/**
 * KinematicDescriptorComponent.cpp
 *
 * CHANGES IN THIS VERSION vs PREVIOUS:
 * ──────────────────────────────────────
 * 1. MAX_DEFORMATION_RADIUS: no longer a hardcoded static constexpr (80.0f).
 *    Now reads from MaxDeformationRadius UPROPERTY, editable in the Details panel.
 *    Default raised to 150.0f to allow particles to travel deeply into the bubble.
 *
 * 2. Tether coefficient: no longer hardcoded (150.0f).
 *    Now reads from TetherCoefficient UPROPERTY. Default raised to 250.0f for
 *    faster, more reliable return once particles exceed MaxDeformationRadius.
 *
 * 3. AttractorSpringConstant default lowered from 500 → 8 (in header).
 *    RepulsorForceMultiplier default raised from 1000 → 15000 (in header).
 *    BaseDragCoefficient default lowered from 10 → 4 (in header).
 *    These are header-only changes — the .cpp physics loop is unchanged.
 *
 * All other logic is identical to the previous version.
 */

#include "kinematicEI_system/KinematicDescriptorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

 // ---------------------------------------------------------------------------
 // Joint contribution weights.
 // Distal joints carry the most expressive velocity signal.
 // ---------------------------------------------------------------------------

static constexpr float WEIGHT_WRIST = 1.0f;
static constexpr float WEIGHT_ELBOW = 0.8f;
static constexpr float WEIGHT_SHOULDER = 0.6f;

static constexpr float TOTAL_JOINT_WEIGHT =
(WEIGHT_WRIST * 2.0f) + (WEIGHT_ELBOW * 2.0f) + (WEIGHT_SHOULDER * 2.0f);

// ---------------------------------------------------------------------------
// Physiological seed values for adaptive normalization range warmup.
// Units: cm/s for velocity descriptors, cm for distance.
// ---------------------------------------------------------------------------

static constexpr float INIT_MIN_EFFORT = 0.0f;
static constexpr float INIT_MAX_EFFORT = 300.0f;
static constexpr float INIT_MIN_EXPANSIVENESS = 0.0f;
static constexpr float INIT_MAX_EXPANSIVENESS = 800.0f;
static constexpr float INIT_MIN_WEIGHT = 0.0f;
static constexpr float INIT_MAX_WEIGHT = 500.0f;
static constexpr float INIT_MIN_FLOW = 0.0f;
static constexpr float INIT_MAX_FLOW = 50.0f;

// ---------------------------------------------------------------------------
// Physics constants — these are not tuning values.
// Tuning values (tether cap, tether coefficient, spring, repulsor multiplier)
// are UPROPERTY members on the component, editable in the Details panel.
// ---------------------------------------------------------------------------

// Minimum limb speed (cm/s) below which no repulsor force is generated.
// Suppresses tracker noise jitter while the performer is still.
static constexpr float MIN_LIMB_SPEED_THRESHOLD = 5.0f;

// Reference maximum limb speed (cm/s) for normalising raw speed to [0, 1].
// 400 cm/s = a fast ballistic arm swing.
static constexpr float REF_MAX_LIMB_SPEED = 400.0f;


// ============================================================================
// Constructor
// ============================================================================

UKinematicDescriptorComponent::UKinematicDescriptorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    const float MinCutoff = 1.0f;
    const float Beta = 0.05f;

    FilterSpine = FOneEuroFilterVector(MinCutoff, Beta);
    FilterLWrist = FOneEuroFilterVector(MinCutoff, Beta);
    FilterRWrist = FOneEuroFilterVector(MinCutoff, Beta);
    FilterLElbow = FOneEuroFilterVector(MinCutoff, Beta);
    FilterRElbow = FOneEuroFilterVector(MinCutoff, Beta);
    FilterLShoulder = FOneEuroFilterVector(MinCutoff, Beta);
    FilterRShoulder = FOneEuroFilterVector(MinCutoff, Beta);

    CurrentEffort = 0.0f;
    CurrentExpansiveness = 0.0f;
    CurrentWeight = 0.0f;
    CurrentFlow = 0.0f;

    PrevLWrist = FVector::ZeroVector;
    PrevRWrist = FVector::ZeroVector;
    PrevLElbow = FVector::ZeroVector;
    PrevRElbow = FVector::ZeroVector;
    PrevLShoulder = FVector::ZeroVector;
    PrevRShoulder = FVector::ZeroVector;

    PrevLWristVelocity = FVector::ZeroVector;
    PrevRWristVelocity = FVector::ZeroVector;
    PrevLElbowVelocity = FVector::ZeroVector;
    PrevRElbowVelocity = FVector::ZeroVector;

    LWristVelocityDir = FVector::ZeroVector;
    RWristVelocityDir = FVector::ZeroVector;
    LElbowVelocityDir = FVector::ZeroVector;
    RElbowVelocityDir = FVector::ZeroVector;

    LWristSpeed = 0.0f;
    RWristSpeed = 0.0f;
    LElbowSpeed = 0.0f;
    RElbowSpeed = 0.0f;

    bFirstDescriptorFrame = true;
    bHomeOffsetsReady = false;

    AdaptiveMin_Effort = INIT_MIN_EFFORT;
    AdaptiveMax_Effort = INIT_MAX_EFFORT;
    AdaptiveMin_Expansiveness = INIT_MIN_EXPANSIVENESS;
    AdaptiveMax_Expansiveness = INIT_MAX_EXPANSIVENESS;
    AdaptiveMin_Weight = INIT_MIN_WEIGHT;
    AdaptiveMax_Weight = INIT_MAX_WEIGHT;
    AdaptiveMin_Flow = INIT_MIN_FLOW;
    AdaptiveMax_Flow = INIT_MAX_FLOW;
}


// ============================================================================
// BeginPlay
// ============================================================================

void UKinematicDescriptorComponent::BeginPlay()
{
    Super::BeginPlay();
    FlowDeltaBuffer.Reserve(FlowWindowSize);

    ProximityDispatch = GetOwner()
        ? GetOwner()->FindComponentByClass<UProximityDispatchComponent>()
        : nullptr;

    if (!ProximityDispatch)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: ProximityDispatchComponent "
                "not found on owner. Limb proximity checks will use "
                "ProximityRadius fallback of 80cm."));
    }
}


// ============================================================================
// TickComponent
// ============================================================================

void UKinematicDescriptorComponent::TickComponent(
    float                        DeltaTime,
    ELevelTick                   TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Auto-discover all ZED Manny skeletal mesh components every tick.
    // This removes Blueprint dependency for TrackedSkeletons population.
    TrackedSkeletons.Empty();
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(
        GetWorld(),
        AActor::StaticClass(),
        FoundActors);

    for (AActor* Actor : FoundActors)
    {
        if (!Actor || !IsValid(Actor)) continue;
        if (!Actor->GetName().Contains(TEXT("ZED_Manny"))) continue;

        USkeletalMeshComponent* Skel =
            Actor->FindComponentByClass<USkeletalMeshComponent>();
        if (Skel && IsValid(Skel))
        {
            TrackedSkeletons.Add(Skel);

            if (!TrackedSkeleton || !IsValid(TrackedSkeleton))
            {
                TrackedSkeleton = Skel;
                bFirstDescriptorFrame = true;
            }
        }
    }

    if (TrackedSkeletons.Num() == 0)
    {
        TrackedSkeleton = nullptr;
        // Run physics even without tracking so the attractor continues
        // pulling displaced particles home when no performer is visible.
        ExecuteKinematicPhysics();
        return;
    }

    if (!TrackedSkeleton || !IsValid(TrackedSkeleton))
        return;

    FVector CleanSpine;
    FVector CleanLWrist, CleanRWrist;
    FVector CleanLElbow, CleanRElbow;
    FVector CleanLShoulder, CleanRShoulder;

    ReadAndFilterKinematics(
        DeltaTime,
        CleanSpine,
        CleanLWrist, CleanRWrist,
        CleanLElbow, CleanRElbow,
        CleanLShoulder, CleanRShoulder);

    ComputeLMADescriptors(
        DeltaTime,
        CleanSpine,
        CleanLWrist, CleanRWrist,
        CleanLElbow, CleanRElbow,
        CleanLShoulder, CleanRShoulder);

    const FVector PelvisLoc =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));
    UpdateRenderSubsystems(PelvisLoc);

    ExecuteKinematicPhysics();
}


// ============================================================================
// ReadAndFilterKinematics
// ============================================================================

void UKinematicDescriptorComponent::ReadAndFilterKinematics(
    float    DeltaTime,
    FVector& OutSpine,
    FVector& OutLWrist, FVector& OutRWrist,
    FVector& OutLElbow, FVector& OutRElbow,
    FVector& OutLShoulder, FVector& OutRShoulder)
{
    // Socket names follow the ZED LiveLink BODY_38 to Manny skeleton retarget:
    //   PELVIS         → Hips
    //   SPINE_2        → Spine1
    //   LEFT_WRIST     → LeftHand
    //   RIGHT_WRIST    → RightHand
    //   LEFT_ELBOW     → LeftForeArm
    //   RIGHT_ELBOW    → RightForeArm
    //   LEFT_SHOULDER  → LeftArm
    //   RIGHT_SHOULDER → RightArm

    OutSpine = FilterSpine.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("Spine1")));
    OutLWrist = FilterLWrist.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("LeftHand")));
    OutRWrist = FilterRWrist.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("RightHand")));
    OutLElbow = FilterLElbow.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("LeftForeArm")));
    OutRElbow = FilterRElbow.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("RightForeArm")));
    OutLShoulder = FilterLShoulder.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("LeftArm")));
    OutRShoulder = FilterRShoulder.Filter(DeltaTime,
        TrackedSkeleton->GetSocketLocation(FName("RightArm")));
}


// ============================================================================
// ComputeLMADescriptors
// ============================================================================

void UKinematicDescriptorComponent::ComputeLMADescriptors(
    float          DeltaTime,
    const FVector& Spine,
    const FVector& LWrist, const FVector& RWrist,
    const FVector& LElbow, const FVector& RElbow,
    const FVector& LShoulder, const FVector& RShoulder)
{
    if (DeltaTime <= 0.0f) return;

    if (bFirstDescriptorFrame)
    {
        PrevLWrist = LWrist;
        PrevRWrist = RWrist;
        PrevLElbow = LElbow;
        PrevRElbow = RElbow;
        PrevLShoulder = LShoulder;
        PrevRShoulder = RShoulder;

        PrevLWristVelocity = FVector::ZeroVector;
        PrevRWristVelocity = FVector::ZeroVector;
        PrevLElbowVelocity = FVector::ZeroVector;
        PrevRElbowVelocity = FVector::ZeroVector;

        bFirstDescriptorFrame = false;
        return;
    }

    // -----------------------------------------------------------------------
    // Per-joint velocity vectors (finite difference).
    // -----------------------------------------------------------------------

    const FVector VelLWrist = (LWrist - PrevLWrist) / DeltaTime;
    const FVector VelRWrist = (RWrist - PrevRWrist) / DeltaTime;
    const FVector VelLElbow = (LElbow - PrevLElbow) / DeltaTime;
    const FVector VelRElbow = (RElbow - PrevRElbow) / DeltaTime;
    const FVector VelLShoulder = (LShoulder - PrevLShoulder) / DeltaTime;
    const FVector VelRShoulder = (RShoulder - PrevRShoulder) / DeltaTime;

    // -----------------------------------------------------------------------
    // Per-limb speed and smoothed direction cache.
    // -----------------------------------------------------------------------

    static constexpr float MIN_SPEED_FOR_DIR_UPDATE = 1.0f;
    static constexpr float DIR_SMOOTH_ALPHA = 0.3f;

    LWristSpeed = VelLWrist.Size();
    RWristSpeed = VelRWrist.Size();
    LElbowSpeed = VelLElbow.Size();
    RElbowSpeed = VelRElbow.Size();

    if (LWristSpeed > MIN_SPEED_FOR_DIR_UPDATE)
        LWristVelocityDir = FMath::Lerp(LWristVelocityDir,
            VelLWrist / LWristSpeed, DIR_SMOOTH_ALPHA).GetSafeNormal();

    if (RWristSpeed > MIN_SPEED_FOR_DIR_UPDATE)
        RWristVelocityDir = FMath::Lerp(RWristVelocityDir,
            VelRWrist / RWristSpeed, DIR_SMOOTH_ALPHA).GetSafeNormal();

    if (LElbowSpeed > MIN_SPEED_FOR_DIR_UPDATE)
        LElbowVelocityDir = FMath::Lerp(LElbowVelocityDir,
            VelLElbow / LElbowSpeed, DIR_SMOOTH_ALPHA).GetSafeNormal();

    if (RElbowSpeed > MIN_SPEED_FOR_DIR_UPDATE)
        RElbowVelocityDir = FMath::Lerp(RElbowVelocityDir,
            VelRElbow / RElbowSpeed, DIR_SMOOTH_ALPHA).GetSafeNormal();

    // -----------------------------------------------------------------------
    // LMA Space: Expansiveness — maximum wrist-to-spine reach distance.
    // -----------------------------------------------------------------------

    const float DistL = FVector::Dist(Spine, LWrist);
    const float DistR = FVector::Dist(Spine, RWrist);
    CurrentExpansiveness = NormalizeAdaptive(
        FMath::Max(DistL, DistR),
        AdaptiveMin_Expansiveness, AdaptiveMax_Expansiveness);

    // -----------------------------------------------------------------------
    // LMA Time: Effort — weighted aggregate velocity magnitude.
    // -----------------------------------------------------------------------

    const float RawEffort =
        (VelLWrist.Size() * WEIGHT_WRIST +
            VelRWrist.Size() * WEIGHT_WRIST +
            VelLElbow.Size() * WEIGHT_ELBOW +
            VelRElbow.Size() * WEIGHT_ELBOW +
            VelLShoulder.Size() * WEIGHT_SHOULDER +
            VelRShoulder.Size() * WEIGHT_SHOULDER)
        / TOTAL_JOINT_WEIGHT;

    CurrentEffort = NormalizeAdaptive(
        RawEffort, AdaptiveMin_Effort, AdaptiveMax_Effort);

    // -----------------------------------------------------------------------
    // LMA Weight: acceleration magnitude across primary limbs.
    // -----------------------------------------------------------------------

    const FVector AccelLWrist = (VelLWrist - PrevLWristVelocity) / DeltaTime;
    const FVector AccelRWrist = (VelRWrist - PrevRWristVelocity) / DeltaTime;
    const FVector AccelLElbow = (VelLElbow - PrevLElbowVelocity) / DeltaTime;
    const FVector AccelRElbow = (VelRElbow - PrevRElbowVelocity) / DeltaTime;

    const float RawWeight =
        (AccelLWrist.Size() * WEIGHT_WRIST +
            AccelRWrist.Size() * WEIGHT_WRIST +
            AccelLElbow.Size() * WEIGHT_ELBOW +
            AccelRElbow.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    CurrentWeight = NormalizeAdaptive(
        RawWeight, AdaptiveMin_Weight, AdaptiveMax_Weight);

    // -----------------------------------------------------------------------
    // LMA Flow: rolling sigma of aggregate velocity delta magnitude.
    // High sigma = erratic/Free. Low sigma = regular/Bound.
    // -----------------------------------------------------------------------

    const float AggVelMag =
        (VelLWrist.Size() * WEIGHT_WRIST + VelRWrist.Size() * WEIGHT_WRIST +
            VelLElbow.Size() * WEIGHT_ELBOW + VelRElbow.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    const float PrevAggVelMag =
        (PrevLWristVelocity.Size() * WEIGHT_WRIST +
            PrevRWristVelocity.Size() * WEIGHT_WRIST +
            PrevLElbowVelocity.Size() * WEIGHT_ELBOW +
            PrevRElbowVelocity.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    const float VelDeltaMag = FMath::Abs(AggVelMag - PrevAggVelMag) / DeltaTime;

    FlowDeltaBuffer.Add(VelDeltaMag);
    if (FlowDeltaBuffer.Num() > FlowWindowSize)
        FlowDeltaBuffer.RemoveAt(0, 1, EAllowShrinking::No);

    const float RawFlow = (FlowDeltaBuffer.Num() >= 2)
        ? ComputeStdDev(FlowDeltaBuffer) : 0.0f;

    CurrentFlow = NormalizeAdaptive(
        RawFlow, AdaptiveMin_Flow, AdaptiveMax_Flow);

    // -----------------------------------------------------------------------
    // Advance joint history state.
    // -----------------------------------------------------------------------

    PrevLWrist = LWrist;
    PrevRWrist = RWrist;
    PrevLElbow = LElbow;
    PrevRElbow = RElbow;
    PrevLShoulder = LShoulder;
    PrevRShoulder = RShoulder;

    PrevLWristVelocity = VelLWrist;
    PrevRWristVelocity = VelRWrist;
    PrevLElbowVelocity = VelLElbow;
    PrevRElbowVelocity = VelRElbow;

    DebugEffort = CurrentEffort;
    DebugExpansiveness = CurrentExpansiveness;
    DebugWeight = CurrentWeight;
    DebugFlow = CurrentFlow;
}


// ============================================================================
// UpdateRenderSubsystems
// ============================================================================

void UKinematicDescriptorComponent::UpdateRenderSubsystems(
    const FVector& PelvisLocation)
{
    if (GlobalMPC)
    {
        UWorld* World = GetWorld();

        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("EffortLevel"), CurrentEffort);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("ExpansivenessLevel"), CurrentExpansiveness);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("WeightLevel"), CurrentWeight);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("FlowLevel"), CurrentFlow);

        /*UKismetMaterialLibrary::SetVectorParameterValue(
            World, GlobalMPC, FName("PelvisWorldLocation"),
            FLinearColor(PelvisLocation.X, PelvisLocation.Y, PelvisLocation.Z, 1.0f));*/
    }

    if (ParticleSystem)
    {
        ParticleSystem->SetFloatParameter(FName("User.EffortLevel"), CurrentEffort);
        ParticleSystem->SetFloatParameter(FName("User.FlowLevel"), CurrentFlow);
    }
}


// ============================================================================
// ExecuteKinematicPhysics
// ============================================================================

void UKinematicDescriptorComponent::ExecuteKinematicPhysics()
{
    if (!bHomeOffsetsReady) return;

    // Read the limb proximity radius from ProximityDispatchComponent.
    // This ensures physics proximity and WOP proximity use the same radius value,
    // keeping the two response systems spatially consistent.
    const float LimbProximityRadius = (ProximityDispatch && IsValid(ProximityDispatch))
        ? ProximityDispatch->ProximityRadius
        : 150.0f;

    const float ExpansivenessScale = 0.5f + CurrentExpansiveness;

    // Flow modulates the attractor spring.
    // Bound (low Flow) = tight snap-back. Free (high Flow) = slow drift.
    const float FlowScale = FMath::Max(1.0f - CurrentFlow, 0.3f);
    const float AttractorScale = 1.0f + FlowScale;

    // Socket names for the four limb joints checked per performer skeleton.
    static const FName LimbSockets[] =
    {
        FName("LeftHand"),
        FName("RightHand"),
        FName("LeftForeArm"),
        FName("RightForeArm")
    };

    static const float LimbWeights[] =
    {
        WEIGHT_WRIST,
        WEIGHT_WRIST,
        WEIGHT_ELBOW,
        WEIGHT_ELBOW
    };

    for (AActor* Cube : ARCubes)
    {
        if (!Cube || !IsValid(Cube)) continue;

        UPrimitiveComponent* PrimComp =
            Cube->FindComponentByClass<UPrimitiveComponent>();

        if (!PrimComp || !PrimComp->IsSimulatingPhysics()) continue;

        const FVector CurrentLoc = Cube->GetActorLocation();

        // Look up home position by actor UniqueID.
        // Falls back to CurrentLoc only if RebuildHomeLocations was not called
        // before this tick, in which case the attractor produces zero force.
        const FVector* HomePtr = HomePosById.Find(Cube->GetUniqueID());
        const FVector HomeLoc = HomePtr ? *HomePtr : CurrentLoc;

        const FVector ToHome = HomeLoc - CurrentLoc;
        const float   DistToHome = ToHome.Size();

        // -------------------------------------------------------------------
        // FORCE 1 — ATTRACTOR
        // Always active. Gentle spring toward the fixed home position.
        // Flow-modulated: Bound = snappy, Free = slow drift.
        // -------------------------------------------------------------------

        const FVector AttractorForce = ToHome * AttractorSpringConstant * AttractorScale;

        // -------------------------------------------------------------------
        // FORCE 2 — PROXIMITY-BASED REPULSOR
        //
        // For each tracked performer, each of the four limb joints is checked.
        // A joint contributes to this particle's repulsor only when:
        //   (a) The joint is within LimbProximityRadius of this particle (3D).
        //   (b) The joint speed exceeds MIN_LIMB_SPEED_THRESHOLD.
        //
        // ProximityFactor: smooth falloff from 1.0 (touching) to 0.0 (at radius edge).
        // Force direction: the limb's velocity direction (where the limb is going).
        // Force magnitude: product of ProximityFactor, NormSpeed, LMA descriptors.
        // -------------------------------------------------------------------

        FVector AccumulatedRepulsorForce = FVector::ZeroVector;

        for (USkeletalMeshComponent* Skel : TrackedSkeletons)
        {
            if (!Skel || !IsValid(Skel)) continue;

            for (int32 i = 0; i < 4; ++i)
            {
                const FVector LimbWorldPos =
                    Skel->GetSocketLocation(LimbSockets[i]);

                const float DistToLimb =
                    FVector::Dist(CurrentLoc, LimbWorldPos);

                // Proximity gate: only particles within LimbProximityRadius receive force.
                if (DistToLimb >= LimbProximityRadius) continue;

                // Smooth proximity falloff: 1.0 at limb position, 0.0 at radius boundary.
                const float ProximityFactor =
                    1.0f - (DistToLimb / LimbProximityRadius);

                // Resolve velocity direction for this limb index.
                FVector LimbDir = FVector::ZeroVector;
                float   LimbSpeed = 0.0f;

                switch (i)
                {
                case 0: LimbDir = LWristVelocityDir; LimbSpeed = LWristSpeed; break;
                case 1: LimbDir = RWristVelocityDir; LimbSpeed = RWristSpeed; break;
                case 2: LimbDir = LElbowVelocityDir; LimbSpeed = LElbowSpeed; break;
                case 3: LimbDir = RElbowVelocityDir; LimbSpeed = RElbowSpeed; break;
                default: break;
                }

                if (LimbSpeed < MIN_LIMB_SPEED_THRESHOLD) continue;
                if (LimbDir.IsNearlyZero())                continue;

                const float NormalisedSpeed = FMath::Clamp(
                    LimbSpeed / REF_MAX_LIMB_SPEED, 0.0f, 1.0f);

                const float ForceMag =
                    ProximityFactor
                    * NormalisedSpeed
                    * CurrentEffort
                    * (0.5f + CurrentWeight * 0.5f)
                    * LimbWeights[i]
                    * ExpansivenessScale;

                AccumulatedRepulsorForce += LimbDir * ForceMag;
            }
        }

        const FVector RepulsorForce =
            AccumulatedRepulsorForce * RepulsorForceMultiplier;

        // -------------------------------------------------------------------
        // FORCE 3 — TETHER
        //
        // Quadratic restorative force that activates when a particle exceeds
        // MaxDeformationRadius from its home position.
        // Force = (Violation²) × TetherCoefficient
        //
        // MaxDeformationRadius and TetherCoefficient are both UPROPERTY,
        // editable in the Details panel without recompiling.
        //
        // This replaces the former hardcoded 80cm cap and 150.0f coefficient.
        // -------------------------------------------------------------------

        FVector TetherForce = FVector::ZeroVector;

        if (DistToHome > MaxDeformationRadius)
        {
            const float Violation = DistToHome - MaxDeformationRadius;
            TetherForce = ToHome.GetSafeNormal()
                * (Violation * Violation * TetherCoefficient);
        }

        // Apply Chaos solver stable linear damping.
        // More stable than manual drag via AddForce at variable frame rates.
        PrimComp->SetLinearDamping(BaseDragCoefficient);

        // Explicitly wake the physics body before applying forces.
		PrimComp->WakeRigidBody();

        // Apply all three forces as mass-independent accelerations.
        PrimComp->AddForce(
            AttractorForce + RepulsorForce + TetherForce,
            NAME_None,
            /*bAccelChange=*/ true);

        // Velocity cap — prevents accumulated velocity from consecutive fast
        // movements from overcoming the tether and attractor in a single tick.
        const FVector PhysicsVelocity = PrimComp->GetPhysicsLinearVelocity();
        const float   CurrentSpeed = PhysicsVelocity.Size();
        if (CurrentSpeed > MaxParticleVelocity)
        {
            PrimComp->SetPhysicsLinearVelocity(
                PhysicsVelocity.GetSafeNormal() * MaxParticleVelocity);
        }
    }
}

// ============================================================================
// RebuildHomeLocations
// ============================================================================

void UKinematicDescriptorComponent::RebuildHomeLocations()
{
    CubeHomeOffsets.Empty();
    HomePositions.Empty();

    if (ARCubes.Num() == 0)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: RebuildHomeLocations — "
                "ARCubes array is empty. Physics gate remains closed."));
        return;
    }

    // Pre-allocate to guarantee index alignment with ARCubes.
    HomePositions.SetNum(ARCubes.Num());

    int32 AnchoredCount = 0;

    for (AActor* Cube : ARCubes)
    {
        if (!Cube || !IsValid(Cube)) continue;

        // Store home position keyed by actor UniqueID.
        // UniqueID is a stable uint32 assigned at object creation and never changes.
        // This avoids TMap raw-pointer equality failures that silently occur when
        // Blueprint object wrappers are involved — the pointer stored at spawn time
        // does not match the pointer seen during physics ticks, so Contains() returns
        // false and HomeLoc falls back to CurrentLoc, zeroing the attractor force.
        // UniqueID comparison is always reliable regardless of wrapping.
        CubeHomeOffsets.Add(Cube, Cube->GetActorLocation());
        HomePosById.Add(Cube->GetUniqueID(), Cube->GetActorLocation());
        ++AnchoredCount;
    }

    // Only open the physics gate if at least one particle was anchored.
    bHomeOffsetsReady = (AnchoredCount > 0);

    UE_LOG(LogTemp, Log,
        TEXT("UKinematicDescriptorComponent: RebuildHomeLocations — "
            "%d / %d particles anchored. Physics gate: %s."),
        AnchoredCount,
        ARCubes.Num(),
        bHomeOffsetsReady ? TEXT("OPEN") : TEXT("CLOSED"));
}


// ============================================================================
// NormalizeAdaptive
// ============================================================================

float UKinematicDescriptorComponent::NormalizeAdaptive(
    float  RawValue,
    float& AdaptiveMin,
    float& AdaptiveMax) const
{
    if (RawValue > AdaptiveMax)
        AdaptiveMax = FMath::Lerp(AdaptiveMax, RawValue, NormRangeExpandAlpha);
    else
        AdaptiveMax = FMath::Lerp(AdaptiveMax, RawValue, NormRangeContractAlpha);

    if (RawValue < AdaptiveMin)
        AdaptiveMin = FMath::Lerp(AdaptiveMin, RawValue, NormRangeExpandAlpha);
    else
        AdaptiveMin = FMath::Lerp(AdaptiveMin, RawValue, NormRangeContractAlpha);

    const float ValidRange = FMath::Max(AdaptiveMax - AdaptiveMin, 1.0f);
    return FMath::Clamp((RawValue - AdaptiveMin) / ValidRange, 0.0f, 1.0f);
}


// ============================================================================
// ComputeStdDev
// ============================================================================

float UKinematicDescriptorComponent::ComputeStdDev(const TArray<float>& Buffer)
{
    if (Buffer.Num() < 2) return 0.0f;

    float Sum = 0.0f;
    for (const float Val : Buffer) Sum += Val;
    const float Mean = Sum / static_cast<float>(Buffer.Num());

    float SumSqDiff = 0.0f;
    for (const float Val : Buffer)
        SumSqDiff += FMath::Square(Val - Mean);

    return FMath::Sqrt(SumSqDiff / static_cast<float>(Buffer.Num()));
}