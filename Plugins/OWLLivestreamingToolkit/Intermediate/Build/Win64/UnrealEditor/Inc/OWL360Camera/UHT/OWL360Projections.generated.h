// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataTypes/OWL360Projections.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OWL360CAMERA_OWL360Projections_generated_h
#error "OWL360Projections.generated.h already included, missing '#pragma once' in OWL360Projections.h"
#endif
#define OWL360CAMERA_OWL360Projections_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWL360Projections_h


#define FOREACH_ENUM_E360PROJECTIONTYPE(op) \
	op(E360ProjectionType::CT_CubeMap) \
	op(E360ProjectionType::CT_DomeMaster) \
	op(E360ProjectionType::CT_EquiRectangular) \
	op(E360ProjectionType::CT_Mono180) \
	op(E360ProjectionType::CT_StereoEquiRectangular) \
	op(E360ProjectionType::CT_StereoVR180) \
	op(E360ProjectionType::CT_Stereographic) 

enum class E360ProjectionType : uint8;
template<> struct TIsUEnumClass<E360ProjectionType> { enum { Value = true }; };
template<> OWL360CAMERA_API UEnum* StaticEnum<E360ProjectionType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
