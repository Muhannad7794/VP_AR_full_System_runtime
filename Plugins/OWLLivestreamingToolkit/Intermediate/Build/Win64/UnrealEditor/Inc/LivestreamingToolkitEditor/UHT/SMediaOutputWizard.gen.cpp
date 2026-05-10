// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkitEditor/Public/SMediaOutputWizard.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSMediaOutputWizard() {}

// Begin Cross Module References
LIVESTREAMINGTOOLKITEDITOR_API UEnum* Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkitEditor();
// End Cross Module References

// Begin Enum EAudioSourceType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAudioSourceType;
static UEnum* EAudioSourceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAudioSourceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAudioSourceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkitEditor(), TEXT("EAudioSourceType"));
	}
	return Z_Registration_Info_UEnum_EAudioSourceType.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKITEDITOR_API UEnum* StaticEnum<EAudioSourceType>()
{
	return EAudioSourceType_StaticEnum();
}
struct Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AS_NoAudio.DisplayName", "No Audio" },
		{ "AS_NoAudio.Name", "EAudioSourceType::AS_NoAudio" },
		{ "AS_Submix.DisplayName", "Yes - Submix" },
		{ "AS_Submix.Name", "EAudioSourceType::AS_Submix" },
		{ "AS_Viewport.DisplayName", "Yes - Viewport" },
		{ "AS_Viewport.Name", "EAudioSourceType::AS_Viewport" },
		{ "ModuleRelativePath", "Public/SMediaOutputWizard.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAudioSourceType::AS_Viewport", (int64)EAudioSourceType::AS_Viewport },
		{ "EAudioSourceType::AS_Submix", (int64)EAudioSourceType::AS_Submix },
		{ "EAudioSourceType::AS_NoAudio", (int64)EAudioSourceType::AS_NoAudio },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LivestreamingToolkitEditor,
	nullptr,
	"EAudioSourceType",
	"EAudioSourceType",
	Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType()
{
	if (!Z_Registration_Info_UEnum_EAudioSourceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAudioSourceType.InnerSingleton, Z_Construct_UEnum_LivestreamingToolkitEditor_EAudioSourceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAudioSourceType.InnerSingleton;
}
// End Enum EAudioSourceType

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaOutputWizard_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAudioSourceType_StaticEnum, TEXT("EAudioSourceType"), &Z_Registration_Info_UEnum_EAudioSourceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1164537340U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaOutputWizard_h_1096098700(TEXT("/Script/LivestreamingToolkitEditor"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaOutputWizard_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaOutputWizard_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
