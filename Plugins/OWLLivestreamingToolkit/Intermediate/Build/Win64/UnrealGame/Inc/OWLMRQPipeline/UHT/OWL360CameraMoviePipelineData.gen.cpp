// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLMRQPipeline/Public/OWL360Camera/OWL360CameraMoviePipelineData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360CameraMoviePipelineData() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector3d();
OWLMRQPIPELINE_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFoundSequenceCamera();
UPackage* Z_Construct_UPackage__Script_OWLMRQPipeline();
// End Cross Module References

// Begin ScriptStruct FOWLFoundSequenceCamera
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera;
class UScriptStruct* FOWLFoundSequenceCamera::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLFoundSequenceCamera, (UObject*)Z_Construct_UPackage__Script_OWLMRQPipeline(), TEXT("OWLFoundSequenceCamera"));
	}
	return Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera.OuterSingleton;
}
template<> OWLMRQPIPELINE_API UScriptStruct* StaticStruct<FOWLFoundSequenceCamera>()
{
	return FOWLFoundSequenceCamera::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Guid_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreeSixtyGuid_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortOrder_MetaData[] = {
		{ "Comment", "// The sort order as of the original track\n" },
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
		{ "ToolTip", "The sort order as of the original track" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentSequenceName_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIs360_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360Camera/OWL360CameraMoviePipelineData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Guid;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ThreeSixtyGuid;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SortOrder;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ParentSequenceName;
	static void NewProp_bIs360_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIs360;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLFoundSequenceCamera>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Guid = { "Guid", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, Guid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Guid_MetaData), NewProp_Guid_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_ThreeSixtyGuid = { "ThreeSixtyGuid", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, ThreeSixtyGuid), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreeSixtyGuid_MetaData), NewProp_ThreeSixtyGuid_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_SortOrder = { "SortOrder", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, SortOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortOrder_MetaData), NewProp_SortOrder_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_ParentSequenceName = { "ParentSequenceName", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, ParentSequenceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentSequenceName_MetaData), NewProp_ParentSequenceName_MetaData) };
void Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_bIs360_SetBit(void* Obj)
{
	((FOWLFoundSequenceCamera*)Obj)->bIs360 = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_bIs360 = { "bIs360", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLFoundSequenceCamera), &Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_bIs360_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIs360_MetaData), NewProp_bIs360_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, Location), Z_Construct_UScriptStruct_FVector3d, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFoundSequenceCamera, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Guid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_ThreeSixtyGuid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_SortOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_ParentSequenceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_bIs360,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewProp_Rotation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWLMRQPipeline,
	nullptr,
	&NewStructOps,
	"OWLFoundSequenceCamera",
	Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::PropPointers),
	sizeof(FOWLFoundSequenceCamera),
	alignof(FOWLFoundSequenceCamera),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLFoundSequenceCamera()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera.InnerSingleton, Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera.InnerSingleton;
}
// End ScriptStruct FOWLFoundSequenceCamera

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelineData_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLFoundSequenceCamera::StaticStruct, Z_Construct_UScriptStruct_FOWLFoundSequenceCamera_Statics::NewStructOps, TEXT("OWLFoundSequenceCamera"), &Z_Registration_Info_UScriptStruct_OWLFoundSequenceCamera, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLFoundSequenceCamera), 3558897373U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelineData_h_3749141655(TEXT("/Script/OWLMRQPipeline"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelineData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLMRQPipeline_Public_OWL360Camera_OWL360CameraMoviePipelineData_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
