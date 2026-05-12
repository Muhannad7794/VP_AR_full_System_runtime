// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLNDI/Public/MediaFramework/Output/OWLNDIMediaOutput.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLNDIMediaOutput() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USoundSubmix_NoRegister();
MEDIAIOCORE_API UClass* Z_Construct_UClass_UMediaOutput();
OWLNDI_API UClass* Z_Construct_UClass_UOWLNDIMediaOutput();
OWLNDI_API UClass* Z_Construct_UClass_UOWLNDIMediaOutput_NoRegister();
OWLNDI_API UEnum* Z_Construct_UEnum_OWLNDI_ENDIVideoConversionFormat();
UPackage* Z_Construct_UPackage__Script_OWLNDI();
// End Cross Module References

// Begin Class UOWLNDIMediaOutput
void UOWLNDIMediaOutput::StaticRegisterNativesUOWLNDIMediaOutput()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLNDIMediaOutput);
UClass* Z_Construct_UClass_UOWLNDIMediaOutput_NoRegister()
{
	return UOWLNDIMediaOutput::StaticClass();
}
struct Z_Construct_UClass_UOWLNDIMediaOutput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Output information for an NDI media capture.\n * This class appears in the Media Output dropdown in nDisplay and other UE systems.\n */" },
		{ "DisplayName", "OWL NDI Output" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ToolTip", "Output information for an NDI media capture.\nThis class appears in the Media Output dropdown in nDisplay and other UE systems." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NDISenderName_MetaData[] = {
		{ "Category", "NDI" },
		{ "Comment", "/** Name of the NDI sender. If empty, will use a default name based on the viewport. */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ToolTip", "Name of the NDI sender. If empty, will use a default name based on the viewport." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoConversionFormat_MetaData[] = {
		{ "Category", "NDI" },
		{ "Comment", "/** \n\x09 * Video conversion format for NDI transmission.\n\x09 * BGRA: Full quality 32-bit RGBA\n\x09 * UYVY: Compressed 8-bit YUV 4:2:2  \n\x09 * P216: High quality 10-bit YUV 4:2:2 (requires NDI 6.0+)\n\x09 */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ToolTip", "Video conversion format for NDI transmission.\nBGRA: Full quality 32-bit RGBA\nUYVY: Compressed 8-bit YUV 4:2:2\nP216: High quality 10-bit YUV 4:2:2 (requires NDI 6.0+)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCaptureAudio_MetaData[] = {
		{ "Category", "NDI" },
		{ "Comment", "/** \n\x09 * Capture audio along with video. Audio will be captured from the main audio device.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ToolTip", "Capture audio along with video. Audio will be captured from the main audio device." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioSubmix_MetaData[] = {
		{ "Category", "NDI" },
		{ "Comment", "/** \n\x09 * Optional submix to narrow down audio you send to the NDI stream.\n\x09 * If not specified, captures from the main audio output.\n\x09 */" },
		{ "EditCondition", "bCaptureAudio" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ToolTip", "Optional submix to narrow down audio you send to the NDI stream.\nIf not specified, captures from the main audio output." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasPriority_MetaData[] = {
		{ "Category", "NDI" },
		{ "Comment", "/** \n\x09 * Priority sender - will take precedence if multiple senders try to use the same name.\n\x09 * Useful when you want this sender to be the \"main\" sender.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaOutput.h" },
		{ "ToolTip", "Priority sender - will take precedence if multiple senders try to use the same name.\nUseful when you want this sender to be the \"main\" sender." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NDISenderName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VideoConversionFormat_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_VideoConversionFormat;
	static void NewProp_bCaptureAudio_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCaptureAudio;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AudioSubmix;
	static void NewProp_bHasPriority_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLNDIMediaOutput>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_NDISenderName = { "NDISenderName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLNDIMediaOutput, NDISenderName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NDISenderName_MetaData), NewProp_NDISenderName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_VideoConversionFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_VideoConversionFormat = { "VideoConversionFormat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLNDIMediaOutput, VideoConversionFormat), Z_Construct_UEnum_OWLNDI_ENDIVideoConversionFormat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoConversionFormat_MetaData), NewProp_VideoConversionFormat_MetaData) }; // 860231916
void Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bCaptureAudio_SetBit(void* Obj)
{
	((UOWLNDIMediaOutput*)Obj)->bCaptureAudio = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bCaptureAudio = { "bCaptureAudio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLNDIMediaOutput), &Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bCaptureAudio_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCaptureAudio_MetaData), NewProp_bCaptureAudio_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_AudioSubmix = { "AudioSubmix", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLNDIMediaOutput, AudioSubmix), Z_Construct_UClass_USoundSubmix_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioSubmix_MetaData), NewProp_AudioSubmix_MetaData) };
void Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bHasPriority_SetBit(void* Obj)
{
	((UOWLNDIMediaOutput*)Obj)->bHasPriority = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bHasPriority = { "bHasPriority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLNDIMediaOutput), &Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bHasPriority_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasPriority_MetaData), NewProp_bHasPriority_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLNDIMediaOutput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_NDISenderName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_VideoConversionFormat_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_VideoConversionFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bCaptureAudio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_AudioSubmix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaOutput_Statics::NewProp_bHasPriority,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaOutput_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLNDIMediaOutput_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMediaOutput,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLNDI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaOutput_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLNDIMediaOutput_Statics::ClassParams = {
	&UOWLNDIMediaOutput::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLNDIMediaOutput_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaOutput_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaOutput_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLNDIMediaOutput_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLNDIMediaOutput()
{
	if (!Z_Registration_Info_UClass_UOWLNDIMediaOutput.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLNDIMediaOutput.OuterSingleton, Z_Construct_UClass_UOWLNDIMediaOutput_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLNDIMediaOutput.OuterSingleton;
}
template<> OWLNDI_API UClass* StaticClass<UOWLNDIMediaOutput>()
{
	return UOWLNDIMediaOutput::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLNDIMediaOutput);
UOWLNDIMediaOutput::~UOWLNDIMediaOutput() {}
// End Class UOWLNDIMediaOutput

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaOutput_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLNDIMediaOutput, UOWLNDIMediaOutput::StaticClass, TEXT("UOWLNDIMediaOutput"), &Z_Registration_Info_UClass_UOWLNDIMediaOutput, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLNDIMediaOutput), 4161536958U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaOutput_h_3250191419(TEXT("/Script/OWLNDI"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaOutput_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaOutput_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
