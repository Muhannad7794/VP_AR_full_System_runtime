// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OWL360Camera/OWL360PipelineSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OWLMRQPIPELINE_OWL360PipelineSettings_generated_h
#error "OWL360PipelineSettings.generated.h already included, missing '#pragma once' in OWL360PipelineSettings.h"
#endif
#define OWLMRQPIPELINE_OWL360PipelineSettings_generated_h

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_45_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics; \
	OWLMRQPIPELINE_API static class UScriptStruct* StaticStruct();


template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<struct FOWL360TilingSettings>();

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_72_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics; \
	OWLMRQPIPELINE_API static class UScriptStruct* StaticStruct();


template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<struct FOWL360OutputSettings>();

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_139_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics; \
	OWLMRQPIPELINE_API static class UScriptStruct* StaticStruct();


template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<struct FOWL360OptimisationSettings>();

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_166_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics; \
	OWLMRQPIPELINE_API static class UScriptStruct* StaticStruct();


template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<struct FOWL360RenderingSettings>();

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_197_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics; \
	OWLMRQPIPELINE_API static class UScriptStruct* StaticStruct();


template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<struct FOWL360PipelineSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h


#define FOREACH_ENUM_EOWLBITDEPTH(op) \
	op(EOWLBitDepth::BT_8Bit) \
	op(EOWLBitDepth::BT_16Bit) \
	op(EOWLBitDepth::BT_32Bit) 

enum class EOWLBitDepth : uint8;
template<> struct TIsUEnumClass<EOWLBitDepth> { enum { Value = true }; };
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLBitDepth>();

#define FOREACH_ENUM_EOWLCOMPOSITEMODE(op) \
	op(EOWLCompositeMode::CM_Over) \
	op(EOWLCompositeMode::CM_Multiply) \
	op(EOWLCompositeMode::CM_Add) \
	op(EOWLCompositeMode::CM_Subtract) \
	op(EOWLCompositeMode::CM_Screen) \
	op(EOWLCompositeMode::CM_Difference) 

enum class EOWLCompositeMode : uint8;
template<> struct TIsUEnumClass<EOWLCompositeMode> { enum { Value = true }; };
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLCompositeMode>();

#define FOREACH_ENUM_EOWLINTERPOLATIONTYPE(op) \
	op(EOWLInterpolationType::EI_Point) \
	op(EOWLInterpolationType::EI_Bilinear) 

enum class EOWLInterpolationType : uint8;
template<> struct TIsUEnumClass<EOWLInterpolationType> { enum { Value = true }; };
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLInterpolationType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
