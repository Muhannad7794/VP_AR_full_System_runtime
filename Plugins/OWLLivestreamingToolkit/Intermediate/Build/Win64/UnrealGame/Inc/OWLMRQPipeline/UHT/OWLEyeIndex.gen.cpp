// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWLEyeIndex.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLEyeIndex() {}

// Begin Cross Module References
OWLMRQPIPELINE_API UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin Enum EOWLMRQEyeIndex
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLMRQEyeIndex;
static UEnum* EOWLMRQEyeIndex_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLMRQEyeIndex.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLMRQEyeIndex.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("EOWLMRQEyeIndex"));
	}
	return Z_Registration_Info_UEnum_EOWLMRQEyeIndex.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UEnum* StaticEnum<EOWLMRQEyeIndex>()
{
	return EOWLMRQEyeIndex_StaticEnum();
}
struct Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "Left.DisplayName", "Left" },
		{ "Left.Name", "EOWLMRQEyeIndex::Left" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWLEyeIndex.h" },
		{ "Right.DisplayName", "Right" },
		{ "Right.Name", "EOWLMRQEyeIndex::Right" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLMRQEyeIndex::Left", (int64)EOWLMRQEyeIndex::Left },
		{ "EOWLMRQEyeIndex::Right", (int64)EOWLMRQEyeIndex::Right },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	"EOWLMRQEyeIndex",
	"EOWLMRQEyeIndex",
	Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex()
{
	if (!Z_Registration_Info_UEnum_EOWLMRQEyeIndex.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLMRQEyeIndex.InnerSingleton, Z_Construct_UEnum_OWLMRQPipeline_EOWLMRQEyeIndex_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLMRQEyeIndex.InnerSingleton;
}
// End Enum EOWLMRQEyeIndex

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLEyeIndex_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLMRQEyeIndex_StaticEnum, TEXT("EOWLMRQEyeIndex"), &Z_Registration_Info_UEnum_EOWLMRQEyeIndex, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1376492923U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLEyeIndex_h_428407236(TEXT("/Script/OWLMRQPipeline"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLEyeIndex_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWLEyeIndex_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
