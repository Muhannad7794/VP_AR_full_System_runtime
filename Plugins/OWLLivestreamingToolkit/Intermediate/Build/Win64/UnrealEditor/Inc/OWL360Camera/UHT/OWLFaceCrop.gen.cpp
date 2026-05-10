// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/DataTypes/OWLFaceCrop.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLFaceCrop() {}

// Begin Cross Module References
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLCroppedFaces();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFaceCrop();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin ScriptStruct FOWLFaceCrop
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLFaceCrop;
class UScriptStruct* FOWLFaceCrop::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFaceCrop.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLFaceCrop.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLFaceCrop, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("OWLFaceCrop"));
	}
	return Z_Registration_Info_UScriptStruct_OWLFaceCrop.OuterSingleton;
}
template<> OWL360CAMERA_API UScriptStruct* StaticStruct<FOWLFaceCrop>()
{
	return FOWLFaceCrop::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLFaceCrop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
		{ "UIMax", "0.990000" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
		{ "UIMax", "0.990000" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Top_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
		{ "UIMax", "0.990000" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bottom_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
		{ "UIMax", "0.990000" },
		{ "UIMin", "0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Left;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Right;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Top;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Bottom;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLFaceCrop>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFaceCrop, Left), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Left_MetaData), NewProp_Left_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFaceCrop, Right), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Right_MetaData), NewProp_Right_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Top = { "Top", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFaceCrop, Top), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Top_MetaData), NewProp_Top_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Bottom = { "Bottom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFaceCrop, Bottom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bottom_MetaData), NewProp_Bottom_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Left,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Right,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Top,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewProp_Bottom,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	&NewStructOps,
	"OWLFaceCrop",
	Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::PropPointers),
	sizeof(FOWLFaceCrop),
	alignof(FOWLFaceCrop),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLFaceCrop()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFaceCrop.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLFaceCrop.InnerSingleton, Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLFaceCrop.InnerSingleton;
}
// End ScriptStruct FOWLFaceCrop

// Begin ScriptStruct FOWLCroppedFaces
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLCroppedFaces;
class UScriptStruct* FOWLCroppedFaces::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLCroppedFaces.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLCroppedFaces.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLCroppedFaces, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("OWLCroppedFaces"));
	}
	return Z_Registration_Info_UScriptStruct_OWLCroppedFaces.OuterSingleton;
}
template<> OWL360CAMERA_API UScriptStruct* StaticStruct<FOWLCroppedFaces>()
{
	return FOWLCroppedFaces::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Front_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Back_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Up_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Down_MetaData[] = {
		{ "Category", "Crop" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceCrop.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Front;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Back;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Left;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Right;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Up;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Down;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLCroppedFaces>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Front = { "Front", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLCroppedFaces, Front), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Front_MetaData), NewProp_Front_MetaData) }; // 3418875187
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Back = { "Back", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLCroppedFaces, Back), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Back_MetaData), NewProp_Back_MetaData) }; // 3418875187
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLCroppedFaces, Left), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Left_MetaData), NewProp_Left_MetaData) }; // 3418875187
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLCroppedFaces, Right), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Right_MetaData), NewProp_Right_MetaData) }; // 3418875187
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Up = { "Up", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLCroppedFaces, Up), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Up_MetaData), NewProp_Up_MetaData) }; // 3418875187
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Down = { "Down", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLCroppedFaces, Down), Z_Construct_UScriptStruct_FOWLFaceCrop, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Down_MetaData), NewProp_Down_MetaData) }; // 3418875187
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Front,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Back,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Left,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Right,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Up,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewProp_Down,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	&NewStructOps,
	"OWLCroppedFaces",
	Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::PropPointers),
	sizeof(FOWLCroppedFaces),
	alignof(FOWLCroppedFaces),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLCroppedFaces()
{
	if (!Z_Registration_Info_UScriptStruct_OWLCroppedFaces.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLCroppedFaces.InnerSingleton, Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLCroppedFaces.InnerSingleton;
}
// End ScriptStruct FOWLCroppedFaces

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceCrop_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLFaceCrop::StaticStruct, Z_Construct_UScriptStruct_FOWLFaceCrop_Statics::NewStructOps, TEXT("OWLFaceCrop"), &Z_Registration_Info_UScriptStruct_OWLFaceCrop, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLFaceCrop), 3418875187U) },
		{ FOWLCroppedFaces::StaticStruct, Z_Construct_UScriptStruct_FOWLCroppedFaces_Statics::NewStructOps, TEXT("OWLCroppedFaces"), &Z_Registration_Info_UScriptStruct_OWLCroppedFaces, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLCroppedFaces), 287722816U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceCrop_h_1910498127(TEXT("/Script/OWL360Camera"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceCrop_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceCrop_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
