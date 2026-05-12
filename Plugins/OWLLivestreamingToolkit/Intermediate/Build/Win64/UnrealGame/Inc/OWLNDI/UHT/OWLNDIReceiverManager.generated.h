// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OWLNDIReceiverManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FNDISource;
#ifdef OWLNDI_OWLNDIReceiverManager_generated_h
#error "OWLNDIReceiverManager.generated.h already included, missing '#pragma once' in OWLNDIReceiverManager.h"
#endif
#define OWLNDI_OWLNDIReceiverManager_generated_h

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_82_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OWLNDI_API UScriptStruct* StaticStruct<struct FOWLNDIReceiverInterface>();

#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetFrameDropRate); \
	DECLARE_FUNCTION(execGetQueueDepths); \
	DECLARE_FUNCTION(execGetPerformanceMetrics); \
	DECLARE_FUNCTION(execSetTallyState); \
	DECLARE_FUNCTION(execOpenWebControlPanel); \
	DECLARE_FUNCTION(execGetWebControlURL); \
	DECLARE_FUNCTION(execPTZManualFocus); \
	DECLARE_FUNCTION(execPTZAutoFocus); \
	DECLARE_FUNCTION(execPTZRecallPreset); \
	DECLARE_FUNCTION(execPTZStorePreset); \
	DECLARE_FUNCTION(execPTZZoom); \
	DECLARE_FUNCTION(execPTZPanTilt); \
	DECLARE_FUNCTION(execIsPTZSupported); \
	DECLARE_FUNCTION(execDeactivateReceiver); \
	DECLARE_FUNCTION(execActivateReceiver); \
	DECLARE_FUNCTION(execGetAvailableNDISources);


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOWLNDIReceiverManager(); \
	friend struct Z_Construct_UClass_AOWLNDIReceiverManager_Statics; \
public: \
	DECLARE_CLASS(AOWLNDIReceiverManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OWLNDI"), NO_API) \
	DECLARE_SERIALIZER(AOWLNDIReceiverManager)


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AOWLNDIReceiverManager(AOWLNDIReceiverManager&&); \
	AOWLNDIReceiverManager(const AOWLNDIReceiverManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOWLNDIReceiverManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOWLNDIReceiverManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOWLNDIReceiverManager) \
	NO_API virtual ~AOWLNDIReceiverManager();


#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_334_PROLOG
#define FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_INCLASS_NO_PURE_DECLS \
	FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_337_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OWLNDI_API UClass* StaticClass<class AOWLNDIReceiverManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h


#define FOREACH_ENUM_EOWLNDIBANDWIDTH(op) \
	op(EOWLNDIBandwidth::MetadataOnly) \
	op(EOWLNDIBandwidth::AudioOnly) \
	op(EOWLNDIBandwidth::Lowest) \
	op(EOWLNDIBandwidth::Highest) 

enum class EOWLNDIBandwidth : uint8;
template<> struct TIsUEnumClass<EOWLNDIBandwidth> { enum { Value = true }; };
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIBandwidth>();

#define FOREACH_ENUM_EOWLNDIAUDIOREFERENCELEVEL(op) \
	op(EOWLNDIAudioReferenceLevel::Default) \
	op(EOWLNDIAudioReferenceLevel::SMPTE) \
	op(EOWLNDIAudioReferenceLevel::EBU) \
	op(EOWLNDIAudioReferenceLevel::Manual) 

enum class EOWLNDIAudioReferenceLevel : uint8;
template<> struct TIsUEnumClass<EOWLNDIAudioReferenceLevel> { enum { Value = true }; };
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIAudioReferenceLevel>();

#define FOREACH_ENUM_EOWLNDICOLORFORMAT(op) \
	op(EOWLNDIColorFormat::Best) \
	op(EOWLNDIColorFormat::Fastest) 

enum class EOWLNDIColorFormat : uint8;
template<> struct TIsUEnumClass<EOWLNDIColorFormat> { enum { Value = true }; };
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIColorFormat>();

#define FOREACH_ENUM_EOWLNDIAUDIOSYNC(op) \
	op(EOWLNDIAudioSync::Automatic) \
	op(EOWLNDIAudioSync::Manual) 

enum class EOWLNDIAudioSync : uint8;
template<> struct TIsUEnumClass<EOWLNDIAudioSync> { enum { Value = true }; };
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIAudioSync>();

#define FOREACH_ENUM_EOWLNDICONNECTIONSTATUS(op) \
	op(EOWLNDIConnectionStatus::Disconnected) \
	op(EOWLNDIConnectionStatus::Connecting) \
	op(EOWLNDIConnectionStatus::Connected) 

enum class EOWLNDIConnectionStatus : uint8;
template<> struct TIsUEnumClass<EOWLNDIConnectionStatus> { enum { Value = true }; };
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIConnectionStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
