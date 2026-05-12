// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "OWL360ResolutionSettings.generated.h"

USTRUCT(BlueprintType)
struct OWL360CAMERA_API FOWL360ResolutionSettings
{
	GENERATED_BODY()

	UPROPERTY()
	int X = 2160;

	UPROPERTY()
	int Y = 1080;

	UPROPERTY()
	float AspectRatio = 2;

	UPROPERTY()
	bool bIsCustomResolution = false;

public:
	FIntPoint ToIntPoint() const
	{
		return FIntPoint(bIsCustomResolution ? X : Y * AspectRatio, Y);
	};

	void Update()
	{
		if (!bIsCustomResolution)
		{
			X = Y * AspectRatio;
		}
	}

	void Set(FIntPoint InRes)
	{
		X = InRes.X;
		Y = InRes.Y;
		bIsCustomResolution = true;
	}
};


