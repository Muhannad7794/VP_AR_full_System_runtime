/**
 * Component: UKinematicDescriptorComponent
 * Purpose: Master ingestion and computation node for Embodied Interaction.
 * Reads raw skeletal data from a ZED LiveLink-driven SkeletalMeshComponent,
 * applies the 1 Euro Filter per joint, computes the four continuous Laban
 * Movement Analysis (LMA) descriptors, routes data to rendering subsystems,
 * and actively governs the kinematic spatial physics of the AR bubble.
 *
 * LMA Descriptor Summary:
 *   Effort       (LMA Time):   Weighted aggregate velocity across six key joints.
 *   Expansiveness(LMA Space):  Maximum wrist-to-spine_2 reach distance.
 *   Weight       (LMA Weight): Aggregate acceleration magnitude across key joints.
 *   Flow         (LMA Flow):   Rolling standard deviation of velocity delta magnitude.
 *
 * STATIC BUBBLE ARCHITECTURE
 * ──────────────────────────
 * The bubble is a fixed sphere of physics-simulated particle actors anchored at
 * the world position of BP_ARGridSpawner. It does not follow any performer.
 * RebuildHomeLocations() stores the absolute world-space spawn position of each
 * particle. ExecuteKinematicPhysics() always pulls particles back to that fixed
 * absolute position.
 *
 * GRAVITY NOTE
 * ────────────
 * Particle physics actors must have gravity disabled (Set Enable Gravity = false
 * in BP_ARGridSpawner after Set Simulate Physics). Without this, the Chaos solver
 * applies 980 cm/s² downward, which the attractor spring cannot counteract at
 * low AttractorSpringConstant values, causing particles to sink and escape.
 *
 * FORCE MODEL CALIBRATION
 * ───────────────────────
 * Equilibrium displacement (cm) ≈ (RepulsorForceMultiplier × NormForceMag)
 *                                  / AttractorSpringConstant
 * NormForceMag ranges 0–1.5 depending on LMA descriptor values and proximity.
 * Displacement is capped at MaxDeformationRadius by the tether force.
 * TetherCoefficient controls how aggressively particles are pulled back once
 * they exceed MaxDeformationRadius. Higher values = harder cap, faster return.
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
    // Core System Architecture
    // -----------------------------------------------------------------------

    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Physics")
    void RebuildHomeLocations();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    USkeletalMeshComponent* TrackedSkeleton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UMaterialParameterCollection* GlobalMPC;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UNiagaraComponent* ParticleSystem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<AActor*> ARCubes;

    UPROPERTY()
    UProximityDispatchComponent* ProximityDispatch;

    UPROPERTY(BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<USkeletalMeshComponent*> TrackedSkeletons;

    // -----------------------------------------------------------------------
    // Physics Tuning — Attractor
    // -----------------------------------------------------------------------

    /**
     * Spring constant pulling particles back toward their static home positions.
     * Scaled by (1 - Flow): Bound = tight snap-back, Free = slow drift.
     *
     * Equilibrium displacement = (RepulsorForceMultiplier × NormForceMag)
     *                            / AttractorSpringConstant
     * Lower values allow larger particle travel before equilibrium is reached.
     * Too low: particles drift and do not return cleanly. Too high: particles
     * appear frozen and do not respond visibly to movement.
     *
     * Recommended range: 5–20. Default: 8.0
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics|Attractor",
        meta = (ClampMin = "0.5", ClampMax = "60.0"))
    float AttractorSpringConstant = 8.0f;

    // -----------------------------------------------------------------------
    // Physics Tuning — Repulsor
    // -----------------------------------------------------------------------

    /**
     * Global multiplier applied to the accumulated repulsor force before AddForce.
     * Primary dial for visible particle travel distance.
     *
     * At 15000 with AttractorSpringConstant = 8:
     *   Moderate movement (Effort ≈ 0.4): displacement ≈ 75cm
     *   Ballistic arm swing (Effort ≈ 0.8): displacement ≈ 150cm (tether cap)
     *
     * Recommended range: 8000–25000. Default: 15000.0
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics|Repulsor",
        meta = (ClampMin = "100.0", ClampMax = "50000.0"))
    float RepulsorForceMultiplier = 15000.0f;

    // -----------------------------------------------------------------------
    // Physics Tuning — Damping
    // -----------------------------------------------------------------------

    /**
     * Linear damping applied to each particle via SetLinearDamping().
     * Uses Chaos solver implicit exponential integration — stable at all frame rates.
     *
     * 3–5: light damping. Particles oscillate and overshoot before settling.
     * 8–12: heavier damping. Particles return to home smoothly without oscillation.
     * For a demo, 4.0 gives visible spring motion. 8.0 gives clean return.
     *
     * Default: 4.0
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics|Damping",
        meta = (ClampMin = "0.5", ClampMax = "25.0"))
    float BaseDragCoefficient = 4.0f;

    // -----------------------------------------------------------------------
    // Physics Tuning — Tether
    // -----------------------------------------------------------------------

    /**
     * Maximum distance (cm) a particle may travel from its static home position
     * before the quadratic tether force activates. This is the effective ceiling
     * for visible particle displacement in any direction.
     *
     * Set this to roughly 75% of the bubble radius for particles that can travel
     * deeply into the bubble interior when pushed. Example: BubbleRadius 200cm
     * → MaxDeformationRadius 150cm allows surface particles to reach the center.
     *
     * Default: 150.0
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics|Tether",
        meta = (ClampMin = "10.0", ClampMax = "500.0"))
    float MaxDeformationRadius = 150.0f;

    /**
     * Coefficient for the quadratic tether force applied when a particle exceeds
     * MaxDeformationRadius. Force = (Violation²) × TetherCoefficient.
     *
     * Higher values produce a harder cap and faster return from the tether zone.
     * Too low: particles escape beyond MaxDeformationRadius persistently.
     * Too high: particles snap back abruptly, eliminating the elastic quality.
     *
     * Recommended range: 150–400. Default: 250.0
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics|Tether",
        meta = (ClampMin = "10.0", ClampMax = "1000.0"))
    float TetherCoefficient = 250.0f;

    // -----------------------------------------------------------------------
    // Physics Tuning — Velocity Cap
    // -----------------------------------------------------------------------

    /** 
    * Hard maximum speed (cm/s) for any particle.
    * Prevents accumulated velocity from consecutive fast movements from
    * exceeding the tether's ability to decelerate the particle in a single
    * physics tick. Ensures the sphere formation is never permanently lost
    * under rapid repeated movements.
    * Recommended range: 200–400. Default: 300.0
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics|VelocityCap",
        meta = (ClampMin = "10.0", ClampMax = "2000.0"))
    float MaxParticleVelocity = 300.0f;

    // -----------------------------------------------------------------------
    // Adaptive Normalization Parameters
    // -----------------------------------------------------------------------

    /**
     * Fast EMA alpha when a raw descriptor value exceeds the tracked maximum.
     * Controls how quickly the normalization range expands to new extremes.
     * Default: 0.1
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Normalization",
        meta = (ClampMin = "0.001", ClampMax = "0.5"))
    float NormRangeExpandAlpha = 0.1f;

    /**
     * Slow EMA alpha when a raw value is within the tracked range.
     * Controls how slowly the range contracts during calmer movement periods.
     * At 30 Hz with 0.001, the time constant is approximately 33 seconds.
     * Default: 0.001
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Normalization",
        meta = (ClampMin = "0.0001", ClampMax = "0.01"))
    float NormRangeContractAlpha = 0.001f;

    /**
     * Number of frames in the rolling window for Flow (LMA Flow) sigma computation.
     * At 30 Hz, 30 frames = 1 second observation window.
     * Default: 30
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Normalization",
        meta = (ClampMin = "5", ClampMax = "120"))
    int32 FlowWindowSize = 30;

    // -----------------------------------------------------------------------
    // Debug Outputs (read-only in Details during Play)
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
    // 1 Euro Filters
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
    // Joint History
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
    bool bHomeOffsetsReady;

    // -----------------------------------------------------------------------
    // Per-limb velocity state
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
    // Flow buffer
    // -----------------------------------------------------------------------

    TArray<float> FlowDeltaBuffer;

    // -----------------------------------------------------------------------
    // Adaptive normalization ranges
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
    // Named CubeHomeOffsets for backward compatibility. Values stored are
    // absolute world positions — NOT pelvis-relative offsets despite the name.
    // -----------------------------------------------------------------------

    TMap<AActor*, FVector> CubeHomeOffsets;

    // -----------------------------------------------------------------------
    // Internal methods
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