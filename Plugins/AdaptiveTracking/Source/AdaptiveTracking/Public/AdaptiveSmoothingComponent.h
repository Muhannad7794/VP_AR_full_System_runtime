#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
// CRITICAL: This include MUST be the last one in the list.
#include "AdaptiveSmoothingComponent.generated.h"


// ---------------------------------------------------------------------------
// 1. Model type enum
// ---------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EAdaptiveModel : uint8
{
    NoSmoothing UMETA(DisplayName = "No Smoothing (Raw)"),
    Linear      UMETA(DisplayName = "Linear"),
    Piecewise   UMETA(DisplayName = "Piecewise"),
    Sigmoid     UMETA(DisplayName = "Sigmoid"),
    OneEuro     UMETA(DisplayName = "One Euro Filter")
};


// ---------------------------------------------------------------------------
// 2. Configuration structs — one per model
// ---------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct FLinearAxisConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = "Config")
    float MinSigma = 0.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float MaxSigma = 100.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float MinSpeed = 3.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float MaxSpeed = 20.0f;
};

USTRUCT(BlueprintType)
struct FSigmoidAxisConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = "Config")
    float MinSigma = 0.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float MaxSigma = 100.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float MinSpeed = 3.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float MaxSpeed = 20.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float Midpoint = 50.0f;

    UPROPERTY(EditAnywhere, Category = "Config")
    float Steepness = 0.1f;
};

USTRUCT(BlueprintType)
struct FPiecewiseAxisConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = "Config")
    TArray<float> SigmaBreaks;

    UPROPERTY(EditAnywhere, Category = "Config")
    TArray<float> SpeedLevels;
};

USTRUCT(BlueprintType)
struct FOneEuroAxisConfig
{
    GENERATED_BODY()

    // Minimum cutoff frequency in Hz. Controls smoothing depth when the
    // signal is at rest. Lower values suppress more jitter but increase
    // lag on slow motion. Tuned offline against stable-scenario velocity
    // distributions.
    UPROPERTY(EditAnywhere, Category = "Config")
    float FcMin = 0.5f;

    // Speed coefficient. Scales the adaptive cutoff rise with signal
    // velocity. Higher values make the filter more transparent during
    // fast motion. Tuned offline against fast-scenario velocity distributions.
    UPROPERTY(EditAnywhere, Category = "Config")
    float Beta = 0.05f;

    // Cutoff frequency for the derivative smoother in Hz. Rarely requires
    // adjustment from the default validated offline value.
    UPROPERTY(EditAnywhere, Category = "Config")
    float DCutoff = 1.0f;
};


// ---------------------------------------------------------------------------
// 3. Component class declaration
// ---------------------------------------------------------------------------

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ADAPTIVETRACKING_API UAdaptiveSmoothingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAdaptiveSmoothingComponent();

    // -----------------------------------------------------------------------
    // Main interface
    // -----------------------------------------------------------------------

    UFUNCTION(BlueprintCallable, Category = "Adaptive Smoothing")
    void GetSmoothedTransform(
        float DeltaTime,
        FVector RawLocation,
        FRotator RawRotation,
        FVector& OutSmoothedLoc,
        FRotator& OutSmoothedRot);

    // -----------------------------------------------------------------------
    // Runtime controls
    // -----------------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Smoothing Control")
    EAdaptiveModel CurrentModel = EAdaptiveModel::NoSmoothing;

    // -----------------------------------------------------------------------
    // Configuration — sigma models
    // -----------------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | General")
    int32 WindowSize = 25;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Sensor")
    float TargetCameraFPS = 25.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Linear")
    TArray<FLinearAxisConfig> LinearConfig;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Sigmoid")
    TArray<FSigmoidAxisConfig> SigmoidConfig;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | Piecewise")
    TArray<FPiecewiseAxisConfig> PiecewiseConfig;

    // -----------------------------------------------------------------------
    // Configuration — One Euro filter
    // Six elements, one per axis in the order:
    //   [0] X_pose  [1] Y_pose  [2] Z_pose
    //   [3] X_rot   [4] Y_rot   [5] Z_rot
    // Values are taken directly from one_euro_params.json produced by the
    // offline pipeline.
    // -----------------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config | One Euro")
    TArray<FOneEuroAxisConfig> OneEuroConfig;

    // -----------------------------------------------------------------------
    // Shader visualisation reference
    // -----------------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visualization")
    UStaticMeshComponent* CalibrationObject;

    UPROPERTY()
    UMaterialInstanceDynamic* DynamicMaterial;

private:

    // -----------------------------------------------------------------------
    // Sigma model internal state
    // -----------------------------------------------------------------------

    TArray<TArray<float>> AccelerationBuffers;

    // -----------------------------------------------------------------------
    // Shared output memory — written by all model paths
    // -----------------------------------------------------------------------

    FVector   InternalSmoothedLoc;
    FRotator  InternalSmoothedRot;
    bool      bFirstFrame = true;
    bool      bIsInitialized = false;

    // -----------------------------------------------------------------------
    // Kinematics history — used by sigma models only
    // -----------------------------------------------------------------------

    FVector  PrevLocation;
    FVector  PrevLinearVelocity;
    FRotator PrevRotation;
    FVector  PrevAngularVelocity;

    // -----------------------------------------------------------------------
    // One Euro filter per-axis state
    //
    // This is a plain C++ struct (not USTRUCT) because it is internal filter
    // state that never needs to be exposed to Blueprint or serialised.
    //
    // FilteredValue stores the previous filter output in the continuous
    // (unwrapped) domain for rotation axes, so that the derivative estimate
    // is not corrupted by Euler-angle boundary crossings. The wrapped value
    // is computed at output time only.
    // -----------------------------------------------------------------------

    struct FOneEuroAxisState
    {
        float FilteredValue = 0.0f;
        float FilteredDerivative = 0.0f;
        bool  bInitialized = false;
    };

    TArray<FOneEuroAxisState> OneEuroState;

    // -----------------------------------------------------------------------
    // Private helpers — sigma models
    // -----------------------------------------------------------------------

    float CalculateSigma(int32 AxisIndex, float CurrentAccel);
    float GetSpeed_Linear(int32 AxisIndex, float Sigma);
    float GetSpeed_Sigmoid(int32 AxisIndex, float Sigma);
    float GetSpeed_Piecewise(int32 AxisIndex, float Sigma);

    // -----------------------------------------------------------------------
    // Private helpers — One Euro filter
    // -----------------------------------------------------------------------

    // Applies the One Euro filter to all six axes in a single pass and
    // writes the results to InternalSmoothedLoc and InternalSmoothedRot.
    void ApplyOneEuroFilter(float DeltaTime, FVector RawLocation, FRotator RawRotation);

    // -----------------------------------------------------------------------
    // Initialisation
    // -----------------------------------------------------------------------

    void InitializeBuffers();
    void SetupMaterial();
};