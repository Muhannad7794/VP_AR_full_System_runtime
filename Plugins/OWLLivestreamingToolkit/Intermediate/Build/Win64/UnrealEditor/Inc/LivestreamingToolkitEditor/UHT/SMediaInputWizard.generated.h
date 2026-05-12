// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SMediaInputWizard.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIVESTREAMINGTOOLKITEDITOR_SMediaInputWizard_generated_h
#error "SMediaInputWizard.generated.h already included, missing '#pragma once' in SMediaInputWizard.h"
#endif
#define LIVESTREAMINGTOOLKITEDITOR_SMediaInputWizard_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaInputWizard_h


#define FOREACH_ENUM_EMEDIAINPUTLOCATION(op) \
	op(EMediaInputLocation::ML_MediaPlate) \
	op(EMediaInputLocation::ML_Material) \
	op(EMediaInputLocation::ML_Plane) 

enum class EMediaInputLocation : uint8;
template<> struct TIsUEnumClass<EMediaInputLocation> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITEDITOR_API UEnum* StaticEnum<EMediaInputLocation>();

#define FOREACH_ENUM_EMEDIAINPUTTYPE(op) \
	op(EMediaInputType::MT_Spout) \
	op(EMediaInputType::MT_NDI) \
	op(EMediaInputType::MT_MonitorCapture) \
	op(EMediaInputType::MT_WindowCapture) \
	op(EMediaInputType::MT_MediaSource) 

enum class EMediaInputType : uint8;
template<> struct TIsUEnumClass<EMediaInputType> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITEDITOR_API UEnum* StaticEnum<EMediaInputType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
