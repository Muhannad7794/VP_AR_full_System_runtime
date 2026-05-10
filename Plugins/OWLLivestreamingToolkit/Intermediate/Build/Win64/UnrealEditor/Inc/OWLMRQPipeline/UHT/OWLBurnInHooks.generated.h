// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OWL360Camera/OWLBurnInHooks.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMoviePipeline;
class UOWL360CameraMoviePipelinePass;
class UOWL360CaptureComponent;
struct FOWLMovieSampleState;
#ifdef OWLMRQPIPELINE_OWLBurnInHooks_generated_h
#error "OWLBurnInHooks.generated.h already included, missing '#pragma once' in OWLBurnInHooks.h"
#endif
#define OWLMRQPIPELINE_OWLBurnInHooks_generated_h

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateWidgetPreRender);


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_CALLBACK_WRAPPERS
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOWLBurnInHooks(); \
	friend struct Z_Construct_UClass_UOWLBurnInHooks_Statics; \
public: \
	DECLARE_CLASS(UOWLBurnInHooks, UOWLMRQ360Hooks, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/OWLMRQPipeline"), OWLMRQPIPELINE_API) \
	DECLARE_SERIALIZER(UOWLBurnInHooks)


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOWLBurnInHooks(UOWLBurnInHooks&&); \
	UOWLBurnInHooks(const UOWLBurnInHooks&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OWLMRQPIPELINE_API, UOWLBurnInHooks); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOWLBurnInHooks); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOWLBurnInHooks) \
	OWLMRQPIPELINE_API virtual ~UOWLBurnInHooks();


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_30_PROLOG
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_CALLBACK_WRAPPERS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_INCLASS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OWLMRQPIPELINE_API UClass* StaticClass<class UOWLBurnInHooks>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h


#define FOREACH_ENUM_EOWLBURNINALIGNMENT(op) \
	op(EOWLBurnInAlignment::AL_TopLeft) \
	op(EOWLBurnInAlignment::AL_TopRight) \
	op(EOWLBurnInAlignment::AL_TopCenter) \
	op(EOWLBurnInAlignment::AL_BottomLeft) \
	op(EOWLBurnInAlignment::AL_BottomRight) \
	op(EOWLBurnInAlignment::AL_BottomCenter) \
	op(EOWLBurnInAlignment::AL_Center) \
	op(EOWLBurnInAlignment::AL_Custom) 

enum class EOWLBurnInAlignment : uint8;
template<> struct TIsUEnumClass<EOWLBurnInAlignment> { enum { Value = true }; };
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLBurnInAlignment>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
