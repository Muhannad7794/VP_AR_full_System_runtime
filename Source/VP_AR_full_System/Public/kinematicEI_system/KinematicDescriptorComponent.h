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
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "kinematicEI_system/OneEuroFilter.h"
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

    // -----------------------------------------------------------------------
    // Physics Tuning Parameters
    // -----------------------------------------------------------------------

    /** Spring constant pulling cubes back toward their home formation. Scaled by (1 - Flow). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics")
    float AttractorSpringConstant = 500.0f;

    /** Force multiplier for the Effort/Expansiveness-driven outward repulsor. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics")
    float RepulsorForceMultiplier = 1000.0f;

    /** Drag coefficient applied to cube velocity, scaled by (1 - Effort). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics")
    float BaseDragCoefficient = 10.0f;

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

    // -----------------------------------------------------------------------
    // Operations
    // -----------------------------------------------------------------------

    /**
     * Toggles the EI system between active (Interactive Mode) and suspended
     * (Compositing Mode). Writes SystemMode to the GlobalMPC on every toggle.
     */
    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Operations")
    void ToggleSystemMode();

private:
    bool bIsEIActive;

    // -----------------------------------------------------------------------
    // 1 Euro Filters — six joints for multi-joint descriptor coverage
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

    // -----------------------------------------------------------------------
    // Flow: Rolling sigma buffer
    // -----------------------------------------------------------------------

    /**
     * Circular buffer of aggregate velocity delta magnitudes for sigma computation.
     * Each entry is the magnitude of the frame-to-frame change in the aggregate
     * velocity across tracked joints. Sigma over this buffer is the Flow descriptor.
     */
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
    // Physics Anchor Storage
    // -----------------------------------------------------------------------

    TMap<AActor*, FVector> CubeHomeLocations;

    // -----------------------------------------------------------------------
    // Internal Helper Methods
    // -----------------------------------------------------------------------

    /**
     * Reads raw socket locations for all tracked joints, applies the 1 Euro
     * Filter to each, and outputs cleaned world-space positions.
     */
    void ReadAndFilterKinematics(
        float DeltaTime,
        FVector& OutSpine,
        FVector& OutLWrist, FVector& OutRWrist,
        FVector& OutLElbow, FVector& OutRElbow,
        FVector& OutLShoulder, FVector& OutRShoulder);

    /**
     * Computes the four LMA descriptors from filtered joint positions.
     * Applies adaptive EMA-based normalization to each raw descriptor value
     * before writing to the Current* member variables.
     */
    void ComputeLMADescriptors(
        float DeltaTime,
        const FVector& Spine,
        const FVector& LWrist, const FVector& RWrist,
        const FVector& LElbow, const FVector& RElbow,
        const FVector& LShoulder, const FVector& RShoulder);

    /**
     * Writes the current descriptor values and PelvisWorldLocation to the
     * GlobalMPC, and Effort/Flow to the Niagara User Parameters.
     */
    void UpdateRenderSubsystems(const FVector& PelvisLocation);

    /**
     * Applies the spring-attractor force model to all registered AR cube actors.
     * Requires cubes to have physics simulation enabled.
     */
    void ExecuteKinematicPhysics();

    /**
     * Updates the adaptive normalization range for a single descriptor and
     * returns the normalized value clamped to [0, 1].
     *
     * The range expands quickly (NormRangeExpandAlpha) when a new extreme is
     * encountered and contracts slowly (NormRangeContractAlpha) otherwise.
     * A minimum valid range of 1.0 is enforced to prevent division by near-zero
     * during the warmup period before enough signal variation has been observed.
     *
     * @param RawValue    The unscaled descriptor value in physical units.
     * @param AdaptiveMin Reference to the tracked minimum for this descriptor.
     * @param AdaptiveMax Reference to the tracked maximum for this descriptor.
     * @return            Normalized value in [0, 1].
     */
    float NormalizeAdaptive(float RawValue, float& AdaptiveMin, float& AdaptiveMax) const;

    /**
     * Computes the standard deviation of the values in a TArray<float>.
     * Returns 0.0 if the array has fewer than two elements.
     * Uses ddof=0 (population standard deviation), consistent with the Python
     * offline validation pipeline (np.std with default ddof=0).
     */
    static float ComputeStdDev(const TArray<float>& Buffer);
};