// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DataTypes/OWLFaceIndex.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OWL360CAMERA_OWLFaceIndex_generated_h
#error "OWLFaceIndex.generated.h already included, missing '#pragma once' in OWLFaceIndex.h"
#endif
#define OWL360CAMERA_OWLFaceIndex_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceIndex_h


#define FOREACH_ENUM_EOWL360FACEINDEX(op) \
	op(EOWL360FaceIndex::Right) \
	op(EOWL360FaceIndex::Left) \
	op(EOWL360FaceIndex::Up) \
	op(EOWL360FaceIndex::Down) \
	op(EOWL360FaceIndex::Front) \
	op(EOWL360FaceIndex::Back) 

enum class EOWL360FaceIndex : uint8;
template<> struct TIsUEnumClass<EOWL360FaceIndex> { enum { Value = true }; };
template<> OWL360CAMERA_API UEnum* StaticEnum<EOWL360FaceIndex>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
