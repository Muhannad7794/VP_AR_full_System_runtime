// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Private/Tracks/OWLCompositeTrack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLCompositeTrack() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneSection_NoRegister();
MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneTrack();
MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneTrackTemplateProducer_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLCameraSection_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLCompositeTrack();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLCompositeTrack_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Class UOWLCompositeTrack
void UOWLCompositeTrack::StaticRegisterNativesUOWLCompositeTrack()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLCompositeTrack);
UClass* Z_Construct_UClass_UOWLCompositeTrack_NoRegister()
{
	return UOWLCompositeTrack::StaticClass();
}
struct Z_Construct_UClass_UOWLCompositeTrack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tracks/OWLCompositeTrack.h" },
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionToKey_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sections_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionOrder_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SectionsRaw_MetaData[] = {
		{ "Comment", "// have to maintain this because of the GetAllSections being const\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
		{ "ToolTip", "have to maintain this because of the GetAllSections being const" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterialDynamic_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCompositeTrack.h" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SectionToKey;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sections_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Sections_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Sections;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SectionOrder_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SectionOrder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SectionsRaw_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SectionsRaw;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterialDynamic;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLCompositeTrack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionToKey = { "SectionToKey", nullptr, (EPropertyFlags)0x0144000001080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCompositeTrack, SectionToKey), Z_Construct_UClass_UMovieSceneSection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionToKey_MetaData), NewProp_SectionToKey_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_Sections_ValueProp = { "Sections", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UOWLCameraSection_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_Sections_Key_KeyProp = { "Sections_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_Sections = { "Sections", nullptr, (EPropertyFlags)0x0040008001000008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCompositeTrack, Sections), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sections_MetaData), NewProp_Sections_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionOrder_Inner = { "SectionOrder", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionOrder = { "SectionOrder", nullptr, (EPropertyFlags)0x0040000001000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCompositeTrack, SectionOrder), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionOrder_MetaData), NewProp_SectionOrder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionsRaw_Inner = { "SectionsRaw", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMovieSceneSection_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionsRaw = { "SectionsRaw", nullptr, (EPropertyFlags)0x0040008000002008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCompositeTrack, SectionsRaw), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SectionsRaw_MetaData), NewProp_SectionsRaw_MetaData) };
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_PreviewMaterial = { "PreviewMaterial", nullptr, (EPropertyFlags)0x0040000800002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCompositeTrack, PreviewMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterial_MetaData), NewProp_PreviewMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_PreviewMaterialDynamic = { "PreviewMaterialDynamic", nullptr, (EPropertyFlags)0x0040000800002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCompositeTrack, PreviewMaterialDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterialDynamic_MetaData), NewProp_PreviewMaterialDynamic_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLCompositeTrack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionToKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_Sections_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_Sections_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_Sections,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionOrder_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionsRaw_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_SectionsRaw,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_PreviewMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCompositeTrack_Statics::NewProp_PreviewMaterialDynamic,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCompositeTrack_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLCompositeTrack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMovieSceneTrack,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCompositeTrack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UOWLCompositeTrack_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UMovieSceneTrackTemplateProducer_NoRegister, (int32)VTABLE_OFFSET(UOWLCompositeTrack, IMovieSceneTrackTemplateProducer), false },  // 2607263461
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLCompositeTrack_Statics::ClassParams = {
	&UOWLCompositeTrack::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLCompositeTrack_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCompositeTrack_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00A000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCompositeTrack_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLCompositeTrack_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLCompositeTrack()
{
	if (!Z_Registration_Info_UClass_UOWLCompositeTrack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLCompositeTrack.OuterSingleton, Z_Construct_UClass_UOWLCompositeTrack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLCompositeTrack.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWLCompositeTrack>()
{
	return UOWLCompositeTrack::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLCompositeTrack);
// End Class UOWLCompositeTrack

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCompositeTrack_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLCompositeTrack, UOWLCompositeTrack::StaticClass, TEXT("UOWLCompositeTrack"), &Z_Registration_Info_UClass_UOWLCompositeTrack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLCompositeTrack), 1984507600U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCompositeTrack_h_818717246(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCompositeTrack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCompositeTrack_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
