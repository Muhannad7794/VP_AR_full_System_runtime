// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MediaFramework/Input/OWLNDIMediaSource.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FNDISource;
#ifdef OWLNDI_OWLNDIMediaSource_generated_h
#error "OWLNDIMediaSource.generated.h already included, missing '#pragma once' in OWLNDIMediaSource.h"
#endif
#define OWLNDI_OWLNDIMediaSource_generated_h

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execChangeNDISource); \
	DECLARE_FUNCTION(execGetAvailableNDISourceNames); \
	DECLARE_FUNCTION(execGetAvailableOCIOColorSpaces); \
	DECLARE_FUNCTION(execGetValidationErrors); \
	DECLARE_FUNCTION(execGetAvailableNDISources); \
	DECLARE_FUNCTION(execSetNDISourceName); \
	DECLARE_FUNCTION(execGetNDISourceName);


#if WITH_EDITOR
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	DECLARE_FUNCTION(execOnMediaPlayerClosed);
#else // WITH_EDITOR
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_RPC_WRAPPERS_NO_PURE_DECLS_EOD
#endif // WITH_EDITOR


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOWLNDIMediaSource(); \
	friend struct Z_Construct_UClass_UOWLNDIMediaSource_Statics; \
public: \
	DECLARE_CLASS(UOWLNDIMediaSource, UMediaSource, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OWLNDI"), NO_API) \
	DECLARE_SERIALIZER(UOWLNDIMediaSource)


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOWLNDIMediaSource(UOWLNDIMediaSource&&); \
	UOWLNDIMediaSource(const UOWLNDIMediaSource&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOWLNDIMediaSource); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOWLNDIMediaSource); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOWLNDIMediaSource) \
	NO_API virtual ~UOWLNDIMediaSource();


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_23_PROLOG
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_INCLASS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OWLNDI_API UClass* StaticClass<class UOWLNDIMediaSource>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Input_OWLNDIMediaSource_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
