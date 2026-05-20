/**
 * Component: UKinematicDescriptorComponent
 * Purpose: Master ingestion and computation node for Embodied Interaction.
 * Reads raw skeletal data from a ZED LiveLink-driven SkeletalMeshComponent,
 * applies the 1 Euro Filter per joint, computes the four continuous Laban
 * Movement Analysis (LMA) descriptors, routes data to rendering subsystems,
 * and actively governs the kinematic spatial physics of the AR grid.
 *
 * LMA Descriptor Summary:
 *   Effort       (LMA Time):   Weighted aggregate velocity across six key joints.
 *   Expansiveness(LMA Space):  Maximum wrist-to-spine_2 reach distance.
 *   Weight       (LMA Weight): Aggregate acceleration magnitude across key joints.
 *   Flow         (LMA Flow):   Rolling standard deviation of velocity delta magnitude.
 *                              Independent of Weight: measures movement consistency,
 *                              not force. High sigma = Free (chaotic). Low sigma = Bound.
 *
 * Normalization:
 *   All raw descriptor values are normalized using an adaptive EMA-based range
 *   tracker. The observed range expands quickly when new extremes are reached
 *   and contracts slowly during calmer periods, removing the need for hardcoded
 *   calibration constants.
 *
 * STATIC BUBBLE ARCHITECTURE
 * ──────────────────────────
 * The bubble is a fixed sphere of physics-simulated particle actors anchored at
 * the world position of BP_ARGridSpawner. It does not follow any performer.
 * RebuildHomeLocations() stores the absolute world-space spawn position of each
 * particle. ExecuteKinematicPhysics() always pulls particles back to that fixed
 * absolute position — home is never recomputed from the pelvis.
 *
 * FORCE MODEL CALIBRATION
 * ───────────────────────
 * AttractorSpringConstant and RepulsorForceMultiplier must be balanced.
 * Equilibrium displacement = RepulsorForceMultiplier × MaxNormForceMag
 *                            / AttractorSpringConstant
 * With defaults below (15 and 8000):
 *   max normalized force mag ≈ 1.5 (wrist + elbow at full Effort/Weight)
 *   equilibrium ≈ 8000 × 1.5 / 15 = 800 cm (capped by tether at 80cm)
 * This ensures visually clear displacement into the tether range.
 * The old defaults (500 and 1000) gave equilibrium ≈ 3cm — imperceptible.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "kinematicEI_system/OneEuroFilter.h"
#include "kinematicEI_system/ProximityDispatchComponent.h"
#include "KinematicDescriptorComponent.generated.h"

class UMaterialParameterCollection;
class UNiagaraComponent;
class USkeletalMeshComponent;
class AActor;

UCLASS(ClassGroup = (KinematicEI), meta = (BlueprintSpawnableComponent))
class VP_AR_FULL_SYSTEM_API UKinematicDescriptorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UKinematicDescriptorComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;

    // -----------------------------------------------------------------------
    // Core System Architecture References
    // -----------------------------------------------------------------------

    // Stores absolute world-space spawn positions for all particles.
    // Call after BP_ARGridSpawner has placed particles and enabled physics.
    // TrackedSkeleton is NOT required — home positions are independent of
    // any performer's location in the static bubble model.
    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Physics")
    void RebuildHomeLocations();

    /** ZED LiveLink-driven SkeletalMeshComponent providing joint socket locations. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    USkeletalMeshComponent* TrackedSkeleton;

    /** Global Material Parameter Collection bridging C++ descriptors to GPU. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UMaterialParameterCollection* GlobalMPC;

    /** Niagara component receiving Effort and Flow User Parameters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UNiagaraComponent* ParticleSystem;

    /** AR cube actors subject to the spring-attractor physics loop. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<AActor*> ARCubes;

    // Reference to ProximityDispatchComponent on the same actor.
    // Cached at BeginPlay. Used to read ProximityRadius for limb proximity checks
    // in ExecuteKinematicPhysics.
    UPROPERTY()
    UProximityDispatchComponent* ProximityDispatch;

    // All active ZED-tracked skeletal meshes in the scene.
    // Populated every tick by auto-discovery of BP_ZED_Manny actors.
    // Physics loop checks all entries for proximity to each particle.
    UPROPERTY(BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<USkeletalMeshComponent*> TrackedSkeletons;

    // -----------------------------------------------------------------------
    // Physics Tuning Parameters
    // -----------------------------------------------------------------------

    /**
     * Spring constant pulling particles back toward their static home positions.
     * Scaled by (1 - Flow): Bound = tight snap-back, Free = slow drift.
     *
     * CRITICAL: This value must be small relative to RepulsorForceMultiplier.
     * Equilibrium displacement = (RepulsorForceMultiplier × ~1.5) / AttractorSpringConstant
     * At 15.0 (default): equilibrium ≈ 800 cm, capped by tether — clear displacement.
     * At 500.0 (old value): equilibrium ≈ 3 cm — particles appear completely static.
     *
     * Do NOT raise this above 40 unless RepulsorForceMultiplier is also raised
     * proportionally. Tuning range: 10–30.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics",
        meta = (ClampMin = "1.0", ClampMax = "60.0"))
    float AttractorSpringConstant = 15.0f;

    /**
     * Global multiplier applied to the accumulated repulsor force before AddForce.
     * This is the primary dial for visible particle travel distance.
     *
     * At 8000 (default) with AttractorSpringConstant = 15:
     *   A moderate arm movement (Effort ≈ 0.5) produces ≈ 50–80 cm displacement.
     *   A fast ballistic arm swing (Effort ≈ 1.0) hits the tether cap at 80 cm.
     * At 1000 (old value): max displacement ≈ 3 cm — imperceptible.
     *
     * Tuning range: 5000–15000. Increase for a more explosive bubble response.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics",
        meta = (ClampMin = "100.0", ClampMax = "30000.0"))
    float RepulsorForceMultiplier = 8000.0f;

    /**
     * Linear damping applied to each particle via SetLinearDamping().
     * Uses the Chaos solver's implicit exponential integration — unconditionally
     * stable, unlike manual drag via AddForce.
     *
     * 5.0 (default): lightly damped. Particles show clear spring oscillation
     * before settling. Appropriate for an elastic, responsive bubble.
     * 10–15: overdamped. Particles return to home with no oscillation.
     * 10.0 (old value): overdamped — acceptable but particles feel heavy.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics",
        meta = (ClampMin = "0.5", ClampMax = "25.0"))
    float BaseDragCoefficient = 5.0f;

    // -----------------------------------------------------------------------
    // Adaptive Normalization Parameters
    // -----------------------------------------------------------------------

    /**
     * Fast EMA alpha applied when a raw value exceeds the current tracked maximum
     * or falls below the current tracked minimum. Controls how quickly the observed
     * range expands to accommodate new extremes.
     * Range: (0, 1). Recommended: 0.05 - 0.15.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Normalization",
        meta = (ClampMin = "0.001", ClampMax = "0.5"))
    float NormRangeExpandAlpha = 0.1f;

    /**
     * Slow EMA alpha applied when a raw value is within the current tracked range.
     * Controls how slowly the range contracts during calmer movement periods.
     * At 30 Hz with 0.001, the time constant is approximately 33 seconds.
     * Range: (0, 0.01). Recommended: 0.0005 - 0.002.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Normalization",
        meta = (ClampMin = "0.0001", ClampMax = "0.01"))
    float NormRangeContractAlpha = 0.001f;

    /**
     * Number of frames in the rolling window for Flow sigma computation.
     * At 30 Hz, the default of 30 corresponds to a 1-second observation window.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Normalization",
        meta = (ClampMin = "5", ClampMax = "120"))
    int32 FlowWindowSize = 30;

    // -----------------------------------------------------------------------
    // Debug Outputs (read-only, visible in Details during Play)
    // -----------------------------------------------------------------------

    UPROPERTY(BlueprintReadOnly, Category = "KinematicEI|Debug")
    float DebugEffort = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "KinematicEI|Debug")
    float DebugExpansiveness = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "KinematicEI|Debug")
    float DebugWeight = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "KinematicEI|Debug")
    float DebugFlow = 0.0f;

private:

    // -----------------------------------------------------------------------
    // 1 Euro Filters — one per tracked joint
    // -----------------------------------------------------------------------

    FOneEuroFilterVector FilterSpine;
    FOneEuroFilterVector FilterLWrist;
    FOneEuroFilterVector FilterRWrist;
    FOneEuroFilterVector FilterLElbow;
    FOneEuroFilterVector FilterRElbow;
    FOneEuroFilterVector FilterLShoulder;
    FOneEuroFilterVector FilterRShoulder;

    // -----------------------------------------------------------------------
    // LMA Descriptor State
    // -----------------------------------------------------------------------

    float CurrentEffort;
    float CurrentExpansiveness;
    float CurrentWeight;
    float CurrentFlow;

    // -----------------------------------------------------------------------
    // Multi-Joint Velocity History (for Effort and Weight computation)
    // -----------------------------------------------------------------------

    FVector PrevLWrist;
    FVector PrevRWrist;
    FVector PrevLElbow;
    FVector PrevRElbow;
    FVector PrevLShoulder;
    FVector PrevRShoulder;

    FVector PrevLWristVelocity;
    FVector PrevRWristVelocity;
    FVector PrevLElbowVelocity;
    FVector PrevRElbowVelocity;

    bool bFirstDescriptorFrame;

    /**
     * Set to true by RebuildHomeLocations() once valid home offsets exist.
     * ExecuteKinematicPhysics() is gated on this flag to prevent force
     * application before the formation anchor is established.
     */
    bool bHomeOffsetsReady;

    // -----------------------------------------------------------------------
    // Per-limb velocity state — written every tick in ComputeLMADescriptors,
    // read every tick in ExecuteKinematicPhysics.
    // -----------------------------------------------------------------------

    FVector LWristVelocityDir;
    FVector RWristVelocityDir;
    FVector LElbowVelocityDir;
    FVector RElbowVelocityDir;

    float LWristSpeed;
    float RWristSpeed;
    float LElbowSpeed;
    float RElbowSpeed;

    // -----------------------------------------------------------------------
    // Flow: Rolling sigma buffer
    // -----------------------------------------------------------------------

    TArray<float> FlowDeltaBuffer;

    // -----------------------------------------------------------------------
    // Adaptive Normalization State — one (min, max) pair per descriptor
    // -----------------------------------------------------------------------

    float AdaptiveMin_Effort;
    float AdaptiveMax_Effort;

    float AdaptiveMin_Expansiveness;
    float AdaptiveMax_Expansiveness;

    float AdaptiveMin_Weight;
    float AdaptiveMax_Weight;

    float AdaptiveMin_Flow;
    float AdaptiveMax_Flow;

    // -----------------------------------------------------------------------
    // Particle home positions (absolute world coordinates).
    // Named CubeHomeOffsets for backward compatibility with existing Blueprint
    // calls to RebuildHomeLocations(). The values stored are absolute world
    // positions — NOT pelvis-relative offsets despite the name.
    // Set once in RebuildHomeLocations(). Never modified after that.
    // -----------------------------------------------------------------------

    TMap<AActor*, FVector> CubeHomeOffsets;

    // -----------------------------------------------------------------------
    // Internal Helper Methods
    // -----------------------------------------------------------------------

    void ReadAndFilterKinematics(
        float DeltaTime,
        FVector& OutSpine,
        FVector& OutLWrist, FVector& OutRWrist,
        FVector& OutLElbow, FVector& OutRElbow,
        FVector& OutLShoulder, FVector& OutRShoulder);

    void ComputeLMADescriptors(
        float DeltaTime,
        const FVector& Spine,
        const FVector& LWrist, const FVector& RWrist,
        const FVector& LElbow, const FVector& RElbow,
        const FVector& LShoulder, const FVector& RShoulder);

    void UpdateRenderSubsystems(const FVector& PelvisLocation);

    void ExecuteKinematicPhysics();

    float NormalizeAdaptive(float RawValue, float& AdaptiveMin, float& AdaptiveMax) const;

    static float ComputeStdDev(const TArray<float>& Buffer);
};