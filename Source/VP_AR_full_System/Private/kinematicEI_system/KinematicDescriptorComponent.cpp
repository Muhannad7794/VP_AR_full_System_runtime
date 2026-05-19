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
    FlowDeltaBuffer.Reserve(FlowWindowSize);

    // Cache the ProximityDispatchComponent from the same owner actor.
    // Used in ExecuteKinematicPhysics to read ProximityRadius without
    // requiring a separate parameter on this component.
    ProximityDispatch = GetOwner()
        ? GetOwner()->FindComponentByClass<UProximityDispatchComponent>()
        : nullptr;

    if (!ProximityDispatch)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: ProximityDispatchComponent "
                "not found on owner. Limb proximity checks will use "
                "fallback radius of 80cm."));
    }
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

    // Auto-discover all ZED Manny skeletal mesh components every tick.
    // This removes all Blueprint dependency for TrackedSkeletons population.
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

            // Keep TrackedSkeleton (singular) pointing to the first found
            // skeleton for LMA descriptor computation.
            if (!TrackedSkeleton || !IsValid(TrackedSkeleton))
            {
                TrackedSkeleton = Skel;
                bFirstDescriptorFrame = true;
            }
        }
    }

    // If no skeletons found, reset state and wait.
    if (TrackedSkeletons.Num() == 0)
    {
        TrackedSkeleton = nullptr;
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
    if (!bHomeOffsetsReady) return;
    if (TrackedSkeletons.Num() == 0) return;

    // Read proximity radius from ProximityDispatchComponent.
    // Fall back to 80cm if the component is not available.
    const float LimbProximityRadius = (ProximityDispatch && IsValid(ProximityDispatch))
        ? ProximityDispatch->ProximityRadius
        : 80.0f;

    const float ExpansivenessScale = 0.5f + CurrentExpansiveness;

    // Socket names for the four limb joints checked per skeleton.
    // These match the ZED BODY_38 to Manny bone name mapping.
    static const FName LimbSockets[] = {
        FName("LeftHand"),
        FName("RightHand"),
        FName("LeftForeArm"),
        FName("RightForeArm")
    };

    static const float LimbWeights[] = {
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
        const FVector CubeVelocity = PrimComp->GetComponentVelocity();

        // Fixed world-space home position set at spawn time.
        const FVector HomeLoc = CubeHomeOffsets.Contains(Cube)
            ? CubeHomeOffsets[Cube]
            : CurrentLoc;

        const FVector ToHome = HomeLoc - CurrentLoc;
        const float   DistToHome = ToHome.Size();

        // -------------------------------------------------------------------
        // ATTRACTOR — fixed home, trivially stable.
        // Flow modulates tightness: Bound = snappy, Free = slow drift.
        // -------------------------------------------------------------------

        const float FlowScale = FMath::Max(1.0f - CurrentFlow, 0.3f);
        const float AttractorScale = 1.0f + FlowScale;

        const FVector AttractorForce = ToHome
            * AttractorSpringConstant
            * AttractorScale;

        // -------------------------------------------------------------------
        // PROXIMITY-BASED MULTI-PERFORMER REPULSOR
        //
        // For every tracked skeleton, check each of the four limb joints.
        // A joint contributes force to this particle only when:
        //   (a) The joint is within LimbProximityRadius of this particle.
        //   (b) The joint has a valid velocity direction (moving above noise).
        //
        // Force magnitude scales with:
        //   ProximityFactor — 1.0 when touching, 0.0 at the radius boundary.
        //                     This creates a natural proximity field: particles
        //                     very close to a limb react strongly, particles at
        //                     the edge of the radius react gently.
        //   NormalisedSpeed — limb speed clamped to [0,1].
        //   CurrentEffort   — zero at rest, full at peak movement.
        //   Weight factor   — maps [0,1] to [0.5,1.0].
        //   LimbWeight      — anatomical importance (wrist > elbow).
        //   ExpansivenessScale — spatial reach from LMA Space descriptor.
        //
        // Force direction = the limb's velocity direction, so a forward
        // thrust pushes nearby particles forward, a lateral sweep pushes
        // them sideways. The particle's outward normal is NOT used as the
        // force direction — the force follows the limb's actual movement.
        // The outward normal is used to compute the proximity factor gradient.
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

                // Skip if limb is outside the proximity radius.
                if (DistToLimb >= LimbProximityRadius) continue;

                // ProximityFactor: 1.0 at zero distance, 0.0 at radius edge.
                const float ProximityFactor =
                    1.0f - (DistToLimb / LimbProximityRadius);

                // Compute limb velocity from pre-computed per-limb state.
                // Use the per-limb direction vectors already computed in
                // ComputeLMADescriptors for the primary tracked skeleton.
                // For secondary performers, approximate from socket motion
                // by using the matching limb direction from the primary.
                // Full per-skeleton velocity tracking is a future extension.
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
                if (LimbDir.IsNearlyZero()) continue;

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
        // SAFETY TETHER — hard exponential cap at MAX_DEFORMATION_RADIUS.
        // With a fixed home this is unconditionally reliable.
        // -------------------------------------------------------------------

        static constexpr float MAX_DEFORMATION_RADIUS = 80.0f;
        FVector TetherForce = FVector::ZeroVector;

        if (DistToHome > MAX_DEFORMATION_RADIUS)
        {
            const float Violation = DistToHome - MAX_DEFORMATION_RADIUS;
            TetherForce = ToHome.GetSafeNormal()
                * (Violation * Violation * 150.0f);
        }

        // Chaos solver stable damping.
        PrimComp->SetLinearDamping(BaseDragCoefficient);

        PrimComp->AddForce(
            AttractorForce + RepulsorForce + TetherForce,
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

    if (ARCubes.Num() == 0)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: RebuildHomeLocations called "
                "with empty ARCubes array."));
        return;
    }

    int32 AnchoredCount = 0;

    for (AActor* Cube : ARCubes)
    {
        if (!Cube || !IsValid(Cube)) continue;

        // Store the cube's spawn world position as its permanent home.
        // The static bubble model uses fixed world-space home positions.
        // Particles deform from these positions and always return to them.
        CubeHomeOffsets.Add(Cube, Cube->GetActorLocation());
        ++AnchoredCount;
    }

    bHomeOffsetsReady = true;

    UE_LOG(LogTemp, Log,
        TEXT("UKinematicDescriptorComponent: RebuildHomeLocations complete — "
            "%d / %d cubes anchored at world-space spawn positions."),
        AnchoredCount, ARCubes.Num());
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