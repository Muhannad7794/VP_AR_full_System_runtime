// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/OWL360ResolutionSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360ResolutionSettings() {}

// Begin Cross Module References
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360ResolutionSettings();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin ScriptStruct FOWL360ResolutionSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings;
class UScriptStruct* FOWL360ResolutionSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWL360ResolutionSettings, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("OWL360ResolutionSettings"));
	}
	return Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings.OuterSingleton;
}
template<> OWL360CAMERA_API UScriptStruct* StaticStruct<FOWL360ResolutionSettings>()
{
	return FOWL360ResolutionSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360ResolutionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360ResolutionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360ResolutionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AspectRatio_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360ResolutionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCustomResolution_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360ResolutionSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_X;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Y;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AspectRatio;
	static void NewProp_bIsCustomResolution_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCustomResolution;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWL360ResolutionSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360ResolutionSettings, X), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_X_MetaData), NewProp_X_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360ResolutionSettings, Y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Y_MetaData), NewProp_Y_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_AspectRatio = { "AspectRatio", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWL360ResolutionSettings, AspectRatio), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AspectRatio_MetaData), NewProp_AspectRatio_MetaData) };
void Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_bIsCustomResolution_SetBit(void* Obj)
{
	((FOWL360ResolutionSettings*)Obj)->bIsCustomResolution = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_bIsCustomResolution = { "bIsCustomResolution", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWL360ResolutionSettings), &Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_bIsCustomResolution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCustomResolution_MetaData), NewProp_bIsCustomResolution_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_AspectRatio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewProp_bIsCustomResolution,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	&NewStructOps,
	"OWL360ResolutionSettings",
	Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::PropPointers),
	sizeof(FOWL360ResolutionSettings),
	alignof(FOWL360ResolutionSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWL360ResolutionSettings()
{
	if (!Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings.InnerSingleton, Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings.InnerSingleton;
}
// End ScriptStruct FOWL360ResolutionSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360ResolutionSettings_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWL360ResolutionSettings::StaticStruct, Z_Construct_UScriptStruct_FOWL360ResolutionSettings_Statics::NewStructOps, TEXT("OWL360ResolutionSettings"), &Z_Registration_Info_UScriptStruct_OWL360ResolutionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWL360ResolutionSettings), 165309397U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360ResolutionSettings_h_112042046(TEXT("/Script/OWL360Camera"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360ResolutionSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360ResolutionSettings_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
