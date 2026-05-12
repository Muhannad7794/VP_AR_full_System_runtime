// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/DataTypes/OWL360Projections.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360Projections() {}

// Begin Cross Module References
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_E360ProjectionType();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin Enum E360ProjectionType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E360ProjectionType;
static UEnum* E360ProjectionType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E360ProjectionType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E360ProjectionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWL360Camera_E360ProjectionType, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("E360ProjectionType"));
	}
	return Z_Registration_Info_UEnum_E360ProjectionType.OuterSingleton;
}
template<> OWL360CAMERA_API UEnum* StaticEnum<E360ProjectionType>()
{
	return E360ProjectionType_StaticEnum();
}
struct Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Type of texture output from the 360 cam\n" },
		{ "CT_CubeMap.DisplayName", "Cubemap" },
		{ "CT_CubeMap.Name", "E360ProjectionType::CT_CubeMap" },
		{ "CT_DomeMaster.DisplayName", "DomeMaster" },
		{ "CT_DomeMaster.Name", "E360ProjectionType::CT_DomeMaster" },
		{ "CT_EquiRectangular.DisplayName", "Equirectangular" },
		{ "CT_EquiRectangular.Name", "E360ProjectionType::CT_EquiRectangular" },
		{ "CT_Mono180.DisplayName", "180 Equirectangular" },
		{ "CT_Mono180.Name", "E360ProjectionType::CT_Mono180" },
		{ "CT_StereoEquiRectangular.DisplayName", "VR360 Stereo Equirectangular [experimental]" },
		{ "CT_StereoEquiRectangular.Name", "E360ProjectionType::CT_StereoEquiRectangular" },
		{ "CT_Stereographic.DisplayName", "Stereographic (Tiny Planet)" },
		{ "CT_Stereographic.Name", "E360ProjectionType::CT_Stereographic" },
		{ "CT_StereoVR180.DisplayName", "VR180 Stereo Equirectangular" },
		{ "CT_StereoVR180.Name", "E360ProjectionType::CT_StereoVR180" },
		{ "ModuleRelativePath", "Public/DataTypes/OWL360Projections.h" },
		{ "ToolTip", "Type of texture output from the 360 cam" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E360ProjectionType::CT_CubeMap", (int64)E360ProjectionType::CT_CubeMap },
		{ "E360ProjectionType::CT_DomeMaster", (int64)E360ProjectionType::CT_DomeMaster },
		{ "E360ProjectionType::CT_EquiRectangular", (int64)E360ProjectionType::CT_EquiRectangular },
		{ "E360ProjectionType::CT_Mono180", (int64)E360ProjectionType::CT_Mono180 },
		{ "E360ProjectionType::CT_StereoEquiRectangular", (int64)E360ProjectionType::CT_StereoEquiRectangular },
		{ "E360ProjectionType::CT_StereoVR180", (int64)E360ProjectionType::CT_StereoVR180 },
		{ "E360ProjectionType::CT_Stereographic", (int64)E360ProjectionType::CT_Stereographic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	"E360ProjectionType",
	"E360ProjectionType",
	Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWL360Camera_E360ProjectionType()
{
	if (!Z_Registration_Info_UEnum_E360ProjectionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E360ProjectionType.InnerSingleton, Z_Construct_UEnum_OWL360Camera_E360ProjectionType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E360ProjectionType.InnerSingleton;
}
// End Enum E360ProjectionType

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWL360Projections_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ E360ProjectionType_StaticEnum, TEXT("E360ProjectionType"), &Z_Registration_Info_UEnum_E360ProjectionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 184384836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWL360Projections_h_2542824472(TEXT("/Script/OWL360Camera"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWL360Projections_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_DataTypes_OWL360Projections_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
