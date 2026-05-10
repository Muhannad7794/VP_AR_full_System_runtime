// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkitShaders/Public/OWLStereoRenderingTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLStereoRenderingTypes() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
LIVESTREAMINGTOOLKITSHADERS_API UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType();
LIVESTREAMINGTOOLKITSHADERS_API UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType();
LIVESTREAMINGTOOLKITSHADERS_API UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode();
LIVESTREAMINGTOOLKITSHADERS_API UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode();
LIVESTREAMINGTOOLKITSHADERS_API UScriptStruct* Z_Construct_UScriptStruct_FOWLStereoRenderingConfig();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkitShaders();
// End Cross Module References

// Begin Enum EOWLStereoOutputViewMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLStereoOutputViewMode;
static UEnum* EOWLStereoOutputViewMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLStereoOutputViewMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLStereoOutputViewMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitShaders(), TEXT("EOWLStereoOutputViewMode"));
	}
	return Z_Registration_Info_UEnum_EOWLStereoOutputViewMode.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLStereoOutputViewMode>()
{
	return EOWLStereoOutputViewMode_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "SOVM_Anaglyph.DisplayName", "Anaglyph" },
		{ "SOVM_Anaglyph.Name", "EOWLStereoOutputViewMode::SOVM_Anaglyph" },
		{ "SOVM_Interlace.DisplayName", "Interlace" },
		{ "SOVM_Interlace.Name", "EOWLStereoOutputViewMode::SOVM_Interlace" },
		{ "SOVM_SideBySide.DisplayName", "Side-by-Side" },
		{ "SOVM_SideBySide.Name", "EOWLStereoOutputViewMode::SOVM_SideBySide" },
		{ "SOVM_TopBottom.DisplayName", "Top-Bottom" },
		{ "SOVM_TopBottom.Name", "EOWLStereoOutputViewMode::SOVM_TopBottom" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLStereoOutputViewMode::SOVM_TopBottom", (int64)EOWLStereoOutputViewMode::SOVM_TopBottom },
		{ "EOWLStereoOutputViewMode::SOVM_SideBySide", (int64)EOWLStereoOutputViewMode::SOVM_SideBySide },
		{ "EOWLStereoOutputViewMode::SOVM_Anaglyph", (int64)EOWLStereoOutputViewMode::SOVM_Anaglyph },
		{ "EOWLStereoOutputViewMode::SOVM_Interlace", (int64)EOWLStereoOutputViewMode::SOVM_Interlace },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitShaders,
	nullptr,
	"EOWLStereoOutputViewMode",
	"EOWLStereoOutputViewMode",
	Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode()
{
	if (!Z_Registration_Info_UEnum_EOWLStereoOutputViewMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLStereoOutputViewMode.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLStereoOutputViewMode.InnerSingleton;
}
// End Enum EOWLStereoOutputViewMode

// Begin Enum EOWLInterlaceType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLInterlaceType;
static UEnum* EOWLInterlaceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLInterlaceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLInterlaceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitShaders(), TEXT("EOWLInterlaceType"));
	}
	return Z_Registration_Info_UEnum_EOWLInterlaceType.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLInterlaceType>()
{
	return EOWLInterlaceType_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IT_Checkerboard.DisplayName", "Checkerboard" },
		{ "IT_Checkerboard.Name", "EOWLInterlaceType::IT_Checkerboard" },
		{ "IT_Column.DisplayName", "Column Interlaced" },
		{ "IT_Column.Name", "EOWLInterlaceType::IT_Column" },
		{ "IT_Row.DisplayName", "Row Interlaced" },
		{ "IT_Row.Name", "EOWLInterlaceType::IT_Row" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLInterlaceType::IT_Row", (int64)EOWLInterlaceType::IT_Row },
		{ "EOWLInterlaceType::IT_Column", (int64)EOWLInterlaceType::IT_Column },
		{ "EOWLInterlaceType::IT_Checkerboard", (int64)EOWLInterlaceType::IT_Checkerboard },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitShaders,
	nullptr,
	"EOWLInterlaceType",
	"EOWLInterlaceType",
	Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType()
{
	if (!Z_Registration_Info_UEnum_EOWLInterlaceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLInterlaceType.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLInterlaceType.InnerSingleton;
}
// End Enum EOWLInterlaceType

// Begin Enum EOWLAnaglyphType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLAnaglyphType;
static UEnum* EOWLAnaglyphType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLAnaglyphType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLAnaglyphType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitShaders(), TEXT("EOWLAnaglyphType"));
	}
	return Z_Registration_Info_UEnum_EOWLAnaglyphType.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLAnaglyphType>()
{
	return EOWLAnaglyphType_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AT_GreenMagenta.DisplayName", "Green-Magenta" },
		{ "AT_GreenMagenta.Name", "EOWLAnaglyphType::AT_GreenMagenta" },
		{ "AT_RedCyan.DisplayName", "Red-Cyan" },
		{ "AT_RedCyan.Name", "EOWLAnaglyphType::AT_RedCyan" },
		{ "AT_YellowBlue.DisplayName", "Yellow-Blue" },
		{ "AT_YellowBlue.Name", "EOWLAnaglyphType::AT_YellowBlue" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLAnaglyphType::AT_RedCyan", (int64)EOWLAnaglyphType::AT_RedCyan },
		{ "EOWLAnaglyphType::AT_GreenMagenta", (int64)EOWLAnaglyphType::AT_GreenMagenta },
		{ "EOWLAnaglyphType::AT_YellowBlue", (int64)EOWLAnaglyphType::AT_YellowBlue },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitShaders,
	nullptr,
	"EOWLAnaglyphType",
	"EOWLAnaglyphType",
	Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType()
{
	if (!Z_Registration_Info_UEnum_EOWLAnaglyphType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLAnaglyphType.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLAnaglyphType.InnerSingleton;
}
// End Enum EOWLAnaglyphType

// Begin Enum EOWLStereoUMGMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLStereoUMGMode;
static UEnum* EOWLStereoUMGMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLStereoUMGMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLStereoUMGMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitShaders(), TEXT("EOWLStereoUMGMode"));
	}
	return Z_Registration_Info_UEnum_EOWLStereoUMGMode.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITSHADERS_API UEnum* StaticEnum<EOWLStereoUMGMode>()
{
	return EOWLStereoUMGMode_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "SUMG_BothEyes.DisplayName", "Both Eyes (Identical)" },
		{ "SUMG_BothEyes.Name", "EOWLStereoUMGMode::SUMG_BothEyes" },
		{ "SUMG_Disabled.DisplayName", "Disabled" },
		{ "SUMG_Disabled.Name", "EOWLStereoUMGMode::SUMG_Disabled" },
		{ "SUMG_LeftEyeOnly.DisplayName", "Left Eye Only" },
		{ "SUMG_LeftEyeOnly.Name", "EOWLStereoUMGMode::SUMG_LeftEyeOnly" },
		{ "SUMG_RightEyeOnly.DisplayName", "Right Eye Only" },
		{ "SUMG_RightEyeOnly.Name", "EOWLStereoUMGMode::SUMG_RightEyeOnly" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLStereoUMGMode::SUMG_BothEyes", (int64)EOWLStereoUMGMode::SUMG_BothEyes },
		{ "EOWLStereoUMGMode::SUMG_LeftEyeOnly", (int64)EOWLStereoUMGMode::SUMG_LeftEyeOnly },
		{ "EOWLStereoUMGMode::SUMG_RightEyeOnly", (int64)EOWLStereoUMGMode::SUMG_RightEyeOnly },
		{ "EOWLStereoUMGMode::SUMG_Disabled", (int64)EOWLStereoUMGMode::SUMG_Disabled },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitShaders,
	nullptr,
	"EOWLStereoUMGMode",
	"EOWLStereoUMGMode",
	Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode()
{
	if (!Z_Registration_Info_UEnum_EOWLStereoUMGMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLStereoUMGMode.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLStereoUMGMode.InnerSingleton;
}
// End Enum EOWLStereoUMGMode

// Begin ScriptStruct FOWLStereoRenderingConfig
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig;
class UScriptStruct* FOWLStereoRenderingConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLStereoRenderingConfig, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitShaders(), TEXT("OWLStereoRenderingConfig"));
	}
	return Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITSHADERS_API UScriptStruct* StaticStruct<FOWLStereoRenderingConfig>()
{
	return FOWLStereoRenderingConfig::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Configuration struct for stereo rendering settings\n" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Configuration struct for stereo rendering settings" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsStereo_MetaData[] = {
		{ "Category", "Stereoscopic Output|General" },
		{ "DisplayName", "Enable Stereoscopic Output" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Enables stereoscopic rendering for 3D displays and VR" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputViewMode_MetaData[] = {
		{ "Category", "Stereoscopic Output|General" },
		{ "DisplayName", "Output View Mode" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Select how stereoscopic 3D content is displayed: Top-Bottom, Side-by-Side, Anaglyph (colored glasses), or Interlaced" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnaglyphType_MetaData[] = {
		{ "Category", "Stereoscopic Output|Anaglyph" },
		{ "DisplayName", "Anaglyph Type" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Anaglyph" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Choose color filter combination for anaglyph glasses: Red-Cyan (most common), Green-Magenta, or Yellow-Blue" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCrossEyeMode_MetaData[] = {
		{ "Category", "Stereoscopic Output|Side-by-Side" },
		{ "DisplayName", "Cross Eye Mode" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_SideBySide" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Enable for cross-eye viewing method, disable for parallel viewing method" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InterlaceType_MetaData[] = {
		{ "Category", "Stereoscopic Output|Interlace" },
		{ "DisplayName", "Interlace Type" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Select interlace pattern: Row (horizontal lines), Column (vertical lines), or Checkerboard pattern" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CheckerboardSize_MetaData[] = {
		{ "Category", "Stereoscopic Output|Interlace" },
		{ "ClampMax", "64.0" },
		{ "ClampMin", "1.0" },
		{ "DisplayName", "Checkerboard Size" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace && InterlaceType == EOWLInterlaceType::IT_Checkerboard" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Size of each checkerboard cell in pixels. Larger values create a coarser pattern" },
		{ "UIMax", "32.0" },
		{ "UIMin", "1.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlendFactor_MetaData[] = {
		{ "Category", "Stereoscopic Output|Interlace" },
		{ "DisplayName", "Blend Factor" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Controls how smoothly left and right eye views blend together. Higher values create softer transitions" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AntiAliasingAmount_MetaData[] = {
		{ "Category", "Stereoscopic Output|Interlace" },
		{ "DisplayName", "Anti-Aliasing Amount" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Reduces visible jagged edges and patterns. Higher values create smoother but potentially blurrier results" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatternOffset_MetaData[] = {
		{ "Category", "Stereoscopic Output|Interlace" },
		{ "DisplayName", "Pattern Offset" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Shifts the interlace pattern to fine-tune alignment. Useful for custom displays or to adjust for viewer position" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSwapLeftRight_MetaData[] = {
		{ "Category", "Stereoscopic Output|Interlace" },
		{ "DisplayName", "Swap Left Right" },
		{ "EditCondition", "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Swaps which eye is shown in each interlaced segment. Toggle this if depth appears inverted" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UMGStereoMode_MetaData[] = {
		{ "Category", "Stereoscopic Output|UMG" },
		{ "DisplayName", "UMG Stereo Mode" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Controls how UMG widgets are rendered in stereoscopic mode" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeSeparation_MetaData[] = {
		{ "Category", "Convergence|Eye Settings" },
		{ "ClampMin", "0.01" },
		{ "DisplayName", "Eye Separation" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "The physical separation between virtual cameras in world units (similar to IPD). Affects the strength of the 3D effect" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeSeparationScale_MetaData[] = {
		{ "Category", "Convergence|Eye Settings" },
		{ "ClampMin", "0.01" },
		{ "DisplayName", "Eye Separation Scale" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Multiplier applied to eye separation. Lower values reduce the 3D effect, higher values increase it" },
		{ "UIMax", "10.0" },
		{ "UIMin", "0.01" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConvergenceDistance_MetaData[] = {
		{ "Category", "Convergence|Distance" },
		{ "ClampMin", "0.1" },
		{ "DisplayName", "Convergence Distance" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Distance at which objects appear at screen depth (neither popping out nor recessed). Objects closer than this will appear to pop out" },
		{ "UIMax", "10000.0" },
		{ "UIMin", "10.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSyncConvergenceWithFocus_MetaData[] = {
		{ "Category", "Convergence|Distance" },
		{ "DisplayName", "Sync Convergence with Camera Focus" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "When enabled, convergence distance will automatically update to match camera focus distance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowConvergencePlane_MetaData[] = {
		{ "Category", "Convergence|Visualization" },
		{ "DisplayName", "Show Convergence Plane" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "Displays a visual indicator showing where the convergence plane is located in the scene" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConvergencePlaneColor_MetaData[] = {
		{ "Category", "Convergence|Visualization" },
		{ "DisplayName", "Convergence Plane Color" },
		{ "EditCondition", "bShowConvergencePlane" },
		{ "ModuleRelativePath", "Public/OWLStereoRenderingTypes.h" },
		{ "ToolTip", "The color of the convergence plane visualization" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsStereo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStereo;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutputViewMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OutputViewMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AnaglyphType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AnaglyphType;
	static void NewProp_bCrossEyeMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCrossEyeMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InterlaceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InterlaceType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CheckerboardSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendFactor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AntiAliasingAmount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PatternOffset;
	static void NewProp_bSwapLeftRight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSwapLeftRight;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UMGStereoMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UMGStereoMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EyeSeparation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EyeSeparationScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ConvergenceDistance;
	static void NewProp_bSyncConvergenceWithFocus_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSyncConvergenceWithFocus;
	static void NewProp_bShowConvergencePlane_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowConvergencePlane;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ConvergencePlaneColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLStereoRenderingConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bIsStereo_SetBit(void* Obj)
{
	((FOWLStereoRenderingConfig*)Obj)->bIsStereo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bIsStereo = { "bIsStereo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLStereoRenderingConfig), &Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bIsStereo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsStereo_MetaData), NewProp_bIsStereo_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_OutputViewMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_OutputViewMode = { "OutputViewMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, OutputViewMode), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoOutputViewMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputViewMode_MetaData), NewProp_OutputViewMode_MetaData) }; // 2901757893
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_AnaglyphType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_AnaglyphType = { "AnaglyphType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, AnaglyphType), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLAnaglyphType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnaglyphType_MetaData), NewProp_AnaglyphType_MetaData) }; // 63718664
void Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bCrossEyeMode_SetBit(void* Obj)
{
	((FOWLStereoRenderingConfig*)Obj)->bCrossEyeMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bCrossEyeMode = { "bCrossEyeMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLStereoRenderingConfig), &Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bCrossEyeMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCrossEyeMode_MetaData), NewProp_bCrossEyeMode_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_InterlaceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_InterlaceType = { "InterlaceType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, InterlaceType), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLInterlaceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InterlaceType_MetaData), NewProp_InterlaceType_MetaData) }; // 3779448905
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_CheckerboardSize = { "CheckerboardSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, CheckerboardSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CheckerboardSize_MetaData), NewProp_CheckerboardSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_BlendFactor = { "BlendFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, BlendFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlendFactor_MetaData), NewProp_BlendFactor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_AntiAliasingAmount = { "AntiAliasingAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, AntiAliasingAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AntiAliasingAmount_MetaData), NewProp_AntiAliasingAmount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_PatternOffset = { "PatternOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, PatternOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatternOffset_MetaData), NewProp_PatternOffset_MetaData) };
void Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSwapLeftRight_SetBit(void* Obj)
{
	((FOWLStereoRenderingConfig*)Obj)->bSwapLeftRight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSwapLeftRight = { "bSwapLeftRight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLStereoRenderingConfig), &Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSwapLeftRight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSwapLeftRight_MetaData), NewProp_bSwapLeftRight_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_UMGStereoMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_UMGStereoMode = { "UMGStereoMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, UMGStereoMode), Z_Construct_UEnum_LivestreamingToolkitShaders_EOWLStereoUMGMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UMGStereoMode_MetaData), NewProp_UMGStereoMode_MetaData) }; // 2352400473
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_EyeSeparation = { "EyeSeparation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, EyeSeparation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeSeparation_MetaData), NewProp_EyeSeparation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_EyeSeparationScale = { "EyeSeparationScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, EyeSeparationScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeSeparationScale_MetaData), NewProp_EyeSeparationScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_ConvergenceDistance = { "ConvergenceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, ConvergenceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConvergenceDistance_MetaData), NewProp_ConvergenceDistance_MetaData) };
void Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSyncConvergenceWithFocus_SetBit(void* Obj)
{
	((FOWLStereoRenderingConfig*)Obj)->bSyncConvergenceWithFocus = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSyncConvergenceWithFocus = { "bSyncConvergenceWithFocus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLStereoRenderingConfig), &Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSyncConvergenceWithFocus_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSyncConvergenceWithFocus_MetaData), NewProp_bSyncConvergenceWithFocus_MetaData) };
void Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bShowConvergencePlane_SetBit(void* Obj)
{
	((FOWLStereoRenderingConfig*)Obj)->bShowConvergencePlane = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bShowConvergencePlane = { "bShowConvergencePlane", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLStereoRenderingConfig), &Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bShowConvergencePlane_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowConvergencePlane_MetaData), NewProp_bShowConvergencePlane_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_ConvergencePlaneColor = { "ConvergencePlaneColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLStereoRenderingConfig, ConvergencePlaneColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConvergencePlaneColor_MetaData), NewProp_ConvergencePlaneColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bIsStereo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_OutputViewMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_OutputViewMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_AnaglyphType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_AnaglyphType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bCrossEyeMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_InterlaceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_InterlaceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_CheckerboardSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_BlendFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_AntiAliasingAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_PatternOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSwapLeftRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_UMGStereoMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_UMGStereoMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_EyeSeparation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_EyeSeparationScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_ConvergenceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bSyncConvergenceWithFocus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_bShowConvergencePlane,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewProp_ConvergencePlaneColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LivestreamingToolkitShaders,
	nullptr,
	&NewStructOps,
	"OWLStereoRenderingConfig",
	Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::PropPointers),
	sizeof(FOWLStereoRenderingConfig),
	alignof(FOWLStereoRenderingConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLStereoRenderingConfig()
{
	if (!Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig.InnerSingleton, Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig.InnerSingleton;
}
// End ScriptStruct FOWLStereoRenderingConfig

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLStereoOutputViewMode_StaticEnum, TEXT("EOWLStereoOutputViewMode"), &Z_Registration_Info_UEnum_EOWLStereoOutputViewMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2901757893U) },
		{ EOWLInterlaceType_StaticEnum, TEXT("EOWLInterlaceType"), &Z_Registration_Info_UEnum_EOWLInterlaceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3779448905U) },
		{ EOWLAnaglyphType_StaticEnum, TEXT("EOWLAnaglyphType"), &Z_Registration_Info_UEnum_EOWLAnaglyphType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 63718664U) },
		{ EOWLStereoUMGMode_StaticEnum, TEXT("EOWLStereoUMGMode"), &Z_Registration_Info_UEnum_EOWLStereoUMGMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2352400473U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLStereoRenderingConfig::StaticStruct, Z_Construct_UScriptStruct_FOWLStereoRenderingConfig_Statics::NewStructOps, TEXT("OWLStereoRenderingConfig"), &Z_Registration_Info_UScriptStruct_OWLStereoRenderingConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLStereoRenderingConfig), 1599242491U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_4289689212(TEXT("/Script/LivestreamingToolkitShaders"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitShaders_Public_OWLStereoRenderingTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
