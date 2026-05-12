// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "DataTypes/OWLFaceBool.h"
#include "OWL360FaceRendering.generated.h"

USTRUCT(BlueprintType)
struct FOWL360FaceRenderingSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faces")
	bool Front = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faces")
	bool Back = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faces")
	bool Left = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faces")
	bool Right = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faces")
	bool Top = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faces")
	bool Bottom = true;

	FOWLFaceBool ToFaceBool() const
	{
		FOWLFaceBool Out;
		Out[EOWL360FaceIndex::Front] = Front;
		Out[EOWL360FaceIndex::Back] = Back;
		Out[EOWL360FaceIndex::Left] = Left;
		Out[EOWL360FaceIndex::Right] = Right;
		Out[EOWL360FaceIndex::Up] = Top;
		Out[EOWL360FaceIndex::Down] = Bottom;
		return Out;
	}
};



