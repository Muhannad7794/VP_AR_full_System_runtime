/**
 * KinematicDescriptorComponent.cpp
 *
 * Implementation of the four LMA descriptor pipeline for Kinematic AR.
 *
 * Physics model — per-limb independent directional forces:
 *   Each tracked limb (left wrist, right wrist, left elbow, right elbow)
 *   contributes an independent force vector to every particle in the bubble.
 *   A particle receives force from a limb only if the particle faces the
 *   direction that limb is moving (positive dot product). This produces
 *   the "spherical cloth" behaviour where different faces of the bubble
 *   deform independently based on which limbs are active and in which
 *   directions they are moving.
 *
 *   LMA descriptors govern the CHARACTER of the deformation:
 *     Effort     — overall urgency, scales the base force magnitude globally
 *     Weight     — acceleration magnitude, scales individual limb force spikes
 *     Flow       — attractor spring strength (Bound = tight, Free = loose)
 *     Expansiveness — spatial reach, scales how far displaced particles travel
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
static constexpr float INIT_MIN_EFFORT = 0.0f;
static constexpr float INIT_MAX_EFFORT = 300.0f;
static constexpr float INIT_MIN_EXPANSIVENESS = 0.0f;
static constexpr float INIT_MAX_EXPANSIVENESS = 800.0f;
static constexpr float INIT_MIN_WEIGHT = 0.0f;
static constexpr float INIT_MAX_WEIGHT = 500.0f;
static constexpr float INIT_MIN_FLOW = 0.0f;
static constexpr float INIT_MAX_FLOW = 50.0f;

// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

UKinematicDescriptorComponent::UKinematicDescriptorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsEIActive = true;

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

    // Per-limb velocity direction state — initialised to zero vectors.
    // Populated every tick in ComputeLMADescriptors after the first frame.
    LWristVelocityDir = FVector::ZeroVector;
    RWristVelocityDir = FVector::ZeroVector;
    LElbowVelocityDir = FVector::ZeroVector;
    RElbowVelocityDir = FVector::ZeroVector;

    // Per-limb speed scalars — initialised to zero.
    LWristSpeed = 0.0f;
    RWristSpeed = 0.0f;
    LElbowSpeed = 0.0f;
    RElbowSpeed = 0.0f;

    bFirstDescriptorFrame = true;

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

    // CubeHomeOffsets are populated by RebuildHomeLocations(), called
    // by BP_ARGridSpawner after spawn completes. Nothing to do here.
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
            GetWorld(), GlobalMPC, FName("SystemMode"),
            bIsEIActive ? 1.0f : 0.0f);
    }
}

// ---------------------------------------------------------------------------
// TickComponent
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!TrackedSkeleton) return;

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
    // 1. Per-joint velocity vectors
    // -----------------------------------------------------------------------

    const FVector VelLWrist = (LWrist - PrevLWrist) / DeltaTime;
    const FVector VelRWrist = (RWrist - PrevRWrist) / DeltaTime;
    const FVector VelLElbow = (LElbow - PrevLElbow) / DeltaTime;
    const FVector VelRElbow = (RElbow - PrevRElbow) / DeltaTime;
    const FVector VelLShoulder = (LShoulder - PrevLShoulder) / DeltaTime;
    const FVector VelRShoulder = (RShoulder - PrevRShoulder) / DeltaTime;

    // -----------------------------------------------------------------------
    // 2. Per-limb speed scalars and normalised direction vectors.
    //    These are written to member variables so ExecuteKinematicPhysics
    //    can apply independent per-limb forces without re-computing them.
    //
    //    Velocity direction is smoothed with a low-alpha lerp to prevent
    //    rapid direction flipping on low-speed frames where noise dominates.
    //    A minimum speed threshold of 1.0 cm/s suppresses direction updates
    //    when the limb is effectively stationary.
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
    // 3. LMA Space — Expansiveness
    // -----------------------------------------------------------------------

    const float DistL = FVector::Dist(Spine, LWrist);
    const float DistR = FVector::Dist(Spine, RWrist);
    CurrentExpansiveness = NormalizeAdaptive(
        FMath::Max(DistL, DistR),
        AdaptiveMin_Expansiveness, AdaptiveMax_Expansiveness);

    // -----------------------------------------------------------------------
    // 4. LMA Time — Effort (weighted aggregate velocity)
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
    // 5. LMA Weight — acceleration magnitude
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
    // 6. LMA Flow — rolling sigma of aggregate velocity delta magnitude
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
    // 7. Advance history state
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
    // 8. Write debug outputs
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

        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("EffortLevel"), CurrentEffort);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("ExpansivenessLevel"), CurrentExpansiveness);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("WeightLevel"), CurrentWeight);
        UKismetMaterialLibrary::SetScalarParameterValue(
            World, GlobalMPC, FName("FlowLevel"), CurrentFlow);

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
        ParticleSystem->SetFloatParameter(
            FName("User.EffortLevel"), CurrentEffort);
        ParticleSystem->SetFloatParameter(
            FName("User.FlowLevel"), CurrentFlow);
    }
}

// ---------------------------------------------------------------------------
// ExecuteKinematicPhysics
//
// Per-particle, per-limb independent force model.
//
// For each bubble particle, four limbs contribute independent force vectors:
//   Left wrist, Right wrist, Left elbow, Right elbow.
//
// A limb contributes force to a particle only when:
//   (a) The particle faces the limb's movement direction (positive dot product
//       between the particle's outward normal and the limb velocity direction).
//   (b) The limb is moving fast enough to be expressive (speed above threshold).
//
// The magnitude of each limb's contribution is scaled by:
//   - The limb's own speed (faster = stronger push)
//   - CurrentEffort (global urgency multiplier)
//   - CurrentWeight (acceleration-based force spike)
//   - Expansiveness (spatial reach scale)
//   - The dot product alignment (particles directly in line receive full force;
//     particles at glancing angles receive proportionally less)
//
// For pull movements (performer pulling arm backward), the velocity direction
// points away from the bubble surface on that side. The dot product with the
// outward normal becomes negative, so those particles receive no push from the
// repulsor. Instead, the attractor pulls them inward toward their home position
// (which is now closer than they were if they had previously been pushed out).
// This produces the "sucked inward" effect without requiring an explicit pull
// force — the attractor handles it naturally when the repulsor stops.
//
// Flow governs attractor strength: Bound movement (low Flow) pulls particles
// back tightly; Free movement (high Flow) weakens the attractor, allowing
// particles to drift and scatter after being pushed.
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::ExecuteKinematicPhysics()
{
    if (!TrackedSkeleton) return;

    const FVector PelvisLoc =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));

    // Limb descriptor array for the per-limb force loop.
    // Each entry: { velocity direction (normalised), speed scalar, joint weight }
    struct FLimbForceDescriptor
    {
        FVector  Dir;
        float    Speed;
        float    JointWeight;
    };

    const FLimbForceDescriptor Limbs[] =
    {
        { LWristVelocityDir, LWristSpeed, WEIGHT_WRIST },
        { RWristVelocityDir, RWristSpeed, WEIGHT_WRIST },
        { LElbowVelocityDir, LElbowSpeed, WEIGHT_ELBOW },
        { RElbowVelocityDir, RElbowSpeed, WEIGHT_ELBOW },
    };

    // Minimum limb speed below which no repulsor contribution is applied.
    // Prevents noise-level micro-movements from continuously jittering particles.
    static constexpr float MIN_LIMB_SPEED_THRESHOLD = 5.0f;

    // Expansiveness spatial reach scale: maps [0,1] to [0.5, 1.5]
    // so even at zero Expansiveness some force still reaches particles.
    const float ExpansivenessScale = 0.5f + CurrentExpansiveness;

    for (AActor* Cube : ARCubes)
    {
        if (!Cube) continue;

        UPrimitiveComponent* PrimComp =
            Cube->FindComponentByClass<UPrimitiveComponent>();

        if (!PrimComp || !PrimComp->IsSimulatingPhysics()) continue;

        const FVector CurrentLoc = Cube->GetActorLocation();
        const FVector CubeVelocity = PrimComp->GetComponentVelocity();

        // Outward normal of this particle relative to the performer's pelvis.
        // This is the direction from the body centre to the particle surface —
        // the direction a push "outward" from the body would travel.
        const FVector OutwardNormal =
            (CurrentLoc - PelvisLoc).GetSafeNormal();

        // Home position follows the performer's pelvis via the stored offset.
        const FVector HomeLoc = CubeHomeOffsets.Contains(Cube)
            ? (PelvisLoc + CubeHomeOffsets[Cube])
            : CurrentLoc;

        // -------------------------------------------------------------------
        // Attractor — pulls particle toward its pelvis-relative home.
        // Strength scales with (1 - Flow):
        //   Bound movement (low Flow)  → strong attractor → tight formation
        //   Free movement  (high Flow) → weak attractor  → loose, drifting
        // -------------------------------------------------------------------

        const FVector ToHome = HomeLoc - CurrentLoc;
        const FVector AttractorForce = ToHome
            * AttractorSpringConstant
            * (1.0f - CurrentFlow);

        // -------------------------------------------------------------------
        // Per-limb repulsor — accumulate independent contributions.
        // Each limb only pushes particles that face its movement direction.
        // -------------------------------------------------------------------

        FVector AccumulatedRepulsorForce = FVector::ZeroVector;

        for (const FLimbForceDescriptor& Limb : Limbs)
        {
            if (Limb.Speed < MIN_LIMB_SPEED_THRESHOLD) continue;

            // Dot product between the particle's outward normal and the limb's
            // velocity direction. Positive → particle faces the movement.
            // Zero or negative → particle is on the opposite side, receives no push.
            const float Alignment = FVector::DotProduct(OutwardNormal, Limb.Dir);
            if (Alignment <= 0.0f) continue;

            // Force magnitude for this limb's contribution:
            //   Speed          — how fast the limb is moving
            //   Alignment      — how directly the particle faces the movement
            //   Effort         — global urgency of movement (LMA Time)
            //   Weight         — acceleration spike (LMA Weight)
            //   JointWeight    — anatomical importance (wrist > elbow)
            //   ExpansivenessScale — spatial reach (LMA Space)
            const float LimbForceMag =
                Limb.Speed
                * Alignment
                * CurrentEffort
                * (0.5f + CurrentWeight * 0.5f)
                * Limb.JointWeight
                * ExpansivenessScale;

            // Force acts along the limb's velocity direction — the particle
            // moves in the same direction the limb is moving, not radially.
            // This means a forward thrust pushes particles forward, a lateral
            // sweep pushes particles sideways, etc.
            AccumulatedRepulsorForce += Limb.Dir * LimbForceMag;
        }

        const FVector RepulsorForce =
            AccumulatedRepulsorForce * RepulsorForceMultiplier;

        // -------------------------------------------------------------------
        // Drag — velocity-proportional damping.
        // Maximum drag at zero Effort (stillness freezes particles in place).
        // Minimum drag at high Effort (explosive movements allow free travel).
        // -------------------------------------------------------------------

        const FVector DragForce = -CubeVelocity
            * BaseDragCoefficient
            * (1.0f - CurrentEffort);

        // AccelChange = true → force applied as acceleration (mass-independent).
        PrimComp->AddForce(
            AttractorForce + RepulsorForce + DragForce,
            NAME_None,
            /*bAccelChange=*/ true);
    }
}

// ---------------------------------------------------------------------------
// RebuildHomeLocations
// ---------------------------------------------------------------------------

void UKinematicDescriptorComponent::RebuildHomeLocations()
{
    CubeHomeOffsets.Empty();

    if (!TrackedSkeleton)
    {
        UE_LOG(LogTemp, Warning,
            TEXT("UKinematicDescriptorComponent: RebuildHomeLocations called "
                "before TrackedSkeleton was assigned."));
        return;
    }

    const FVector PelvisNow =
        TrackedSkeleton->GetSocketLocation(FName("Hips"));

    for (AActor* Cube : ARCubes)
    {
        if (Cube)
        {
            CubeHomeOffsets.Add(Cube, Cube->GetActorLocation() - PelvisNow);
        }
    }

    UE_LOG(LogTemp, Log,
        TEXT("UKinematicDescriptorComponent: RebuildHomeLocations — "
            "%d cubes anchored. Pelvis at %.1f, %.1f, %.1f."),
        CubeHomeOffsets.Num(),
        PelvisNow.X, PelvisNow.Y, PelvisNow.Z);
}

// ---------------------------------------------------------------------------
// NormalizeAdaptive
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