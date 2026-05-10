// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLNDI/Public/MediaFramework/Output/OWLNDIMediaCapture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLNDIMediaCapture() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USoundSubmix_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
MEDIAIOCORE_API UClass* Z_Construct_UClass_UMediaCapture();
OWLNDI_API UClass* Z_Construct_UClass_UOWLNDIMediaCapture();
OWLNDI_API UClass* Z_Construct_UClass_UOWLNDIMediaCapture_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLNDI();
// End Cross Module References

// Begin Class UOWLNDIMediaCapture
void UOWLNDIMediaCapture::StaticRegisterNativesUOWLNDIMediaCapture()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLNDIMediaCapture);
UClass* Z_Construct_UClass_UOWLNDIMediaCapture_NoRegister()
{
	return UOWLNDIMediaCapture::StaticClass();
}
struct Z_Construct_UClass_UOWLNDIMediaCapture_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Implementation of media capture for NDI.\n * This class handles the actual capturing and sending of render targets via NDI.\n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "MediaFramework/Output/OWLNDIMediaCapture.h" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaCapture.h" },
		{ "ToolTip", "Implementation of media capture for NDI.\nThis class handles the actual capturing and sending of render targets via NDI." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioSubmix_MetaData[] = {
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaCapture.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NDIRenderTarget_MetaData[] = {
		{ "Comment", "// === RENDER TARGET MANAGEMENT ===\n" },
		{ "ModuleRelativePath", "Public/MediaFramework/Output/OWLNDIMediaCapture.h" },
		{ "ToolTip", "=== RENDER TARGET MANAGEMENT ===" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AudioSubmix;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NDIRenderTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLNDIMediaCapture>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLNDIMediaCapture_Statics::NewProp_AudioSubmix = { "AudioSubmix", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLNDIMediaCapture, AudioSubmix), Z_Construct_UClass_USoundSubmix_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioSubmix_MetaData), NewProp_AudioSubmix_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLNDIMediaCapture_Statics::NewProp_NDIRenderTarget = { "NDIRenderTarget", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLNDIMediaCapture, NDIRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NDIRenderTarget_MetaData), NewProp_NDIRenderTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLNDIMediaCapture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaCapture_Statics::NewProp_AudioSubmix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLNDIMediaCapture_Statics::NewProp_NDIRenderTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaCapture_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLNDIMediaCapture_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMediaCapture,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLNDI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaCapture_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLNDIMediaCapture_Statics::ClassParams = {
	&UOWLNDIMediaCapture::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLNDIMediaCapture_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaCapture_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaCapture_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLNDIMediaCapture_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLNDIMediaCapture()
{
	if (!Z_Registration_Info_UClass_UOWLNDIMediaCapture.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLNDIMediaCapture.OuterSingleton, Z_Construct_UClass_UOWLNDIMediaCapture_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLNDIMediaCapture.OuterSingleton;
}
template<> OWLNDI_API UClass* StaticClass<UOWLNDIMediaCapture>()
{
	return UOWLNDIMediaCapture::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLNDIMediaCapture);
// End Class UOWLNDIMediaCapture

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaCapture_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLNDIMediaCapture, UOWLNDIMediaCapture::StaticClass, TEXT("UOWLNDIMediaCapture"), &Z_Registration_Info_UClass_UOWLNDIMediaCapture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLNDIMediaCapture), 3326348993U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaCapture_h_2317362597(TEXT("/Script/OWLNDI"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLNDI_Public_MediaFramework_Output_OWLNDIMediaCapture_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
