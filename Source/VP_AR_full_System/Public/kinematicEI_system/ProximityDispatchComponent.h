/**
 * Component: UProximityDispatchComponent
 *
 * Responsibility:
 *   Runs every tick to compute a per-cube normalised proximity value between
 *   the performer's pelvis joint and each registered AR mesh actor. The result
 *   is written to each actor's Dynamic Material Instance (DMI) under the scalar
 *   parameter name "PerformerProximity". This drives the contact-deformation
 *   World Position Offset channel in M_KinematicGrid, which remains active in
 *   both Compositing Mode and Interactive Mode.
 *
 *   The component also owns the SystemMode toggle. Calling SetSystemMode(true)
 *   switches to Interactive Mode (EI descriptors live); false returns to
 *   Compositing Mode (EI suspended, WPO channels 2 and 3 gated to zero via
 *   the MPC "SystemMode" scalar).
 *
 * Setup:
 *   - Add this component to BP_KinematicManager alongside
 *     UKinematicDescriptorComponent.
 *   - Assign TrackedSkeleton at runtime via the Level Blueprint BeginPlay
 *     sequence (same pattern as KinematicDescriptorComponent).
 *   - Populate ARMeshActors with all cube actors in the Details panel before
 *     Play. BeginPlay creates a DMI for each actor and caches it.
 *   - Assign GlobalMPC to MPC_KinematicAR in the Details panel.
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
     * Mode (bIsInteractive = true). Writes the corresponding 0.0 or 1.0 value
     * to the "SystemMode" scalar in GlobalMPC, which gates WPO channels 2 and 3
     * in all AR materials simultaneously via the shared MPC.
     */
    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Mode")
    void SetSystemMode(bool bInteractive);

    /**
     * Convenience toggle. Flips the current mode and propagates to the MPC.
     */
    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Mode")
    void ToggleSystemMode();

    // -----------------------------------------------------------------------
    // References — assign in Details panel or via Level Blueprint
    // -----------------------------------------------------------------------

    /**
     * The SkeletalMeshComponent of the live ZED Manny actor. Injected at
     * runtime by the Level Blueprint BeginPlay sequence after the 2-second
     * startup delay. Must be set before Tick runs proximity computation.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    USkeletalMeshComponent* TrackedSkeleton;

    /**
     * All AR cube actors whose DMIs receive the PerformerProximity scalar.
     * Assign every cube in the grid here before Play. BeginPlay creates a
     * cached DMI per actor from slot index 0 of its first static mesh component.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<AActor*> ARMeshActors;

    /**
     * MPC_KinematicAR asset reference. Used to write the SystemMode scalar.
     * Assign in the Details panel.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UMaterialParameterCollection* GlobalMPC;

    // -----------------------------------------------------------------------
    // Tuning
    // -----------------------------------------------------------------------

    /**
     * Distance in Unreal centimetres at which PerformerProximity reaches 1.0
     * (maximum contact deformation). At distances greater than this value,
     * PerformerProximity scales linearly toward 0.0. Default: 150 cm (1.5 m).
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Proximity")
    float ProximityRadius = 150.0f;

private:
    // Cached DMIs — one per entry in ARMeshActors, same index order.
    TArray<UMaterialInstanceDynamic*> CachedDMIs;

    // Current mode state.
    bool bIsInteractive = false;
};
