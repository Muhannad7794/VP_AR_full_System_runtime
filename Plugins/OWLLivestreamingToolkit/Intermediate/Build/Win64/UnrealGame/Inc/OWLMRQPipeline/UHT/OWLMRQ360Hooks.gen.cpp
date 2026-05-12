// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWLMRQ360Hooks.h"
#include "OWL360Camera/Public/DataTypes/OWLFaceCrop.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLMRQ360Hooks() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTimecode();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FPostProcessSettings();
MOVIERENDERPIPELINECORE_API UClass* Z_Construct_UClass_UMoviePipeline_NoRegister();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360CaptureComponent_NoRegister();
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFaceCrop();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLMRQ360Hooks();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLMRQ360Hooks_NoRegister();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360HookStitchInfo();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360HookTileInfo();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWLMovieSampleState();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin ScriptStruct FOWLMovieSampleState
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLMovieSampleState;
class UScriptStruct* FOWLMovieSampleState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLMovieSampleState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLMovieSampleState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLMovieSampleState, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWLMovieSampleState"));
	}
	return Z_Registration_Info_UScriptStruct_OWLMovieSampleState.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWLMovieSampleState>()
{
	return FOWLMovieSampleState::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputFrameNumber_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/**\n\x09* The expected output frame count that the render is working towards creating.\n\x09* This number accurately tracks the number of frames we have produced even if\n\x09* the file written to disk uses a different number (due to relative frame numbers\n\x09* or offset frames being added.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The expected output frame count that the render is working towards creating.\nThis number accurately tracks the number of frames we have produced even if\nthe file written to disk uses a different number (due to relative frame numbers\nor offset frames being added." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotIndex_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** Which shot is this output state for? */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Which shot is this output state for?" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotCount_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** How many shots total will we be outputting? */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "How many shots total will we be outputting?" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemporalSampleIndex_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** Which sub-frame are we on when using Accumulation Frame rendering. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Which sub-frame are we on when using Accumulation Frame rendering." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemporalSampleCount_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** How many temporal samples do we add together to produce one Output Frame? */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "How many temporal samples do we add together to produce one Output Frame?" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotOutputFrameNumber_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/**\n\x09* The expected output frame count for this current shot that we're working towards\n\x09* creating. Like OutputFrameNumber but relative to this shot. This should get reset between shots.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The expected output frame count for this current shot that we're working towards\ncreating. Like OutputFrameNumber but relative to this shot. This should get reset between shots." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotSamplesRendered_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** The total number of samples (including warm ups) that have been sent to the GPU for this shot. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The total number of samples (including warm ups) that have been sent to the GPU for this shot." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraName_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** The name of the currently active camera being rendered. May be empty. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The name of the currently active camera being rendered. May be empty." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraNameOverride_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** Name used by the {camera_name} format tag. May be empty */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Name used by the {camera_name} format tag. May be empty" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotName_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** THe name of the currently active shot. May be empty if there is no shot track. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "THe name of the currently active shot. May be empty if there is no shot track." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipRendering_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/**\n\x09* This can be true when the fade value is 0 for the current camera.\n\x09* If true, then the rendering for this frame should be skipped (ie: nothing submitted to the gpu, and the output merger not told to expect this frame).\n\x09* This is used for rendering every Nth frame for rendering drafts. We still run the game thread logic for the skipped frames (which is relatively cheap)\n\x09* and simply omit rendering them. This increases consistency with non-skipped renders, and will be useful for consistency when rendering on a farm.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "This can be true when the fade value is 0 for the current camera.\nIf true, then the rendering for this frame should be skipped (ie: nothing submitted to the gpu, and the output merger not told to expect this frame).\nThis is used for rendering every Nth frame for rendering drafts. We still run the game thread logic for the skipped frames (which is relatively cheap)\nand simply omit rendering them. This increases consistency with non-skipped renders, and will be useful for consistency when rendering on a farm." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCaptureRendering_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/**\n\x09* If true, and a IRenderCaptureProvider is available, trigger a capture of the rendering process of this frame.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "If true, and a IRenderCaptureProvider is available, trigger a capture of the rendering process of this frame." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDiscardRenderResult_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/**\n\x09* If this is true, then the frame will be rendered but the results discarded and not sent to the accumulator. This is used for render warmup frames\n\x09* or gpu-based feedback loops. Ignored if bSkipRendering is true.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "If this is true, then the frame will be rendered but the results discarded and not sent to the accumulator. This is used for render warmup frames\nor gpu-based feedback loops. Ignored if bSkipRendering is true." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceFrameNumber_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** The closest frame number (in Display Rate) on the Sequence. May be duplicates in the case of different output framerate or Play Rate tracks. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The closest frame number (in Display Rate) on the Sequence. May be duplicates in the case of different output framerate or Play Rate tracks." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceTimeCode_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** The closest time code version of the SourceFrameNumber on the Sequence. May be a duplicate in the case of different output framerate or Play Rate tracks. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The closest time code version of the SourceFrameNumber on the Sequence. May be a duplicate in the case of different output framerate or Play Rate tracks." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectiveFrameNumber_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/**\n\x09* The closest frame number (in Display Rate) on the Sequence adjusted for the effective output rate. These numbers will not line up with the frame\n\x09* in the source Sequence if the output frame rate differs from the Sequence display rate. May be a duplicate in the event of Play Rate tracks.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The closest frame number (in Display Rate) on the Sequence adjusted for the effective output rate. These numbers will not line up with the frame\nin the source Sequence if the output frame rate differs from the Sequence display rate. May be a duplicate in the event of Play Rate tracks." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectiveTimeCode_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** The closest time code version of the EffectiveFrameNumber. May be a duplicate in the event of Play Rate tracks. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "The closest time code version of the EffectiveFrameNumber. May be a duplicate in the event of Play Rate tracks." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileMetadata_MetaData[] = {
		{ "Category", "Sample State" },
		{ "Comment", "/** Metadata to attach to the output file (if supported by the output container) */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Metadata to attach to the output file (if supported by the output container)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShotSourceFrameNumber_MetaData[] = {
		{ "Category", "Sample State" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShotSourceTimeCode_MetaData[] = {
		{ "Category", "Sample State" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraIndex_MetaData[] = {
		{ "Category", "Sample State" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutputFrameNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShotIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShotCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TemporalSampleIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TemporalSampleCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShotOutputFrameNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShotSamplesRendered;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CameraName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CameraNameOverride;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShotName;
	static void NewProp_bSkipRendering_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipRendering;
	static void NewProp_bCaptureRendering_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCaptureRendering;
	static void NewProp_bDiscardRenderResult_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDiscardRenderResult;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SourceFrameNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceTimeCode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EffectiveFrameNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EffectiveTimeCode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileMetadata_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileMetadata_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FileMetadata;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentShotSourceFrameNumber;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentShotSourceTimeCode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CameraIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLMovieSampleState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_OutputFrameNumber = { "OutputFrameNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, OutputFrameNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputFrameNumber_MetaData), NewProp_OutputFrameNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotIndex = { "ShotIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, ShotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotIndex_MetaData), NewProp_ShotIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotCount = { "ShotCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, ShotCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotCount_MetaData), NewProp_ShotCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_TemporalSampleIndex = { "TemporalSampleIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, TemporalSampleIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemporalSampleIndex_MetaData), NewProp_TemporalSampleIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_TemporalSampleCount = { "TemporalSampleCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, TemporalSampleCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemporalSampleCount_MetaData), NewProp_TemporalSampleCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotOutputFrameNumber = { "ShotOutputFrameNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, ShotOutputFrameNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotOutputFrameNumber_MetaData), NewProp_ShotOutputFrameNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotSamplesRendered = { "ShotSamplesRendered", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, ShotSamplesRendered), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotSamplesRendered_MetaData), NewProp_ShotSamplesRendered_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CameraName = { "CameraName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, CameraName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraName_MetaData), NewProp_CameraName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CameraNameOverride = { "CameraNameOverride", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, CameraNameOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraNameOverride_MetaData), NewProp_CameraNameOverride_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotName = { "ShotName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, ShotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotName_MetaData), NewProp_ShotName_MetaData) };
void Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bSkipRendering_SetBit(void* Obj)
{
	((FOWLMovieSampleState*)Obj)->bSkipRendering = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bSkipRendering = { "bSkipRendering", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLMovieSampleState), &Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bSkipRendering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipRendering_MetaData), NewProp_bSkipRendering_MetaData) };
void Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bCaptureRendering_SetBit(void* Obj)
{
	((FOWLMovieSampleState*)Obj)->bCaptureRendering = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bCaptureRendering = { "bCaptureRendering", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLMovieSampleState), &Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bCaptureRendering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCaptureRendering_MetaData), NewProp_bCaptureRendering_MetaData) };
void Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bDiscardRenderResult_SetBit(void* Obj)
{
	((FOWLMovieSampleState*)Obj)->bDiscardRenderResult = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bDiscardRenderResult = { "bDiscardRenderResult", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLMovieSampleState), &Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bDiscardRenderResult_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDiscardRenderResult_MetaData), NewProp_bDiscardRenderResult_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_SourceFrameNumber = { "SourceFrameNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, SourceFrameNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceFrameNumber_MetaData), NewProp_SourceFrameNumber_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_SourceTimeCode = { "SourceTimeCode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, SourceTimeCode), Z_Construct_UScriptStruct_FTimecode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceTimeCode_MetaData), NewProp_SourceTimeCode_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_EffectiveFrameNumber = { "EffectiveFrameNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, EffectiveFrameNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectiveFrameNumber_MetaData), NewProp_EffectiveFrameNumber_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_EffectiveTimeCode = { "EffectiveTimeCode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, EffectiveTimeCode), Z_Construct_UScriptStruct_FTimecode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectiveTimeCode_MetaData), NewProp_EffectiveTimeCode_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_FileMetadata_ValueProp = { "FileMetadata", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_FileMetadata_Key_KeyProp = { "FileMetadata_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_FileMetadata = { "FileMetadata", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, FileMetadata), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileMetadata_MetaData), NewProp_FileMetadata_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CurrentShotSourceFrameNumber = { "CurrentShotSourceFrameNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, CurrentShotSourceFrameNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShotSourceFrameNumber_MetaData), NewProp_CurrentShotSourceFrameNumber_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CurrentShotSourceTimeCode = { "CurrentShotSourceTimeCode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, CurrentShotSourceTimeCode), Z_Construct_UScriptStruct_FTimecode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShotSourceTimeCode_MetaData), NewProp_CurrentShotSourceTimeCode_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CameraIndex = { "CameraIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMovieSampleState, CameraIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraIndex_MetaData), NewProp_CameraIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_OutputFrameNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_TemporalSampleIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_TemporalSampleCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotOutputFrameNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotSamplesRendered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CameraName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CameraNameOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_ShotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bSkipRendering,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bCaptureRendering,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_bDiscardRenderResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_SourceFrameNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_SourceTimeCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_EffectiveFrameNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_EffectiveTimeCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_FileMetadata_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_FileMetadata_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_FileMetadata,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CurrentShotSourceFrameNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CurrentShotSourceTimeCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewProp_CameraIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWLMovieSampleState",
	Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::PropPointers),
	sizeof(FOWLMovieSampleState),
	alignof(FOWLMovieSampleState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLMovieSampleState()
{
	if (!Z_Registration_Info_UScriptStruct_OWLMovieSampleState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLMovieSampleState.InnerSingleton, Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLMovieSampleState.InnerSingleton;
}
// End ScriptStruct FOWLMovieSampleState

// Begin ScriptStruct FOWL360HookStitchInfo
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo;
class UScriptStruct* FOWL360HookStitchInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360HookStitchInfo, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360HookStitchInfo"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360HookStitchInfo>()
{
	return FOWL360HookStitchInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameNumber_MetaData[] = {
		{ "Category", "Stitch Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneViewIndex_MetaData[] = {
		{ "Category", "Stitch Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraIndex_MetaData[] = {
		{ "Category", "Stitch Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Resolution_MetaData[] = {
		{ "Category", "Stitch Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_FrameNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SceneViewIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CameraIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Resolution;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360HookStitchInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_FrameNumber = { "FrameNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookStitchInfo, FrameNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameNumber_MetaData), NewProp_FrameNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_SceneViewIndex = { "SceneViewIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookStitchInfo, SceneViewIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneViewIndex_MetaData), NewProp_SceneViewIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_CameraIndex = { "CameraIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookStitchInfo, CameraIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraIndex_MetaData), NewProp_CameraIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_Resolution = { "Resolution", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookStitchInfo, Resolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Resolution_MetaData), NewProp_Resolution_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_FrameNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_SceneViewIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_CameraIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewProp_Resolution,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWL360HookStitchInfo",
	Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::PropPointers),
	sizeof(FOWL360HookStitchInfo),
	alignof(FOWL360HookStitchInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360HookStitchInfo()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo.InnerSingleton, Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo.InnerSingleton;
}
// End ScriptStruct FOWL360HookStitchInfo

// Begin ScriptStruct FOWL360HookTileInfo
static_assert(std::is_polymorphic<FOWL360HookTileInfo>() == std::is_polymorphic<FOWL360HookStitchInfo>(), "USTRUCT FOWL360HookTileInfo cannot be polymorphic unless super FOWL360HookStitchInfo is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360HookTileInfo;
class UScriptStruct* FOWL360HookTileInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360HookTileInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360HookTileInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360HookTileInfo, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360HookTileInfo"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360HookTileInfo.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360HookTileInfo>()
{
	return FOWL360HookTileInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Crop_MetaData[] = {
		{ "Category", "Tile Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Face_MetaData[] = {
		{ "Category", "Tile Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Eye_MetaData[] = {
		{ "Category", "Tile Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TileIndex_MetaData[] = {
		{ "Category", "Tile Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalTiles_MetaData[] = {
		{ "Category", "Tile Info" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Crop;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Face_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Face;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Eye_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Eye;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TileIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TotalTiles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360HookTileInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Crop = { "Crop", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookTileInfo, Crop), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Crop_MetaData), NewProp_Crop_MetaData) }; // 3418875187
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Face_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Face = { "Face", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookTileInfo, Face), Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Face_MetaData), NewProp_Face_MetaData) }; // 3198239973
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Eye_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Eye = { "Eye", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookTileInfo, Eye), Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Eye_MetaData), NewProp_Eye_MetaData) }; // 1376492923
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_TileIndex = { "TileIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookTileInfo, TileIndex), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TileIndex_MetaData), NewProp_TileIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_TotalTiles = { "TotalTiles", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360HookTileInfo, TotalTiles), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalTiles_MetaData), NewProp_TotalTiles_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Crop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Face_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Face,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Eye_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_Eye,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_TileIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewProp_TotalTiles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	Z_Construct_UScriptStruct_FOWL360HookStitchInfo,
	&NewStructOps,
	"OWL360HookTileInfo",
	Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::PropPointers),
	sizeof(FOWL360HookTileInfo),
	alignof(FOWL360HookTileInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360HookTileInfo()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360HookTileInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360HookTileInfo.InnerSingleton, Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360HookTileInfo.InnerSingleton;
}
// End ScriptStruct FOWL360HookTileInfo

// Begin Enum EOWL360MRQPassType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWL360MRQPassType;
static UEnum* EOWL360MRQPassType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWL360MRQPassType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWL360MRQPassType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("EOWL360MRQPassType"));
	}
	return Z_Registration_Info_UEnum_EOWL360MRQPassType.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWL360MRQPassType>()
{
	return EOWL360MRQPassType_StaticEnum();
}
struct Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "PT_Combined.DisplayName", "Combined Render Pass" },
		{ "PT_Combined.Name", "PT_Combined" },
		{ "PT_SingleFacePass.DisplayName", "Single Face Pass" },
		{ "PT_SingleFacePass.Name", "PT_SingleFacePass" },
		{ "PT_StitchPass.DisplayName", "Stitch Pass" },
		{ "PT_StitchPass.Name", "PT_StitchPass" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "PT_Combined", (int64)PT_Combined },
		{ "PT_SingleFacePass", (int64)PT_SingleFacePass },
		{ "PT_StitchPass", (int64)PT_StitchPass },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	"EOWL360MRQPassType",
	"EOWL360MRQPassType",
	Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType()
{
	if (!Z_Registration_Info_UEnum_EOWL360MRQPassType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWL360MRQPassType.InnerSingleton, Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWL360MRQPassType.InnerSingleton;
}
// End Enum EOWL360MRQPassType

// Begin Class UOWLMRQ360Hooks Function ModifyTilePostProcess_GameThread
struct OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms
{
	FPostProcessSettings CurrentPostProcessSettings;
	FPostProcessSettings PostProcessSettings;
	FOWL360HookTileInfo TileInfo;
	const UMoviePipeline* Pipeline;
};
static FName NAME_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread = FName(TEXT("ModifyTilePostProcess_GameThread"));
void UOWLMRQ360Hooks::ModifyTilePostProcess_GameThread(FPostProcessSettings const& CurrentPostProcessSettings, FPostProcessSettings& PostProcessSettings, FOWL360HookTileInfo const& TileInfo, const UMoviePipeline* Pipeline)
{
	OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms Parms;
	Parms.CurrentPostProcessSettings=CurrentPostProcessSettings;
	Parms.PostProcessSettings=PostProcessSettings;
	Parms.TileInfo=TileInfo;
	Parms.Pipeline=Pipeline;
	ProcessEvent(FindFunctionChecked(NAME_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread),&Parms);
	PostProcessSettings=Parms.PostProcessSettings;
}
struct Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL Hooks" },
		{ "Comment", "/* Called before submitting a render for a frame on the game thread. Can be used to add optional blend materials etc for a given tile / face */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Called before submitting a render for a frame on the game thread. Can be used to add optional blend materials etc for a given tile / face" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPostProcessSettings_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TileInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pipeline_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentPostProcessSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PostProcessSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TileInfo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_CurrentPostProcessSettings = { "CurrentPostProcessSettings", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms, CurrentPostProcessSettings), Z_Construct_UScriptStruct_FPostProcessSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPostProcessSettings_MetaData), NewProp_CurrentPostProcessSettings_MetaData) }; // 1858651484
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_PostProcessSettings = { "PostProcessSettings", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms, PostProcessSettings), Z_Construct_UScriptStruct_FPostProcessSettings, METADATA_PARAMS(0, nullptr) }; // 1858651484
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_TileInfo = { "TileInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms, TileInfo), Z_Construct_UScriptStruct_FOWL360HookTileInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TileInfo_MetaData), NewProp_TileInfo_MetaData) }; // 3769616700
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms, Pipeline), Z_Construct_UClass_UMoviePipeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pipeline_MetaData), NewProp_Pipeline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_CurrentPostProcessSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_PostProcessSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_TileInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::NewProp_Pipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWLMRQ360Hooks, nullptr, "ModifyTilePostProcess_GameThread", nullptr, nullptr, Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::PropPointers), sizeof(OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::Function_MetaDataParams) };
static_assert(sizeof(OWLMRQ360Hooks_eventModifyTilePostProcess_GameThread_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWLMRQ360Hooks::execModifyTilePostProcess_GameThread)
{
	P_GET_STRUCT_REF(FPostProcessSettings,Z_Param_Out_CurrentPostProcessSettings);
	P_GET_STRUCT_REF(FPostProcessSettings,Z_Param_Out_PostProcessSettings);
	P_GET_STRUCT_REF(FOWL360HookTileInfo,Z_Param_Out_TileInfo);
	P_GET_OBJECT(UMoviePipeline,Z_Param_Pipeline);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ModifyTilePostProcess_GameThread_Implementation(Z_Param_Out_CurrentPostProcessSettings,Z_Param_Out_PostProcessSettings,Z_Param_Out_TileInfo,Z_Param_Pipeline);
	P_NATIVE_END;
}
// End Class UOWLMRQ360Hooks Function ModifyTilePostProcess_GameThread

// Begin Class UOWLMRQ360Hooks Function PreRenderCamera_GameThread
struct OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms
{
	int32 CameraIndex;
	FOWLMovieSampleState SampleState;
	const UOWL360CameraMoviePipelinePass* OWLPass;
	const UMoviePipeline* Pipeline;
	const UOWL360CaptureComponent* CaptureComponent;
};
static FName NAME_UOWLMRQ360Hooks_PreRenderCamera_GameThread = FName(TEXT("PreRenderCamera_GameThread"));
void UOWLMRQ360Hooks::PreRenderCamera_GameThread(const int32 CameraIndex, FOWLMovieSampleState const& SampleState, const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline, const UOWL360CaptureComponent* CaptureComponent)
{
	OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms Parms;
	Parms.CameraIndex=CameraIndex;
	Parms.SampleState=SampleState;
	Parms.OWLPass=OWLPass;
	Parms.Pipeline=Pipeline;
	Parms.CaptureComponent=CaptureComponent;
	ProcessEvent(FindFunctionChecked(NAME_UOWLMRQ360Hooks_PreRenderCamera_GameThread),&Parms);
}
struct Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL Hooks" },
		{ "Comment", "/* Called before any tiles have been rendered and after setup */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Called before any tiles have been rendered and after setup" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraIndex_MetaData[] = {
		{ "NativeConst", "" },
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
	static const UECodeGen_Private::FIntPropertyParams NewProp_CameraIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SampleState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OWLPass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_CameraIndex = { "CameraIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms, CameraIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraIndex_MetaData), NewProp_CameraIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_SampleState = { "SampleState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms, SampleState), Z_Construct_UScriptStruct_FOWLMovieSampleState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SampleState_MetaData), NewProp_SampleState_MetaData) }; // 3424178246
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_OWLPass = { "OWLPass", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms, OWLPass), Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OWLPass_MetaData), NewProp_OWLPass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms, Pipeline), Z_Construct_UClass_UMoviePipeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pipeline_MetaData), NewProp_Pipeline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_CaptureComponent = { "CaptureComponent", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms, CaptureComponent), Z_Construct_UClass_UOWL360CaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureComponent_MetaData), NewProp_CaptureComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_CameraIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_SampleState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_OWLPass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_Pipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::NewProp_CaptureComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWLMRQ360Hooks, nullptr, "PreRenderCamera_GameThread", nullptr, nullptr, Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::PropPointers), sizeof(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::Function_MetaDataParams) };
static_assert(sizeof(OWLMRQ360Hooks_eventPreRenderCamera_GameThread_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWLMRQ360Hooks::execPreRenderCamera_GameThread)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_CameraIndex);
	P_GET_STRUCT_REF(FOWLMovieSampleState,Z_Param_Out_SampleState);
	P_GET_OBJECT(UOWL360CameraMoviePipelinePass,Z_Param_OWLPass);
	P_GET_OBJECT(UMoviePipeline,Z_Param_Pipeline);
	P_GET_OBJECT(UOWL360CaptureComponent,Z_Param_CaptureComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PreRenderCamera_GameThread_Implementation(Z_Param_CameraIndex,Z_Param_Out_SampleState,Z_Param_OWLPass,Z_Param_Pipeline,Z_Param_CaptureComponent);
	P_NATIVE_END;
}
// End Class UOWLMRQ360Hooks Function PreRenderCamera_GameThread

// Begin Class UOWLMRQ360Hooks Function Setup_GameThread
struct OWLMRQ360Hooks_eventSetup_GameThread_Parms
{
	const UOWL360CameraMoviePipelinePass* OWLPass;
	const UMoviePipeline* Pipeline;
};
static FName NAME_UOWLMRQ360Hooks_Setup_GameThread = FName(TEXT("Setup_GameThread"));
void UOWLMRQ360Hooks::Setup_GameThread(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline)
{
	OWLMRQ360Hooks_eventSetup_GameThread_Parms Parms;
	Parms.OWLPass=OWLPass;
	Parms.Pipeline=Pipeline;
	ProcessEvent(FindFunctionChecked(NAME_UOWLMRQ360Hooks_Setup_GameThread),&Parms);
}
struct Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL Hooks" },
		{ "Comment", "/* Called when the movie render pipeline is being setup */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Called when the movie render pipeline is being setup" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OWLPass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pipeline_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OWLPass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::NewProp_OWLPass = { "OWLPass", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventSetup_GameThread_Parms, OWLPass), Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OWLPass_MetaData), NewProp_OWLPass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventSetup_GameThread_Parms, Pipeline), Z_Construct_UClass_UMoviePipeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pipeline_MetaData), NewProp_Pipeline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::NewProp_OWLPass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::NewProp_Pipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWLMRQ360Hooks, nullptr, "Setup_GameThread", nullptr, nullptr, Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::PropPointers), sizeof(OWLMRQ360Hooks_eventSetup_GameThread_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::Function_MetaDataParams) };
static_assert(sizeof(OWLMRQ360Hooks_eventSetup_GameThread_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWLMRQ360Hooks::execSetup_GameThread)
{
	P_GET_OBJECT(UOWL360CameraMoviePipelinePass,Z_Param_OWLPass);
	P_GET_OBJECT(UMoviePipeline,Z_Param_Pipeline);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Setup_GameThread_Implementation(Z_Param_OWLPass,Z_Param_Pipeline);
	P_NATIVE_END;
}
// End Class UOWLMRQ360Hooks Function Setup_GameThread

// Begin Class UOWLMRQ360Hooks Function TearDown_GameThread
struct OWLMRQ360Hooks_eventTearDown_GameThread_Parms
{
	const UOWL360CameraMoviePipelinePass* OWLPass;
	const UMoviePipeline* Pipeline;
};
static FName NAME_UOWLMRQ360Hooks_TearDown_GameThread = FName(TEXT("TearDown_GameThread"));
void UOWLMRQ360Hooks::TearDown_GameThread(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline)
{
	OWLMRQ360Hooks_eventTearDown_GameThread_Parms Parms;
	Parms.OWLPass=OWLPass;
	Parms.Pipeline=Pipeline;
	ProcessEvent(FindFunctionChecked(NAME_UOWLMRQ360Hooks_TearDown_GameThread),&Parms);
}
struct Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL Hooks" },
		{ "Comment", "/* Called when the movie pipeline is shutting down */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
		{ "ToolTip", "Called when the movie pipeline is shutting down" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OWLPass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pipeline_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OWLPass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Pipeline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::NewProp_OWLPass = { "OWLPass", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventTearDown_GameThread_Parms, OWLPass), Z_Construct_UClass_UOWL360CameraMoviePipelinePass_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OWLPass_MetaData), NewProp_OWLPass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::NewProp_Pipeline = { "Pipeline", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWLMRQ360Hooks_eventTearDown_GameThread_Parms, Pipeline), Z_Construct_UClass_UMoviePipeline_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pipeline_MetaData), NewProp_Pipeline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::NewProp_OWLPass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::NewProp_Pipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWLMRQ360Hooks, nullptr, "TearDown_GameThread", nullptr, nullptr, Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::PropPointers), sizeof(OWLMRQ360Hooks_eventTearDown_GameThread_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::Function_MetaDataParams) };
static_assert(sizeof(OWLMRQ360Hooks_eventTearDown_GameThread_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWLMRQ360Hooks::execTearDown_GameThread)
{
	P_GET_OBJECT(UOWL360CameraMoviePipelinePass,Z_Param_OWLPass);
	P_GET_OBJECT(UMoviePipeline,Z_Param_Pipeline);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TearDown_GameThread_Implementation(Z_Param_OWLPass,Z_Param_Pipeline);
	P_NATIVE_END;
}
// End Class UOWLMRQ360Hooks Function TearDown_GameThread

// Begin Class UOWLMRQ360Hooks
void UOWLMRQ360Hooks::StaticRegisterNativesUOWLMRQ360Hooks()
{
	UClass* Class = UOWLMRQ360Hooks::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ModifyTilePostProcess_GameThread", &UOWLMRQ360Hooks::execModifyTilePostProcess_GameThread },
		{ "PreRenderCamera_GameThread", &UOWLMRQ360Hooks::execPreRenderCamera_GameThread },
		{ "Setup_GameThread", &UOWLMRQ360Hooks::execSetup_GameThread },
		{ "TearDown_GameThread", &UOWLMRQ360Hooks::execTearDown_GameThread },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLMRQ360Hooks);
UClass* Z_Construct_UClass_UOWLMRQ360Hooks_NoRegister()
{
	return UOWLMRQ360Hooks::StaticClass();
}
struct Z_Construct_UClass_UOWLMRQ360Hooks_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OWL360Camera/OWLMRQ360Hooks.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PassType_MetaData[] = {
		{ "Category", "OWL Hooks" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLMRQ360Hooks.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_PassType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOWLMRQ360Hooks_ModifyTilePostProcess_GameThread, "ModifyTilePostProcess_GameThread" }, // 1247896947
		{ &Z_Construct_UFunction_UOWLMRQ360Hooks_PreRenderCamera_GameThread, "PreRenderCamera_GameThread" }, // 2136922327
		{ &Z_Construct_UFunction_UOWLMRQ360Hooks_Setup_GameThread, "Setup_GameThread" }, // 1499564162
		{ &Z_Construct_UFunction_UOWLMRQ360Hooks_TearDown_GameThread, "TearDown_GameThread" }, // 3276003210
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLMRQ360Hooks>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWLMRQ360Hooks_Statics::NewProp_PassType = { "PassType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLMRQ360Hooks, PassType), Z_Construct_UEnum_OWLMRQPipeline_EOWL360MRQPassType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PassType_MetaData), NewProp_PassType_MetaData) }; // 1937592594
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLMRQ360Hooks_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLMRQ360Hooks_Statics::NewProp_PassType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLMRQ360Hooks_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLMRQ360Hooks_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLMRQ360Hooks_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLMRQ360Hooks_Statics::ClassParams = {
	&UOWLMRQ360Hooks::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOWLMRQ360Hooks_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLMRQ360Hooks_Statics::PropPointers),
	0,
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLMRQ360Hooks_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLMRQ360Hooks_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLMRQ360Hooks()
{
	if (!Z_Registration_Info_UClass_UOWLMRQ360Hooks.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLMRQ360Hooks.OuterSingleton, Z_Construct_UClass_UOWLMRQ360Hooks_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLMRQ360Hooks.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UClass* StaticClass<UOWLMRQ360Hooks>()
{
	return UOWLMRQ360Hooks::StaticClass();
}
UOWLMRQ360Hooks::UOWLMRQ360Hooks(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLMRQ360Hooks);
// End Class UOWLMRQ360Hooks

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWL360MRQPassType_StaticEnum, TEXT("EOWL360MRQPassType"), &Z_Registration_Info_UEnum_EOWL360MRQPassType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1937592594U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLMovieSampleState::StaticStruct, Z_Construct_UScriptStruct_FOWLMovieSampleState_Statics::NewStructOps, TEXT("OWLMovieSampleState"), &Z_Registration_Info_UScriptStruct_OWLMovieSampleState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLMovieSampleState), 3424178246U) },
		{ FOWL360HookStitchInfo::StaticStruct, Z_Construct_UScriptStruct_FOWL360HookStitchInfo_Statics::NewStructOps, TEXT("OWL360HookStitchInfo"), &Z_Registration_Info_UScriptStruct_OWL360HookStitchInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360HookStitchInfo), 1125651867U) },
		{ FOWL360HookTileInfo::StaticStruct, Z_Construct_UScriptStruct_FOWL360HookTileInfo_Statics::NewStructOps, TEXT("OWL360HookTileInfo"), &Z_Registration_Info_UScriptStruct_OWL360HookTileInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360HookTileInfo), 3769616700U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLMRQ360Hooks, UOWLMRQ360Hooks::StaticClass, TEXT("UOWLMRQ360Hooks"), &Z_Registration_Info_UClass_UOWLMRQ360Hooks, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLMRQ360Hooks), 160572871U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_1502827417(TEXT("/Script/OWLMRQPipeline"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLMRQ360Hooks_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
