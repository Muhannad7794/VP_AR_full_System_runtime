// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkitEditor/Public/Factories/OWLNDIMediaOutputFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLNDIMediaOutputFactory() {}

// Begin Cross Module References
LIVESTREAMINGTOOLKITEDITOR_API UClass* Z_Construct_UClass_UOWLNDIMediaOutputFactory();
LIVESTREAMINGTOOLKITEDITOR_API UClass* Z_Construct_UClass_UOWLNDIMediaOutputFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkitEditor();
// End Cross Module References

// Begin Class UOWLNDIMediaOutputFactory
void UOWLNDIMediaOutputFactory::StaticRegisterNativesUOWLNDIMediaOutputFactory()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLNDIMediaOutputFactory);
UClass* Z_Construct_UClass_UOWLNDIMediaOutputFactory_NoRegister()
{
	return UOWLNDIMediaOutputFactory::StaticClass();
}
struct Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Factory for creating OWL NDI Media Output assets.\n * This makes the NDI Media Output appear in the Content Browser and dropdowns.\n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Factories/OWLNDIMediaOutputFactory.h" },
		{ "ModuleRelativePath", "Public/Factories/OWLNDIMediaOutputFactory.h" },
		{ "ToolTip", "Factory for creating OWL NDI Media Output assets.\nThis makes the NDI Media Output appear in the Content Browser and dropdowns." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLNDIMediaOutputFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_LivestreamingToolkitEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics::ClassParams = {
	&UOWLNDIMediaOutputFactory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLNDIMediaOutputFactory()
{
	if (!Z_Registration_Info_UClass_UOWLNDIMediaOutputFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLNDIMediaOutputFactory.OuterSingleton, Z_Construct_UClass_UOWLNDIMediaOutputFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLNDIMediaOutputFactory.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITEDITOR_API UClass* StaticClass<UOWLNDIMediaOutputFactory>()
{
	return UOWLNDIMediaOutputFactory::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLNDIMediaOutputFactory);
UOWLNDIMediaOutputFactory::~UOWLNDIMediaOutputFactory() {}
// End Class UOWLNDIMediaOutputFactory

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLNDIMediaOutputFactory_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLNDIMediaOutputFactory, UOWLNDIMediaOutputFactory::StaticClass, TEXT("UOWLNDIMediaOutputFactory"), &Z_Registration_Info_UClass_UOWLNDIMediaOutputFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLNDIMediaOutputFactory), 1083862727U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLNDIMediaOutputFactory_h_1084935978(TEXT("/Script/LivestreamingToolkitEditor"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLNDIMediaOutputFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLNDIMediaOutputFactory_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
