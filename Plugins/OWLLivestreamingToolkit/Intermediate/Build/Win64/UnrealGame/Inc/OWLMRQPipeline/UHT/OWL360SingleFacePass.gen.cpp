// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360SingleFacePass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360SingleFacePass() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360SingleFacePass();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360SingleFacePass_NoRegister();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Class UOWL360SingleFacePass
void UOWL360SingleFacePass::StaticRegisterNativesUOWL360SingleFacePass()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWL360SingleFacePass);
UClass* Z_Construct_UClass_UOWL360SingleFacePass_NoRegister()
{
	return UOWL360SingleFacePass::StaticClass();
}
struct Z_Construct_UClass_UOWL360SingleFacePass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OWL360Camera/OWL360SingleFacePass.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360SingleFacePass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FaceToRender_MetaData[] = {
		{ "Category", "Output" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360SingleFacePass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeIndex_MetaData[] = {
		{ "Category", "Output" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360SingleFacePass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraGuid_MetaData[] = {
		{ "Category", "Output" },
		{ "Comment", "/* When not empty, only render a specific camera from the sequence */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360SingleFacePass.h" },
		{ "ToolTip", "When not empty, only render a specific camera from the sequence" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWriteIntermediateDebugFiles_MetaData[] = {
		{ "Category", "Output" },
		{ "Comment", "/* In addition to the .owli intermediate files, write exr files and accompanying human-readable metadata text files */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360SingleFacePass.h" },
		{ "ToolTip", "In addition to the .owli intermediate files, write exr files and accompanying human-readable metadata text files" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FaceToRender_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FaceToRender;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EyeIndex_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EyeIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraGuid;
	static void NewProp_bWriteIntermediateDebugFiles_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWriteIntermediateDebugFiles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWL360SingleFacePass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_FaceToRender_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_FaceToRender = { "FaceToRender", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360SingleFacePass, FaceToRender), Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FaceToRender_MetaData), NewProp_FaceToRender_MetaData) }; // 3198239973
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_EyeIndex_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_EyeIndex = { "EyeIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360SingleFacePass, EyeIndex), Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeIndex_MetaData), NewProp_EyeIndex_MetaData) }; // 1376492923
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_CameraGuid = { "CameraGuid", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360SingleFacePass, CameraGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraGuid_MetaData), NewProp_CameraGuid_MetaData) };
void Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_bWriteIntermediateDebugFiles_SetBit(void* Obj)
{
	((UOWL360SingleFacePass*)Obj)->bWriteIntermediateDebugFiles = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_bWriteIntermediateDebugFiles = { "bWriteIntermediateDebugFiles", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360SingleFacePass), &Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_bWriteIntermediateDebugFiles_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWriteIntermediateDebugFiles_MetaData), NewProp_bWriteIntermediateDebugFiles_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWL360SingleFacePass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_FaceToRender_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_FaceToRender,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_EyeIndex_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_EyeIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_CameraGuid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360SingleFacePass_Statics::NewProp_bWriteIntermediateDebugFiles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360SingleFacePass_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWL360SingleFacePass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UOWL360CameraMoviePipelinePass,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360SingleFacePass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWL360SingleFacePass_Statics::ClassParams = {
	&UOWL360SingleFacePass::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWL360SingleFacePass_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360SingleFacePass_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360SingleFacePass_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWL360SingleFacePass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWL360SingleFacePass()
{
	if (!Z_Registration_Info_UClass_UOWL360SingleFacePass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWL360SingleFacePass.OuterSingleton, Z_Construct_UClass_UOWL360SingleFacePass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWL360SingleFacePass.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWL360SingleFacePass>()
{
	return UOWL360SingleFacePass::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWL360SingleFacePass);
// End Class UOWL360SingleFacePass

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360SingleFacePass_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWL360SingleFacePass, UOWL360SingleFacePass::StaticClass, TEXT("UOWL360SingleFacePass"), &Z_Registration_Info_UClass_UOWL360SingleFacePass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWL360SingleFacePass), 1193477854U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360SingleFacePass_h_2233683060(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360SingleFacePass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360SingleFacePass_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
