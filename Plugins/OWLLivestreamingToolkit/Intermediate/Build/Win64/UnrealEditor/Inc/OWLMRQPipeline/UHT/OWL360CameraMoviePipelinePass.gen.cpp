// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360CameraMoviePipelinePass.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360PipelineLauncher.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360PipelineSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360CameraMoviePipelinePass() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
MOVIERENDERPIPELINERENDERPASSES_API UClass* Z_Construct_UClass_UMoviePipelineDeferredPassBase();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLMRQ360Hooks_NoRegister();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360PipelineLauncher();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360PipelineSettings();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Class UOWL360CameraMoviePipelinePass Function SetCustomOutputResolution
struct Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics
{
	struct OWL360CameraMoviePipelinePass_eventSetCustomOutputResolution_Parms
	{
		FIntPoint InRes;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::NewProp_InRes = { "InRes", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CameraMoviePipelinePass_eventSetCustomOutputResolution_Parms, InRes), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::NewProp_InRes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CameraMoviePipelinePass, nullptr, "SetCustomOutputResolution", nullptr, nullptr, Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::OWL360CameraMoviePipelinePass_eventSetCustomOutputResolution_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::OWL360CameraMoviePipelinePass_eventSetCustomOutputResolution_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CameraMoviePipelinePass::execSetCustomOutputResolution)
{
	P_GET_STRUCT(FIntPoint,Z_Param_InRes);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCustomOutputResolution(Z_Param_InRes);
	P_NATIVE_END;
}
// End Class UOWL360CameraMoviePipelinePass Function SetCustomOutputResolution

// Begin Class UOWL360CameraMoviePipelinePass
void UOWL360CameraMoviePipelinePass::StaticRegisterNativesUOWL360CameraMoviePipelinePass()
{
	UClass* Class = UOWL360CameraMoviePipelinePass::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetCustomOutputResolution", &UOWL360CameraMoviePipelinePass::execSetCustomOutputResolution },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWL360CameraMoviePipelinePass);
UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister()
{
	return UOWL360CameraMoviePipelinePass::StaticClass();
}
struct Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OWL360Camera/OWL360CameraMoviePipelinePass.h" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFirstInitialised_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Settings_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "// Blueprint API\n" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "Blueprint API" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Launcher_MetaData[] = {
		{ "Category", "High Resolution Renders" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeAlpha_MetaData[] = {
		{ "Category", "Output" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderingHooks_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelinePass.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bFirstInitialised_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFirstInitialised;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Settings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Launcher;
	static void NewProp_bIncludeAlpha_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeAlpha;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderingHooks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RenderingHooks;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOWL360CameraMoviePipelinePass_SetCustomOutputResolution, "SetCustomOutputResolution" }, // 1429069274
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWL360CameraMoviePipelinePass>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bFirstInitialised_SetBit(void* Obj)
{
	((UOWL360CameraMoviePipelinePass*)Obj)->bFirstInitialised = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bFirstInitialised = { "bFirstInitialised", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CameraMoviePipelinePass), &Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bFirstInitialised_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFirstInitialised_MetaData), NewProp_bFirstInitialised_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_Settings = { "Settings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CameraMoviePipelinePass, Settings), Z_Construct_UScriptStruct_FOWL360PipelineSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Settings_MetaData), NewProp_Settings_MetaData) }; // 3555580295
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_Launcher = { "Launcher", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CameraMoviePipelinePass, Launcher), Z_Construct_UScriptStruct_FOWL360PipelineLauncher, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Launcher_MetaData), NewProp_Launcher_MetaData) }; // 3040617347
void Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bIncludeAlpha_SetBit(void* Obj)
{
	((UOWL360CameraMoviePipelinePass*)Obj)->bIncludeAlpha = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bIncludeAlpha = { "bIncludeAlpha", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CameraMoviePipelinePass), &Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bIncludeAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeAlpha_MetaData), NewProp_bIncludeAlpha_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_RenderingHooks_Inner = { "RenderingHooks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UOWLMRQ360Hooks_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_RenderingHooks = { "RenderingHooks", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CameraMoviePipelinePass, RenderingHooks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderingHooks_MetaData), NewProp_RenderingHooks_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bFirstInitialised,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_Settings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_Launcher,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_bIncludeAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_RenderingHooks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::NewProp_RenderingHooks,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMoviePipelineDeferredPassBase,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::ClassParams = {
	&UOWL360CameraMoviePipelinePass::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass()
{
	if (!Z_Registration_Info_UClass_UOWL360CameraMoviePipelinePass.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWL360CameraMoviePipelinePass.OuterSingleton, Z_Construct_UClass_UOWL360CameraMoviePipelinePass_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWL360CameraMoviePipelinePass.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWL360CameraMoviePipelinePass>()
{
	return UOWL360CameraMoviePipelinePass::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWL360CameraMoviePipelinePass);
// End Class UOWL360CameraMoviePipelinePass

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelinePass_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWL360CameraMoviePipelinePass, UOWL360CameraMoviePipelinePass::StaticClass, TEXT("UOWL360CameraMoviePipelinePass"), &Z_Registration_Info_UClass_UOWL360CameraMoviePipelinePass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWL360CameraMoviePipelinePass), 1427917099U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelinePass_h_2381682831(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelinePass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelinePass_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
