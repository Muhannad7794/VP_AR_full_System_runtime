// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OWLStereoRenderingTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIVESTREAMINGTOOLKITSHADERS_OWLStereoRenderingTypes_generated_h
#error "OWLStereoRenderingTypes.generated.h already included, missing '#pragma once' in OWLStereoRenderingTypes.h"
#endif
#define LIVESTREAMINGTOOLKITSHADERS_OWLStereoRenderingTypes_generated_h

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_47_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics; \
	LIVESTREAMINGTOOLKITSHADERS_API static class UScriptStruct* StaticStruct();


template<> LIVESTREAMINGTOOLKITSHADERS_API UScriptStruct* StaticStruct<struct FOWLStereoRenderingConfig>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h


#define FOREACH_ENUM_EOWLSTEREOOUTPUTVIEWMODE(op) \
	op(EOWLStereoOutputViewMode::SOVM_TopBottom) \
	op(EOWLStereoOutputViewMode::SOVM_SideBySide) \
	op(EOWLStereoOutputViewMode::SOVM_Anaglyph) \
	op(EOWLStereoOutputViewMode::SOVM_Interlace) 

enum class EOWLStereoOutputViewMode : uint8;
template<> struct TIsUEnumClass<EOWLStereoOutputViewMode> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLStereoOutputViewMode>();

#define FOREACH_ENUM_EOWLINTERLACETYPE(op) \
	op(EOWLInterlaceType::IT_Row) \
	op(EOWLInterlaceType::IT_Column) \
	op(EOWLInterlaceType::IT_Checkerboard) 

enum class EOWLInterlaceType : uint8;
template<> struct TIsUEnumClass<EOWLInterlaceType> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLInterlaceType>();

#define FOREACH_ENUM_EOWLANAGLYPHTYPE(op) \
	op(EOWLAnaglyphType::AT_RedCyan) \
	op(EOWLAnaglyphType::AT_GreenMagenta) \
	op(EOWLAnaglyphType::AT_YellowBlue) 

enum class EOWLAnaglyphType : uint8;
template<> struct TIsUEnumClass<EOWLAnaglyphType> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLAnaglyphType>();

#define FOREACH_ENUM_EOWLSTEREOUMGMODE(op) \
	op(EOWLStereoUMGMode::SUMG_BothEyes) \
	op(EOWLStereoUMGMode::SUMG_LeftEyeOnly) \
	op(EOWLStereoUMGMode::SUMG_RightEyeOnly) \
	op(EOWLStereoUMGMode::SUMG_Disabled) 

enum class EOWLStereoUMGMode : uint8;
template<> struct TIsUEnumClass<EOWLStereoUMGMode> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLStereoUMGMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
