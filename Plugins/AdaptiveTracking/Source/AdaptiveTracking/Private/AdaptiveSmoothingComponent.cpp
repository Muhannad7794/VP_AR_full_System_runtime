#include "AdaptiveSmoothingComponent.h"
#include "Kismet/KismetMathLibrary.h"


// ---------------------------------------------------------------------------
// Internal math helpers — file scope, not exported
// ---------------------------------------------------------------------------

// Compute the EMA alpha coefficient for a given time step and cutoff frequency.
//
// Derived from matching the discrete exponential moving average transfer
// function to an analogue RC low-pass filter with time constant:
//   tau = 1 / (2 * pi * CutoffHz)
//
// The resulting relationship is:
//   r     = 2 * pi * CutoffHz * DeltaTime
//   alpha = r / (r + 1)
//
// At CutoffHz -> 0: alpha -> 0 (output barely moves, maximum smoothing).
// At CutoffHz -> inf: alpha -> 1 (output equals input, no smoothing).
static float OneEuroAlpha(float DeltaTime, float CutoffHz)
{
    const float r = 2.0f * PI * CutoffHz * DeltaTime;
    return r / (r + 1.0f);
}


// ---------------------------------------------------------------------------
// Constructor
// ---------------------------------------------------------------------------

UAdaptiveSmoothingComponent::UAdaptiveSmoothingComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    LinearConfig.SetNum(6);
    SigmoidConfig.SetNum(6);
    PiecewiseConfig.SetNum(6);
    OneEuroConfig.SetNum(6);
    OneEuroState.SetNum(6);
}


// ---------------------------------------------------------------------------
// Initialisation helpers
// ---------------------------------------------------------------------------

void UAdaptiveSmoothingComponent::InitializeBuffers()
{
    AccelerationBuffers.Empty();
    for (int32 i = 0; i < 6; i++)
    {
        AccelerationBuffers.Add(TArray<float>());
        AccelerationBuffers[i].Reserve(WindowSize + 5);
    }

    // Reset One Euro filter state so that switching models or restarting
    // the component re-initialises the filter from the next raw sample.
    for (FOneEuroAxisState& State : OneEuroState)
    {
        State.FilteredValue = 0.0f;
        State.FilteredDerivative = 0.0f;
        State.bInitialized = false;
    }

    bIsInitialized = true;
}

void UAdaptiveSmoothingComponent::SetupMaterial()
{
    if (CalibrationObject)
    {
        DynamicMaterial = CalibrationObject->CreateAndSetMaterialInstanceDynamic(0);
    }
}


// ---------------------------------------------------------------------------
// Main interface
// ---------------------------------------------------------------------------

void UAdaptiveSmoothingComponent::GetSmoothedTransform(
    float DeltaTime,
    FVector RawLocation,
    FRotator RawRotation,
    FVector& OutSmoothedLoc,
    FRotator& OutSmoothedRot)
{
    // 1. Initialise buffers on first call.
    if (!bIsInitialized)
        InitializeBuffers();

    // First-frame snap: output the raw transform directly and prime the
    // kinematics history used by the sigma models.
    if (bFirstFrame)
    {
        InternalSmoothedLoc = RawLocation;
        InternalSmoothedRot = RawRotation;
        PrevLocation = RawLocation;
        PrevRotation = RawRotation;
        bFirstFrame = false;
    }

    // Guard against zero or negative DeltaTime (can occur during nDisplay
    // sync frames or before the first real tick).
    if (DeltaTime <= 0.0001f)
    {
        OutSmoothedLoc = InternalSmoothedLoc;
        OutSmoothedRot = InternalSmoothedRot;
        return;
    }

    // -----------------------------------------------------------------------
    // 2. MODEL: NO SMOOTHING — bypass all filtering and reset kinematics
    //    history so there are no stale values when switching back to a
    //    smoothing model.
    // -----------------------------------------------------------------------

    if (CurrentModel == EAdaptiveModel::NoSmoothing)
    {
        InternalSmoothedLoc = RawLocation;
        InternalSmoothedRot = RawRotation;

        PrevLocation = RawLocation;
        PrevRotation = RawRotation;
        PrevLinearVelocity = FVector::ZeroVector;
        PrevAngularVelocity = FVector::ZeroVector;

        OutSmoothedLoc = RawLocation;
        OutSmoothedRot = RawRotation;
        return;
    }

    // -----------------------------------------------------------------------
    // 3. MODEL: ONE EURO FILTER — velocity-adaptive first-order low-pass.
    //
    //    This path is entirely independent of the sigma model infrastructure.
    //    It does not use the acceleration buffer, rolling sigma, ClampedDT,
    //    or FInterpTo. It uses real DeltaTime directly in the EMA alpha
    //    computation, which is required for the cutoff frequency relationship
    //    to hold correctly. The kinematics history used by the sigma models
    //    is not updated on this path.
    // -----------------------------------------------------------------------

    if (CurrentModel == EAdaptiveModel::OneEuro)
    {
        ApplyOneEuroFilter(DeltaTime, RawLocation, RawRotation);
        OutSmoothedLoc = InternalSmoothedLoc;
        OutSmoothedRot = InternalSmoothedRot;
        return;
    }

    // -----------------------------------------------------------------------
    // 4. SIGMA MODEL PATHS (Linear, Piecewise, Sigmoid)
    //
    //    ClampedDT is used for kinematics to prevent a rendering lag spike
    //    from producing a near-zero acceleration reading, which would cause
    //    the sigma buffer to report false stability. Real DeltaTime is still
    //    used for the FInterpTo smoothing step.
    // -----------------------------------------------------------------------

    const float TargetDT = 1.0f / TargetCameraFPS;
    const float ClampedDT = FMath::Min(DeltaTime, TargetDT);

    // Compute linear and angular velocity and acceleration.
    FVector CurrVel = (RawLocation - PrevLocation) / ClampedDT;
    FVector CurrAccel = (CurrVel - PrevLinearVelocity) / ClampedDT;
    PrevLocation = RawLocation;
    PrevLinearVelocity = CurrVel;

    FRotator DeltaRot = (RawRotation - PrevRotation).GetNormalized();
    FVector  CurrAngVel;
    CurrAngVel.X = DeltaRot.Roll / ClampedDT;
    CurrAngVel.Y = DeltaRot.Pitch / ClampedDT;
    CurrAngVel.Z = DeltaRot.Yaw / ClampedDT;
    FVector CurrAngAccel = (CurrAngVel - PrevAngularVelocity) / ClampedDT;
    PrevRotation = RawRotation;
    PrevAngularVelocity = CurrAngVel;

    // Flat array of accelerations in axis order:
    //   [0] X_pose  [1] Y_pose  [2] Z_pose
    //   [3] X_rot   [4] Y_rot   [5] Z_rot
    float Accels[6] = {
        (float)CurrAccel.X,    (float)CurrAccel.Y,    (float)CurrAccel.Z,
        (float)CurrAngAccel.X, (float)CurrAngAccel.Y, (float)CurrAngAccel.Z
    };
    float Speeds[6];
    float TotalSigma = 0.0f;

    for (int32 i = 0; i < 6; i++)
    {
        float Sigma = CalculateSigma(i, Accels[i]);

        // Accumulate positional sigma for the shader visualisation.
        if (i < 3)
            TotalSigma += Sigma;

        switch (CurrentModel)
        {
        case EAdaptiveModel::Linear:
            Speeds[i] = GetSpeed_Linear(i, Sigma);
            break;
        case EAdaptiveModel::Sigmoid:
            Speeds[i] = GetSpeed_Sigmoid(i, Sigma);
            break;
        case EAdaptiveModel::Piecewise:
            Speeds[i] = GetSpeed_Piecewise(i, Sigma);
            break;
        default:
            Speeds[i] = 20.0f;
        }
    }

    // Apply FInterpTo smoothing using real DeltaTime.
    InternalSmoothedLoc.X = FMath::FInterpTo(InternalSmoothedLoc.X, RawLocation.X, DeltaTime, Speeds[0]);
    InternalSmoothedLoc.Y = FMath::FInterpTo(InternalSmoothedLoc.Y, RawLocation.Y, DeltaTime, Speeds[1]);
    InternalSmoothedLoc.Z = FMath::FInterpTo(InternalSmoothedLoc.Z, RawLocation.Z, DeltaTime, Speeds[2]);

    float NewRoll = FMath::FInterpTo(InternalSmoothedRot.Roll, RawRotation.Roll, DeltaTime, Speeds[3]);
    float NewPitch = FMath::FInterpTo(InternalSmoothedRot.Pitch, RawRotation.Pitch, DeltaTime, Speeds[4]);
    float NewYaw = FMath::FInterpTo(InternalSmoothedRot.Yaw, RawRotation.Yaw, DeltaTime, Speeds[5]);
    InternalSmoothedRot = FRotator(NewPitch, NewYaw, NewRoll);

    OutSmoothedLoc = InternalSmoothedLoc;
    OutSmoothedRot = InternalSmoothedRot;

    // Update the shader material with average positional instability.
    if (DynamicMaterial)
    {
        float AvgSigma = TotalSigma / 3.0f;
        DynamicMaterial->SetScalarParameterValue(TEXT("CameraInstability"), AvgSigma);
    }
}


// ---------------------------------------------------------------------------
// One Euro filter implementation
// ---------------------------------------------------------------------------

void UAdaptiveSmoothingComponent::ApplyOneEuroFilter(
    float DeltaTime,
    FVector RawLocation,
    FRotator RawRotation)
{
    // Raw values in the canonical axis order used throughout this component:
    //   [0] X_pose  [1] Y_pose  [2] Z_pose
    //   [3] X_rot (Roll)  [4] Y_rot (Pitch)  [5] Z_rot (Yaw)
    const float RawValues[6] = {
        (float)RawLocation.X,
        (float)RawLocation.Y,
        (float)RawLocation.Z,
        (float)RawRotation.Roll,
        (float)RawRotation.Pitch,
        (float)RawRotation.Yaw
    };

    float FilteredValues[6];

    for (int32 i = 0; i < 6; i++)
    {
        if (!OneEuroConfig.IsValidIndex(i) || !OneEuroState.IsValidIndex(i))
        {
            FilteredValues[i] = RawValues[i];
            continue;
        }

        const FOneEuroAxisConfig& Cfg = OneEuroConfig[i];
        FOneEuroAxisState& State = OneEuroState[i];
        const bool bIsRotation = (i >= 3);
        const float RawIn = RawValues[i];

        // First valid sample: initialise filter state and pass through raw.
        if (!State.bInitialized)
        {
            State.FilteredValue = RawIn;
            State.FilteredDerivative = 0.0f;
            State.bInitialized = true;
            FilteredValues[i] = RawIn;
            continue;
        }

        // -----------------------------------------------------------------
        // Rotation unwrapping
        //
        // Euler angles are cyclic: a camera at 179 deg that rotates 4 deg
        // further produces a raw jump from 179 to -177 deg. Without
        // correction, the backward-difference derivative reads -356 deg/s,
        // which incorrectly opens the adaptive cutoff.
        //
        // FMath::FindDeltaAngleDegrees(A, B) returns the shortest-path
        // angular delta from A to B in (-180, 180], handling the case
        // where A is in the continuous unwrapped domain correctly.
        // Adding that delta to State.FilteredValue keeps the filter
        // operating on a continuous signal.
        // -----------------------------------------------------------------

        float InputValue;
        if (bIsRotation)
        {
            const float ShortestDelta = FMath::FindDeltaAngleDegrees(State.FilteredValue, RawIn);
            InputValue = State.FilteredValue + ShortestDelta;
        }
        else
        {
            InputValue = RawIn;
        }

        // -----------------------------------------------------------------
        // Causal backward-difference derivative
        //
        // The derivative is computed from the filtered previous value, not
        // the raw previous value. This reduces noise in the velocity
        // estimate, which in turn reduces noise in the adaptive cutoff.
        // This matches the Python offline implementation exactly.
        // -----------------------------------------------------------------

        const float DxRaw = (InputValue - State.FilteredValue) / DeltaTime;

        // Smooth the derivative with a fixed-cutoff EMA.
        const float AlphaD = OneEuroAlpha(DeltaTime, Cfg.DCutoff);
        State.FilteredDerivative = AlphaD * DxRaw + (1.0f - AlphaD) * State.FilteredDerivative;

        // Adaptive cutoff: rises linearly with the smoothed derivative magnitude.
        const float Fc = Cfg.FcMin + Cfg.Beta * FMath::Abs(State.FilteredDerivative);
        const float Alpha = OneEuroAlpha(DeltaTime, Fc);

        // Filter the primary signal. State.FilteredValue stays in the
        // continuous (unwrapped) domain for rotation axes.
        State.FilteredValue = Alpha * InputValue + (1.0f - Alpha) * State.FilteredValue;

        // Wrap rotation output back to (-180, 180] for use downstream.
        if (bIsRotation)
        {
            FilteredValues[i] = FMath::UnwindDegrees(State.FilteredValue);
        }
        else
        {
            FilteredValues[i] = State.FilteredValue;
        }
    }

    // Write filtered values to shared output memory.
    InternalSmoothedLoc.X = FilteredValues[0];
    InternalSmoothedLoc.Y = FilteredValues[1];
    InternalSmoothedLoc.Z = FilteredValues[2];

    // FRotator constructor: FRotator(Pitch, Yaw, Roll)
    InternalSmoothedRot = FRotator(
        FilteredValues[4],  // Pitch (Y_rot)
        FilteredValues[5],  // Yaw   (Z_rot)
        FilteredValues[3]   // Roll  (X_rot)
    );
}


// ---------------------------------------------------------------------------
// Sigma model helpers — unchanged
// ---------------------------------------------------------------------------

float UAdaptiveSmoothingComponent::CalculateSigma(int32 AxisIndex, float CurrentAccel)
{
    if (!AccelerationBuffers.IsValidIndex(AxisIndex))
        return 0.0f;

    TArray<float>& Buffer = AccelerationBuffers[AxisIndex];
    Buffer.Add(CurrentAccel);

    if (Buffer.Num() > WindowSize)
        Buffer.RemoveAt(0);

    // Warm-up: require at least half the window before reporting sigma.
    // Mirrors the Python pipeline's min_periods = window // 2.
    const int32 MinSamples = FMath::Max(1, WindowSize / 2);
    if (Buffer.Num() < MinSamples)
        return 0.0f;

    float Sum = 0.0f;
    for (float Val : Buffer) Sum += Val;
    const float Mean = Sum / Buffer.Num();

    float SumSqDiff = 0.0f;
    for (float Val : Buffer) SumSqDiff += FMath::Square(Val - Mean);

    return FMath::Sqrt(SumSqDiff / Buffer.Num());
}

float UAdaptiveSmoothingComponent::GetSpeed_Linear(int32 AxisIndex, float Sigma)
{
    if (!LinearConfig.IsValidIndex(AxisIndex))
        return 10.0f;
    const FLinearAxisConfig& Cfg = LinearConfig[AxisIndex];
    return FMath::GetMappedRangeValueClamped(
        FVector2D(Cfg.MinSigma, Cfg.MaxSigma),
        FVector2D(Cfg.MaxSpeed, Cfg.MinSpeed),
        Sigma);
}

float UAdaptiveSmoothingComponent::GetSpeed_Sigmoid(int32 AxisIndex, float Sigma)
{
    if (!SigmoidConfig.IsValidIndex(AxisIndex))
        return 10.0f;
    const FSigmoidAxisConfig& Cfg = SigmoidConfig[AxisIndex];
    const float Logistic = 1.0f / (1.0f + FMath::Exp(-Cfg.Steepness * (Sigma - Cfg.Midpoint)));
    return Cfg.MinSpeed + (Cfg.MaxSpeed - Cfg.MinSpeed) * (1.0f - Logistic);
}

float UAdaptiveSmoothingComponent::GetSpeed_Piecewise(int32 AxisIndex, float Sigma)
{
    if (!PiecewiseConfig.IsValidIndex(AxisIndex))
        return 10.0f;
    const FPiecewiseAxisConfig& Cfg = PiecewiseConfig[AxisIndex];

    if (Cfg.SigmaBreaks.Num() == 0 || Cfg.SigmaBreaks.Num() != Cfg.SpeedLevels.Num())
        return 10.0f;

    if (Sigma <= Cfg.SigmaBreaks[0])    return Cfg.SpeedLevels[0];
    if (Sigma >= Cfg.SigmaBreaks.Last()) return Cfg.SpeedLevels.Last();

    for (int32 i = 0; i < Cfg.SigmaBreaks.Num() - 1; i++)
    {
        const float B0 = Cfg.SigmaBreaks[i];
        const float B1 = Cfg.SigmaBreaks[i + 1];
        if (Sigma >= B0 && Sigma <= B1)
        {
            const float Alpha = (Sigma - B0) / (B1 - B0);
            return FMath::Lerp(Cfg.SpeedLevels[i], Cfg.SpeedLevels[i + 1], Alpha);
        }
    }
    return Cfg.SpeedLevels.Last();
}