// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLCamera/Public/OWLSnapshotSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLSnapshotSettings() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDirectoryPath();
OWLCAMERA_API UEnum* Z_Construct_UEnum_OWLCamera_EOWLImageFormat();
OWLCAMERA_API UFunction* Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature();
OWLCAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLSnapshotSettings();
UPackage* Z_Construct_UPackage__Script_OWLCamera();
// End Cross Module References

// Begin Delegate FOnSnapshotCompletionDelegate
struct Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics
{
	struct _Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms
	{
		FString OutputPath;
		bool bSuccess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutputPath;
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::NewProp_OutputPath = { "OutputPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms, OutputPath), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((_Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms), &Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::NewProp_OutputPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::NewProp_bSuccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OWLCamera, nullptr, "OnSnapshotCompletionDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::_Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::_Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSnapshotCompletionDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnSnapshotCompletionDelegate, const FString& OutputPath, bool bSuccess)
{
	struct _Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms
	{
		FString OutputPath;
		bool bSuccess;
	};
	_Script_OWLCamera_eventOnSnapshotCompletionDelegate_Parms Parms;
	Parms.OutputPath=OutputPath;
	Parms.bSuccess=bSuccess ? true : false;
	OnSnapshotCompletionDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSnapshotCompletionDelegate

// Begin Enum EOWLImageFormat
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLImageFormat;
static UEnum* EOWLImageFormat_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLImageFormat.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLImageFormat.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLCamera_EOWLImageFormat, (UObject*)Z_Construct_UPackage__Script_OWLCamera(), TEXT("EOWLImageFormat"));
	}
	return Z_Registration_Info_UEnum_EOWLImageFormat.OuterSingleton;
}
template<> OWLCAMERA_API UEnum* StaticEnum<EOWLImageFormat>()
{
	return EOWLImageFormat_StaticEnum();
}
struct Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "PNG.DisplayName", "PNG" },
		{ "PNG.Name", "EOWLImageFormat::PNG" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLImageFormat::PNG", (int64)EOWLImageFormat::PNG },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLCamera,
	nullptr,
	"EOWLImageFormat",
	"EOWLImageFormat",
	Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLCamera_EOWLImageFormat()
{
	if (!Z_Registration_Info_UEnum_EOWLImageFormat.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLImageFormat.InnerSingleton, Z_Construct_UEnum_OWLCamera_EOWLImageFormat_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLImageFormat.InnerSingleton;
}
// End Enum EOWLImageFormat

// Begin ScriptStruct FOWLSnapshotSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLSnapshotSettings;
class UScriptStruct* FOWLSnapshotSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLSnapshotSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLSnapshotSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLSnapshotSettings, (UObject*)Z_Construct_UPackage__Script_OWLCamera(), TEXT("OWLSnapshotSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWLSnapshotSettings.OuterSingleton;
}
template<> OWLCAMERA_API UScriptStruct* StaticStruct<FOWLSnapshotSettings>()
{
	return FOWLSnapshotSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputDirectory_MetaData[] = {
		{ "AbsolutePath", "" },
		{ "Category", "Snapshot Settings" },
		{ "Comment", "/** Directory path where snapshots will be saved */" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "Directory path where snapshots will be saved" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "Category", "Snapshot Settings" },
		{ "Comment", "/** Base filename for the snapshot (without extension) */" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "Base filename for the snapshot (without extension)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAppendTimestamp_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Snapshot Settings" },
		{ "Comment", "/** Whether to automatically append timestamp to filename */" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "Whether to automatically append timestamp to filename" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageFormat_MetaData[] = {
		{ "Category", "Snapshot Settings" },
		{ "Comment", "/** Format to save the snapshot in */" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "Format to save the snapshot in" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarmupFrames_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Snapshot Settings" },
		{ "ClampMax", "30" },
		{ "ClampMin", "0" },
		{ "Comment", "/** Number of warmup frames to render before taking the actual snapshot. Helps resolve temporal effects like clouds, TAA, and Lumen. */" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "Number of warmup frames to render before taking the actual snapshot. Helps resolve temporal effects like clouds, TAA, and Lumen." },
		{ "UIMax", "15" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowNotificationPopup_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Snapshot Settings" },
		{ "Comment", "/** If true, shows notification popup when snapshot is taken */" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "If true, shows notification popup when snapshot is taken" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NotificationDuration_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Snapshot Settings" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** Duration of notification popup in seconds (0 = persistent until closed) */" },
		{ "EditCondition", "bShowNotificationPopup" },
		{ "ModuleRelativePath", "Public/OWLSnapshotSettings.h" },
		{ "ToolTip", "Duration of notification popup in seconds (0 = persistent until closed)" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputDirectory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_bAppendTimestamp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAppendTimestamp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ImageFormat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ImageFormat;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WarmupFrames;
	static void NewProp_bShowNotificationPopup_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowNotificationPopup;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NotificationDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLSnapshotSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_OutputDirectory = { "OutputDirectory", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLSnapshotSettings, OutputDirectory), Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputDirectory_MetaData), NewProp_OutputDirectory_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLSnapshotSettings, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
void Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bAppendTimestamp_SetBit(void* Obj)
{
	((FOWLSnapshotSettings*)Obj)->bAppendTimestamp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bAppendTimestamp = { "bAppendTimestamp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLSnapshotSettings), &Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bAppendTimestamp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAppendTimestamp_MetaData), NewProp_bAppendTimestamp_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_ImageFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_ImageFormat = { "ImageFormat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLSnapshotSettings, ImageFormat), Z_Construct_UEnum_OWLCamera_EOWLImageFormat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageFormat_MetaData), NewProp_ImageFormat_MetaData) }; // 2962309940
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_WarmupFrames = { "WarmupFrames", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLSnapshotSettings, WarmupFrames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarmupFrames_MetaData), NewProp_WarmupFrames_MetaData) };
void Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bShowNotificationPopup_SetBit(void* Obj)
{
	((FOWLSnapshotSettings*)Obj)->bShowNotificationPopup = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bShowNotificationPopup = { "bShowNotificationPopup", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLSnapshotSettings), &Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bShowNotificationPopup_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowNotificationPopup_MetaData), NewProp_bShowNotificationPopup_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_NotificationDuration = { "NotificationDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLSnapshotSettings, NotificationDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NotificationDuration_MetaData), NewProp_NotificationDuration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_OutputDirectory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bAppendTimestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_ImageFormat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_ImageFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_WarmupFrames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_bShowNotificationPopup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewProp_NotificationDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLCamera,
	nullptr,
	&NewStructOps,
	"OWLSnapshotSettings",
	Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::PropPointers),
	sizeof(FOWLSnapshotSettings),
	alignof(FOWLSnapshotSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLSnapshotSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWLSnapshotSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLSnapshotSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLSnapshotSettings.InnerSingleton;
}
// End ScriptStruct FOWLSnapshotSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLSnapshotSettings_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLImageFormat_StaticEnum, TEXT("EOWLImageFormat"), &Z_Registration_Info_UEnum_EOWLImageFormat, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2962309940U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLSnapshotSettings::StaticStruct, Z_Construct_UScriptStruct_FOWLSnapshotSettings_Statics::NewStructOps, TEXT("OWLSnapshotSettings"), &Z_Registration_Info_UScriptStruct_OWLSnapshotSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLSnapshotSettings), 1520511220U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLSnapshotSettings_h_935356437(TEXT("/Script/OWLCamera"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLSnapshotSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLSnapshotSettings_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLSnapshotSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLSnapshotSettings_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
