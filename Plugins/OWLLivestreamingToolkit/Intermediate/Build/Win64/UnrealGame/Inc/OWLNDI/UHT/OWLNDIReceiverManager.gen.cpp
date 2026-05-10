// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLNDI/Public/OWLNDIReceiverManager.h"
#include "OpenColorIO/Public/OpenColorIOColorSpace.h"
#include "OWLNDI/Public/OWLNDIFinder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLNDIReceiverManager() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
OPENCOLORIO_API UClass* Z_Construct_UClass_UOpenColorIOConfiguration_NoRegister();
OPENCOLORIO_API UScriptStruct* Z_Construct_UScriptStruct_FOpenColorIOColorSpace();
OWLNDI_API UClass* Z_Construct_UClass_AOWLNDIReceiverManager();
OWLNDI_API UClass* Z_Construct_UClass_AOWLNDIReceiverManager_NoRegister();
OWLNDI_API UClass* Z_Construct_UClass_UOWLNDISoundWave_NoRegister();
OWLNDI_API UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel();
OWLNDI_API UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync();
OWLNDI_API UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth();
OWLNDI_API UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat();
OWLNDI_API UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus();
OWLNDI_API UScriptStruct* Z_Construct_UScriptStruct_FNDISource();
OWLNDI_API UScriptStruct* Z_Construct_UScriptStruct_FOWLNDIReceiverInterface();
UPackage* Z_Construct_UPackage__Script_OWLNDI();
// End Cross Module References

// Begin Enum EOWLNDIBandwidth
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLNDIBandwidth;
static UEnum* EOWLNDIBandwidth_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIBandwidth.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLNDIBandwidth.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth, (UObject*)Z_Construct_UPackage__Script_OWLNDI(), TEXT("EOWLNDIBandwidth"));
	}
	return Z_Registration_Info_UEnum_EOWLNDIBandwidth.OuterSingleton;
}
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIBandwidth>()
{
	return EOWLNDIBandwidth_StaticEnum();
}
struct Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AudioOnly.DisplayName", "Audio Only" },
		{ "AudioOnly.Name", "EOWLNDIBandwidth::AudioOnly" },
		{ "AudioOnly.ToolTip", "Receive metadata and audio (~1-2 Mbps)" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Enum for NDI bandwidth settings\n */" },
		{ "Highest.DisplayName", "Highest" },
		{ "Highest.Name", "EOWLNDIBandwidth::Highest" },
		{ "Highest.ToolTip", "Receive full resolution stream (~100-250 Mbps)" },
		{ "Lowest.DisplayName", "Lowest" },
		{ "Lowest.Name", "EOWLNDIBandwidth::Lowest" },
		{ "Lowest.ToolTip", "Receive proxy stream at 640x360 (~18-66 Mbps)" },
		{ "MetadataOnly.DisplayName", "Metadata Only" },
		{ "MetadataOnly.Name", "EOWLNDIBandwidth::MetadataOnly" },
		{ "MetadataOnly.ToolTip", "Receive only metadata (<1 Mbps)" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Enum for NDI bandwidth settings" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLNDIBandwidth::MetadataOnly", (int64)EOWLNDIBandwidth::MetadataOnly },
		{ "EOWLNDIBandwidth::AudioOnly", (int64)EOWLNDIBandwidth::AudioOnly },
		{ "EOWLNDIBandwidth::Lowest", (int64)EOWLNDIBandwidth::Lowest },
		{ "EOWLNDIBandwidth::Highest", (int64)EOWLNDIBandwidth::Highest },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLNDI,
	nullptr,
	"EOWLNDIBandwidth",
	"EOWLNDIBandwidth",
	Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIBandwidth.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLNDIBandwidth.InnerSingleton, Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLNDIBandwidth.InnerSingleton;
}
// End Enum EOWLNDIBandwidth

// Begin Enum EOWLNDIAudioReferenceLevel
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel;
static UEnum* EOWLNDIAudioReferenceLevel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel, (UObject*)Z_Construct_UPackage__Script_OWLNDI(), TEXT("EOWLNDIAudioReferenceLevel"));
	}
	return Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel.OuterSingleton;
}
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIAudioReferenceLevel>()
{
	return EOWLNDIAudioReferenceLevel_StaticEnum();
}
struct Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Enum for audio reference level standards\n */" },
		{ "Default.DisplayName", "Default" },
		{ "Default.Name", "EOWLNDIAudioReferenceLevel::Default" },
		{ "Default.ToolTip", "Full 16-bit range (default for gaming/streaming)" },
		{ "EBU.DisplayName", "EBU" },
		{ "EBU.Name", "EOWLNDIAudioReferenceLevel::EBU" },
		{ "EBU.ToolTip", "EBU standard with 18 dB headroom for European broadcast" },
		{ "Manual.DisplayName", "Manual" },
		{ "Manual.Name", "EOWLNDIAudioReferenceLevel::Manual" },
		{ "Manual.ToolTip", "Custom scaling factor" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "SMPTE.DisplayName", "SMPTE" },
		{ "SMPTE.Name", "EOWLNDIAudioReferenceLevel::SMPTE" },
		{ "SMPTE.ToolTip", "SMPTE standard with 20 dB headroom for broadcast" },
		{ "ToolTip", "Enum for audio reference level standards" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLNDIAudioReferenceLevel::Default", (int64)EOWLNDIAudioReferenceLevel::Default },
		{ "EOWLNDIAudioReferenceLevel::SMPTE", (int64)EOWLNDIAudioReferenceLevel::SMPTE },
		{ "EOWLNDIAudioReferenceLevel::EBU", (int64)EOWLNDIAudioReferenceLevel::EBU },
		{ "EOWLNDIAudioReferenceLevel::Manual", (int64)EOWLNDIAudioReferenceLevel::Manual },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLNDI,
	nullptr,
	"EOWLNDIAudioReferenceLevel",
	"EOWLNDIAudioReferenceLevel",
	Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel.InnerSingleton, Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel.InnerSingleton;
}
// End Enum EOWLNDIAudioReferenceLevel

// Begin Enum EOWLNDIColorFormat
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLNDIColorFormat;
static UEnum* EOWLNDIColorFormat_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIColorFormat.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLNDIColorFormat.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat, (UObject*)Z_Construct_UPackage__Script_OWLNDI(), TEXT("EOWLNDIColorFormat"));
	}
	return Z_Registration_Info_UEnum_EOWLNDIColorFormat.OuterSingleton;
}
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIColorFormat>()
{
	return EOWLNDIColorFormat_StaticEnum();
}
struct Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Best.DisplayName", "Best (Highest Available)" },
		{ "Best.Name", "EOWLNDIColorFormat::Best" },
		{ "Best.ToolTip", "Automatically select the highest quality format available from the source. Supports both SDR and HDR content." },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Enum for NDI color format settings\n */" },
		{ "Fastest.DisplayName", "Fastest (Choose fastest available quality)" },
		{ "Fastest.Name", "EOWLNDIColorFormat::Fastest" },
		{ "Fastest.ToolTip", "This format will try to decode the video using the fastest available color format for the incoming video signal." },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Enum for NDI color format settings" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLNDIColorFormat::Best", (int64)EOWLNDIColorFormat::Best },
		{ "EOWLNDIColorFormat::Fastest", (int64)EOWLNDIColorFormat::Fastest },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLNDI,
	nullptr,
	"EOWLNDIColorFormat",
	"EOWLNDIColorFormat",
	Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIColorFormat.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLNDIColorFormat.InnerSingleton, Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLNDIColorFormat.InnerSingleton;
}
// End Enum EOWLNDIColorFormat

// Begin Enum EOWLNDIAudioSync
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLNDIAudioSync;
static UEnum* EOWLNDIAudioSync_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIAudioSync.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLNDIAudioSync.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync, (UObject*)Z_Construct_UPackage__Script_OWLNDI(), TEXT("EOWLNDIAudioSync"));
	}
	return Z_Registration_Info_UEnum_EOWLNDIAudioSync.OuterSingleton;
}
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIAudioSync>()
{
	return EOWLNDIAudioSync_StaticEnum();
}
struct Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Automatic.DisplayName", "Automatic" },
		{ "Automatic.Name", "EOWLNDIAudioSync::Automatic" },
		{ "Automatic.ToolTip", "Automatically sync audio and video" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Enum for audio synchronization modes\n */" },
		{ "Manual.DisplayName", "Manual" },
		{ "Manual.Name", "EOWLNDIAudioSync::Manual" },
		{ "Manual.ToolTip", "Manually set audio delay" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Enum for audio synchronization modes" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLNDIAudioSync::Automatic", (int64)EOWLNDIAudioSync::Automatic },
		{ "EOWLNDIAudioSync::Manual", (int64)EOWLNDIAudioSync::Manual },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLNDI,
	nullptr,
	"EOWLNDIAudioSync",
	"EOWLNDIAudioSync",
	Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIAudioSync.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLNDIAudioSync.InnerSingleton, Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLNDIAudioSync.InnerSingleton;
}
// End Enum EOWLNDIAudioSync

// Begin Enum EOWLNDIConnectionStatus
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLNDIConnectionStatus;
static UEnum* EOWLNDIConnectionStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIConnectionStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLNDIConnectionStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus, (UObject*)Z_Construct_UPackage__Script_OWLNDI(), TEXT("EOWLNDIConnectionStatus"));
	}
	return Z_Registration_Info_UEnum_EOWLNDIConnectionStatus.OuterSingleton;
}
template<> OWLNDI_API UEnum* StaticEnum<EOWLNDIConnectionStatus>()
{
	return EOWLNDIConnectionStatus_StaticEnum();
}
struct Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Enum for connection status reporting\n */" },
		{ "Connected.DisplayName", "Connected" },
		{ "Connected.Name", "EOWLNDIConnectionStatus::Connected" },
		{ "Connected.ToolTip", "Successfully connected and receiving" },
		{ "Connecting.DisplayName", "Connecting" },
		{ "Connecting.Name", "EOWLNDIConnectionStatus::Connecting" },
		{ "Connecting.ToolTip", "Attempting to connect" },
		{ "Disconnected.DisplayName", "Disconnected" },
		{ "Disconnected.Name", "EOWLNDIConnectionStatus::Disconnected" },
		{ "Disconnected.ToolTip", "Not connected to any source" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Enum for connection status reporting" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLNDIConnectionStatus::Disconnected", (int64)EOWLNDIConnectionStatus::Disconnected },
		{ "EOWLNDIConnectionStatus::Connecting", (int64)EOWLNDIConnectionStatus::Connecting },
		{ "EOWLNDIConnectionStatus::Connected", (int64)EOWLNDIConnectionStatus::Connected },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLNDI,
	nullptr,
	"EOWLNDIConnectionStatus",
	"EOWLNDIConnectionStatus",
	Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus()
{
	if (!Z_Registration_Info_UEnum_EOWLNDIConnectionStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLNDIConnectionStatus.InnerSingleton, Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLNDIConnectionStatus.InnerSingleton;
}
// End Enum EOWLNDIConnectionStatus

// Begin ScriptStruct FOWLNDIReceiverInterface
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface;
class UScriptStruct* FOWLNDIReceiverInterface::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLNDIReceiverInterface, (UObject*)Z_Construct_UPackage__Script_OWLNDI(), TEXT("OWLNDIReceiverInterface"));
	}
	return Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface.OuterSingleton;
}
template<> OWLNDI_API UScriptStruct* StaticStruct<FOWLNDIReceiverInterface>()
{
	return FOWLNDIReceiverInterface::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Struct to handle NDI receive functionality and settings\n */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Struct to handle NDI receive functionality and settings" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bConvertGamma_MetaData[] = {
		{ "Category", "Color Management" },
		{ "Comment", "/** If enabled, for 8bit textures, a gamma conversion will be applied to ensure that Unreal output matches color range on 3rd party programs */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "If enabled, for 8bit textures, a gamma conversion will be applied to ensure that Unreal output matches color range on 3rd party programs" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseOCIO_MetaData[] = {
		{ "Category", "Color Management" },
		{ "Comment", "/** Enable OCIO color space conversion */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Enable OCIO color space conversion" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OCIOConfiguration_MetaData[] = {
		{ "Category", "Color Management" },
		{ "Comment", "/** OCIO Configuration Asset to use for color conversion */" },
		{ "EditCondition", "bUseOCIO" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "OCIO Configuration Asset to use for color conversion" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceColorSpace_MetaData[] = {
		{ "Category", "Color Management" },
		{ "Comment", "/** Source color space (what the NDI stream is in) */" },
		{ "EditCondition", "bUseOCIO && OCIOConfiguration != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Source color space (what the NDI stream is in)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationColorSpace_MetaData[] = {
		{ "Category", "Color Management" },
		{ "Comment", "/** Destination color space (what we want to convert to) */" },
		{ "EditCondition", "bUseOCIO && OCIOConfiguration != nullptr" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Destination color space (what we want to convert to)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bApplyGammaBeforeOCIO_MetaData[] = {
		{ "Category", "Color Management" },
		{ "Comment", "/** Whether to apply gamma correction before OCIO conversion */" },
		{ "EditCondition", "bUseOCIO" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Whether to apply gamma correction before OCIO conversion" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Active_MetaData[] = {
		{ "Category", "Basic" },
		{ "Comment", "/** Whether this receiver is active */" },
		{ "EditCondition", "!bUnderExternalControl" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Whether this receiver is active" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Basic" },
		{ "Comment", "/** The name of the NDI source to connect to */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "The name of the NDI source to connect to" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_MetaData[] = {
		{ "Category", "Basic" },
		{ "Comment", "/** The render target to receive video frames to */" },
		{ "EditCondition", "!bUnderExternalControl" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "The render target to receive video frames to" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bandwidth_MetaData[] = {
		{ "Category", "Performance" },
		{ "Comment", "/** Controls bandwidth and resolution of received video */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Controls bandwidth and resolution of received video" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorFormat_MetaData[] = {
		{ "Category", "Performance" },
		{ "Comment", "/** Specify preferred video format to receive */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Specify preferred video format to receive" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NDISoundWave_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "/** The sound wave object for audio reception */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "The sound wave object for audio reception" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioReferenceLevel_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "/** Audio reference level standard for professional audio */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Audio reference level standard for professional audio" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomAudioScale_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.1" },
		{ "Comment", "/** Custom audio scaling factor when using Manual reference level */" },
		{ "EditCondition", "AudioReferenceLevel == EOWLNDIAudioReferenceLevel::Manual" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Custom audio scaling factor when using Manual reference level" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioSyncMode_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "/** Controls audio/video synchronization */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Controls audio/video synchronization" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioDelayMs_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMax", "500" },
		{ "ClampMin", "-500" },
		{ "Comment", "/** Manual audio delay in milliseconds */" },
		{ "EditCondition", "AudioSyncMode == EOWLNDIAudioSync::Manual" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Manual audio delay in milliseconds" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOnProgram_MetaData[] = {
		{ "Category", "Tally" },
		{ "Comment", "/** Set tally state to show source it's visible in program */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Set tally state to show source it's visible in program" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOnPreview_MetaData[] = {
		{ "Category", "Tally" },
		{ "Comment", "/** Set tally state to show source it's visible in preview */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Set tally state to show source it's visible in preview" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectionStatus_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Current connection status */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Current connection status" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceInfo_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Source information string */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Source information string" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceResolution_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Native resolution of connected source */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Native resolution of connected source" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceFrameRate_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Frame rate of connected source */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Frame rate of connected source" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentBandwidthMbps_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Current bandwidth usage in Mbps */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Current bandwidth usage in Mbps" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSourceSupportsPTZ_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Whether source supports PTZ control */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Whether source supports PTZ control" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSourceHasWebControls_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/** Whether source has web controls available */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Whether source has web controls available" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUnderExternalControl_MetaData[] = {
		{ "Category", "Internal" },
		{ "Comment", "/** Internal flag to track if receiver is under external control */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Internal flag to track if receiver is under external control" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_World_MetaData[] = {
		{ "Comment", "/** Reference to the world */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Reference to the world" },
	};
#endif // WITH_METADATA
	static void NewProp_bConvertGamma_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConvertGamma;
	static void NewProp_bUseOCIO_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseOCIO;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OCIOConfiguration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceColorSpace;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DestinationColorSpace;
	static void NewProp_bApplyGammaBeforeOCIO_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bApplyGammaBeforeOCIO;
	static void NewProp_Active_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Active;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bandwidth_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Bandwidth;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ColorFormat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ColorFormat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NDISoundWave;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AudioReferenceLevel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AudioReferenceLevel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CustomAudioScale;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AudioSyncMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AudioSyncMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AudioDelayMs;
	static void NewProp_bOnProgram_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOnProgram;
	static void NewProp_bOnPreview_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOnPreview;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ConnectionStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ConnectionStatus;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceResolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SourceFrameRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentBandwidthMbps;
	static void NewProp_bSourceSupportsPTZ_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSourceSupportsPTZ;
	static void NewProp_bSourceHasWebControls_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSourceHasWebControls;
	static void NewProp_bUnderExternalControl_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnderExternalControl;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLNDIReceiverInterface>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bConvertGamma_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bConvertGamma = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bConvertGamma = { "bConvertGamma", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bConvertGamma_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bConvertGamma_MetaData), NewProp_bConvertGamma_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUseOCIO_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bUseOCIO = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUseOCIO = { "bUseOCIO", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUseOCIO_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseOCIO_MetaData), NewProp_bUseOCIO_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_OCIOConfiguration = { "OCIOConfiguration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, OCIOConfiguration), Z_Construct_UClass_UOpenColorIOConfiguration_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OCIOConfiguration_MetaData), NewProp_OCIOConfiguration_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceColorSpace = { "SourceColorSpace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, SourceColorSpace), Z_Construct_UScriptStruct_FOpenColorIOColorSpace, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceColorSpace_MetaData), NewProp_SourceColorSpace_MetaData) }; // 4010390020
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_DestinationColorSpace = { "DestinationColorSpace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, DestinationColorSpace), Z_Construct_UScriptStruct_FOpenColorIOColorSpace, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationColorSpace_MetaData), NewProp_DestinationColorSpace_MetaData) }; // 4010390020
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bApplyGammaBeforeOCIO_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bApplyGammaBeforeOCIO = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bApplyGammaBeforeOCIO = { "bApplyGammaBeforeOCIO", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bApplyGammaBeforeOCIO_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bApplyGammaBeforeOCIO_MetaData), NewProp_bApplyGammaBeforeOCIO_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Active_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->Active = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Active = { "Active", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Active_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Active_MetaData), NewProp_Active_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_RenderTarget = { "RenderTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, RenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget_MetaData), NewProp_RenderTarget_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Bandwidth_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Bandwidth = { "Bandwidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, Bandwidth), Z_Construct_UEnum_OWLNDI_EOWLNDIBandwidth, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bandwidth_MetaData), NewProp_Bandwidth_MetaData) }; // 2845975965
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ColorFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ColorFormat = { "ColorFormat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, ColorFormat), Z_Construct_UEnum_OWLNDI_EOWLNDIColorFormat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorFormat_MetaData), NewProp_ColorFormat_MetaData) }; // 3821708198
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_NDISoundWave = { "NDISoundWave", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, NDISoundWave), Z_Construct_UClass_UOWLNDISoundWave_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NDISoundWave_MetaData), NewProp_NDISoundWave_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioReferenceLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioReferenceLevel = { "AudioReferenceLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, AudioReferenceLevel), Z_Construct_UEnum_OWLNDI_EOWLNDIAudioReferenceLevel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioReferenceLevel_MetaData), NewProp_AudioReferenceLevel_MetaData) }; // 3350711942
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_CustomAudioScale = { "CustomAudioScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, CustomAudioScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomAudioScale_MetaData), NewProp_CustomAudioScale_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioSyncMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioSyncMode = { "AudioSyncMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, AudioSyncMode), Z_Construct_UEnum_OWLNDI_EOWLNDIAudioSync, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioSyncMode_MetaData), NewProp_AudioSyncMode_MetaData) }; // 957268686
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioDelayMs = { "AudioDelayMs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, AudioDelayMs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioDelayMs_MetaData), NewProp_AudioDelayMs_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnProgram_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bOnProgram = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnProgram = { "bOnProgram", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnProgram_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOnProgram_MetaData), NewProp_bOnProgram_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnPreview_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bOnPreview = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnPreview = { "bOnPreview", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnPreview_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOnPreview_MetaData), NewProp_bOnPreview_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ConnectionStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ConnectionStatus = { "ConnectionStatus", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, ConnectionStatus), Z_Construct_UEnum_OWLNDI_EOWLNDIConnectionStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectionStatus_MetaData), NewProp_ConnectionStatus_MetaData) }; // 3946657392
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceInfo = { "SourceInfo", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, SourceInfo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceInfo_MetaData), NewProp_SourceInfo_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceResolution = { "SourceResolution", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, SourceResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceResolution_MetaData), NewProp_SourceResolution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceFrameRate = { "SourceFrameRate", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, SourceFrameRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceFrameRate_MetaData), NewProp_SourceFrameRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_CurrentBandwidthMbps = { "CurrentBandwidthMbps", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, CurrentBandwidthMbps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentBandwidthMbps_MetaData), NewProp_CurrentBandwidthMbps_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceSupportsPTZ_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bSourceSupportsPTZ = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceSupportsPTZ = { "bSourceSupportsPTZ", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceSupportsPTZ_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSourceSupportsPTZ_MetaData), NewProp_bSourceSupportsPTZ_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceHasWebControls_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bSourceHasWebControls = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceHasWebControls = { "bSourceHasWebControls", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceHasWebControls_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSourceHasWebControls_MetaData), NewProp_bSourceHasWebControls_MetaData) };
void Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUnderExternalControl_SetBit(void* Obj)
{
	((FOWLNDIReceiverInterface*)Obj)->bUnderExternalControl = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUnderExternalControl = { "bUnderExternalControl", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLNDIReceiverInterface), &Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUnderExternalControl_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUnderExternalControl_MetaData), NewProp_bUnderExternalControl_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLNDIReceiverInterface, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_World_MetaData), NewProp_World_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bConvertGamma,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUseOCIO,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_OCIOConfiguration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceColorSpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_DestinationColorSpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bApplyGammaBeforeOCIO,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Active,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_RenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Bandwidth_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_Bandwidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ColorFormat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ColorFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_NDISoundWave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioReferenceLevel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioReferenceLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_CustomAudioScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioSyncMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioSyncMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_AudioDelayMs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnProgram,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bOnPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ConnectionStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_ConnectionStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_SourceFrameRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_CurrentBandwidthMbps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceSupportsPTZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bSourceHasWebControls,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_bUnderExternalControl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLNDI,
	nullptr,
	&NewStructOps,
	"OWLNDIReceiverInterface",
	Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::PropPointers),
	sizeof(FOWLNDIReceiverInterface),
	alignof(FOWLNDIReceiverInterface),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLNDIReceiverInterface()
{
	if (!Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface.InnerSingleton, Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface.InnerSingleton;
}
// End ScriptStruct FOWLNDIReceiverInterface

// Begin Class AOWLNDIReceiverManager Function ActivateReceiver
struct Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics
{
	struct OWLNDIReceiverManager_eventActivateReceiver_Parms
	{
		int32 Index;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Off World Live NDI Receiver" },
		{ "Comment", "/* Activates an NDI receiver. True if found, false if not */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Activates an NDI receiver. True if found, false if not" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventActivateReceiver_Parms, Index), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventActivateReceiver_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventActivateReceiver_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "ActivateReceiver", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::OWLNDIReceiverManager_eventActivateReceiver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::OWLNDIReceiverManager_eventActivateReceiver_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execActivateReceiver)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ActivateReceiver(Z_Param_Index);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function ActivateReceiver

// Begin Class AOWLNDIReceiverManager Function DeactivateReceiver
struct Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics
{
	struct OWLNDIReceiverManager_eventDeactivateReceiver_Parms
	{
		int32 Index;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Off World Live NDI Receiver" },
		{ "Comment", "/* Deactivates an NDI receiver. True if found, false if not */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Deactivates an NDI receiver. True if found, false if not" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventDeactivateReceiver_Parms, Index), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventDeactivateReceiver_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventDeactivateReceiver_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "DeactivateReceiver", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::OWLNDIReceiverManager_eventDeactivateReceiver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::OWLNDIReceiverManager_eventDeactivateReceiver_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execDeactivateReceiver)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->DeactivateReceiver(Z_Param_Index);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function DeactivateReceiver

// Begin Class AOWLNDIReceiverManager Function GetAvailableNDISources
struct Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics
{
	struct OWLNDIReceiverManager_eventGetAvailableNDISources_Parms
	{
		TArray<FNDISource> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Off World Live NDI Receiver" },
		{ "Comment", "/** Returns a list of NDI sources that are available at this moment in time. */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Returns a list of NDI sources that are available at this moment in time." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FNDISource, METADATA_PARAMS(0, nullptr) }; // 1673757425
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetAvailableNDISources_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1673757425
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "GetAvailableNDISources", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::OWLNDIReceiverManager_eventGetAvailableNDISources_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::OWLNDIReceiverManager_eventGetAvailableNDISources_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execGetAvailableNDISources)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FNDISource>*)Z_Param__Result=P_THIS->GetAvailableNDISources();
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function GetAvailableNDISources

// Begin Class AOWLNDIReceiverManager Function GetFrameDropRate
struct Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics
{
	struct OWLNDIReceiverManager_eventGetFrameDropRate_Parms
	{
		int32 ReceiverIndex;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | Diagnostics" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetFrameDropRate_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetFrameDropRate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "GetFrameDropRate", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::OWLNDIReceiverManager_eventGetFrameDropRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::OWLNDIReceiverManager_eventGetFrameDropRate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execGetFrameDropRate)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetFrameDropRate(Z_Param_ReceiverIndex);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function GetFrameDropRate

// Begin Class AOWLNDIReceiverManager Function GetPerformanceMetrics
struct Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics
{
	struct OWLNDIReceiverManager_eventGetPerformanceMetrics_Parms
	{
		int32 ReceiverIndex;
		int32 FramesReceived;
		int32 FramesDropped;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | Diagnostics" },
		{ "Comment", "/** Get performance metrics for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Get performance metrics for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FramesReceived;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FramesDropped;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetPerformanceMetrics_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::NewProp_FramesReceived = { "FramesReceived", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetPerformanceMetrics_Parms, FramesReceived), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::NewProp_FramesDropped = { "FramesDropped", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetPerformanceMetrics_Parms, FramesDropped), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::NewProp_FramesReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::NewProp_FramesDropped,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "GetPerformanceMetrics", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::OWLNDIReceiverManager_eventGetPerformanceMetrics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::OWLNDIReceiverManager_eventGetPerformanceMetrics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execGetPerformanceMetrics)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_FramesReceived);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_FramesDropped);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetPerformanceMetrics(Z_Param_ReceiverIndex,Z_Param_Out_FramesReceived,Z_Param_Out_FramesDropped);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function GetPerformanceMetrics

// Begin Class AOWLNDIReceiverManager Function GetQueueDepths
struct Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics
{
	struct OWLNDIReceiverManager_eventGetQueueDepths_Parms
	{
		int32 ReceiverIndex;
		int32 VideoFramesQueued;
		int32 AudioFramesQueued;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | Diagnostics" },
		{ "Comment", "/** Get queue depths for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Get queue depths for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_VideoFramesQueued;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AudioFramesQueued;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetQueueDepths_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::NewProp_VideoFramesQueued = { "VideoFramesQueued", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetQueueDepths_Parms, VideoFramesQueued), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::NewProp_AudioFramesQueued = { "AudioFramesQueued", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetQueueDepths_Parms, AudioFramesQueued), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::NewProp_VideoFramesQueued,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::NewProp_AudioFramesQueued,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "GetQueueDepths", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::OWLNDIReceiverManager_eventGetQueueDepths_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::OWLNDIReceiverManager_eventGetQueueDepths_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execGetQueueDepths)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_VideoFramesQueued);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_AudioFramesQueued);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetQueueDepths(Z_Param_ReceiverIndex,Z_Param_Out_VideoFramesQueued,Z_Param_Out_AudioFramesQueued);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function GetQueueDepths

// Begin Class AOWLNDIReceiverManager Function GetWebControlURL
struct Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics
{
	struct OWLNDIReceiverManager_eventGetWebControlURL_Parms
	{
		int32 ReceiverIndex;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | Advanced" },
		{ "Comment", "/** Get web control URL for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Get web control URL for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetWebControlURL_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventGetWebControlURL_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "GetWebControlURL", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::OWLNDIReceiverManager_eventGetWebControlURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::OWLNDIReceiverManager_eventGetWebControlURL_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execGetWebControlURL)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetWebControlURL(Z_Param_ReceiverIndex);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function GetWebControlURL

// Begin Class AOWLNDIReceiverManager Function IsPTZSupported
struct Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics
{
	struct OWLNDIReceiverManager_eventIsPTZSupported_Parms
	{
		int32 ReceiverIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Check if a receiver source supports PTZ control */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Check if a receiver source supports PTZ control" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventIsPTZSupported_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventIsPTZSupported_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventIsPTZSupported_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "IsPTZSupported", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::OWLNDIReceiverManager_eventIsPTZSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::OWLNDIReceiverManager_eventIsPTZSupported_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execIsPTZSupported)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPTZSupported(Z_Param_ReceiverIndex);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function IsPTZSupported

// Begin Class AOWLNDIReceiverManager Function OpenWebControlPanel
struct Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics
{
	struct OWLNDIReceiverManager_eventOpenWebControlPanel_Parms
	{
		int32 ReceiverIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | Advanced" },
		{ "Comment", "/** Open web control panel for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Open web control panel for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventOpenWebControlPanel_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::NewProp_ReceiverIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "OpenWebControlPanel", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::OWLNDIReceiverManager_eventOpenWebControlPanel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::OWLNDIReceiverManager_eventOpenWebControlPanel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execOpenWebControlPanel)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenWebControlPanel(Z_Param_ReceiverIndex);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function OpenWebControlPanel

// Begin Class AOWLNDIReceiverManager Function PTZAutoFocus
struct Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics
{
	struct OWLNDIReceiverManager_eventPTZAutoFocus_Parms
	{
		int32 ReceiverIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Set auto-focus for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Set auto-focus for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZAutoFocus_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventPTZAutoFocus_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventPTZAutoFocus_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "PTZAutoFocus", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::OWLNDIReceiverManager_eventPTZAutoFocus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::OWLNDIReceiverManager_eventPTZAutoFocus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execPTZAutoFocus)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PTZAutoFocus(Z_Param_ReceiverIndex);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function PTZAutoFocus

// Begin Class AOWLNDIReceiverManager Function PTZManualFocus
struct Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics
{
	struct OWLNDIReceiverManager_eventPTZManualFocus_Parms
	{
		int32 ReceiverIndex;
		float FocusValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Control manual focus for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Control manual focus for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FocusValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZManualFocus_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_FocusValue = { "FocusValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZManualFocus_Parms, FocusValue), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventPTZManualFocus_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventPTZManualFocus_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_FocusValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "PTZManualFocus", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::OWLNDIReceiverManager_eventPTZManualFocus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::OWLNDIReceiverManager_eventPTZManualFocus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execPTZManualFocus)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_FocusValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PTZManualFocus(Z_Param_ReceiverIndex,Z_Param_FocusValue);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function PTZManualFocus

// Begin Class AOWLNDIReceiverManager Function PTZPanTilt
struct Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics
{
	struct OWLNDIReceiverManager_eventPTZPanTilt_Parms
	{
		int32 ReceiverIndex;
		float Pan;
		float Tilt;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Control pan and tilt for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Control pan and tilt for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Pan;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Tilt;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZPanTilt_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_Pan = { "Pan", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZPanTilt_Parms, Pan), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_Tilt = { "Tilt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZPanTilt_Parms, Tilt), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventPTZPanTilt_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventPTZPanTilt_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_Pan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_Tilt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "PTZPanTilt", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::OWLNDIReceiverManager_eventPTZPanTilt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::OWLNDIReceiverManager_eventPTZPanTilt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execPTZPanTilt)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Pan);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Tilt);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PTZPanTilt(Z_Param_ReceiverIndex,Z_Param_Pan,Z_Param_Tilt);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function PTZPanTilt

// Begin Class AOWLNDIReceiverManager Function PTZRecallPreset
struct Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics
{
	struct OWLNDIReceiverManager_eventPTZRecallPreset_Parms
	{
		int32 ReceiverIndex;
		int32 PresetNumber;
		float Speed;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Recall a preset for a specific receiver */" },
		{ "CPP_Default_Speed", "1.000000" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Recall a preset for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PresetNumber;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZRecallPreset_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_PresetNumber = { "PresetNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZRecallPreset_Parms, PresetNumber), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZRecallPreset_Parms, Speed), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventPTZRecallPreset_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventPTZRecallPreset_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_PresetNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_Speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "PTZRecallPreset", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::OWLNDIReceiverManager_eventPTZRecallPreset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::OWLNDIReceiverManager_eventPTZRecallPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execPTZRecallPreset)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_PresetNumber);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PTZRecallPreset(Z_Param_ReceiverIndex,Z_Param_PresetNumber,Z_Param_Speed);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function PTZRecallPreset

// Begin Class AOWLNDIReceiverManager Function PTZStorePreset
struct Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics
{
	struct OWLNDIReceiverManager_eventPTZStorePreset_Parms
	{
		int32 ReceiverIndex;
		int32 PresetNumber;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Store current position as a preset for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Store current position as a preset for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PresetNumber;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZStorePreset_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_PresetNumber = { "PresetNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZStorePreset_Parms, PresetNumber), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventPTZStorePreset_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventPTZStorePreset_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_PresetNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "PTZStorePreset", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::OWLNDIReceiverManager_eventPTZStorePreset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::OWLNDIReceiverManager_eventPTZStorePreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execPTZStorePreset)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_PresetNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PTZStorePreset(Z_Param_ReceiverIndex,Z_Param_PresetNumber);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function PTZStorePreset

// Begin Class AOWLNDIReceiverManager Function PTZZoom
struct Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics
{
	struct OWLNDIReceiverManager_eventPTZZoom_Parms
	{
		int32 ReceiverIndex;
		float Zoom;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | PTZ" },
		{ "Comment", "/** Control zoom for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Control zoom for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Zoom;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZZoom_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_Zoom = { "Zoom", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventPTZZoom_Parms, Zoom), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventPTZZoom_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventPTZZoom_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_Zoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "PTZZoom", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::OWLNDIReceiverManager_eventPTZZoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::OWLNDIReceiverManager_eventPTZZoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execPTZZoom)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Zoom);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->PTZZoom(Z_Param_ReceiverIndex,Z_Param_Zoom);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function PTZZoom

// Begin Class AOWLNDIReceiverManager Function SetTallyState
struct Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics
{
	struct OWLNDIReceiverManager_eventSetTallyState_Parms
	{
		int32 ReceiverIndex;
		bool bIsOnProgram;
		bool bIsOnPreview;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NDI Receiver | Tally" },
		{ "Comment", "/** Set tally state for a specific receiver */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Set tally state for a specific receiver" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiverIndex;
	static void NewProp_bIsOnProgram_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnProgram;
	static void NewProp_bIsOnPreview_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnPreview;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_ReceiverIndex = { "ReceiverIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLNDIReceiverManager_eventSetTallyState_Parms, ReceiverIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnProgram_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventSetTallyState_Parms*)Obj)->bIsOnProgram = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnProgram = { "bIsOnProgram", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventSetTallyState_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnProgram_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnPreview_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventSetTallyState_Parms*)Obj)->bIsOnPreview = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnPreview = { "bIsOnPreview", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventSetTallyState_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnPreview_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWLNDIReceiverManager_eventSetTallyState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWLNDIReceiverManager_eventSetTallyState_Parms), &Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_ReceiverIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnProgram,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_bIsOnPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOWLNDIReceiverManager, nullptr, "SetTallyState", nullptr, nullptr, Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::OWLNDIReceiverManager_eventSetTallyState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::OWLNDIReceiverManager_eventSetTallyState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOWLNDIReceiverManager::execSetTallyState)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ReceiverIndex);
	P_GET_UBOOL(Z_Param_bIsOnProgram);
	P_GET_UBOOL(Z_Param_bIsOnPreview);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetTallyState(Z_Param_ReceiverIndex,Z_Param_bIsOnProgram,Z_Param_bIsOnPreview);
	P_NATIVE_END;
}
// End Class AOWLNDIReceiverManager Function SetTallyState

// Begin Class AOWLNDIReceiverManager
void AOWLNDIReceiverManager::StaticRegisterNativesAOWLNDIReceiverManager()
{
	UClass* Class = AOWLNDIReceiverManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ActivateReceiver", &AOWLNDIReceiverManager::execActivateReceiver },
		{ "DeactivateReceiver", &AOWLNDIReceiverManager::execDeactivateReceiver },
		{ "GetAvailableNDISources", &AOWLNDIReceiverManager::execGetAvailableNDISources },
		{ "GetFrameDropRate", &AOWLNDIReceiverManager::execGetFrameDropRate },
		{ "GetPerformanceMetrics", &AOWLNDIReceiverManager::execGetPerformanceMetrics },
		{ "GetQueueDepths", &AOWLNDIReceiverManager::execGetQueueDepths },
		{ "GetWebControlURL", &AOWLNDIReceiverManager::execGetWebControlURL },
		{ "IsPTZSupported", &AOWLNDIReceiverManager::execIsPTZSupported },
		{ "OpenWebControlPanel", &AOWLNDIReceiverManager::execOpenWebControlPanel },
		{ "PTZAutoFocus", &AOWLNDIReceiverManager::execPTZAutoFocus },
		{ "PTZManualFocus", &AOWLNDIReceiverManager::execPTZManualFocus },
		{ "PTZPanTilt", &AOWLNDIReceiverManager::execPTZPanTilt },
		{ "PTZRecallPreset", &AOWLNDIReceiverManager::execPTZRecallPreset },
		{ "PTZStorePreset", &AOWLNDIReceiverManager::execPTZStorePreset },
		{ "PTZZoom", &AOWLNDIReceiverManager::execPTZZoom },
		{ "SetTallyState", &AOWLNDIReceiverManager::execSetTallyState },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOWLNDIReceiverManager);
UClass* Z_Construct_UClass_AOWLNDIReceiverManager_NoRegister()
{
	return AOWLNDIReceiverManager::StaticClass();
}
struct Z_Construct_UClass_AOWLNDIReceiverManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * NDI Receiver Manager class to manage multiple NDI receivers\n */" },
		{ "DisplayName", "OWL NDI Receiver Manager" },
		{ "IncludePath", "OWLNDIReceiverManager.h" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "NDI Receiver Manager class to manage multiple NDI receivers" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NDIReceivers_MetaData[] = {
		{ "Category", "Off World Live NDI Receiver Settings" },
		{ "Comment", "/**\n\x09 * Array of NDI receivers managed by this component\n\x09 */" },
		{ "ModuleRelativePath", "Public/OWLNDIReceiverManager.h" },
		{ "ToolTip", "Array of NDI receivers managed by this component" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NDIReceivers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NDIReceivers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_ActivateReceiver, "ActivateReceiver" }, // 2859364524
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_DeactivateReceiver, "DeactivateReceiver" }, // 1703087172
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_GetAvailableNDISources, "GetAvailableNDISources" }, // 3575069605
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_GetFrameDropRate, "GetFrameDropRate" }, // 4197826319
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_GetPerformanceMetrics, "GetPerformanceMetrics" }, // 871042618
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_GetQueueDepths, "GetQueueDepths" }, // 819105811
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_GetWebControlURL, "GetWebControlURL" }, // 2951143126
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_IsPTZSupported, "IsPTZSupported" }, // 188754105
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_OpenWebControlPanel, "OpenWebControlPanel" }, // 60038089
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZAutoFocus, "PTZAutoFocus" }, // 2921761123
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZManualFocus, "PTZManualFocus" }, // 711761100
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZPanTilt, "PTZPanTilt" }, // 4110402961
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZRecallPreset, "PTZRecallPreset" }, // 944433254
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZStorePreset, "PTZStorePreset" }, // 809598500
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_PTZZoom, "PTZZoom" }, // 2264016389
		{ &Z_Construct_UFunction_AOWLNDIReceiverManager_SetTallyState, "SetTallyState" }, // 3513899822
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOWLNDIReceiverManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOWLNDIReceiverManager_Statics::NewProp_NDIReceivers_Inner = { "NDIReceivers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOWLNDIReceiverInterface, METADATA_PARAMS(0, nullptr) }; // 4250167736
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOWLNDIReceiverManager_Statics::NewProp_NDIReceivers = { "NDIReceivers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLNDIReceiverManager, NDIReceivers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NDIReceivers_MetaData), NewProp_NDIReceivers_MetaData) }; // 4250167736
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOWLNDIReceiverManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLNDIReceiverManager_Statics::NewProp_NDIReceivers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLNDIReceiverManager_Statics::NewProp_NDIReceivers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLNDIReceiverManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOWLNDIReceiverManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLNDI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLNDIReceiverManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOWLNDIReceiverManager_Statics::ClassParams = {
	&AOWLNDIReceiverManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AOWLNDIReceiverManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AOWLNDIReceiverManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLNDIReceiverManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AOWLNDIReceiverManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOWLNDIReceiverManager()
{
	if (!Z_Registration_Info_UClass_AOWLNDIReceiverManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOWLNDIReceiverManager.OuterSingleton, Z_Construct_UClass_AOWLNDIReceiverManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOWLNDIReceiverManager.OuterSingleton;
}
template<> OWLNDI_API UClass* StaticClass<AOWLNDIReceiverManager>()
{
	return AOWLNDIReceiverManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOWLNDIReceiverManager);
AOWLNDIReceiverManager::~AOWLNDIReceiverManager() {}
// End Class AOWLNDIReceiverManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLNDIBandwidth_StaticEnum, TEXT("EOWLNDIBandwidth"), &Z_Registration_Info_UEnum_EOWLNDIBandwidth, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2845975965U) },
		{ EOWLNDIAudioReferenceLevel_StaticEnum, TEXT("EOWLNDIAudioReferenceLevel"), &Z_Registration_Info_UEnum_EOWLNDIAudioReferenceLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3350711942U) },
		{ EOWLNDIColorFormat_StaticEnum, TEXT("EOWLNDIColorFormat"), &Z_Registration_Info_UEnum_EOWLNDIColorFormat, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3821708198U) },
		{ EOWLNDIAudioSync_StaticEnum, TEXT("EOWLNDIAudioSync"), &Z_Registration_Info_UEnum_EOWLNDIAudioSync, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 957268686U) },
		{ EOWLNDIConnectionStatus_StaticEnum, TEXT("EOWLNDIConnectionStatus"), &Z_Registration_Info_UEnum_EOWLNDIConnectionStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3946657392U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLNDIReceiverInterface::StaticStruct, Z_Construct_UScriptStruct_FOWLNDIReceiverInterface_Statics::NewStructOps, TEXT("OWLNDIReceiverInterface"), &Z_Registration_Info_UScriptStruct_OWLNDIReceiverInterface, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLNDIReceiverInterface), 4250167736U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOWLNDIReceiverManager, AOWLNDIReceiverManager::StaticClass, TEXT("AOWLNDIReceiverManager"), &Z_Registration_Info_UClass_AOWLNDIReceiverManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOWLNDIReceiverManager), 1538173956U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_2351676493(TEXT("/Script/OWLNDI"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_OWLNDIReceiverManager_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
