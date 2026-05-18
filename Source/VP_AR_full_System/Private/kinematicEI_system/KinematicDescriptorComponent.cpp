/**
 * KinematicDescriptorComponent.cpp
 *
 * Core runtime component of the Kinematic AR Embodied Interaction system.
 *
 * RESPONSIBILITIES
 * ────────────────
 * 1. Reads raw joint positions from a ZED LiveLink-driven SkeletalMeshComponent
 * every tick and passes them through per-joint 1 Euro Filters to remove
 * tracker noise while preserving expressive transients.
 *
 * 2. Computes four continuous Laban Movement Analysis (LMA) descriptors:
 * Effort       (LMA Time)   — weighted aggregate velocity across six joints.
 * Expansiveness(LMA Space)  — maximum wrist-to-spine reach distance.
 * Weight       (LMA Weight) — weighted aggregate acceleration magnitude.
 * Flow         (LMA Flow)   — rolling standard deviation of velocity delta,
 * measuring movement regularity (Bound vs Free).
 *
 * 3. Writes all four descriptor values and the pelvis world position to the
 * shared Material Parameter Collection (MPC_KinematicAR) and to the Niagara
 * system, routing live data to the GPU and particle subsystems every frame.
 *
 * 4. Executes a per-particle, per-limb physics force model ("spherical cloth"):
 *
 * FORMATION FOLLOWING
 * The bubble formation follows the performer's pelvis continuously every tick.
 * Each particle stores a pelvis-relative home offset (set by RebuildHomeLocations).
 * Every tick: HomeLoc = LivePelvisPosition + StoredOffset.
 * As the performer moves, LivePelvisPosition changes, and every particle's
 * home moves with it. The attractor spring pulls each particle toward home,
 * translating the entire bubble with the body in real time.
 *
 * PER-LIMB DIRECTIONAL DEFORMATION
 * Four limbs (L/R wrist, L/R elbow) each push only the particles whose
 * outward normal (from pelvis to particle) aligns with the limb's velocity
 * direction. A forward arm thrust deforms only the front face. A lateral
 * sweep deforms only the side face. The opposite face is unaffected.
 * Pull movements produce implicit inward deformation: when the repulsor
 * stops firing on a face, the attractor pulls those particles inward.
 *
 * LMA DESCRIPTOR ROLES
 * Effort        → scales all repulsor force magnitudes globally.
 * Weight        → scales acceleration-spike component of repulsor force.
 * Flow          → scales attractor spring (Bound = tight, Free = loose).
 * Expansiveness → scales the spatial reach of the repulsor effect.
 *
 * 5. Handles ZED plugin lifecycle: BP_ZED_Manny can be destroyed and recreated
 * at any time. TrackedSkeleton validity is checked every tick; stale pointers
 * reset all state cleanly and suspend processing until reassignment.
 *
 * SETUP
 * ─────
 * - Add to BP_KinematicManager alongside UProximityDispatchComponent.
 * - Assign TrackedSkeleton at runtime via the Level Blueprint BeginPlay
 * sequence after the startup delay.
 * - Assign GlobalMPC (MPC_KinematicAR) and ParticleSystem in the Details panel.
 * - Leave ARCubes empty in the editor. BP_ARGridSpawner populates it at runtime
 * then calls RebuildHomeLocations() to anchor home offsets.
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
 // Joint contribution weights for Effort and Flow descriptors.
 // Distal joints carry the most expressive velocity signal in upper-body
 // performance movement and receive the highest weight.
 // ---------------------------------------------------------------------------

static constexpr float WEIGHT_WRIST = 1.0f;
static constexpr float WEIGHT_ELBOW = 0.8f;
static constexpr float WEIGHT_SHOULDER = 0.6f;

static constexpr float TOTAL_JOINT_WEIGHT =
(WEIGHT_WRIST * 2.0f) + (WEIGHT_ELBOW * 2.0f) + (WEIGHT_SHOULDER * 2.0f);

// ---------------------------------------------------------------------------
// Physiological seed values for adaptive normalization range.
// Used only during warmup before sufficient real movement data is observed.
// Units: cm/s for velocity-based descriptors, cm for distance.
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
// Physics constants.
// ---------------------------------------------------------------------------

// Minimum limb speed (cm/s) below which no repulsor force is generated.
// Prevents tracker noise from continuously jittering bubble particles at rest.
static constexpr float MIN_LIMB_SPEED_THRESHOLD = 5.0f;

// Reference maximum limb speed (cm/s) used to normalise raw speed to [0,1].
// 400 cm/s represents a fast ballistic arm swing. Values above this clamp
// to 1.0, preventing force explosion on sudden explosive movements.
static constexpr float REF_MAX_LIMB_SPEED = 400.0f;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

UKinematicDescriptorComponent::UKinematicDescriptorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    // 1 Euro Filter parameters validated against ZED 2i BODY_38 at 30 Hz
    // with NEURAL depth mode. Suppress jitter while preserving ballistic
    // movement transients with no measurable group delay.
    const float MinCutoff = 1.0f;
    const float Beta = 0.05f;

    FilterSpine = FOneEuroFilterVector(MinCutoff, Beta);
    FilterLWrist = FOneEuroFilterVector(MinCutoff, Beta);
    FilterRWrist = FOneEuroFilterVector(MinCutoff, Beta);
    FilterLElbow = FOneEuroFilterVector(MinCutoff, Beta);
    FilterRElbow = FOneEuroFilterVector(MinCutoff, Beta);
    FilterLShoulder = FOneEuroFilterVector(MinCutoff, Beta);
    FilterRShoulder = FOneEuroFilterVector(MinCutoff, Beta);

    // LMA descriptor state — neutral (no movement) at startup.
    CurrentEffort = 0.0f;
    CurrentExpansiveness = 0.0f;
    CurrentWeight = 0.0f;
    CurrentFlow = 0.0f;

    // Joint position and velocity history — seeded to zero.
    // On the first valid descriptor frame these are initialised from live
    // joint positions to prevent a spurious large velocity spike.
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

    // Per-limb velocity direction vectors (smoothed world-space unit vectors).
    // Updated each tick when limb speed exceeds the minimum threshold.
    // Read by ExecuteKinematicPhysics for directional force computation.
    LWristVelocityDir = FVector::ZeroVector;
    RWristVelocityDir = FVector::ZeroVector;
    LElbowVelocityDir = FVector::ZeroVector;
    RElbowVelocityDir = FVector::ZeroVector;

    // Per-limb raw speed scalars (cm/s) — updated every tick.
    LWristSpeed = 0.0f;
    RWristSpeed = 0.0f;
    LElbowSpeed = 0.0f;
    RElbowSpeed = 0.0f;

    // Lifecycle flags.
    // bFirstDescriptorFrame: seeds joint history on the first valid tick.
    // bHomeOffsetsReady: gates ExecuteKinematicPhysics until anchors are set.
    bFirstDescriptorFrame = true;
    bHomeOffsetsReady = false;

    // Seed adaptive normalization ranges with conservative physiological
    // estimates. Refined automatically as real movement data is observed.
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

    // Pre-allocate the Flow sigma circular buffer to avoid per-tick heap
    // reallocation. FlowWindowSize defaults to 30 frames (~1 second at 30 Hz).
    FlowDeltaBuffer.Reserve(FlowWindowSize);

    // CubeHomeOffsets and physics activation are handled by BP_ARGridSpawner
    // at runtime via RebuildHomeLocations(). Nothing to do here at BeginPlay.
}

// ---------------------------------------------------------------------------
// TickComponent — main pipeline entry point, runs every engine frame.
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Guard: no skeleton assigned yet (pre-BeginPlay delay period).
    if (!TrackedSkeleton) return;

    // Guard: ZED LiveLink plugin destroys and recreates BP_ZED_Manny whenever
    // a skeleton enters or leaves the camera frame. If the actor has been
    // garbage-collected, reset all state cleanly and stop processing until
    // TrackedSkeleton is reassigned by the Level Blueprint sequence.
    if (!IsValid(TrackedSkeleton))
    {
        TrackedSkeleton = nullptr;
        bHomeOffsetsReady = false;
        bFirstDescriptorFrame = true;

        // Zero descriptor outputs so the MPC does not show stale values.
        CurrentEffort = CurrentExpansiveness = CurrentWeight = CurrentFlow = 0.0f;
        DebugEffort = DebugExpansiveness = DebugWeight = DebugFlow = 0.0f;

        // Zero per-limb state to prevent stale directions producing phantom
        // forces when the next valid skeleton frame arrives.
        LWristVelocityDir = RWristVelocityDir =
            LElbowVelocityDir = RElbowVelocityDir = FVector::ZeroVector;
        LWristSpeed = RWristSpeed = LElbowSpeed = RElbowSpeed = 0.0f;

        FlowDeltaBuffer.Empty();

        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: TrackedSkeleton actor was "
                "destroyed (skeleton left camera frame). All state reset. "
                "Waiting for TrackedSkeleton to be reassigned."));
        return;
    }

    // Read raw joint positions from the skeleton and apply 1 Euro Filter
    // to each joint independently.
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

    // Compute LMA descriptors from filtered joint data. Also updates
    // per-limb velocity direction and speed member variables consumed
    // by ExecuteKinematicPhysics.
    ComputeLMADescriptors(
        DeltaTime,
        CleanSpine,
        CleanLWrist, CleanRWrist,
        CleanLElbow, CleanRElbow,
        CleanLShoulder, CleanRShoulder);

    // Write descriptor values and pelvis world position to the MPC and
    // Niagara system for GPU-side material and particle effects.
    const FVector PelvisLoc =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));
    UpdateRenderSubsystems(PelvisLoc);

    // Apply per-particle physics forces. Gated internally on bHomeOffsetsReady.
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
    // BODY_38 bone name map (ZED joint → Manny skeleton bone):
    //   PELVIS         → Hips        (read in TickComponent directly)
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

    // On the first valid frame, seed history buffers with current positions
    // to prevent a large spurious velocity spike on the following frame.
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
    // Step 1 — Per-joint velocity vectors (finite difference, dt-normalised).
    // -----------------------------------------------------------------------

    const FVector VelLWrist = (LWrist - PrevLWrist) / DeltaTime;
    const FVector VelRWrist = (RWrist - PrevRWrist) / DeltaTime;
    const FVector VelLElbow = (LElbow - PrevLElbow) / DeltaTime;
    const FVector VelRElbow = (RElbow - PrevRElbow) / DeltaTime;
    const FVector VelLShoulder = (LShoulder - PrevLShoulder) / DeltaTime;
    const FVector VelRShoulder = (RShoulder - PrevRShoulder) / DeltaTime;

    // -----------------------------------------------------------------------
    // Step 2 — Per-limb speed scalars and smoothed direction vectors.
    //
    // Written to member variables so ExecuteKinematicPhysics can apply
    // independent per-limb directional forces without recomputing them.
    //
    // Direction smoothing (alpha = 0.3) prevents rapid flipping when limb
    // speed is low and tracker noise dominates the direction signal.
    // Direction is only updated when speed exceeds MIN_SPEED_FOR_DIR_UPDATE.
    // -----------------------------------------------------------------------

    static constexpr float MIN_SPEED_FOR_DIR_UPDATE = 1.0f;
    static constexpr float DIR_SMOOTH_ALPHA = 0.3f;

    LWristSpeed = VelLWrist.Size();
    RWristSpeed = VelRWrist.Size();
    LElbowSpeed = VelLElbow.Size();
    RElbowSpeed = VelRElbow.Size();

    if (LWristSpeed > MIN_SPEED_FOR_DIR_UPDATE)
    {
        LWristVelocityDir = FMath::Lerp(
            LWristVelocityDir,
            VelLWrist / LWristSpeed,
            DIR_SMOOTH_ALPHA).GetSafeNormal();
    }
    if (RWristSpeed > MIN_SPEED_FOR_DIR_UPDATE)
    {
        RWristVelocityDir = FMath::Lerp(
            RWristVelocityDir,
            VelRWrist / RWristSpeed,
            DIR_SMOOTH_ALPHA).GetSafeNormal();
    }
    if (LElbowSpeed > MIN_SPEED_FOR_DIR_UPDATE)
    {
        LElbowVelocityDir = FMath::Lerp(
            LElbowVelocityDir,
            VelLElbow / LElbowSpeed,
            DIR_SMOOTH_ALPHA).GetSafeNormal();
    }
    if (RElbowSpeed > MIN_SPEED_FOR_DIR_UPDATE)
    {
        RElbowVelocityDir = FMath::Lerp(
            RElbowVelocityDir,
            VelRElbow / RElbowSpeed,
            DIR_SMOOTH_ALPHA).GetSafeNormal();
    }

    // -----------------------------------------------------------------------
    // Step 3 — LMA Space: Expansiveness
    //
    // Maximum of left and right wrist-to-spine reach distances. Using the
    // maximum (not average) correctly captures kinesphere extent: the
    // performer's spatial reach is defined by the most extended limb.
    // -----------------------------------------------------------------------

    const float DistL = FVector::Dist(Spine, LWrist);
    const float DistR = FVector::Dist(Spine, RWrist);
    CurrentExpansiveness = NormalizeAdaptive(
        FMath::Max(DistL, DistR),
        AdaptiveMin_Expansiveness, AdaptiveMax_Expansiveness);

    // -----------------------------------------------------------------------
    // Step 4 — LMA Time: Effort
    //
    // Weighted aggregate velocity magnitude across six joints.
    // Summing magnitudes (not the vector sum) prevents left/right cancellation
    // during symmetric bilateral movements such as a two-arm push.
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
    // Step 5 — LMA Weight: Acceleration magnitude
    //
    // Computed from the four most kinematically active joints (wrists and
    // elbows). Shoulder acceleration is lower frequency and would dilute the
    // Weight signal during fast distal movements.
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
    // Step 6 — LMA Flow: Rolling sigma of aggregate velocity delta magnitude.
    //
    // Flow is independent of Weight. Weight measures instantaneous acceleration
    // magnitude; Flow measures consistency of velocity change over time.
    // A controlled Press (Strong + Bound) = high Weight, low sigma.
    // A Slash (Strong + Free) = high Weight AND high sigma.
    // This independence is what separates the eight LMA action drives.
    // -----------------------------------------------------------------------

    const float AggVelMag =
        (VelLWrist.Size() * WEIGHT_WRIST +
            VelRWrist.Size() * WEIGHT_WRIST +
            VelLElbow.Size() * WEIGHT_ELBOW +
            VelRElbow.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    const float PrevAggVelMag =
        (PrevLWristVelocity.Size() * WEIGHT_WRIST +
            PrevRWristVelocity.Size() * WEIGHT_WRIST +
            PrevLElbowVelocity.Size() * WEIGHT_ELBOW +
            PrevRElbowVelocity.Size() * WEIGHT_ELBOW)
        / (WEIGHT_WRIST * 2.0f + WEIGHT_ELBOW * 2.0f);

    const float VelDeltaMag =
        FMath::Abs(AggVelMag - PrevAggVelMag) / DeltaTime;

    FlowDeltaBuffer.Add(VelDeltaMag);
    if (FlowDeltaBuffer.Num() > FlowWindowSize)
    {
        FlowDeltaBuffer.RemoveAt(0, 1, false);
    }

    const float RawFlow = (FlowDeltaBuffer.Num() >= 2)
        ? ComputeStdDev(FlowDeltaBuffer) : 0.0f;

    CurrentFlow = NormalizeAdaptive(
        RawFlow, AdaptiveMin_Flow, AdaptiveMax_Flow);

    // -----------------------------------------------------------------------
    // Step 7 — Advance joint history state for the next tick.
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
    // Step 8 — Write debug-readable copies (visible in Details panel during Play).
    // -----------------------------------------------------------------------

    DebugEffort = CurrentEffort;
    DebugExpansiveness = CurrentExpansiveness;
    DebugWeight = CurrentWeight;
    DebugFlow = CurrentFlow;
}

// ---------------------------------------------------------------------------
// UpdateRenderSubsystems
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::UpdateRenderSubsystems(
    const FVector& PelvisLocation)
{
    if (GlobalMPC)
    {
        UWorld* World = GetWorld();

        // Write the four LMA descriptor scalars. All AR cube materials read
        // these via MPC_KinematicAR without any per-frame Blueprint overhead.
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("EffortLevel"), CurrentEffort);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("ExpansivenessLevel"), CurrentExpansiveness);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("WeightLevel"), CurrentWeight);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("FlowLevel"), CurrentFlow);

        // Write the pelvis world position as a vector parameter.
        // M_KinematicGrid reads this for GPU-side proximity distance computation
        // in the Proximity Mask section. FLinearColor packs the 3D position as
        // RGBA with the fourth channel unused (set to 1.0).
        UKismetMaterialLibrary::SetVectorParameterValue(
            World, GlobalMPC, FName("PelvisWorldLocation"),
            FLinearColor(
                PelvisLocation.X,
                PelvisLocation.Y,
                PelvisLocation.Z,
                1.0f));
    }

    if (ParticleSystem)
    {
        // Pass Effort and Flow as Niagara User parameters.
        // Effort drives spawn rate and velocity scale.
        // Flow modulates turbulence, distinguishing Bound from Free quality.
        ParticleSystem->SetFloatParameter(
            FName("User.EffortLevel"), CurrentEffort);
        ParticleSystem->SetFloatParameter(
            FName("User.FlowLevel"), CurrentFlow);
    }
}

// ---------------------------------------------------------------------------
// ExecuteKinematicPhysics
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::ExecuteKinematicPhysics()
{
    // Physics is gated on both skeleton validity and home offset readiness.
    // bHomeOffsetsReady is set true only after RebuildHomeLocations() has
    // successfully anchored all particle home positions. Before that, no
    // forces are applied and particles remain at their spawn positions.
    if (!TrackedSkeleton || !bHomeOffsetsReady) return;

    const FVector PelvisLoc =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));

    // Build the per-limb descriptor array for the inner force computation.
    struct FLimbDescriptor
    {
        FVector Dir;        // Smoothed world-space velocity direction unit vector.
        float   Speed;      // Raw speed scalar (cm/s).
        float   JointWeight;// Anatomical importance weighting.
    };

    const FLimbDescriptor Limbs[] =
    {
        { LWristVelocityDir, LWristSpeed, WEIGHT_WRIST  },
        { RWristVelocityDir, RWristSpeed, WEIGHT_WRIST  },
        { LElbowVelocityDir, LElbowSpeed, WEIGHT_ELBOW  },
        { RElbowVelocityDir, RElbowSpeed, WEIGHT_ELBOW  },
    };

    // Maps CurrentExpansiveness [0,1] to [0.5, 1.5]. The 0.5 floor ensures
    // some spatial reach even during fully contracted movement.
    const float ExpansivenessScale = 0.5f + CurrentExpansiveness;

    for (AActor* Cube : ARCubes)
    {
        // Skip null entries and actors that have been garbage-collected
        // (e.g. if the level is being torn down mid-session).
        if (!Cube || !IsValid(Cube)) continue;

        UPrimitiveComponent* PrimComp =
            Cube->FindComponentByClass<UPrimitiveComponent>();

        // Skip actors without an active physics simulation. Physics is
        // enabled per-particle by BP_ARGridSpawner after RebuildHomeLocations.
        if (!PrimComp || !PrimComp->IsSimulatingPhysics()) continue;

        const FVector CurrentLoc = Cube->GetActorLocation();
        const FVector CubeVelocity = PrimComp->GetComponentVelocity();

        // -------------------------------------------------------------------
        // HOME POSITION: pelvis world location + stored pelvis-relative offset.
        //
        // This recomputes every tick as the live pelvis moves through the stage.
        // The entire bubble formation translates with the performer continuously.
        // If no offset exists for this cube (edge case — should not occur after
        // RebuildHomeLocations), fall back to current location (zero attractor).
        // -------------------------------------------------------------------

        const FVector HomeLoc = CubeHomeOffsets.Contains(Cube)
            ? (PelvisLoc + CubeHomeOffsets[Cube])
            : CurrentLoc;

        // Outward normal: direction from the body centre to this particle.
        // This is the "outward" direction of the bubble surface at this point.
        const FVector OutwardNormal =
            (CurrentLoc - PelvisLoc).GetSafeNormal();

        // -------------------------------------------------------------------
        // ATTRACTOR FORCE
        //
        // Pulls each particle toward its continuously-updated home position.
        // Two-component scaling:
        //   BaseScale (1.0)  — constant, always-on. Ensures the formation
        //                      follows the performer at any movement speed.
        //   LMAScale         — ranges [0.3, 1.0] inversely with Flow.
        //                      Bound (low Flow)  = tight formation.
        //                      Free  (high Flow) = loose, drifting particles.
        // Combined scale range: [1.3, 2.0].
        // The minimum of 1.3 at maximum Free ensures particles always return.
        // -------------------------------------------------------------------

        const FVector ToHome = HomeLoc - CurrentLoc;
        const float   LMAScale = FMath::Max(1.0f - CurrentFlow, 0.3f);
        const float   AttractorScale = 1.0f + LMAScale;

        const FVector AttractorForce = ToHome
            * AttractorSpringConstant
            * AttractorScale;

        // -------------------------------------------------------------------
        // PER-LIMB REPULSOR FORCE (directional "spherical cloth" deformation)
        //
        // Each limb is evaluated independently. A limb contributes repulsor
        // force to this particle only when both conditions are met:
        //   (a) Limb speed exceeds MIN_LIMB_SPEED_THRESHOLD (limb is actively
        //       moving, not just tracker noise).
        //   (b) The particle faces the limb's movement direction (dot product
        //       of OutwardNormal and limb velocity direction > 0).
        //
        // Force direction = the limb's velocity direction (not radially outward).
        // A forward thrust pushes the bubble forward.
        // A lateral sweep pushes the bubble sideways.
        // A pull movement (limb moving away from bubble surface) produces
        // Alignment ≤ 0 on the retreating face — no push on that face.
        // The attractor then pulls those particles inward, creating the
        // implicit "sucked in" deformation effect.
        //
        // Force magnitude per limb:
        //   NormalisedSpeed   — speed clamped to [0,1] against 400 cm/s.
        //   Alignment         — how directly the particle faces the movement.
        //   CurrentEffort     — ensures a subtle response to gentle movement without phantom drifting.
        //   Weight factor     — maps Weight [0,1] to [0.5,1.0], amplifying
        //                       Strong moves and reducing Light ones.
        //   JointWeight       — anatomical importance (wrist > elbow).
        //   ExpansivenessScale— spatial reach multiplier.
        // -------------------------------------------------------------------

        FVector AccumulatedRepulsorForce = FVector::ZeroVector;

        for (const FLimbDescriptor& Limb : Limbs)
        {
            if (Limb.Speed < MIN_LIMB_SPEED_THRESHOLD) continue;

            const float Alignment = FVector::DotProduct(OutwardNormal, Limb.Dir);
            if (Alignment <= 0.0f) continue;

            const float NormalisedSpeed = FMath::Clamp(
                Limb.Speed / REF_MAX_LIMB_SPEED, 0.0f, 1.0f);

            // FIX: Removed the FMath::Max(CurrentEffort, 0.05f) floor that caused constant phantom drift.
            const float LimbForceMag =
                NormalisedSpeed
                * Alignment
                * CurrentEffort
                * (0.5f + CurrentWeight * 0.5f)
                * Limb.JointWeight
                * ExpansivenessScale;

            AccumulatedRepulsorForce += Limb.Dir * LimbForceMag;
        }

        const FVector RepulsorForce =
            AccumulatedRepulsorForce * RepulsorForceMultiplier;

        // -------------------------------------------------------------------
        // DRAG FORCE
        //
        // Velocity-proportional damping that prevents infinite oscillation.
        // FIX: Removed LMADragScale completely. The system now utilizes the 
        // base drag coefficient constantly to maintain critical damping.
        // -------------------------------------------------------------------
        const FVector DragForce = -CubeVelocity * BaseDragCoefficient;

        // Apply the combined force as a pure acceleration (bAccelChange = true).
        // Acceleration mode is mass-independent, ensuring all particles in
        // the bubble respond identically regardless of physics body mass.
        // FIX: Removed the manual velocity cap that fought the integration step.
        PrimComp->AddForce(
            AttractorForce + RepulsorForce + DragForce,
            NAME_None,
            /*bAccelChange=*/ true);
    }
}

// ---------------------------------------------------------------------------
// RebuildHomeLocations
//
// Stores a pelvis-relative home offset for every registered AR cube actor.
// Called once by BP_ARGridSpawner after:
//   1. The Fibonacci sphere has been spawned around the live pelvis position.
//   2. TrackedSkeleton has been injected by the Level Blueprint sequence.
//   3. Simulate Physics has been enabled on all particle static meshes.
//
// After this call completes successfully:
//   - CubeHomeOffsets maps each cube to its offset from the pelvis.
//   - bHomeOffsetsReady = true, unblocking ExecuteKinematicPhysics.
//   - Every tick: HomeLoc = LivePelvisLoc + StoredOffset, so the formation
//     follows the performer continuously through the stage.
//
// If TrackedSkeleton is not valid, logs a warning and returns without setting
// the ready flag. BP_ARGridSpawner must ensure TrackedSkeleton is assigned
// before calling this (enforced by the Level Blueprint timing sequence).
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::RebuildHomeLocations()
{
    CubeHomeOffsets.Empty();

    if (!TrackedSkeleton || !IsValid(TrackedSkeleton))
    {
        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: RebuildHomeLocations called "
                "while TrackedSkeleton is null or invalid. Home offsets "
                "not set. Physics will remain suspended."));
        return;
    }

    const FVector PelvisNow =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));

    int32 AnchoredCount = 0;

    for (AActor* Cube : ARCubes)
    {
        // Skip null or already-destroyed entries.
        if (!Cube || !IsValid(Cube)) continue;

        // Store the vector from the live pelvis to this cube's world position.
        // Each tick replays this offset against the new pelvis position.
        CubeHomeOffsets.Add(Cube, Cube->GetActorLocation() - PelvisNow);
        ++AnchoredCount;
    }

    // Set the physics gate. ExecuteKinematicPhysics will begin running on
    // the next tick. All particle physics components must already be active
    // at this point (enabled by BP_ARGridSpawner before calling this).
    bHomeOffsetsReady = true;

    UE_LOG(LogTemp, Log,
        TEXT("UKinematicDescriptorComponent: RebuildHomeLocations complete — "
            "%d / %d cubes anchored. "
            "Pelvis at (%.1f, %.1f, %.1f). "
            "Physics gate opened. Bubble is now active."),
        AnchoredCount,
        ARCubes.Num(),
        PelvisNow.X, PelvisNow.Y, PelvisNow.Z);
}

// ---------------------------------------------------------------------------
// NormalizeAdaptive
//
// Normalises a raw descriptor value to [0, 1] using an adaptive EMA-based
// range tracker. The range expands quickly toward new extremes
// (alpha = NormRangeExpandAlpha, default 0.1) and contracts slowly during
// calmer periods (alpha = NormRangeContractAlpha, default 0.001).
//
// A minimum valid range of 1.0 is enforced to prevent division by near-zero
// during warmup before sufficient movement variation has been observed.
// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------
// ComputeStdDev
//
// Population standard deviation (ddof=0) of a float array.
// Returns 0.0 for arrays with fewer than two elements.
// Consistent with numpy.std default (ddof=0) used in the Python offline
// descriptor validation pipeline.
// ---------------------------------------------------------------------------

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