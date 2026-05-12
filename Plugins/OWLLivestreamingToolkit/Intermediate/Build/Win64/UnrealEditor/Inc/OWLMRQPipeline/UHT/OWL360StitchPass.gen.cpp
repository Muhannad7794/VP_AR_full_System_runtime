// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360StitchPass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360StitchPass() {}

// Begin Cross Module References
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360StitchPass();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360StitchPass_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Class UOWL360StitchPass
void UOWL360StitchPass::StaticRegisterNativesUOWL360StitchPass()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWL360StitchPass);
UClass* Z_Construct_UClass_UOWL360StitchPass_NoRegister()
{
	return UOWL360StitchPass::StaticClass();
}
struct Z_Construct_UClass_UOWL360StitchPass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OWL360Camera/OWL360StitchPass.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360StitchPass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDeleteIntermediatesAfterStitch_MetaData[] = {
		{ "Category", "Stitching" },
		{ "Comment", "/* Delete the intermediate files once stitching has completed */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360StitchPass.h" },
		{ "ToolTip", "Delete the intermediate files once stitching has completed" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxConcurrentStitches_MetaData[] = {
		{ "Category", "Stitching|Advanced" },
		{ "ClampMax", "20" },
		{ "ClampMin", "0" },
		{ "Comment", "/* Maximum number of stitches to run on separate threads concurrently. Lower this number if you run into RAM issues */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360StitchPass.h" },
		{ "ToolTip", "Maximum number of stitches to run on separate threads concurrently. Lower this number if you run into RAM issues" },
		{ "UIMax", "20" },
		{ "UIMin", "0" },
	};
#endif // WITH_METADATA
	static void NewProp_bDeleteIntermediatesAfterStitch_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDeleteIntermediatesAfterStitch;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxConcurrentStitches;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWL360StitchPass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UOWL360StitchPass_Statics::NewProp_bDeleteIntermediatesAfterStitch_SetBit(void* Obj)
{
	((UOWL360StitchPass*)Obj)->bDeleteIntermediatesAfterStitch = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360StitchPass_Statics::NewProp_bDeleteIntermediatesAfterStitch = { "bDeleteIntermediatesAfterStitch", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360StitchPass), &Z_Construct_UClass_UOWL360StitchPass_Statics::NewProp_bDeleteIntermediatesAfterStitch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDeleteIntermediatesAfterStitch_MetaData), NewProp_bDeleteIntermediatesAfterStitch_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360StitchPass_Statics::NewProp_MaxConcurrentStitches = { "MaxConcurrentStitches", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360StitchPass, MaxConcurrentStitches), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxConcurrentStitches_MetaData), NewProp_MaxConcurrentStitches_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWL360StitchPass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360StitchPass_Statics::NewProp_bDeleteIntermediatesAfterStitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360StitchPass_Statics::NewProp_MaxConcurrentStitches,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360StitchPass_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWL360StitchPass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UOWL360CameraMoviePipelinePass,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360StitchPass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWL360StitchPass_Statics::ClassParams = {
	&UOWL360StitchPass::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWL360StitchPass_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360StitchPass_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360StitchPass_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWL360StitchPass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWL360StitchPass()
{
	if (!Z_Registration_Info_UClass_UOWL360StitchPass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWL360StitchPass.OuterSingleton, Z_Construct_UClass_UOWL360StitchPass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWL360StitchPass.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWL360StitchPass>()
{
	return UOWL360StitchPass::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWL360StitchPass);
UOWL360StitchPass::~UOWL360StitchPass() {}
// End Class UOWL360StitchPass

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360StitchPass_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWL360StitchPass, UOWL360StitchPass::StaticClass, TEXT("UOWL360StitchPass"), &Z_Registration_Info_UClass_UOWL360StitchPass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWL360StitchPass), 54160887U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360StitchPass_h_1265437258(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360StitchPass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360StitchPass_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
