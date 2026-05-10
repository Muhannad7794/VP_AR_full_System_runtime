// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Private/Tracks/OWLCameraSection.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360CameraMoviePipelineData.h"
#include "Runtime/MovieScene/Public/Channels/MovieSceneFloatChannel.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLCameraSection() {}

// Begin Cross Module References
MOVIESCENE_API UClass* Z_Construct_UClass_UMovieSceneSection();
MOVIESCENE_API UScriptStruct* Z_Construct_UScriptStruct_FMovieSceneFloatChannel();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLCameraSection();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLCameraSection_NoRegister();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFoundSequenceCamera();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Class UOWLCameraSection
void UOWLCameraSection::StaticRegisterNativesUOWLCameraSection()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLCameraSection);
UClass* Z_Construct_UClass_UOWLCameraSection_NoRegister()
{
	return UOWLCameraSection::StaticClass();
}
struct Z_Construct_UClass_UOWLCameraSection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tracks/OWLCameraSection.h" },
		{ "ModuleRelativePath", "Private/Tracks/OWLCameraSection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpacityCurve_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCameraSection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortOrder_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCameraSection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompositeMode_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCameraSection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssociatedCamera_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCameraSection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCameraBound_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tracks/OWLCameraSection.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OpacityCurve;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SortOrder;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CompositeMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CompositeMode;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AssociatedCamera;
	static void NewProp_bCameraBound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCameraBound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLCameraSection>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_OpacityCurve = { "OpacityCurve", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCameraSection, OpacityCurve), Z_Construct_UScriptStruct_FMovieSceneFloatChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpacityCurve_MetaData), NewProp_OpacityCurve_MetaData) }; // 139010471
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_SortOrder = { "SortOrder", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCameraSection, SortOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortOrder_MetaData), NewProp_SortOrder_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_CompositeMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_CompositeMode = { "CompositeMode", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCameraSection, CompositeMode), Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompositeMode_MetaData), NewProp_CompositeMode_MetaData) }; // 4207851973
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_AssociatedCamera = { "AssociatedCamera", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLCameraSection, AssociatedCamera), Z_Construct_UScriptStruct_FOWLFoundSequenceCamera, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssociatedCamera_MetaData), NewProp_AssociatedCamera_MetaData) }; // 3558897373
void Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_bCameraBound_SetBit(void* Obj)
{
	((UOWLCameraSection*)Obj)->bCameraBound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_bCameraBound = { "bCameraBound", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLCameraSection), &Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_bCameraBound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCameraBound_MetaData), NewProp_bCameraBound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLCameraSection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_OpacityCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_SortOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_CompositeMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_CompositeMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_AssociatedCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLCameraSection_Statics::NewProp_bCameraBound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCameraSection_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLCameraSection_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMovieSceneSection,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCameraSection_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLCameraSection_Statics::ClassParams = {
	&UOWLCameraSection::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLCameraSection_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCameraSection_Statics::PropPointers),
	0,
	0x002000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLCameraSection_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLCameraSection_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLCameraSection()
{
	if (!Z_Registration_Info_UClass_UOWLCameraSection.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLCameraSection.OuterSingleton, Z_Construct_UClass_UOWLCameraSection_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLCameraSection.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWLCameraSection>()
{
	return UOWLCameraSection::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLCameraSection);
IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UOWLCameraSection)
// End Class UOWLCameraSection

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCameraSection_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLCameraSection, UOWLCameraSection::StaticClass, TEXT("UOWLCameraSection"), &Z_Registration_Info_UClass_UOWLCameraSection, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLCameraSection), 1460170099U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCameraSection_h_3604471244(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCameraSection_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Private_Tracks_OWLCameraSection_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
