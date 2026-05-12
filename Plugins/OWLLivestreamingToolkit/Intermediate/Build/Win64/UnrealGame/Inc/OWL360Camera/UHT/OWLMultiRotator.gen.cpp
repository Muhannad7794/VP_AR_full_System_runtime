// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/DataTypes/OWLMultiRotator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLMultiRotator() {}

// Begin Cross Module References
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLMultiRotator();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin ScriptStruct FOWLMultiRotator
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLMultiRotator;
class UScriptStruct* FOWLMultiRotator::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLMultiRotator.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLMultiRotator.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLMultiRotator, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("OWLMultiRotator"));
	}
	return Z_Registration_Info_UScriptStruct_OWLMultiRotator.OuterSingleton;
}
template<> OWL360CAMERA_API UScriptStruct* StaticStruct<FOWLMultiRotator>()
{
	return FOWLMultiRotator::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLMultiRotator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/* This struct exists so that these values can be keyed in the sequencer.\n * The source of truth should be the individual `FRotator` and the array\n * exists purely for the user to manipulate. When updated\n */" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
		{ "ToolTip", "This struct exists so that these values can be keyed in the sequencer.\n* The source of truth should be the individual `FRotator` and the array\n* exists purely for the user to manipulate. When updated" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_0_Pitch_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_0_Yaw_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_0_Roll_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_1_Pitch_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_1_Yaw_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_1_Roll_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_2_Pitch_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_2_Yaw_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_2_Roll_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_3_Pitch_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_3_Yaw_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_3_Roll_MetaData[] = {
		{ "Category", "Rotation" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLMultiRotator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_0_Pitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_0_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_0_Roll;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_1_Pitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_1_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_1_Roll;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_2_Pitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_2_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_2_Roll;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_3_Pitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_3_Yaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Rotation_3_Roll;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLMultiRotator>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_0_Pitch = { "Rotation_0_Pitch", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_0_Pitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_0_Pitch_MetaData), NewProp_Rotation_0_Pitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_0_Yaw = { "Rotation_0_Yaw", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_0_Yaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_0_Yaw_MetaData), NewProp_Rotation_0_Yaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_0_Roll = { "Rotation_0_Roll", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_0_Roll), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_0_Roll_MetaData), NewProp_Rotation_0_Roll_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_1_Pitch = { "Rotation_1_Pitch", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_1_Pitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_1_Pitch_MetaData), NewProp_Rotation_1_Pitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_1_Yaw = { "Rotation_1_Yaw", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_1_Yaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_1_Yaw_MetaData), NewProp_Rotation_1_Yaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_1_Roll = { "Rotation_1_Roll", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_1_Roll), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_1_Roll_MetaData), NewProp_Rotation_1_Roll_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_2_Pitch = { "Rotation_2_Pitch", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_2_Pitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_2_Pitch_MetaData), NewProp_Rotation_2_Pitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_2_Yaw = { "Rotation_2_Yaw", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_2_Yaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_2_Yaw_MetaData), NewProp_Rotation_2_Yaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_2_Roll = { "Rotation_2_Roll", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_2_Roll), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_2_Roll_MetaData), NewProp_Rotation_2_Roll_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_3_Pitch = { "Rotation_3_Pitch", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_3_Pitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_3_Pitch_MetaData), NewProp_Rotation_3_Pitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_3_Yaw = { "Rotation_3_Yaw", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_3_Yaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_3_Yaw_MetaData), NewProp_Rotation_3_Yaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_3_Roll = { "Rotation_3_Roll", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLMultiRotator, Rotation_3_Roll), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_3_Roll_MetaData), NewProp_Rotation_3_Roll_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_0_Pitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_0_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_0_Roll,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_1_Pitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_1_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_1_Roll,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_2_Pitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_2_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_2_Roll,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_3_Pitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_3_Yaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewProp_Rotation_3_Roll,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	&NewStructOps,
	"OWLMultiRotator",
	Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::PropPointers),
	sizeof(FOWLMultiRotator),
	alignof(FOWLMultiRotator),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLMultiRotator()
{
	if (!Z_Registration_Info_UScriptStruct_OWLMultiRotator.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLMultiRotator.InnerSingleton, Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLMultiRotator.InnerSingleton;
}
// End ScriptStruct FOWLMultiRotator

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLMultiRotator_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLMultiRotator::StaticStruct, Z_Construct_UScriptStruct_FOWLMultiRotator_Statics::NewStructOps, TEXT("OWLMultiRotator"), &Z_Registration_Info_UScriptStruct_OWLMultiRotator, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLMultiRotator), 3367980913U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLMultiRotator_h_1503274513(TEXT("/Script/OWL360Camera"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLMultiRotator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLMultiRotator_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
