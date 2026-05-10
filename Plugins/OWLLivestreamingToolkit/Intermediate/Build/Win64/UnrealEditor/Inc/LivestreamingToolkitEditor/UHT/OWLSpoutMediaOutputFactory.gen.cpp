// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkitEditor/Public/Factories/OWLSpoutMediaOutputFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLSpoutMediaOutputFactory() {}

// Begin Cross Module References
LIVESTREAMINGTOOLKITEDITOR_API UClass* Z_Construct_UClass_UOWLSpoutMediaOutputFactory();
LIVESTREAMINGTOOLKITEDITOR_API UClass* Z_Construct_UClass_UOWLSpoutMediaOutputFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkitEditor();
// End Cross Module References

// Begin Class UOWLSpoutMediaOutputFactory
void UOWLSpoutMediaOutputFactory::StaticRegisterNativesUOWLSpoutMediaOutputFactory()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLSpoutMediaOutputFactory);
UClass* Z_Construct_UClass_UOWLSpoutMediaOutputFactory_NoRegister()
{
	return UOWLSpoutMediaOutputFactory::StaticClass();
}
struct Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Factory for creating OWL Spout Media Output assets.\n * This makes the Spout Media Output appear in the Content Browser and dropdowns.\n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Factories/OWLSpoutMediaOutputFactory.h" },
		{ "ModuleRelativePath", "Public/Factories/OWLSpoutMediaOutputFactory.h" },
		{ "ToolTip", "Factory for creating OWL Spout Media Output assets.\nThis makes the Spout Media Output appear in the Content Browser and dropdowns." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLSpoutMediaOutputFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_LivestreamingToolkitEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics::ClassParams = {
	&UOWLSpoutMediaOutputFactory::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLSpoutMediaOutputFactory()
{
	if (!Z_Registration_Info_UClass_UOWLSpoutMediaOutputFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLSpoutMediaOutputFactory.OuterSingleton, Z_Construct_UClass_UOWLSpoutMediaOutputFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLSpoutMediaOutputFactory.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITEDITOR_API UClass* StaticClass<UOWLSpoutMediaOutputFactory>()
{
	return UOWLSpoutMediaOutputFactory::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLSpoutMediaOutputFactory);
UOWLSpoutMediaOutputFactory::~UOWLSpoutMediaOutputFactory() {}
// End Class UOWLSpoutMediaOutputFactory

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaOutputFactory_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLSpoutMediaOutputFactory, UOWLSpoutMediaOutputFactory::StaticClass, TEXT("UOWLSpoutMediaOutputFactory"), &Z_Registration_Info_UClass_UOWLSpoutMediaOutputFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLSpoutMediaOutputFactory), 799949384U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaOutputFactory_h_2377861246(TEXT("/Script/LivestreamingToolkitEditor"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaOutputFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaOutputFactory_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
