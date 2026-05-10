// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360PipelineSettings.h"
#include "LivestreamingToolkit/Public/Tools/OWLFileInput.h"
#include "OWL360Camera/Public/OWL360ResolutionSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360PipelineSettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FFilePath();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
LIVESTREAMINGTOOLKIT_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFileInput();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360ResolutionSettings();
OWLMRQPIPELINE_API UClass* Z_Construct_UClass_UOWLMRQ360Hooks_NoRegister();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType();
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360OptimisationSettings();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360OutputSettings();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360PipelineSettings();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360RenderingSettings();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360TilingSettings();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Enum EOWLBitDepth
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLBitDepth;
static UEnum* EOWLBitDepth_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLBitDepth.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLBitDepth.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("EOWLBitDepth"));
	}
	return Z_Registration_Info_UEnum_EOWLBitDepth.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLBitDepth>()
{
	return EOWLBitDepth_StaticEnum();
}
struct Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BT_16Bit.DisplayName", "16 Bit" },
		{ "BT_16Bit.Name", "EOWLBitDepth::BT_16Bit" },
		{ "BT_32Bit.DisplayName", "32 Bit" },
		{ "BT_32Bit.Name", "EOWLBitDepth::BT_32Bit" },
		{ "BT_8Bit.DisplayName", "8 Bit" },
		{ "BT_8Bit.Name", "EOWLBitDepth::BT_8Bit" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLBitDepth::BT_8Bit", (int64)EOWLBitDepth::BT_8Bit },
		{ "EOWLBitDepth::BT_16Bit", (int64)EOWLBitDepth::BT_16Bit },
		{ "EOWLBitDepth::BT_32Bit", (int64)EOWLBitDepth::BT_32Bit },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	"EOWLBitDepth",
	"EOWLBitDepth",
	Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth()
{
	if (!Z_Registration_Info_UEnum_EOWLBitDepth.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLBitDepth.InnerSingleton, Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLBitDepth.InnerSingleton;
}
// End Enum EOWLBitDepth

// Begin Enum EOWLCompositeMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLCompositeMode;
static UEnum* EOWLCompositeMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLCompositeMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLCompositeMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("EOWLCompositeMode"));
	}
	return Z_Registration_Info_UEnum_EOWLCompositeMode.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLCompositeMode>()
{
	return EOWLCompositeMode_StaticEnum();
}
struct Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "CM_Add.DisplayName", "Add (Linear Dodge)" },
		{ "CM_Add.Name", "EOWLCompositeMode::CM_Add" },
		{ "CM_Difference.DisplayName", "Difference" },
		{ "CM_Difference.Name", "EOWLCompositeMode::CM_Difference" },
		{ "CM_Multiply.DisplayName", "Multiply" },
		{ "CM_Multiply.Name", "EOWLCompositeMode::CM_Multiply" },
		{ "CM_Over.DisplayName", "Over (Alpha Compositing)" },
		{ "CM_Over.Name", "EOWLCompositeMode::CM_Over" },
		{ "CM_Screen.DisplayName", "Screen" },
		{ "CM_Screen.Name", "EOWLCompositeMode::CM_Screen" },
		{ "CM_Subtract.DisplayName", "Subtract" },
		{ "CM_Subtract.Name", "EOWLCompositeMode::CM_Subtract" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLCompositeMode::CM_Over", (int64)EOWLCompositeMode::CM_Over },
		{ "EOWLCompositeMode::CM_Multiply", (int64)EOWLCompositeMode::CM_Multiply },
		{ "EOWLCompositeMode::CM_Add", (int64)EOWLCompositeMode::CM_Add },
		{ "EOWLCompositeMode::CM_Subtract", (int64)EOWLCompositeMode::CM_Subtract },
		{ "EOWLCompositeMode::CM_Screen", (int64)EOWLCompositeMode::CM_Screen },
		{ "EOWLCompositeMode::CM_Difference", (int64)EOWLCompositeMode::CM_Difference },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	"EOWLCompositeMode",
	"EOWLCompositeMode",
	Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode()
{
	if (!Z_Registration_Info_UEnum_EOWLCompositeMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLCompositeMode.InnerSingleton, Z_Construct_UEnum_OWLMRQPipeline_EOWLCompositeMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLCompositeMode.InnerSingleton;
}
// End Enum EOWLCompositeMode

// Begin ScriptStruct FOWL360TilingSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360TilingSettings;
class UScriptStruct* FOWL360TilingSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360TilingSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360TilingSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360TilingSettings, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360TilingSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360TilingSettings.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360TilingSettings>()
{
	return FOWL360TilingSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "Tiling" },
		{ "Comment", "/* The position of this tile relative to the face, zero-indexed */" },
		{ "DisplayName", "Index" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "The position of this tile relative to the face, zero-indexed" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Total_MetaData[] = {
		{ "Category", "Tiling" },
		{ "Comment", "/* Total number of tiles on a give face */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Total number of tiles on a give face" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlapPercent_MetaData[] = {
		{ "Category", "Tiling" },
		{ "Comment", "/* The percentage each tile should overlap with the adjacent tile */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "The percentage each tile should overlap with the adjacent tile" },
		{ "UIMax", "50" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumTileDimension_MetaData[] = {
		{ "Category", "Tiling" },
		{ "Comment", "/* It may be useful to set a minimum dimension of the tile. This ensures that some post-process effects work correctly */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "It may be useful to set a minimum dimension of the tile. This ensures that some post-process effects work correctly" },
		{ "UIMax", "50" },
		{ "UIMin", "0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Total;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OverlapPercent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinimumTileDimension;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360TilingSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360TilingSettings, Position), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_Total = { "Total", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360TilingSettings, Total), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Total_MetaData), NewProp_Total_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_OverlapPercent = { "OverlapPercent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360TilingSettings, OverlapPercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlapPercent_MetaData), NewProp_OverlapPercent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_MinimumTileDimension = { "MinimumTileDimension", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360TilingSettings, MinimumTileDimension), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumTileDimension_MetaData), NewProp_MinimumTileDimension_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_Total,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_OverlapPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewProp_MinimumTileDimension,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWL360TilingSettings",
	Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::PropPointers),
	sizeof(FOWL360TilingSettings),
	alignof(FOWL360TilingSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360TilingSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360TilingSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360TilingSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360TilingSettings.InnerSingleton;
}
// End ScriptStruct FOWL360TilingSettings

// Begin ScriptStruct FOWL360OutputSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360OutputSettings;
class UScriptStruct* FOWL360OutputSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360OutputSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360OutputSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360OutputSettings, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360OutputSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360OutputSettings.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360OutputSettings>()
{
	return FOWL360OutputSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Resolution_MetaData[] = {
		{ "Category", "Output" },
		{ "Comment", "/* Texture resolution for camera render output */" },
		{ "DisplayPriority", "1" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Texture resolution for camera render output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideInternalFaceDimensions_MetaData[] = {
		{ "Category", "Output" },
		{ "Comment", "/* Use a custom width/height (must be square) for the cube face renders that comprise the final output */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Use a custom width/height (must be square) for the cube face renders that comprise the final output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverrideFaceDimension_MetaData[] = {
		{ "Category", "Output" },
		{ "Comment", "/* Custom width and height (must be square) for the cube face renders that comprise the final output */" },
		{ "EditCondition", "bOverrideInternalFaceDimensions" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Custom width and height (must be square) for the cube face renders that comprise the final output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tiling_MetaData[] = {
		{ "Category", "Output" },
		{ "EditCondition", "bIsTile" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTile_MetaData[] = {
		{ "Category", "Output|Tiling" },
		{ "EditCondition", "false" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputMaskPath_MetaData[] = {
		{ "Category", "Output|Mask" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseAbsoluteMaskPath_MetaData[] = {
		{ "DeprecatedProperty", "" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputMaskFilePath_MetaData[] = {
		{ "Comment", "/* A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. NB. This does not apply to CubeMap projections*/" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Use OutputMaskPath instead" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. NB. This does not apply to CubeMap projections" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputMaskFilePathAbsolute_MetaData[] = {
		{ "Comment", "/* A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. NB. This does not apply to CubeMap projections*/" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Use OutputMaskPath instead" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. NB. This does not apply to CubeMap projections" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCompositeCameras_MetaData[] = {
		{ "Category", "Output|Compositing" },
		{ "Comment", "/* Where multiple 360 cameras are in a sequence, composite them together based on the `Fade` value set on the component. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Where multiple 360 cameras are in a sequence, composite them together based on the `Fade` value set on the component." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRenderOnlyOneEye_MetaData[] = {
		{ "Category", "Output|Stereo" },
		{ "Comment", "/* Enable to render only left or right eye as a separate image. This pass should be duplicated and the 'eye' changed to render the stereo pair as separate image. This is a PRO only feature and will only work if the projection is stereo. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Enable to render only left or right eye as a separate image. This pass should be duplicated and the 'eye' changed to render the stereo pair as separate image. This is a PRO only feature and will only work if the projection is stereo." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeToRender_MetaData[] = {
		{ "Category", "Output|Stereo" },
		{ "Comment", "/* Select the eye to render when 'Render Only One Eye' active. */" },
		{ "EditCondition", "bRenderOnlyOneEye" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Select the eye to render when 'Render Only One Eye' active." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bExitOnFailure_MetaData[] = {
		{ "Category", "Output|Error Handling" },
		{ "Comment", "/* When rendering a sequence, do not attempt to continue rendering further frames if an error occurs */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "When rendering a sequence, do not attempt to continue rendering further frames if an error occurs" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Resolution;
	static void NewProp_bOverrideInternalFaceDimensions_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideInternalFaceDimensions;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OverrideFaceDimension;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tiling;
	static void NewProp_bIsTile_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputMaskPath;
	static void NewProp_bUseAbsoluteMaskPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseAbsoluteMaskPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputMaskFilePath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputMaskFilePathAbsolute;
	static void NewProp_bCompositeCameras_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCompositeCameras;
	static void NewProp_bRenderOnlyOneEye_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRenderOnlyOneEye;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EyeToRender_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EyeToRender;
	static void NewProp_bExitOnFailure_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExitOnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360OutputSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_Resolution = { "Resolution", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, Resolution), Z_Construct_UScriptStruct_FOWL360ResolutionSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Resolution_MetaData), NewProp_Resolution_MetaData) }; // 165309397
void Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bOverrideInternalFaceDimensions_SetBit(void* Obj)
{
	((FOWL360OutputSettings*)Obj)->bOverrideInternalFaceDimensions = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bOverrideInternalFaceDimensions = { "bOverrideInternalFaceDimensions", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OutputSettings), &Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bOverrideInternalFaceDimensions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideInternalFaceDimensions_MetaData), NewProp_bOverrideInternalFaceDimensions_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OverrideFaceDimension = { "OverrideFaceDimension", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, OverrideFaceDimension), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverrideFaceDimension_MetaData), NewProp_OverrideFaceDimension_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_Tiling = { "Tiling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, Tiling), Z_Construct_UScriptStruct_FOWL360TilingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tiling_MetaData), NewProp_Tiling_MetaData) }; // 145964450
void Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bIsTile_SetBit(void* Obj)
{
	((FOWL360OutputSettings*)Obj)->bIsTile = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bIsTile = { "bIsTile", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OutputSettings), &Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bIsTile_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTile_MetaData), NewProp_bIsTile_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OutputMaskPath = { "OutputMaskPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, OutputMaskPath), Z_Construct_UScriptStruct_FOWLFileInput, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputMaskPath_MetaData), NewProp_OutputMaskPath_MetaData) }; // 856243302
void Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bUseAbsoluteMaskPath_SetBit(void* Obj)
{
	((FOWL360OutputSettings*)Obj)->bUseAbsoluteMaskPath_DEPRECATED = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bUseAbsoluteMaskPath = { "bUseAbsoluteMaskPath", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OutputSettings), &Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bUseAbsoluteMaskPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseAbsoluteMaskPath_MetaData), NewProp_bUseAbsoluteMaskPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OutputMaskFilePath = { "OutputMaskFilePath", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, OutputMaskFilePath_DEPRECATED), Z_Construct_UScriptStruct_FFilePath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputMaskFilePath_MetaData), NewProp_OutputMaskFilePath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OutputMaskFilePathAbsolute = { "OutputMaskFilePathAbsolute", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, OutputMaskFilePathAbsolute_DEPRECATED), Z_Construct_UScriptStruct_FFilePath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputMaskFilePathAbsolute_MetaData), NewProp_OutputMaskFilePathAbsolute_MetaData) };
void Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bCompositeCameras_SetBit(void* Obj)
{
	((FOWL360OutputSettings*)Obj)->bCompositeCameras = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bCompositeCameras = { "bCompositeCameras", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OutputSettings), &Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bCompositeCameras_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCompositeCameras_MetaData), NewProp_bCompositeCameras_MetaData) };
void Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bRenderOnlyOneEye_SetBit(void* Obj)
{
	((FOWL360OutputSettings*)Obj)->bRenderOnlyOneEye = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bRenderOnlyOneEye = { "bRenderOnlyOneEye", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OutputSettings), &Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bRenderOnlyOneEye_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRenderOnlyOneEye_MetaData), NewProp_bRenderOnlyOneEye_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_EyeToRender_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_EyeToRender = { "EyeToRender", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OutputSettings, EyeToRender), Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeToRender_MetaData), NewProp_EyeToRender_MetaData) }; // 1376492923
void Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bExitOnFailure_SetBit(void* Obj)
{
	((FOWL360OutputSettings*)Obj)->bExitOnFailure = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bExitOnFailure = { "bExitOnFailure", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OutputSettings), &Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bExitOnFailure_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bExitOnFailure_MetaData), NewProp_bExitOnFailure_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_Resolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bOverrideInternalFaceDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OverrideFaceDimension,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_Tiling,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bIsTile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OutputMaskPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bUseAbsoluteMaskPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OutputMaskFilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_OutputMaskFilePathAbsolute,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bCompositeCameras,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bRenderOnlyOneEye,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_EyeToRender_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_EyeToRender,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewProp_bExitOnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWL360OutputSettings",
	Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::PropPointers),
	sizeof(FOWL360OutputSettings),
	alignof(FOWL360OutputSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360OutputSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360OutputSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360OutputSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360OutputSettings.InnerSingleton;
}
// End ScriptStruct FOWL360OutputSettings

// Begin Enum EOWLInterpolationType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLInterpolationType;
static UEnum* EOWLInterpolationType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLInterpolationType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLInterpolationType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("EOWLInterpolationType"));
	}
	return Z_Registration_Info_UEnum_EOWLInterpolationType.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLInterpolationType>()
{
	return EOWLInterpolationType_StaticEnum();
}
struct Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EI_Bilinear.DisplayName", "Bilinear Sampling" },
		{ "EI_Bilinear.Name", "EOWLInterpolationType::EI_Bilinear" },
		{ "EI_Point.DisplayName", "Point Sampling" },
		{ "EI_Point.Name", "EOWLInterpolationType::EI_Point" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLInterpolationType::EI_Point", (int64)EOWLInterpolationType::EI_Point },
		{ "EOWLInterpolationType::EI_Bilinear", (int64)EOWLInterpolationType::EI_Bilinear },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	"EOWLInterpolationType",
	"EOWLInterpolationType",
	Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType()
{
	if (!Z_Registration_Info_UEnum_EOWLInterpolationType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLInterpolationType.InnerSingleton, Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLInterpolationType.InnerSingleton;
}
// End Enum EOWLInterpolationType

// Begin ScriptStruct FOWL360OptimisationSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings;
class UScriptStruct* FOWL360OptimisationSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360OptimisationSettings, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360OptimisationSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360OptimisationSettings>()
{
	return FOWL360OptimisationSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntermediateBitDepth_MetaData[] = {
		{ "Category", "Optimizations" },
		{ "Comment", "/* To target specific outputs you may find you get a better result by forcing intermediate processing to a given bit rate */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "To target specific outputs you may find you get a better result by forcing intermediate processing to a given bit rate" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableParallelRendering_MetaData[] = {
		{ "Category", "Optimizations" },
		{ "Comment", "/* Ensures that each frame completes before rendering the next. Very important with large resolutions */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Ensures that each frame completes before rendering the next. Very important with large resolutions" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InterpolationType_MetaData[] = {
		{ "Category", "Optimizations" },
		{ "Comment", "/* Change the way face pixels are interpolated in the final render.\n\x09 This can increase or decreases the pixel clarity  in the final stitch. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Change the way face pixels are interpolated in the final render.\n       This can increase or decreases the pixel clarity  in the final stitch." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableMultipleSceneViewStates_MetaData[] = {
		{ "Category", "Optimizations" },
		{ "Comment", "/* Scene View States store large amount of temporal information to improve Nanite rendering, motion blur and other\n\x09 intra-frame post-process optimisations. Disabling multiple view states reduces GPU load at the cost\n\x09 of these effects. GPU Memory requirements are reduced at the cost of output quality. */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Scene View States store large amount of temporal information to improve Nanite rendering, motion blur and other\n       intra-frame post-process optimisations. Disabling multiple view states reduces GPU load at the cost\n       of these effects. GPU Memory requirements are reduced at the cost of output quality." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_IntermediateBitDepth_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_IntermediateBitDepth;
	static void NewProp_bDisableParallelRendering_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableParallelRendering;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InterpolationType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InterpolationType;
	static void NewProp_bDisableMultipleSceneViewStates_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableMultipleSceneViewStates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360OptimisationSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_IntermediateBitDepth_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_IntermediateBitDepth = { "IntermediateBitDepth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OptimisationSettings, IntermediateBitDepth), Z_Construct_UEnum_OWLMRQPipeline_EOWLBitDepth, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntermediateBitDepth_MetaData), NewProp_IntermediateBitDepth_MetaData) }; // 406506681
void Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableParallelRendering_SetBit(void* Obj)
{
	((FOWL360OptimisationSettings*)Obj)->bDisableParallelRendering = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableParallelRendering = { "bDisableParallelRendering", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OptimisationSettings), &Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableParallelRendering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableParallelRendering_MetaData), NewProp_bDisableParallelRendering_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_InterpolationType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_InterpolationType = { "InterpolationType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360OptimisationSettings, InterpolationType), Z_Construct_UEnum_OWLMRQPipeline_EOWLInterpolationType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InterpolationType_MetaData), NewProp_InterpolationType_MetaData) }; // 2514039434
void Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableMultipleSceneViewStates_SetBit(void* Obj)
{
	((FOWL360OptimisationSettings*)Obj)->bDisableMultipleSceneViewStates = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableMultipleSceneViewStates = { "bDisableMultipleSceneViewStates", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360OptimisationSettings), &Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableMultipleSceneViewStates_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableMultipleSceneViewStates_MetaData), NewProp_bDisableMultipleSceneViewStates_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_IntermediateBitDepth_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_IntermediateBitDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableParallelRendering,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_InterpolationType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_InterpolationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewProp_bDisableMultipleSceneViewStates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWL360OptimisationSettings",
	Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::PropPointers),
	sizeof(FOWL360OptimisationSettings),
	alignof(FOWL360OptimisationSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360OptimisationSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings.InnerSingleton;
}
// End ScriptStruct FOWL360OptimisationSettings

// Begin ScriptStruct FOWL360RenderingSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360RenderingSettings;
class UScriptStruct* FOWL360RenderingSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360RenderingSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360RenderingSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360RenderingSettings, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360RenderingSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360RenderingSettings.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360RenderingSettings>()
{
	return FOWL360RenderingSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPathTracing_MetaData[] = {
		{ "Category", "Rendering" },
		{ "Comment", "// Path Tracing\n" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Path Tracing" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReferenceMotionBlur_MetaData[] = {
		{ "Category", "Rendering" },
		{ "Comment", "/** When enabled, the path tracer will blend all spatial and temporal samples prior to the denoising and will disable post-processed motion blur.\n     *  In this mode it is possible to use higher temporal sample counts to improve the motion blur quality.\n     *  When this option is disabled, the path tracer will accumulate spatial samples, but denoise them prior to accumulation of temporal samples.\n     */" },
		{ "EditCondition", "bPathTracing" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "When enabled, the path tracer will blend all spatial and temporal samples prior to the denoising and will disable post-processed motion blur.\nIn this mode it is possible to use higher temporal sample counts to improve the motion blur quality.\nWhen this option is disabled, the path tracer will accumulate spatial samples, but denoise them prior to accumulation of temporal samples." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Optimisations_MetaData[] = {
		{ "Category", "Rendering" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderingHooks_MetaData[] = {
		{ "Category", "Rendering|Advanced" },
		{ "Comment", "/* Add one or multiple blueprints to apply transforms at various points in the stitching process. This is only available with a PRO MRQ license */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Add one or multiple blueprints to apply transforms at various points in the stitching process. This is only available with a PRO MRQ license" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMaintainFrameOrder_MetaData[] = {
		{ "Category", "Rendering|Advanced" },
		{ "Comment", "/* Ensures that frames are output to the MRQ writer (disk writer etc) in sequential order. This comes at a memory and slight performance cost */" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ToolTip", "Ensures that frames are output to the MRQ writer (disk writer etc) in sequential order. This comes at a memory and slight performance cost" },
	};
#endif // WITH_METADATA
	static void NewProp_bPathTracing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPathTracing;
	static void NewProp_bReferenceMotionBlur_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReferenceMotionBlur;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Optimisations;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RenderingHooks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RenderingHooks;
	static void NewProp_bMaintainFrameOrder_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMaintainFrameOrder;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360RenderingSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bPathTracing_SetBit(void* Obj)
{
	((FOWL360RenderingSettings*)Obj)->bPathTracing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bPathTracing = { "bPathTracing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360RenderingSettings), &Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bPathTracing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPathTracing_MetaData), NewProp_bPathTracing_MetaData) };
void Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bReferenceMotionBlur_SetBit(void* Obj)
{
	((FOWL360RenderingSettings*)Obj)->bReferenceMotionBlur = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bReferenceMotionBlur = { "bReferenceMotionBlur", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360RenderingSettings), &Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bReferenceMotionBlur_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReferenceMotionBlur_MetaData), NewProp_bReferenceMotionBlur_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_Optimisations = { "Optimisations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360RenderingSettings, Optimisations), Z_Construct_UScriptStruct_FOWL360OptimisationSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Optimisations_MetaData), NewProp_Optimisations_MetaData) }; // 1608767441
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_RenderingHooks_Inner = { "RenderingHooks", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UOWLMRQ360Hooks_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_RenderingHooks = { "RenderingHooks", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360RenderingSettings, RenderingHooks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderingHooks_MetaData), NewProp_RenderingHooks_MetaData) };
void Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bMaintainFrameOrder_SetBit(void* Obj)
{
	((FOWL360RenderingSettings*)Obj)->bMaintainFrameOrder = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bMaintainFrameOrder = { "bMaintainFrameOrder", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360RenderingSettings), &Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bMaintainFrameOrder_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMaintainFrameOrder_MetaData), NewProp_bMaintainFrameOrder_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bPathTracing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bReferenceMotionBlur,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_Optimisations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_RenderingHooks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_RenderingHooks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewProp_bMaintainFrameOrder,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWL360RenderingSettings",
	Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::PropPointers),
	sizeof(FOWL360RenderingSettings),
	alignof(FOWL360RenderingSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360RenderingSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360RenderingSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360RenderingSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360RenderingSettings.InnerSingleton;
}
// End ScriptStruct FOWL360RenderingSettings

// Begin ScriptStruct FOWL360PipelineSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360PipelineSettings;
class UScriptStruct* FOWL360PipelineSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360PipelineSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360PipelineSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360PipelineSettings, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWL360PipelineSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360PipelineSettings.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWL360PipelineSettings>()
{
	return FOWL360PipelineSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Output_MetaData[] = {
		{ "Category", "Output" },
		{ "DisplayName", "Output" },
		{ "DisplayPriority", "2" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rendering_MetaData[] = {
		{ "Category", "Rendering" },
		{ "DisplayName", "Rendering" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360PipelineSettings.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Output;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rendering;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360PipelineSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::NewProp_Output = { "Output", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360PipelineSettings, Output), Z_Construct_UScriptStruct_FOWL360OutputSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Output_MetaData), NewProp_Output_MetaData) }; // 2785041486
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::NewProp_Rendering = { "Rendering", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360PipelineSettings, Rendering), Z_Construct_UScriptStruct_FOWL360RenderingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rendering_MetaData), NewProp_Rendering_MetaData) }; // 2590538197
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::NewProp_Output,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::NewProp_Rendering,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWL360PipelineSettings",
	Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::PropPointers),
	sizeof(FOWL360PipelineSettings),
	alignof(FOWL360PipelineSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360PipelineSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360PipelineSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360PipelineSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360PipelineSettings.InnerSingleton;
}
// End ScriptStruct FOWL360PipelineSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLBitDepth_StaticEnum, TEXT("EOWLBitDepth"), &Z_Registration_Info_UEnum_EOWLBitDepth, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 406506681U) },
		{ EOWLCompositeMode_StaticEnum, TEXT("EOWLCompositeMode"), &Z_Registration_Info_UEnum_EOWLCompositeMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4207851973U) },
		{ EOWLInterpolationType_StaticEnum, TEXT("EOWLInterpolationType"), &Z_Registration_Info_UEnum_EOWLInterpolationType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2514039434U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWL360TilingSettings::StaticStruct, Z_Construct_UScriptStruct_FOWL360TilingSettings_Statics::NewStructOps, TEXT("OWL360TilingSettings"), &Z_Registration_Info_UScriptStruct_OWL360TilingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360TilingSettings), 145964450U) },
		{ FOWL360OutputSettings::StaticStruct, Z_Construct_UScriptStruct_FOWL360OutputSettings_Statics::NewStructOps, TEXT("OWL360OutputSettings"), &Z_Registration_Info_UScriptStruct_OWL360OutputSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360OutputSettings), 2785041486U) },
		{ FOWL360OptimisationSettings::StaticStruct, Z_Construct_UScriptStruct_FOWL360OptimisationSettings_Statics::NewStructOps, TEXT("OWL360OptimisationSettings"), &Z_Registration_Info_UScriptStruct_OWL360OptimisationSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360OptimisationSettings), 1608767441U) },
		{ FOWL360RenderingSettings::StaticStruct, Z_Construct_UScriptStruct_FOWL360RenderingSettings_Statics::NewStructOps, TEXT("OWL360RenderingSettings"), &Z_Registration_Info_UScriptStruct_OWL360RenderingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360RenderingSettings), 2590538197U) },
		{ FOWL360PipelineSettings::StaticStruct, Z_Construct_UScriptStruct_FOWL360PipelineSettings_Statics::NewStructOps, TEXT("OWL360PipelineSettings"), &Z_Registration_Info_UScriptStruct_OWL360PipelineSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360PipelineSettings), 3555580295U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_2823332330(TEXT("/Script/OWLMRQPipeline"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360PipelineSettings_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
