/**
 * ProximityDispatchComponent.cpp
 *
 * Implementation of UProximityDispatchComponent.
 * See header for full description of responsibilities and setup instructions.
 */

#include "kinematicEI_system/ProximityDispatchComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialParameterCollection.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

UProximityDispatchComponent::UProximityDispatchComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    TrackedSkeleton = nullptr;
    GlobalMPC       = nullptr;
    bIsInteractive  = false;
}

// ---------------------------------------------------------------------------
// BeginPlay
// ---------------------------------------------------------------------------

void UProximityDispatchComponent::BeginPlay()
{
    Super::BeginPlay();

    // Pre-build one DMI per registered AR mesh actor and cache it.
    // Creating DMIs at BeginPlay avoids per-tick allocation overhead and
    // ensures that every Tick call writes to a valid, actor-owned instance.
    CachedDMIs.Empty();
    CachedDMIs.Reserve(ARMeshActors.Num());

    for (AActor* Actor : ARMeshActors)
    {
        if (!Actor)
        {
            CachedDMIs.Add(nullptr);
            continue;
        }

        UStaticMeshComponent* MeshComp =
            Actor->FindComponentByClass<UStaticMeshComponent>();

        if (!MeshComp)
        {
            UE_LOG(LogTemp, Warning,
                TEXT("UProximityDispatchComponent: Actor '%s' has no "
                     "StaticMeshComponent — skipping DMI creation."),
                *Actor->GetName());
            CachedDMIs.Add(nullptr);
            continue;
        }

        // CreateAndSetMaterialInstanceDynamic replaces the material at slot 0
        // with a new DMI that wraps the original material asset. All material
        // parameters (including PerformerProximity) can then be set per-frame
        // without affecting the base M_KinematicGrid asset.
        UMaterialInstanceDynamic* DMI =
            MeshComp->CreateAndSetMaterialInstanceDynamic(0);

        if (!DMI)
        {
            UE_LOG(LogTemp, Warning,
                TEXT("UProximityDispatchComponent: Failed to create DMI for "
                     "actor '%s'."),
                *Actor->GetName());
        }

        CachedDMIs.Add(DMI);
    }

    // Initialise SystemMode in the MPC to Compositing Mode (0.0) on startup.
    // Interactive Mode is entered only via explicit SetSystemMode or
    // ToggleSystemMode calls.
    if (GlobalMPC)
    {
        UKismetMaterialLibrary::SetScalarParameterValue(
            GetWorld(), GlobalMPC, FName("SystemMode"), 0.0f);
    }

    UE_LOG(LogTemp, Log,
        TEXT("UProximityDispatchComponent: Initialised with %d AR mesh actors. "
             "Starting in Compositing Mode."),
        ARMeshActors.Num());
}

// ---------------------------------------------------------------------------
// TickComponent
// ---------------------------------------------------------------------------

void UProximityDispatchComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Proximity dispatch runs in both modes — do not gate on bIsInteractive.
    if (!TrackedSkeleton)
    {
        return;
    }

    // Read the performer's pelvis world position. The socket name "Hips" is
    // the Manny rig bone name that the ZED LiveLink plugin maps from PELVIS.
    const FVector PelvisLoc =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));

    const int32 ActorCount = ARMeshActors.Num();

    for (int32 i = 0; i < ActorCount; ++i)
    {
        AActor* Actor = ARMeshActors[i];
        UMaterialInstanceDynamic* DMI = CachedDMIs.IsValidIndex(i)
            ? CachedDMIs[i] : nullptr;

        if (!Actor || !DMI)
        {
            continue;
        }

        // Compute the 3D Euclidean distance between the cube's world location
        // and the performer's pelvis. Using the actor's root location (centre
        // of the cube) is a valid approximation for the physics-scale grid.
        const float Distance =
            FVector::Dist(Actor->GetActorLocation(), PelvisLoc);

        // Normalise to [0, 1] within ProximityRadius.
        // At Distance == 0     → PerformerProximity = 1.0 (maximum deformation).
        // At Distance >= Radius → PerformerProximity = 0.0 (no deformation).
        // FMath::Clamp ensures values never exceed [0, 1] regardless of geometry.
        const float NormalisedProximity = FMath::Clamp(
            1.0f - (Distance / FMath::Max(ProximityRadius, 1.0f)),
            0.0f,
            1.0f);

        // Write the scalar to the cube's DMI. The M_KinematicGrid material
        // reads this as "PerformerProximity" in the contact-deformation WPO
        // channel, which is always active regardless of SystemMode.
        DMI->SetScalarParameterValue(
            FName("PerformerProximity"), NormalisedProximity);
    }
}

// ---------------------------------------------------------------------------
// SetSystemMode
// ---------------------------------------------------------------------------

void UProximityDispatchComponent::SetSystemMode(bool bInteractive)
{
    bIsInteractive = bInteractive;

    if (GlobalMPC)
    {
        // SystemMode = 1.0 enables Interactive Mode (WPO channels 2 and 3 live).
        // SystemMode = 0.0 enables Compositing Mode (channels 2 and 3 zeroed).
        UKismetMaterialLibrary::SetScalarParameterValue(
            GetWorld(),
            GlobalMPC,
            FName("SystemMode"),
            bIsInteractive ? 1.0f : 0.0f);
    }

    UE_LOG(LogTemp, Log,
        TEXT("UProximityDispatchComponent: System mode set to %s."),
        bIsInteractive ? TEXT("Interactive") : TEXT("Compositing"));
}

// ---------------------------------------------------------------------------
// ToggleSystemMode
// ---------------------------------------------------------------------------

void UProximityDispatchComponent::ToggleSystemMode()
{
    SetSystemMode(!bIsInteractive);
}
