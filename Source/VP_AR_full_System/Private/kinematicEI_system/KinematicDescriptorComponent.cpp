/**
 * KinematicDescriptorComponent.cpp
 *
 * Implementation of the four LMA descriptor pipeline for Kinematic AR.
 * Corrected from the initial version to resolve three issues:
 *
 *   1. Flow independence: Flow now measures rolling sigma of velocity delta
 *      magnitude across the tracked joint set, making it independent of Weight.
 *      High sigma = Free (erratic, unpredictable). Low sigma = Bound (controlled).
 *
 *   2. Multi-joint Effort: Effort is now a weighted aggregate velocity across
 *      six joints (wrists, elbows, shoulders) rather than a single right-wrist
 *      signal. This ensures the descriptor registers both bilateral and
 *      asymmetric expressive movements.
 *
 *   3. Adaptive normalization: Per-descriptor adaptive EMA-based range tracking
 *      replaces all hardcoded normalization constants. The range expands quickly
 *      when new extremes are encountered and contracts slowly otherwise.
 */

#include "kinematicEI_system/KinematicDescriptorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/GameplayStatics.h"

 // ---------------------------------------------------------------------------
 // Joint weights for the Effort (LMA Time) descriptor.
 // Distal joints (wrists) are weighted more heavily because they carry the most
 // expressive velocity information in upper-body dance and performance movement.
 // ---------------------------------------------------------------------------
static constexpr float WEIGHT_WRIST = 1.0f;
static constexpr float WEIGHT_ELBOW = 0.8f;
static constexpr float WEIGHT_SHOULDER = 0.6f;

static constexpr float TOTAL_JOINT_WEIGHT =
(WEIGHT_WRIST * 2.0f) + (WEIGHT_ELBOW * 2.0f) + (WEIGHT_SHOULDER * 2.0f);

// Initial seed values for the adaptive normalization range.
// These are conservative physiological estimates used only until real data
// establishes tighter bounds during the session warmup period.
// Units match the raw descriptor outputs (mm/s for velocity-based, mm for distance).
static constexpr float INIT_MIN_EFFORT = 0.0f;
static constexpr float INIT_MAX_EFFORT = 300.0f;  // mm/s — slow sustained movement
static constexpr float INIT_MIN_EXPANSIVENESS = 0.0f;
static constexpr float INIT_MAX_EXPANSIVENESS = 800.0f;  // mm — near-full arm extension
static constexpr float INIT_MIN_WEIGHT = 0.0f;
static constexpr float INIT_MAX_WEIGHT = 500.0f;  // mm/s^2 — moderate acceleration
static constexpr float INIT_MIN_FLOW = 0.0f;
static constexpr float INIT_MAX_FLOW = 50.0f;  // mm/s^2 — low sigma at rest

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

UKinematicDescriptorComponent::UKinematicDescriptorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsEIActive = true;

    // 1 Euro Filter initialization — parameters validated in Phase 3 against
    // ZED 2i BODY_38 at 30 Hz with NEURAL depth mode.
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

    bFirstDescriptorFrame = true;

    // Seed the adaptive normalization ranges with physiologically reasonable
    // initial estimates. These will be refined within the first few seconds
    // of actual movement as the adaptive tracker observes real values.
    AdaptiveMin_Effort = INIT_MIN_EFFORT;
    AdaptiveMax_Effort = INIT_MAX_EFFORT;
    AdaptiveMin_Expansiveness = INIT_MIN_EXPANSIVENESS;
    AdaptiveMax_Expansiveness = INIT_MAX_EXPANSIVENESS;
    AdaptiveMin_Weight = INIT_MIN_WEIGHT;
    AdaptiveMax_Weight = INIT_MAX_WEIGHT;
    AdaptiveMin_Flow = INIT_MIN_FLOW;
    AdaptiveMax_Flow = INIT_MAX_FLOW;
}

// ---------------------------------------------------------------------------
// BeginPlay
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::BeginPlay()
{
    Super::BeginPlay();

    // Store the initial world locations of the AR cubes as their "Home" anchor.
    // These are used by the spring-attractor physics loop to pull cubes back
    // toward their formation positions.
    for (AActor* Cube : ARCubes)
    {
        if (Cube)
        {
            CubeHomeLocations.Add(Cube, Cube->GetActorLocation());
        }
    }

    // Pre-allocate the Flow sigma buffer to avoid heap reallocation during tick.
    FlowDeltaBuffer.Reserve(FlowWindowSize);
}

// ---------------------------------------------------------------------------
// ToggleSystemMode
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::ToggleSystemMode()
{
    bIsEIActive = !bIsEIActive;

    if (GlobalMPC)
    {
        UKismetMaterialLibrary::SetScalarParameterValue(
            GetWorld(), GlobalMPC, FName("SystemMode"), bIsEIActive ? 1.0f : 0.0f);
    }
}

// ---------------------------------------------------------------------------
// Tick — main pipeline
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bIsEIActive || !TrackedSkeleton) return;

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

    const FVector PelvisLoc = TrackedSkeleton->GetSocketLocation(FName("Hips"));
    UpdateRenderSubsystems(PelvisLoc);

    ExecuteKinematicPhysics();
}

// ---------------------------------------------------------------------------
// ReadAndFilterKinematics
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::ReadAndFilterKinematics(
    float DeltaTime,
    FVector& OutSpine,
    FVector& OutLWrist, FVector& OutRWrist,
    FVector& OutLElbow, FVector& OutRElbow,
    FVector& OutLShoulder, FVector& OutRShoulder)
{
    // Socket names use the Manny rig bone names as mapped by the ZED LiveLink
    // plugin's Bone Name Map 38 (ZED joint name → Manny skeleton bone name):
    //   PELVIS        → Hips
    //   SPINE_2       → Spine1
    //   LEFT_WRIST    → LeftHand
    //   RIGHT_WRIST   → RightHand
    //   LEFT_ELBOW    → LeftForeArm
    //   RIGHT_ELBOW   → RightForeArm
    //   LEFT_SHOULDER → LeftArm
    //   RIGHT_SHOULDER→ RightArm
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

// ---------------------------------------------------------------------------
// ComputeLMADescriptors
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::ComputeLMADescriptors(
    float DeltaTime,
    const FVector& Spine,
    const FVector& LWrist, const FVector& RWrist,
    const FVector& LElbow, const FVector& RElbow,
    const FVector& LShoulder, const FVector& RShoulder)
{
    if (DeltaTime <= 0.0f) return;

    // On the first valid frame, initialize history to current positions
    // to avoid a large spurious velocity spike on frame two.
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
    // 1. Per-joint velocity computation
    // -----------------------------------------------------------------------

    const FVector VelLWrist = (LWrist - PrevLWrist) / DeltaTime;
    const FVector VelRWrist = (RWrist - PrevRWrist) / DeltaTime;
    const FVector VelLElbow = (LElbow - PrevLElbow) / DeltaTime;
    const FVector VelRElbow = (RElbow - PrevRElbow) / DeltaTime;
    const FVector VelLShoulder = (LShoulder - PrevLShoulder) / DeltaTime;
    const FVector VelRShoulder = (RShoulder - PrevRShoulder) / DeltaTime;

    // -----------------------------------------------------------------------
    // 2. LMA Space — Expansiveness
    //    Maximum of both wrist-to-spine distances. Using the maximum rather
    //    than the average correctly captures kinesphere reach: the performer's
    //    spatial extent is defined by their most extended limb.
    // -----------------------------------------------------------------------

    const float DistL = FVector::Dist(Spine, LWrist);
    const float DistR = FVector::Dist(Spine, RWrist);
    const float RawExpansiveness = FMath::Max(DistL, DistR);

    CurrentExpansiveness = NormalizeAdaptive(
        RawExpansiveness, AdaptiveMin_Expansiveness, AdaptiveMax_Expansiveness);

    // -----------------------------------------------------------------------
    // 3. LMA Time — Effort
    //    Weighted aggregate velocity magnitude across six joints.
    //    Wrists are the primary expressive effectors (weight 1.0).
    //    Elbows carry significant arm movement energy (weight 0.8).
    //    Shoulders provide gross upper-body motion context (weight 0.6).
    //    Summing weighted magnitudes rather than vector magnitudes prevents
    //    left/right cancellation from reducing the aggregate to near zero
    //    during symmetric bilateral movements.
    // -----------------------------------------------------------------------

    const float RawEffort =
        (VelLWrist.Size() * WEIGHT_WRIST +
            VelRWrist.Size() * WEIGHT_WRIST +
            VelLElbow.Size() * WEIGHT_ELBOW +
            VelRElbow.Size() * WEIGHT_ELBOW +
            VelLShoulder.Size() * WEIGHT_SHOULDER +
            VelRShoulder.Size() * WEIGHT_SHOULDER)
        / TOTAL_JOINT_WEIGHT;

    CurrentEffort = NormalizeAdaptive(RawEffort, AdaptiveMin_Effort, AdaptiveMax_Effort);

    // -----------------------------------------------------------------------
    // 4. LMA Weight — Acceleration magnitude
    //    Using the four most kinematically active joints (wrists and elbows)
    //    rather than all six. Shoulder acceleration is generally lower frequency
    //    and would dilute the Weight signal during fast distal movements.
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

    CurrentWeight = NormalizeAdaptive(RawWeight, AdaptiveMin_Weight, AdaptiveMax_Weight);

    // -----------------------------------------------------------------------
    // 5. LMA Flow — Rolling sigma of aggregate velocity delta magnitude
    //
    //    Flow is independent of Weight. While Weight measures how large the
    //    acceleration is at this instant, Flow measures how consistent or
    //    erratic the velocity changes have been over the last FlowWindowSize
    //    frames. A performer executing a controlled Press (Strong + Bound) has
    //    high Weight but low Flow sigma: the acceleration is large but
    //    predictable. A performer executing a Slash (Strong + Free) has high
    //    Weight AND high Flow sigma: the acceleration is both large and chaotic.
    //    This distinction is what makes the eight LMA action drives separable.
    //
    //    The aggregate velocity is the weighted mean velocity magnitude across
    //    the four primary joints (same set as Weight). Its frame-to-frame delta
    //    (i.e., the rate of change of the aggregate velocity magnitude) feeds
    //    the sigma buffer.
    // -----------------------------------------------------------------------

    const float AggregateVelocityMag =
        (VelLWrist.Size() * WEIGHT_WRIST +
            VelRWrist.Size() * WEIGHT_WRIST +
            VelLElbow.Size() * WEIGHT_ELBOW +
            VelRElbow.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    // PrevAggregateVelocityMag is reconstructed from saved velocities.
    const float PrevAggregateVelocityMag =
        (PrevLWristVelocity.Size() * WEIGHT_WRIST +
            PrevRWristVelocity.Size() * WEIGHT_WRIST +
            PrevLElbowVelocity.Size() * WEIGHT_ELBOW +
            PrevRElbowVelocity.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    const float VelocityDeltaMag = FMath::Abs(
        AggregateVelocityMag - PrevAggregateVelocityMag) / DeltaTime;

    // Maintain rolling circular buffer of velocity delta magnitudes.
    FlowDeltaBuffer.Add(VelocityDeltaMag);
    if (FlowDeltaBuffer.Num() > FlowWindowSize)
    {
        FlowDeltaBuffer.RemoveAt(0, 1, false);
    }

    // Sigma requires at least two samples. Hold Flow at zero during warmup.
    const float RawFlow = (FlowDeltaBuffer.Num() >= 2)
        ? ComputeStdDev(FlowDeltaBuffer)
        : 0.0f;

    CurrentFlow = NormalizeAdaptive(RawFlow, AdaptiveMin_Flow, AdaptiveMax_Flow);

    // -----------------------------------------------------------------------
    // 6. Advance history state
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

    // -----------------------------------------------------------------------
    // 7. Write debug outputs
    // -----------------------------------------------------------------------

    DebugEffort = CurrentEffort;
    DebugExpansiveness = CurrentExpansiveness;
    DebugWeight = CurrentWeight;
    DebugFlow = CurrentFlow;
}

// ---------------------------------------------------------------------------
// UpdateRenderSubsystems
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::UpdateRenderSubsystems(const FVector& PelvisLocation)
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

        // PelvisWorldLocation is passed as FLinearColor (R=X, G=Y, B=Z, A=1)
        // because Material Parameter Collections store vectors as FLinearColor.
        // The material reads .rgb as the 3D position for GPU-side distance computation.
        UKismetMaterialLibrary::SetVectorParameterValue(
            World, GlobalMPC, FName("PelvisWorldLocation"),
            FLinearColor(PelvisLocation.X, PelvisLocation.Y, PelvisLocation.Z, 1.0f));
    }

    if (ParticleSystem)
    {
        ParticleSystem->SetFloatParameter(FName("User.EffortLevel"), CurrentEffort);
        ParticleSystem->SetFloatParameter(FName("User.FlowLevel"), CurrentFlow);
    }
}

// ---------------------------------------------------------------------------
// ExecuteKinematicPhysics
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::ExecuteKinematicPhysics()
{
    if (!TrackedSkeleton) return;

    const FVector PelvisLoc = TrackedSkeleton->GetSocketLocation(FName("Hips"));

    for (AActor* Cube : ARCubes)
    {
        if (!Cube) continue;

        UPrimitiveComponent* PrimComp =
            Cube->FindComponentByClass<UPrimitiveComponent>();

        if (!PrimComp || !PrimComp->IsSimulatingPhysics()) continue;

        const FVector CurrentLoc = Cube->GetActorLocation();
        const FVector HomeLoc = CubeHomeLocations.Contains(Cube)
            ? CubeHomeLocations[Cube] : CurrentLoc;
        const FVector CubeVelocity = PrimComp->GetComponentVelocity();

        // Attractor: pulls cubes back toward formation home.
        // Strength scales with (1 - Flow) so Bound movement maintains a tighter
        // formation while Free movement allows more chaotic dispersion.
        const FVector ToHome = HomeLoc - CurrentLoc;
        const FVector AttractorForce = ToHome * AttractorSpringConstant
            * (1.0f - CurrentFlow);

        // Repulsor: pushes cubes outward from the performer's pelvis.
        // The direction is derived from the wrist-to-spine vector projected
        // onto the cube's relative position rather than purely radial, but
        // using pelvis as the centre point is a valid simplification for the
        // physics layer. The exact directional intent is handled in the
        // GPU-side material via PelvisWorldLocation.
        const FVector OutwardDir = (CurrentLoc - PelvisLoc).GetSafeNormal();
        const FVector RepulsorForce = OutwardDir * RepulsorForceMultiplier
            * CurrentEffort
            * CurrentExpansiveness;

        // Drag: damps cube velocity. Strongest when Effort is zero, creating
        // a "freeze" effect when the performer is still. Reduces as Effort rises,
        // allowing cubes to continue moving during energetic sequences.
        const FVector DragForce = -CubeVelocity * BaseDragCoefficient
            * (1.0f - CurrentEffort);

        // AccelChange=true applies force as acceleration (mass-independent),
        // ensuring uniform grid behaviour regardless of individual cube masses.
        PrimComp->AddForce(
            AttractorForce + RepulsorForce + DragForce,
            NAME_None,
            /*bAccelChange=*/ true);
    }
}

// ---------------------------------------------------------------------------
// NormalizeAdaptive
// ---------------------------------------------------------------------------

float UKinematicDescriptorComponent::NormalizeAdaptive(
    float RawValue,
    float& AdaptiveMin,
    float& AdaptiveMax) const
{
    // Update the tracked maximum.
    // Expands quickly toward new observed maxima; contracts slowly otherwise.
    if (RawValue > AdaptiveMax)
    {
        AdaptiveMax = FMath::Lerp(AdaptiveMax, RawValue, NormRangeExpandAlpha);
    }
    else
    {
        AdaptiveMax = FMath::Lerp(AdaptiveMax, RawValue, NormRangeContractAlpha);
    }

    // Update the tracked minimum with opposite logic.
    if (RawValue < AdaptiveMin)
    {
        AdaptiveMin = FMath::Lerp(AdaptiveMin, RawValue, NormRangeExpandAlpha);
    }
    else
    {
        AdaptiveMin = FMath::Lerp(AdaptiveMin, RawValue, NormRangeContractAlpha);
    }

    // Enforce a minimum valid range to prevent division by near-zero during
    // the warmup period or in degenerate cases where all values are equal.
    const float ValidRange = FMath::Max(AdaptiveMax - AdaptiveMin, 1.0f);

    return FMath::Clamp((RawValue - AdaptiveMin) / ValidRange, 0.0f, 1.0f);
}

// ---------------------------------------------------------------------------
// ComputeStdDev
// ---------------------------------------------------------------------------

float UKinematicDescriptorComponent::ComputeStdDev(const TArray<float>& Buffer)
{
    if (Buffer.Num() < 2)
    {
        return 0.0f;
    }

    float Sum = 0.0f;
    for (const float Val : Buffer)
    {
        Sum += Val;
    }
    const float Mean = Sum / static_cast<float>(Buffer.Num());

    float SumSqDiff = 0.0f;
    for (const float Val : Buffer)
    {
        SumSqDiff += FMath::Square(Val - Mean);
    }

    // Population standard deviation (ddof=0), consistent with np.std default    
    // in the Python offline validation pipeline.
    return FMath::Sqrt(SumSqDiff / static_cast<float>(Buffer.Num()));
}

// ---------------------------------------------------------------------------
// RebuildHomeLocations
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::RebuildHomeLocations()
{
    CubeHomeLocations.Empty();

    for (AActor* Cube : ARCubes)
    {
        if (Cube)
        {
            CubeHomeLocations.Add(Cube, Cube->GetActorLocation());
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("UKinematicDescriptorComponent: RebuildHomeLocations — "
            "anchored %d cubes."),
        CubeHomeLocations.Num());
}