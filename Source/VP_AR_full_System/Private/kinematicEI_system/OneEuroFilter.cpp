#include "kinematicEI_system/OneEuroFilter.h"
#include "Math/UnrealMathUtility.h"

FOneEuroFilterVector::FOneEuroFilterVector()
    : MinCutoff(1.0f)
    , Beta(0.05f)
    , DCutoff(1.0f)
    , PrevX(FVector::ZeroVector)
    , PrevDX(FVector::ZeroVector)
    , bIsInitialized(false)
{
}

FOneEuroFilterVector::FOneEuroFilterVector(float InMinCutoff, float InBeta, float InDCutoff)
    : MinCutoff(InMinCutoff)
    , Beta(InBeta)
    , DCutoff(InDCutoff)
    , PrevX(FVector::ZeroVector)
    , PrevDX(FVector::ZeroVector)
    , bIsInitialized(false)
{
}

float FOneEuroFilterVector::CalculateAlpha(float DeltaTime, float Cutoff) const
{
    float R = 2.0f * PI * Cutoff * DeltaTime;
    return R / (R + 1.0f);
}

FVector FOneEuroFilterVector::Filter(float DeltaTime, const FVector& X)
{
    // 1. Guard clause: Handle occlusion drops (NaN) without corrupting the state memory
    if (X.ContainsNaN())
    {
        return FVector(NAN, NAN, NAN);
    }

    // 2. State Initialization / Recovery
    if (!bIsInitialized || PrevX.ContainsNaN())
    {
        PrevX = X;
        PrevDX = FVector::ZeroVector;
        bIsInitialized = true;
        return X;
    }

    if (DeltaTime <= 0.0f)
    {
        return X;
    }

    // 3. Filter the derivative (velocity magnitude extraction)
    float AlphaD = CalculateAlpha(DeltaTime, DCutoff);
    FVector DX = (X - PrevX) / DeltaTime;
    FVector DXHat = (DX * AlphaD) + (PrevDX * (1.0f - AlphaD));

    // 4. Estimate adaptive cutoff frequency based on velocity magnitude
    float Cutoff = MinCutoff + (Beta * DXHat.Size());

    // 5. Filter the primary spatial signal
    float Alpha = CalculateAlpha(DeltaTime, Cutoff);
    FVector XHat = (X * Alpha) + (PrevX * (1.0f - Alpha));

    // 6. Update states
    PrevX = XHat;
    PrevDX = DXHat;

    return XHat;
}