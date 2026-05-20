/**
 * ProximityDispatchComponent.cpp
 *
 * CHANGES FROM PREVIOUS VERSION:
 *
 * 1. PROXIMITY MEASUREMENT: Changed from pelvis-to-particle distance to
 *    minimum(all limb positions)-to-particle distance. Limbs checked per
 *    performer: Pelvis, LWrist, RWrist, LElbow, RElbow. This means particles
 *    respond to where limbs actually are in 3D space, not just where the
 *    torso is.
 *
 * 2. MULTI-PERFORMER: Instead of a single TrackedSkeleton, the component reads
 *    TrackedSkeletons from UKinematicDescriptorComponent on the same owner actor.
 *    KDC already auto-discovers all ZED_Manny actors every tick — this component
 *    reuses that list rather than doing its own discovery. PerformerProximity
 *    is written as the maximum proximity across all performers' limbs.
 *
 * 3. LAZY DMI CACHE: DMIs are no longer created only in BeginPlay. They are
 *    rebuilt automatically in TickComponent whenever ARMeshActors.Num() changes.
 *    This allows BP_ARGridSpawner to set ARMeshActors via Blueprint at any point
 *    after BeginPlay without requiring an explicit RegisterARMeshActors() call.
 */

#include "kinematicEI_system/ProximityDispatchComponent.h"
#include "kinematicEI_system/KinematicDescriptorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialParameterCollection.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


 // ============================================================================
 // Socket names for the five limb points checked per performer skeleton.
 // These match the ZED LiveLink BODY_38 to UE5 Manny bone name retarget.
 // Adjust these FName values if the project uses a different retarget asset.
 // ============================================================================

namespace ProximityLimbSockets
{
    static const FName Pelvis = FName("Hips");
    static const FName LWrist = FName("LeftHand");
    static const FName RWrist = FName("RightHand");
    static const FName LElbow = FName("LeftForeArm");
    static const FName RElbow = FName("RightForeArm");

    static const FName AllSockets[] = { Pelvis, LWrist, RWrist, LElbow, RElbow };
    static constexpr int32 SocketCount = 5;
}


// ============================================================================
// Constructor
// ============================================================================

UProximityDispatchComponent::UProximityDispatchComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsInteractive = false;
    LastKnownActorCount = 0;
}


// ============================================================================
// BeginPlay
// ============================================================================

void UProximityDispatchComponent::BeginPlay()
{
    Super::BeginPlay();

    // Initialise SystemMode in the MPC to Interactive Mode (1.0) at startup.
    // Compositing Mode is entered only via an explicit SetSystemMode(false) call.
    bIsInteractive = true;

    // Build the initial DMI cache if ARMeshActors was already populated in the
    // editor (i.e. for test setups with pre-placed particles). In production
    // the array will be empty here and populated by BP_ARGridSpawner later.
    if (ARMeshActors.Num() > 0)
    {
        RebuildDMICache();
    }

    UE_LOG(LogTemp, Log,
        TEXT("UProximityDispatchComponent: BeginPlay — %d AR actors registered. "
            "Interactive Mode active."),
        ARMeshActors.Num());
}


// ============================================================================
// RebuildDMICache
//
// Creates a Dynamic Material Instance from slot 0 of each actor's first
// UStaticMeshComponent and stores it in CachedDMIs. Previous entries are
// discarded. Called automatically from TickComponent when the actor count changes.
// ============================================================================

void UProximityDispatchComponent::RebuildDMICache()
{
    CachedDMIs.Empty();

    for (AActor* Actor : ARMeshActors)
    {
        if (!Actor || !IsValid(Actor))
        {
            CachedDMIs.Add(nullptr);
            continue;
        }

        UStaticMeshComponent* SMC = Actor->FindComponentByClass<UStaticMeshComponent>();
        if (!SMC)
        {
            UE_LOG(LogTemp, Warning,
                TEXT("UProximityDispatchComponent: Actor '%s' has no "
                    "UStaticMeshComponent. DMI skipped."),
                *Actor->GetName());
            CachedDMIs.Add(nullptr);
            continue;
        }

        UMaterialInstanceDynamic* DMI = SMC->CreateDynamicMaterialInstance(0);
        CachedDMIs.Add(DMI);
    }

    LastKnownActorCount = ARMeshActors.Num();

    UE_LOG(LogTemp, Log,
        TEXT("UProximityDispatchComponent: DMI cache rebuilt — %d entries."),
        CachedDMIs.Num());
}


// ============================================================================
// TickComponent
// ============================================================================

void UProximityDispatchComponent::TickComponent(
    float                        DeltaTime,
    ELevelTick                   TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // -----------------------------------------------------------------------
    // Lazy DMI cache rebuild.
    // BP_ARGridSpawner sets ARMeshActors after BeginPlay. Detecting the count
    // change here rebuilds the DMI cache automatically on the following tick.
    // -----------------------------------------------------------------------

    if (ARMeshActors.Num() != LastKnownActorCount)
    {
        RebuildDMICache();
    }

    const int32 ActorCount = ARMeshActors.Num();
    if (ActorCount == 0) return;

    // -----------------------------------------------------------------------
    // Resolve the active skeleton list.
    //
    // Primary source: UKinematicDescriptorComponent on the same owner actor.
    // KDC auto-discovers all ZED_Manny actors every tick and maintains
    // TrackedSkeletons. Reading from it avoids duplicate discovery work.
    //
    // Fallback: the manually assigned TrackedSkeleton on this component.
    // Used for single-performer setups without KDC, or as a safety fallback.
    // -----------------------------------------------------------------------

    TArray<USkeletalMeshComponent*> ActiveSkeletons;

    UKinematicDescriptorComponent* KDC = GetOwner()
        ? GetOwner()->FindComponentByClass<UKinematicDescriptorComponent>()
        : nullptr;

    if (KDC && KDC->TrackedSkeletons.Num() > 0)
    {
        // Reuse the skeleton list already maintained by KDC.
        ActiveSkeletons = KDC->TrackedSkeletons;
    }
    else if (TrackedSkeleton && IsValid(TrackedSkeleton))
    {
        ActiveSkeletons.Add(TrackedSkeleton);
    }

    // -----------------------------------------------------------------------
    // Per-particle proximity computation.
    //
    // For each particle actor, find the minimum 3D distance from its world
    // position to any limb of any tracked performer. Normalise to [0, 1]
    // within ProximityRadius. Write to the particle's DMI as "PerformerProximity".
    //
    // M_KinematicGrid must multiply its WPO output by this value. At 0.0
    // (no limb nearby), WPO is suppressed for that particle. At 1.0 (limb
    // touching), full WPO deformation applies.
    // -----------------------------------------------------------------------

    for (int32 i = 0; i < ActorCount; ++i)
    {
        AActor* Actor = ARMeshActors[i];
        UMaterialInstanceDynamic* DMI = CachedDMIs.IsValidIndex(i)
            ? CachedDMIs[i] : nullptr;

        if (!Actor || !IsValid(Actor) || !DMI) continue;

        const FVector ActorLoc = Actor->GetActorLocation();

        // Find the minimum distance from this particle to any tracked limb
        // across all active performers.
        const float MinDist = ComputeMinLimbDistance(ActorLoc, ActiveSkeletons);

        // Normalise: 1.0 at zero distance, 0.0 at or beyond ProximityRadius.
        const float NormalisedProximity = (MinDist < FLT_MAX)
            ? FMath::Clamp(
                1.0f - (MinDist / FMath::Max(ProximityRadius, 1.0f)),
                0.0f, 1.0f)
            : 0.0f;

        DMI->SetScalarParameterValue(FName("PerformerProximity"), NormalisedProximity);
    }
}


// ============================================================================
// ComputeMinLimbDistance
//
// Iterates over all active performer skeletons and all tracked limb sockets.
// Returns the smallest Euclidean distance found between WorldLocation and any
// limb position. Returns FLT_MAX if Skeletons is empty or all are invalid.
// ============================================================================

float UProximityDispatchComponent::ComputeMinLimbDistance(
    const FVector& WorldLocation,
    const TArray<USkeletalMeshComponent*>& Skeletons) const
{
    if (Skeletons.Num() == 0) return FLT_MAX;

    float MinDistance = FLT_MAX;

    for (const USkeletalMeshComponent* Skel : Skeletons)
    {
        if (!Skel || !IsValid(Skel)) continue;

        for (int32 s = 0; s < ProximityLimbSockets::SocketCount; ++s)
        {
            const FVector LimbPos =
                Skel->GetSocketLocation(ProximityLimbSockets::AllSockets[s]);

            const float Dist = FVector::Dist(WorldLocation, LimbPos);

            if (Dist < MinDistance)
            {
                MinDistance = Dist;
            }
        }
    }

    return MinDistance;
}


// ============================================================================
// SetSystemMode
// ============================================================================

void UProximityDispatchComponent::SetSystemMode(bool bInteractive)
{
    bIsInteractive = bInteractive;

    UE_LOG(LogTemp, Log,
        TEXT("UProximityDispatchComponent: Mode switched to %s."),
        bInteractive ? TEXT("Interactive") : TEXT("Compositing"));
}


// ============================================================================
// ToggleSystemMode
// ============================================================================

void UProximityDispatchComponent::ToggleSystemMode()
{
    SetSystemMode(!bIsInteractive);
}