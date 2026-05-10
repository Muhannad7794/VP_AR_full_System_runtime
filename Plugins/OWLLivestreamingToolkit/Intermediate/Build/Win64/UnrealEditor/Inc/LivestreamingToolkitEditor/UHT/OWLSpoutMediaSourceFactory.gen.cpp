// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkitEditor/Public/Factories/OWLSpoutMediaSourceFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLSpoutMediaSourceFactory() {}

// Begin Cross Module References
LIVESTREAMINGTOOLKITEDITOR_API UClass* Z_Construct_UClass_UOWLSpoutMediaSourceFactory();
LIVESTREAMINGTOOLKITEDITOR_API UClass* Z_Construct_UClass_UOWLSpoutMediaSourceFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkitEditor();
// End Cross Module References

// Begin Class UOWLSpoutMediaSourceFactory
void UOWLSpoutMediaSourceFactory::StaticRegisterNativesUOWLSpoutMediaSourceFactory()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLSpoutMediaSourceFactory);
UClass* Z_Construct_UClass_UOWLSpoutMediaSourceFactory_NoRegister()
{
	return UOWLSpoutMediaSourceFactory::StaticClass();
}
struct Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Implements a factory for UOWLSpoutMediaSource objects.\n * This makes \"Spout Media Source\" appear in the Content Browser's right-click \"Media\" menu.\n */" },
		{ "IncludePath", "Factories/OWLSpoutMediaSourceFactory.h" },
		{ "ModuleRelativePath", "Public/Factories/OWLSpoutMediaSourceFactory.h" },
		{ "ToolTip", "Implements a factory for UOWLSpoutMediaSource objects.\nThis makes \"Spout Media Source\" appear in the Content Browser's right-click \"Media\" menu." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLSpoutMediaSourceFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_LivestreamingToolkitEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics::ClassParams = {
	&UOWLSpoutMediaSourceFactory::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLSpoutMediaSourceFactory()
{
	if (!Z_Registration_Info_UClass_UOWLSpoutMediaSourceFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLSpoutMediaSourceFactory.OuterSingleton, Z_Construct_UClass_UOWLSpoutMediaSourceFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLSpoutMediaSourceFactory.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITEDITOR_API UClass* StaticClass<UOWLSpoutMediaSourceFactory>()
{
	return UOWLSpoutMediaSourceFactory::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLSpoutMediaSourceFactory);
UOWLSpoutMediaSourceFactory::~UOWLSpoutMediaSourceFactory() {}
// End Class UOWLSpoutMediaSourceFactory

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaSourceFactory_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLSpoutMediaSourceFactory, UOWLSpoutMediaSourceFactory::StaticClass, TEXT("UOWLSpoutMediaSourceFactory"), &Z_Registration_Info_UClass_UOWLSpoutMediaSourceFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLSpoutMediaSourceFactory), 914092975U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaSourceFactory_h_502072240(TEXT("/Script/LivestreamingToolkitEditor"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaSourceFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_Factories_OWLSpoutMediaSourceFactory_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
