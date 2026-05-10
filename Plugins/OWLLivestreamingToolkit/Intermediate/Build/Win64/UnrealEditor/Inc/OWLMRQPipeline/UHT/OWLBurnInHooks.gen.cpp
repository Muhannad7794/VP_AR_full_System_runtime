// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWLBurnInHooks.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWLMRQ360Hooks.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLBurnInHooks() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
MOVIERENDERPIPELINECORE_API UClass* Z_Construct_UClass_UMoviePipeline_NoRegister();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360CaptureComponent_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLBurnInHooks();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLBurnInHooks_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLMRQ360Hooks();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWLMovieSampleState();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Enum EOWLBurnInAlignment
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLBurnInAlignment;
static UEnum* EOWLBurnInAlignment_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLBurnInAlignment.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLBurnInAlignment.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("EOWLBurnInAlignment"));
	}
	return Z_Registration_Info_UEnum_EOWLBurnInAlignment.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLBurnInAlignment>()
{
	return EOWLBurnInAlignment_StaticEnum();
}
struct Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AL_BottomCenter.DisplayName", "Bottom Center" },
		{ "AL_BottomCenter.Name", "EOWLBurnInAlignment::AL_BottomCenter" },
		{ "AL_BottomLeft.DisplayName", "Bottom Left" },
		{ "AL_BottomLeft.Name", "EOWLBurnInAlignment::AL_BottomLeft" },
		{ "AL_BottomRight.DisplayName", "Bottom Right" },
		{ "AL_BottomRight.Name", "EOWLBurnInAlignment::AL_BottomRight" },
		{ "AL_Center.DisplayName", "Center" },
		{ "AL_Center.Name", "EOWLBurnInAlignment::AL_Center" },
		{ "AL_Custom.DisplayName", "Custom" },
		{ "AL_Custom.Name", "EOWLBurnInAlignment::AL_Custom" },
		{ "AL_TopCenter.DisplayName", "Top Center" },
		{ "AL_TopCenter.Name", "EOWLBurnInAlignment::AL_TopCenter" },
		{ "AL_TopLeft.DisplayName", "Top Left" },
		{ "AL_TopLeft.Name", "EOWLBurnInAlignment::AL_TopLeft" },
		{ "AL_TopRight.DisplayName", "Top Right" },
		{ "AL_TopRight.Name", "EOWLBurnInAlignment::AL_TopRight" },
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLBurnInAlignment::AL_TopLeft", (int64)EOWLBurnInAlignment::AL_TopLeft },
		{ "EOWLBurnInAlignment::AL_TopRight", (int64)EOWLBurnInAlignment::AL_TopRight },
		{ "EOWLBurnInAlignment::AL_TopCenter", (int64)EOWLBurnInAlignment::AL_TopCenter },
		{ "EOWLBurnInAlignment::AL_BottomLeft", (int64)EOWLBurnInAlignment::AL_BottomLeft },
		{ "EOWLBurnInAlignment::AL_BottomRight", (int64)EOWLBurnInAlignment::AL_BottomRight },
		{ "EOWLBurnInAlignment::AL_BottomCenter", (int64)EOWLBurnInAlignment::AL_BottomCenter },
		{ "EOWLBurnInAlignment::AL_Center", (int64)EOWLBurnInAlignment::AL_Center },
		{ "EOWLBurnInAlignment::AL_Custom", (int64)EOWLBurnInAlignment::AL_Custom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	"EOWLBurnInAlignment",
	"EOWLBurnInAlignment",
	Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment()
{
	if (!Z_Registration_Info_UEnum_EOWLBurnInAlignment.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLBurnInAlignment.InnerSingleton, Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLBurnInAlignment.InnerSingleton;
}
// End Enum EOWLBurnInAlignment

// Begin Class UOWLBurnInHooks Function UpdateWidgetPreRender
struct OWLBurnInHooks_eventUpdateWidgetPreRender_Parms
{
	FOWLMovieSampleState SampleState;
	const UOWL360CameraMoviePipelinePass* OWLPass;
	const UMoviePipeline* Pipeline;
	const UOWL360CaptureComponent* CaptureComponent;
};
static FName NAME_UOWLBurnInHooks_UpdateWidgetPreRender = FName(TEXT("UpdateWidgetPreRender"));
void UOWLBurnInHooks::UpdateWidgetPreRender(FOWLMovieSampleState const& SampleState, const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline, const UOWL360CaptureComponent* CaptureComponent)
{
	OWLBurnInHooks_eventUpdateWidgetPreRender_Parms Parms;
	Parms.SampleState=SampleState;
	Parms.OWLPass=OWLPass;
	Parms.Pipeline=Pipeline;
	Parms.CaptureComponent=CaptureComponent;
	ProcessEvent(FindFunctionChecked(NAME_UOWLBurnInHooks_UpdateWidgetPreRender),&Parms);
}
struct Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Burn In" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SampleState_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OWLPass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pipeline_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SampleState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OWLPass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_SampleState = { "SampleState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLBurnInHooks_eventUpdateWidgetPreRender_Parms, SampleState), Z_Construct_UScriptStruct_FOWLMovieSampleState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SampleState_MetaData), NewProp_SampleState_MetaData) }; // 3424178246
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_OWLPass = { "OWLPass", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLBurnInHooks_eventUpdateWidgetPreRender_Parms, OWLPass), Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OWLPass_MetaData), NewProp_OWLPass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLBurnInHooks_eventUpdateWidgetPreRender_Parms, Pipeline), Z_Construct_UClass_UMoviePipeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pipeline_MetaData), NewProp_Pipeline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_CaptureComponent = { "CaptureComponent", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLBurnInHooks_eventUpdateWidgetPreRender_Parms, CaptureComponent), Z_Construct_UClass_UOWL360CaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureComponent_MetaData), NewProp_CaptureComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_SampleState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_OWLPass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_Pipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::NewProp_CaptureComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWLBurnInHooks, nullptr, "UpdateWidgetPreRender", nullptr, nullptr, Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::PropPointers), sizeof(OWLBurnInHooks_eventUpdateWidgetPreRender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::Function_MetaDataParams) };
static_assert(sizeof(OWLBurnInHooks_eventUpdateWidgetPreRender_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWLBurnInHooks::execUpdateWidgetPreRender)
{
	P_GET_STRUCT_REF(FOWLMovieSampleState,Z_Param_Out_SampleState);
	P_GET_OBJECT(UOWL360CameraMoviePipelinePass,Z_Param_OWLPass);
	P_GET_OBJECT(UMoviePipeline,Z_Param_Pipeline);
	P_GET_OBJECT(UOWL360CaptureComponent,Z_Param_CaptureComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateWidgetPreRender_Implementation(Z_Param_Out_SampleState,Z_Param_OWLPass,Z_Param_Pipeline,Z_Param_CaptureComponent);
	P_NATIVE_END;
}
// End Class UOWLBurnInHooks Function UpdateWidgetPreRender

// Begin Class UOWLBurnInHooks
void UOWLBurnInHooks::StaticRegisterNativesUOWLBurnInHooks()
{
	UClass* Class = UOWLBurnInHooks::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "UpdateWidgetPreRender", &UOWLBurnInHooks::execUpdateWidgetPreRender },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLBurnInHooks);
UClass* Z_Construct_UClass_UOWLBurnInHooks_NoRegister()
{
	return UOWLBurnInHooks::StaticClass();
}
struct Z_Construct_UClass_UOWLBurnInHooks_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * This class enables you to render custom widgets on top\n * of the stitched 360 content. Optionally it can be added\n * as a separate pass with transparency in your EXR output\n */" },
		{ "IncludePath", "OWL360Camera/OWLBurnInHooks.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "This class enables you to render custom widgets on top\nof the stitched 360 content. Optionally it can be added\nas a separate pass with transparency in your EXR output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Alignment_MetaData[] = {
		{ "Category", "Burn In" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopLeft_MetaData[] = {
		{ "Category", "Burn In" },
		{ "Comment", "/* Position of the top left of the Burn in UI on the final output */" },
		{ "EditCondition", "Alignment == EOWLBurnInAlignment::AL_Custom" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
		{ "ToolTip", "Position of the top left of the Burn in UI on the final output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetWidth_MetaData[] = {
		{ "Category", "Burn In" },
		{ "ClampMax", "3500" },
		{ "ClampMin", "30" },
		{ "Comment", "/* Width of the widget in pixels */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
		{ "ToolTip", "Width of the widget in pixels" },
		{ "UIMax", "3500" },
		{ "UIMin", "30" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetHeight_MetaData[] = {
		{ "Category", "Burn In" },
		{ "ClampMax", "3500" },
		{ "ClampMin", "30" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
		{ "UIMax", "3500" },
		{ "UIMin", "30" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bExportAsSeparatePass_MetaData[] = {
		{ "Category", "Burn In" },
		{ "Comment", "/* Do not composite this onto the main color output, instead export it as a layer to EXR etc */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
		{ "ToolTip", "Do not composite this onto the main color output, instead export it as a layer to EXR etc" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetType_MetaData[] = {
		{ "Category", "Burn In" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurnInTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetToRender_MetaData[] = {
		{ "Category", "Burn In" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLBurnInHooks.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Alignment_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Alignment;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TopLeft;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WidgetWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WidgetHeight;
	static void NewProp_bExportAsSeparatePass_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExportAsSeparatePass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WidgetType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BurnInTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetToRender;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOWLBurnInHooks_UpdateWidgetPreRender, "UpdateWidgetPreRender" }, // 140272929
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLBurnInHooks>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_Alignment_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_Alignment = { "Alignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, Alignment), Z_Construct_UEnum_OWLMRQPipeline_EOWLBurnInAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Alignment_MetaData), NewProp_Alignment_MetaData) }; // 1399565831
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_TopLeft = { "TopLeft", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, TopLeft), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopLeft_MetaData), NewProp_TopLeft_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetWidth = { "WidgetWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, WidgetWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetWidth_MetaData), NewProp_WidgetWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetHeight = { "WidgetHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, WidgetHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetHeight_MetaData), NewProp_WidgetHeight_MetaData) };
void Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_bExportAsSeparatePass_SetBit(void* Obj)
{
	((UOWLBurnInHooks*)Obj)->bExportAsSeparatePass = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_bExportAsSeparatePass = { "bExportAsSeparatePass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLBurnInHooks), &Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_bExportAsSeparatePass_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bExportAsSeparatePass_MetaData), NewProp_bExportAsSeparatePass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetType = { "WidgetType", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, WidgetType), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetType_MetaData), NewProp_WidgetType_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_BurnInTarget = { "BurnInTarget", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, BurnInTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurnInTarget_MetaData), NewProp_BurnInTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetToRender = { "WidgetToRender", nullptr, (EPropertyFlags)0x01240800000a201d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLBurnInHooks, WidgetToRender), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetToRender_MetaData), NewProp_WidgetToRender_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLBurnInHooks_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_Alignment_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_Alignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_TopLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_bExportAsSeparatePass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_BurnInTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLBurnInHooks_Statics::NewProp_WidgetToRender,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLBurnInHooks_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLBurnInHooks_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UOWLMRQ360Hooks,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLBurnInHooks_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLBurnInHooks_Statics::ClassParams = {
	&UOWLBurnInHooks::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOWLBurnInHooks_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLBurnInHooks_Statics::PropPointers),
	0,
	0x008800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLBurnInHooks_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLBurnInHooks_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLBurnInHooks()
{
	if (!Z_Registration_Info_UClass_UOWLBurnInHooks.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLBurnInHooks.OuterSingleton, Z_Construct_UClass_UOWLBurnInHooks_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLBurnInHooks.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWLBurnInHooks>()
{
	return UOWLBurnInHooks::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLBurnInHooks);
UOWLBurnInHooks::~UOWLBurnInHooks() {}
// End Class UOWLBurnInHooks

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLBurnInAlignment_StaticEnum, TEXT("EOWLBurnInAlignment"), &Z_Registration_Info_UEnum_EOWLBurnInAlignment, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1399565831U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLBurnInHooks, UOWLBurnInHooks::StaticClass, TEXT("UOWLBurnInHooks"), &Z_Registration_Info_UClass_UOWLBurnInHooks, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLBurnInHooks), 1103331994U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_984985857(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLBurnInHooks_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
