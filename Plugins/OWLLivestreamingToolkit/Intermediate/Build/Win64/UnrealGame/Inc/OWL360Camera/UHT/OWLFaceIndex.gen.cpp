// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/DataTypes/OWLFaceIndex.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLFaceIndex() {}

// Begin Cross Module References
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin Enum EOWL360FaceIndex
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWL360FaceIndex;
static UEnum* EOWL360FaceIndex_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWL360FaceIndex.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWL360FaceIndex.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("EOWL360FaceIndex"));
	}
	return Z_Registration_Info_UEnum_EOWL360FaceIndex.OuterSingleton;
}
template<> OWL360CAMERA_API UEnum* StaticEnum<EOWL360FaceIndex>()
{
	return EOWL360FaceIndex_StaticEnum();
}
struct Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Back.DisplayName", "Back Face" },
		{ "Back.Name", "EOWL360FaceIndex::Back" },
		{ "BlueprintType", "true" },
		{ "Down.DisplayName", "Down Face" },
		{ "Down.Name", "EOWL360FaceIndex::Down" },
		{ "Front.DisplayName", "Front Face" },
		{ "Front.Name", "EOWL360FaceIndex::Front" },
		{ "Left.DisplayName", "Left Face" },
		{ "Left.Name", "EOWL360FaceIndex::Left" },
		{ "ModuleRelativePath", "Public/DataTypes/OWLFaceIndex.h" },
		{ "Right.DisplayName", "Right Face" },
		{ "Right.Name", "EOWL360FaceIndex::Right" },
		{ "Up.DisplayName", "Up Face" },
		{ "Up.Name", "EOWL360FaceIndex::Up" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWL360FaceIndex::Right", (int64)EOWL360FaceIndex::Right },
		{ "EOWL360FaceIndex::Left", (int64)EOWL360FaceIndex::Left },
		{ "EOWL360FaceIndex::Up", (int64)EOWL360FaceIndex::Up },
		{ "EOWL360FaceIndex::Down", (int64)EOWL360FaceIndex::Down },
		{ "EOWL360FaceIndex::Front", (int64)EOWL360FaceIndex::Front },
		{ "EOWL360FaceIndex::Back", (int64)EOWL360FaceIndex::Back },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	"EOWL360FaceIndex",
	"EOWL360FaceIndex",
	Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex()
{
	if (!Z_Registration_Info_UEnum_EOWL360FaceIndex.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWL360FaceIndex.InnerSingleton, Z_Construct_UEnum_OWL360Camera_EOWL360FaceIndex_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWL360FaceIndex.InnerSingleton;
}
// End Enum EOWL360FaceIndex

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceIndex_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWL360FaceIndex_StaticEnum, TEXT("EOWL360FaceIndex"), &Z_Registration_Info_UEnum_EOWL360FaceIndex, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3198239973U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceIndex_h_3150341852(TEXT("/Script/OWL360Camera"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceIndex_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWLFaceIndex_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
