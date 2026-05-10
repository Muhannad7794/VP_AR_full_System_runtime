// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLSpout/Public/MediaFramework/Output/OWLSpoutMediaCapture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLSpoutMediaCapture() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
MEDIAIOCORE_API UClass* Z_Construct_UClass_UMediaCapture();
OWLSPOUT_API UClass* Z_Construct_UClass_UOWLSpoutMediaCapture();
OWLSPOUT_API UClass* Z_Construct_UClass_UOWLSpoutMediaCapture_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLSpout();
// End Cross Module References

// Begin Class UOWLSpoutMediaCapture
void UOWLSpoutMediaCapture::StaticRegisterNativesUOWLSpoutMediaCapture()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLSpoutMediaCapture);
UClass* Z_Construct_UClass_UOWLSpoutMediaCapture_NoRegister()
{
	return UOWLSpoutMediaCapture::StaticClass();
}
struct Z_Construct_UClass_UOWLSpoutMediaCapture_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Implementation of media capture for Spout.\n * This class handles the actual capturing and sending of render targets via Spout.\n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "MediaFramework/Output/OWLSpoutMediaCapture.h" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLSpoutMediaCapture.h" },
		{ "ToolTip", "Implementation of media capture for Spout.\nThis class handles the actual capturing and sending of render targets via Spout." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpoutRenderTarget_MetaData[] = {
		{ "Comment", "// === RENDER TARGET MANAGEMENT ===\n" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLSpoutMediaCapture.h" },
		{ "ToolTip", "=== RENDER TARGET MANAGEMENT ===" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpoutRenderTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLSpoutMediaCapture>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::NewProp_SpoutRenderTarget = { "SpoutRenderTarget", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLSpoutMediaCapture, SpoutRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpoutRenderTarget_MetaData), NewProp_SpoutRenderTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::NewProp_SpoutRenderTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMediaCapture,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLSpout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::ClassParams = {
	&UOWLSpoutMediaCapture::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLSpoutMediaCapture()
{
	if (!Z_Registration_Info_UClass_UOWLSpoutMediaCapture.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLSpoutMediaCapture.OuterSingleton, Z_Construct_UClass_UOWLSpoutMediaCapture_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLSpoutMediaCapture.OuterSingleton;
}
template<> OWLSPOUT_API UClass* StaticClass<UOWLSpoutMediaCapture>()
{
	return UOWLSpoutMediaCapture::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLSpoutMediaCapture);
// End Class UOWLSpoutMediaCapture

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaCapture_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLSpoutMediaCapture, UOWLSpoutMediaCapture::StaticClass, TEXT("UOWLSpoutMediaCapture"), &Z_Registration_Info_UClass_UOWLSpoutMediaCapture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLSpoutMediaCapture), 568904272U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaCapture_h_3328061597(TEXT("/Script/OWLSpout"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLSpout_Public_MediaFramework_Output_OWLSpoutMediaCapture_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
