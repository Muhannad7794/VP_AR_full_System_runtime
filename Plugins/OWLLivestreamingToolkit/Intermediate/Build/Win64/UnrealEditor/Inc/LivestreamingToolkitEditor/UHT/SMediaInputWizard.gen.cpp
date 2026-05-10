// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkitEditor/Public/SMediaInputWizard.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMediaInputWizard() {}

// Begin Cross Module References
LIVESTREAMINGTOOLKITEDITOR_API UEnum* Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation();
LIVESTREAMINGTOOLKITEDITOR_API UEnum* Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkitEditor();
// End Cross Module References

// Begin Enum EMediaInputLocation
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMediaInputLocation;
static UEnum* EMediaInputLocation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMediaInputLocation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMediaInputLocation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitEditor(), TEXT("EMediaInputLocation"));
	}
	return Z_Registration_Info_UEnum_EMediaInputLocation.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITEDITOR_API UEnum* StaticEnum<EMediaInputLocation>()
{
	return EMediaInputLocation_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ML_Material.DisplayName", "Material" },
		{ "ML_Material.Name", "EMediaInputLocation::ML_Material" },
		{ "ML_MediaPlate.DisplayName", "Unreal Media Plate" },
		{ "ML_MediaPlate.Name", "EMediaInputLocation::ML_MediaPlate" },
		{ "ML_Plane.DisplayName", "Plane" },
		{ "ML_Plane.Name", "EMediaInputLocation::ML_Plane" },
		{ "ModuleRelativePath", "Public/SMediaInputWizard.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMediaInputLocation::ML_MediaPlate", (int64)EMediaInputLocation::ML_MediaPlate },
		{ "EMediaInputLocation::ML_Material", (int64)EMediaInputLocation::ML_Material },
		{ "EMediaInputLocation::ML_Plane", (int64)EMediaInputLocation::ML_Plane },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitEditor,
	nullptr,
	"EMediaInputLocation",
	"EMediaInputLocation",
	Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation()
{
	if (!Z_Registration_Info_UEnum_EMediaInputLocation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMediaInputLocation.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputLocation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMediaInputLocation.InnerSingleton;
}
// End Enum EMediaInputLocation

// Begin Enum EMediaInputType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMediaInputType;
static UEnum* EMediaInputType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMediaInputType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMediaInputType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitEditor(), TEXT("EMediaInputType"));
	}
	return Z_Registration_Info_UEnum_EMediaInputType.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITEDITOR_API UEnum* StaticEnum<EMediaInputType>()
{
	return EMediaInputType_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SMediaInputWizard.h" },
		{ "MT_MediaSource.DisplayName", "Media Source" },
		{ "MT_MediaSource.Name", "EMediaInputType::MT_MediaSource" },
		{ "MT_MonitorCapture.DisplayName", "Monitor Capture" },
		{ "MT_MonitorCapture.Name", "EMediaInputType::MT_MonitorCapture" },
		{ "MT_NDI.DisplayName", "NDI" },
		{ "MT_NDI.Name", "EMediaInputType::MT_NDI" },
		{ "MT_Spout.DisplayName", "Spout" },
		{ "MT_Spout.Name", "EMediaInputType::MT_Spout" },
		{ "MT_WindowCapture.DisplayName", "Window Capture" },
		{ "MT_WindowCapture.Name", "EMediaInputType::MT_WindowCapture" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMediaInputType::MT_Spout", (int64)EMediaInputType::MT_Spout },
		{ "EMediaInputType::MT_NDI", (int64)EMediaInputType::MT_NDI },
		{ "EMediaInputType::MT_MonitorCapture", (int64)EMediaInputType::MT_MonitorCapture },
		{ "EMediaInputType::MT_WindowCapture", (int64)EMediaInputType::MT_WindowCapture },
		{ "EMediaInputType::MT_MediaSource", (int64)EMediaInputType::MT_MediaSource },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitEditor,
	nullptr,
	"EMediaInputType",
	"EMediaInputType",
	Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType()
{
	if (!Z_Registration_Info_UEnum_EMediaInputType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMediaInputType.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitEditor_EMediaInputType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMediaInputType.InnerSingleton;
}
// End Enum EMediaInputType

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaInputWizard_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMediaInputLocation_StaticEnum, TEXT("EMediaInputLocation"), &Z_Registration_Info_UEnum_EMediaInputLocation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1394306178U) },
		{ EMediaInputType_StaticEnum, TEXT("EMediaInputType"), &Z_Registration_Info_UEnum_EMediaInputType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 896358450U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaInputWizard_h_2483780119(TEXT("/Script/LivestreamingToolkitEditor"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaInputWizard_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaInputWizard_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
