// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLSpout/Public/MediaFramework/Output/OWLSpoutMediaOutput.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLSpoutMediaOutput() {}

// Begin Cross Module References
MEDIAIOCORE_API UClass* Z_Construct_UClass_UMediaOutput();
OWLSPOUT_API UClass* Z_Construct_UClass_UOWLSpoutMediaOutput();
OWLSPOUT_API UClass* Z_Construct_UClass_UOWLSpoutMediaOutput_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLSpout();
// End Cross Module References

// Begin Class UOWLSpoutMediaOutput
void UOWLSpoutMediaOutput::StaticRegisterNativesUOWLSpoutMediaOutput()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLSpoutMediaOutput);
UClass* Z_Construct_UClass_UOWLSpoutMediaOutput_NoRegister()
{
	return UOWLSpoutMediaOutput::StaticClass();
}
struct Z_Construct_UClass_UOWLSpoutMediaOutput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Output information for a Spout media capture.\n * This class appears in the Media Output dropdown in nDisplay and other UE systems.\n */" },
		{ "DisplayName", "OWL Spout Output" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "MediaFramework/Output/OWLSpoutMediaOutput.h" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLSpoutMediaOutput.h" },
		{ "ToolTip", "Output information for a Spout media capture.\nThis class appears in the Media Output dropdown in nDisplay and other UE systems." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpoutSenderName_MetaData[] = {
		{ "Category", "Spout" },
		{ "Comment", "/** Name of the Spout sender. If empty, will use a default name based on the viewport. */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLSpoutMediaOutput.h" },
		{ "ToolTip", "Name of the Spout sender. If empty, will use a default name based on the viewport." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFixGamma_MetaData[] = {
		{ "Category", "Spout" },
		{ "Comment", "/** \n\x09 * Apply gamma correction to match Unreal's viewport appearance.\n\x09 * Unreal manages files in linear color space but applies linear to sRGB conversion.\n\x09 * Enable this to make your Spout output look the same as the viewport.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLSpoutMediaOutput.h" },
		{ "ToolTip", "Apply gamma correction to match Unreal's viewport appearance.\nUnreal manages files in linear color space but applies linear to sRGB conversion.\nEnable this to make your Spout output look the same as the viewport." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasPriority_MetaData[] = {
		{ "Category", "Spout" },
		{ "Comment", "/** \n\x09 * Priority sender - will take precedence if multiple senders try to use the same name.\n\x09 * Useful when you want this sender to be the \"main\" sender.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLSpoutMediaOutput.h" },
		{ "ToolTip", "Priority sender - will take precedence if multiple senders try to use the same name.\nUseful when you want this sender to be the \"main\" sender." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SpoutSenderName;
	static void NewProp_bFixGamma_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFixGamma;
	static void NewProp_bHasPriority_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLSpoutMediaOutput>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_SpoutSenderName = { "SpoutSenderName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLSpoutMediaOutput, SpoutSenderName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpoutSenderName_MetaData), NewProp_SpoutSenderName_MetaData) };
void Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bFixGamma_SetBit(void* Obj)
{
	((UOWLSpoutMediaOutput*)Obj)->bFixGamma = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bFixGamma = { "bFixGamma", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLSpoutMediaOutput), &Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bFixGamma_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFixGamma_MetaData), NewProp_bFixGamma_MetaData) };
void Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bHasPriority_SetBit(void* Obj)
{
	((UOWLSpoutMediaOutput*)Obj)->bHasPriority = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bHasPriority = { "bHasPriority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLSpoutMediaOutput), &Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bHasPriority_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasPriority_MetaData), NewProp_bHasPriority_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_SpoutSenderName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bFixGamma,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::NewProp_bHasPriority,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMediaOutput,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLSpout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::ClassParams = {
	&UOWLSpoutMediaOutput::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::PropPointers),
	0,
	0x001010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLSpoutMediaOutput()
{
	if (!Z_Registration_Info_UClass_UOWLSpoutMediaOutput.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLSpoutMediaOutput.OuterSingleton, Z_Construct_UClass_UOWLSpoutMediaOutput_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLSpoutMediaOutput.OuterSingleton;
}
template<> OWLSPOUT_API UClass* StaticClass<UOWLSpoutMediaOutput>()
{
	return UOWLSpoutMediaOutput::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLSpoutMediaOutput);
UOWLSpoutMediaOutput::~UOWLSpoutMediaOutput() {}
// End Class UOWLSpoutMediaOutput

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaOutput_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLSpoutMediaOutput, UOWLSpoutMediaOutput::StaticClass, TEXT("UOWLSpoutMediaOutput"), &Z_Registration_Info_UClass_UOWLSpoutMediaOutput, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLSpoutMediaOutput), 3071122004U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaOutput_h_2257789285(TEXT("/Script/OWLSpout"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaOutput_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaOutput_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
