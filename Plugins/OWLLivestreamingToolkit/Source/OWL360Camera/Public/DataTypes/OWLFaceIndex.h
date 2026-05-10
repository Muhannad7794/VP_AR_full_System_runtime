// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "OWLFaceIndex.generated.h"

UENUM(BlueprintType)
enum class EOWL360FaceIndex : uint8
{
	Right = 0 UMETA(DisplayName = "Right Face"),
	Left = 1 UMETA(DisplayName = "Left Face"),
	Up = 2 UMETA(DisplayName = "Up Face"),
	Down = 3 UMETA(DisplayName = "Down Face"),
	Front = 4 UMETA(DisplayName = "Front Face"),
	Back = 5 UMETA(DisplayName = "Back Face"),
};


