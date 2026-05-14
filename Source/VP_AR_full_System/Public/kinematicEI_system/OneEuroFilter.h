/**
 * Struct: FOneEuroFilterVector
 * Purpose: A first-order low-pass filter with an adaptive cutoff frequency.
 * Optimized for 3D coordinate processing (FVector) in real-time interactive systems.
 * Designed to attenuate high-frequency sensor noise at low velocities while
 * preserving signal integrity during rapid ballistic movements.
 */

#pragma once

#include "CoreMinimal.h"
#include "OneEuroFilter.generated.h"

USTRUCT(BlueprintType)
struct VP_AR_FULL_SYSTEM_API FOneEuroFilterVector
{
    GENERATED_BODY()

public:
    // Minimum cutoff frequency (Hz) to eliminate idle positional noise
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinematics|Filtering")
    float MinCutoff;

    // Speed coefficient to dynamically scale the cutoff during rapid movement
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinematics|Filtering")
    float Beta;

    // Cutoff frequency for the derivative (velocity) filter
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kinematics|Filtering")
    float DCutoff;

    FOneEuroFilterVector();
    FOneEuroFilterVector(float InMinCutoff, float InBeta, float InDCutoff = 1.0f);

    /**
     * Applies the adaptive low-pass filter to the incoming 3D coordinate.
     * Includes guard clauses for NaN values to maintain state integrity during tracking loss.
     * @param DeltaTime The time elapsed since the last frame (seconds).
     * @param X The raw 3D coordinate from the kinematic sensor.
     * @return The smoothed 3D coordinate.
     */
    FVector Filter(float DeltaTime, const FVector& X);

private:
    FVector PrevX;
    FVector PrevDX;
    bool bIsInitialized;

    float CalculateAlpha(float DeltaTime, float Cutoff) const;
};