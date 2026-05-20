/**
 * Component: UProximityDispatchComponent
 *
 * Responsibility:
 *   Runs every tick to compute a per-particle normalised proximity value between
 *   each registered AR particle actor and the nearest limb of any tracked performer.
 *   The result is written to each actor's Dynamic Material Instance (DMI) under the
 *   scalar parameter name "PerformerProximity". This gates the WPO deformation
 *   channel in M_KinematicGrid — which must multiply its WPO output by this value.
 *
 * CHANGE FROM PREVIOUS VERSION (pelvis-only):
 *   Previous: distance measured from performer PELVIS to each particle.
 *             A raised arm did not trigger WPO on particles near the hand.
 *             All particles at the same pelvis distance deformed equally.
 *   Current:  distance measured from the NEAREST LIMB (LWrist, RWrist, LElbow,
 *             RElbow, Pelvis) across ALL tracked performers. A raised arm
 *             triggers WPO on particles near the hand only. PerformerProximity
 *             is the maximum across all performers' limbs — a particle responds
 *             to the closest limb from any performer in the scene.
 *
 * SKELETON DISCOVERY:
 *   This component does NOT maintain its own skeleton array. It reads
 *   TrackedSkeletons from UKinematicDescriptorComponent on the same owner actor,
 *   which already performs auto-discovery of ZED_Manny actors every tick.
 *   Fallback: if KDC is not found, uses the manually assigned TrackedSkeleton.
 *
 * DMI CACHE:
 *   Dynamic Material Instances are created lazily in TickComponent whenever
 *   ARMeshActors.Num() != CachedDMIs.Num(). This means BP_ARGridSpawner can
 *   set the ARMeshActors array via Blueprint at any time after BeginPlay —
 *   the next tick automatically creates the DMI cache without any additional
 *   function call required.
 *
 * MATERIAL REQUIREMENT:
 *   M_KinematicGrid MUST multiply its WPO output by the "PerformerProximity"
 *   ScalarParameter for proximity-gated deformation to work. See the fix guide
 *   for the exact node connection in the Material Editor.
 *
 * Setup:
 *   - Add to BP_KinematicManager alongside UKinematicDescriptorComponent.
 *   - Assign GlobalMPC (MPC_KinematicAR) in the Details panel.
 *   - Set ARMeshActors from BP_ARGridSpawner after particles are spawned.
 *   - TrackedSkeleton may be left unassigned if KDC is present on the same actor.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "ProximityDispatchComponent.generated.h"

class USkeletalMeshComponent;
class UMaterialParameterCollection;

UCLASS(ClassGroup = (KinematicEI), meta = (BlueprintSpawnableComponent))
class VP_AR_FULL_SYSTEM_API UProximityDispatchComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UProximityDispatchComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;

    // -----------------------------------------------------------------------
    // Public Interface
    // -----------------------------------------------------------------------

    /**
     * Toggles between Compositing Mode (bIsInteractive = false) and Interactive
     * Mode (bIsInteractive = true). Writes 0.0 or 1.0 to the "SystemMode"
     * scalar in GlobalMPC, which gates WPO channels 2 and 3 in all AR materials.
     */
    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Mode")
    void SetSystemMode(bool bInteractive);

    /**
     * Convenience toggle. Flips the current mode and propagates to the MPC.
     */
    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Mode")
    void ToggleSystemMode();

    // -----------------------------------------------------------------------
    // References — assign in Details panel or via Blueprint
    // -----------------------------------------------------------------------

    /**
     * Fallback single tracked skeleton. Used only when UKinematicDescriptorComponent
     * is not present on the same owner actor. Assign in the Details panel for
     * single-performer setups that do not use KDC.
     * If KDC is present, its auto-discovered TrackedSkeletons array takes precedence.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    USkeletalMeshComponent* TrackedSkeleton;

    /**
     * All AR particle actors. Set this array from BP_ARGridSpawner via Blueprint
     * after particles are spawned. The DMI cache is rebuilt automatically on the
     * next tick after this array is modified — no additional function call required.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<AActor*> ARMeshActors;

    /**
     * MPC_KinematicAR asset. Used to write the SystemMode scalar.
     * Assign in the Details panel before Play.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UMaterialParameterCollection* GlobalMPC;

    // -----------------------------------------------------------------------
    // Tuning
    // -----------------------------------------------------------------------

    /**
     * Maximum distance (cm) at which PerformerProximity is non-zero.
     * Measured from the nearest limb (LWrist, RWrist, LElbow, RElbow, Pelvis)
     * of any tracked performer to the particle's world position.
     *
     * This value also drives the physics proximity gate in
     * UKinematicDescriptorComponent::ExecuteKinematicPhysics() via the
     * ProximityDispatch pointer cached at BeginPlay on that component.
     * Keep this value in sync with KDC::LimbPhysicsProximityRadius if using
     * both. Default: 150 cm.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Proximity",
        meta = (ClampMin = "10.0", ClampMax = "500.0"))
    float ProximityRadius = 150.0f;

private:
    // Cached DMIs — one per entry in ARMeshActors, same index order.
    // Rebuilt automatically when ARMeshActors.Num() != CachedDMIs.Num().
    TArray<UMaterialInstanceDynamic*> CachedDMIs;

    // Current interactive mode state.
    bool bIsInteractive = false;

    // Number of ARMeshActors entries at the time the DMI cache was last built.
    // Used to detect when the array changes and a cache rebuild is needed.
    int32 LastKnownActorCount = 0;

    /**
     * Builds or rebuilds the CachedDMIs array from the current ARMeshActors.
     * Creates a Dynamic Material Instance for slot 0 of each actor's first
     * UStaticMeshComponent. Called automatically from TickComponent whenever
     * ARMeshActors.Num() != LastKnownActorCount.
     */
    void RebuildDMICache();

    /**
     * Computes the minimum 3D distance from the given WorldLocation to any
     * tracked limb position across all active performer skeletons.
     * Limbs checked: Pelvis, LWrist, RWrist, LElbow, RElbow (5 points per skeleton).
     * Returns FLT_MAX if no valid skeletons are available.
     */
    float ComputeMinLimbDistance(const FVector& WorldLocation,
        const TArray<USkeletalMeshComponent*>& Skeletons) const;
};