// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "OWL360Projections.generated.h"

// Type of texture output from the 360 cam
UENUM(BlueprintType)
enum class E360ProjectionType : uint8 {
	CT_CubeMap UMETA(DisplayName = "Cubemap"),
	CT_DomeMaster UMETA(DisplayName = "DomeMaster"),
	CT_EquiRectangular UMETA(DisplayName = "Equirectangular"),
	CT_Mono180 UMETA(DisplayName = "180 Equirectangular"),
	CT_StereoEquiRectangular UMETA(DisplayName = "VR360 Stereo Equirectangular [experimental]"),
	CT_StereoVR180 UMETA(DisplayName = "VR180 Stereo Equirectangular"),
	CT_Stereographic UMETA(DisplayName = "Stereographic (Tiny Planet)"),
};


