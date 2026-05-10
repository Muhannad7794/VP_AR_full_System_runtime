// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MediaFramework/Input/OWLSpoutMediaSource.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OWLSPOUT_OWLSpoutMediaSource_generated_h
#error "OWLSpoutMediaSource.generated.h already included, missing '#pragma once' in OWLSpoutMediaSource.h"
#endif
#define OWLSPOUT_OWLSpoutMediaSource_generated_h

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execChangeSpoutSender); \
	DECLARE_FUNCTION(execGetAvailableSpoutSenderNames); \
	DECLARE_FUNCTION(execGetValidationErrors); \
	DECLARE_FUNCTION(execGetAvailableSpoutSenders); \
	DECLARE_FUNCTION(execSetSpoutSenderName); \
	DECLARE_FUNCTION(execGetSpoutSenderName);


#if WITH_EDITOR
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	DECLARE_FUNCTION(execOnMediaPlayerClosed);
#else // WITH_EDITOR
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_RPC_WRAPPERS_NO_PURE_DECLS_EOD
#endif // WITH_EDITOR


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOWLSpoutMediaSource(); \
	friend struct Z_Construct_UClass_UOWLSpoutMediaSource_Statics; \
public: \
	DECLARE_CLASS(UOWLSpoutMediaSource, UMediaSource, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OWLSpout"), NO_API) \
	DECLARE_SERIALIZER(UOWLSpoutMediaSource)


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOWLSpoutMediaSource(UOWLSpoutMediaSource&&); \
	UOWLSpoutMediaSource(const UOWLSpoutMediaSource&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOWLSpoutMediaSource); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOWLSpoutMediaSource); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOWLSpoutMediaSource) \
	NO_API virtual ~UOWLSpoutMediaSource();


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_20_PROLOG
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_INCLASS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OWLSPOUT_API UClass* StaticClass<class UOWLSpoutMediaSource>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Input_OWLSpoutMediaSource_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
