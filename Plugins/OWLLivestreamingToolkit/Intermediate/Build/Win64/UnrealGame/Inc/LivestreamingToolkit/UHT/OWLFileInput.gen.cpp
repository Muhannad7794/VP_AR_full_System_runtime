// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LivestreamingToolkit/Public/Tools/OWLFileInput.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLFileInput() {}

// Begin Cross Module References
LIVESTREAMINGTOOLKIT_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFileInput();
UPackage* Z_Construct_UPackage__Script_LivestreamingToolkit();
// End Cross Module References

// Begin ScriptStruct FOWLFileInput
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLFileInput;
class UScriptStruct* FOWLFileInput::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFileInput.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLFileInput.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLFileInput, (UObject*)Z_Construct_UPackage__Script_LivestreamingToolkit(), TEXT("OWLFileInput"));
	}
	return Z_Registration_Info_UScriptStruct_OWLFileInput.OuterSingleton;
}
template<> LIVESTREAMINGTOOLKIT_API UScriptStruct* StaticStruct<FOWLFileInput>()
{
	return FOWLFileInput::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLFileInput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Tools/OWLFileInput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "Category", "OWL File Input" },
		{ "ModuleRelativePath", "Public/Tools/OWLFileInput.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAbsolutePath_MetaData[] = {
		{ "Category", "OWL File Input" },
		{ "Comment", "/* if true, stores the absolute path, if false, a path relative to project directory or executable */" },
		{ "ModuleRelativePath", "Public/Tools/OWLFileInput.h" },
		{ "ToolTip", "if true, stores the absolute path, if false, a path relative to project directory or executable" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static void NewProp_bAbsolutePath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAbsolutePath;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLFileInput>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFileInput, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
void Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewProp_bAbsolutePath_SetBit(void* Obj)
{
	((FOWLFileInput*)Obj)->bAbsolutePath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewProp_bAbsolutePath = { "bAbsolutePath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLFileInput), &Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewProp_bAbsolutePath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAbsolutePath_MetaData), NewProp_bAbsolutePath_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLFileInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewProp_bAbsolutePath,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFileInput_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLFileInput_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LivestreamingToolkit,
	nullptr,
	&NewStructOps,
	"OWLFileInput",
	Z_Construct_UScriptStruct_FOWLFileInput_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFileInput_Statics::PropPointers),
	sizeof(FOWLFileInput),
	alignof(FOWLFileInput),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFileInput_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLFileInput_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLFileInput()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFileInput.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLFileInput.InnerSingleton, Z_Construct_UScriptStruct_FOWLFileInput_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLFileInput.InnerSingleton;
}
// End ScriptStruct FOWLFileInput

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkit_Public_Tools_OWLFileInput_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLFileInput::StaticStruct, Z_Construct_UScriptStruct_FOWLFileInput_Statics::NewStructOps, TEXT("OWLFileInput"), &Z_Registration_Info_UScriptStruct_OWLFileInput, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLFileInput), 856243302U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkit_Public_Tools_OWLFileInput_h_1078220707(TEXT("/Script/LivestreamingToolkit"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkit_Public_Tools_OWLFileInput_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkit_Public_Tools_OWLFileInput_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
