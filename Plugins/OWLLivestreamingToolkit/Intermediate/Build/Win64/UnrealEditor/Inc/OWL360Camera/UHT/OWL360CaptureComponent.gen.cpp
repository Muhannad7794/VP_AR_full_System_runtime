// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/OWL360CaptureComponent.h"
#include "OpenColorIO/Public/OpenColorIOColorSpace.h"
#include "OWL360Camera/Public/DataTypes/OWLFaceCrop.h"
#include "OWL360Camera/Public/DataTypes/OWLMultiRotator.h"
#include "OWL360Camera/Public/OWL360FaceRendering.h"
#include "OWL360Camera/Public/OWL360ResolutionSettings.h"
#include "OWLCamera/Public/OWLSnapshotSettings.h"
#include "Runtime/Engine/Classes/Components/SceneCaptureComponent.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360CaptureComponent() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FEngineShowFlagsSetting();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FPostProcessSettings();
OPENCOLORIO_API UScriptStruct* Z_Construct_UScriptStruct_FOpenColorIODisplayConfiguration();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360CaptureComponent();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360CaptureComponent_NoRegister();
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_E360PostProcessPipeline();
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_E360ProjectionType();
OWL360CAMERA_API UEnum* Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360FaceRenderingSettings();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWL360ResolutionSettings();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLCroppedFaces();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLFaceControl();
OWL360CAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLMultiRotator();
OWLCAMERA_API UClass* Z_Construct_UClass_UOWLViewportPreview_NoRegister();
OWLCAMERA_API UEnum* Z_Construct_UEnum_OWLCamera_EOWLOutputBufferVisualisation();
OWLCAMERA_API UFunction* Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature();
OWLCAMERA_API UScriptStruct* Z_Construct_UScriptStruct_FOWLSnapshotSettings();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin ScriptStruct FOWLFaceControl
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OWLFaceControl;
class UScriptStruct* FOWLFaceControl::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFaceControl.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OWLFaceControl.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOWLFaceControl, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("OWLFaceControl"));
	}
	return Z_Registration_Info_UScriptStruct_OWLFaceControl.OuterSingleton;
}
template<> OWL360CAMERA_API UScriptStruct* StaticStruct<FOWLFaceControl>()
{
	return FOWLFaceControl::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOWLFaceControl_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugFaceColors_MetaData[] = {
		{ "Category", "Face Control" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cropping_MetaData[] = {
		{ "Category", "Face Control" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Faces_MetaData[] = {
		{ "Category", "Face Control" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bShowDebugFaceColors_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugFaceColors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Cropping;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Faces;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOWLFaceControl>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_bShowDebugFaceColors_SetBit(void* Obj)
{
	((FOWLFaceControl*)Obj)->bShowDebugFaceColors = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_bShowDebugFaceColors = { "bShowDebugFaceColors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOWLFaceControl), &Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_bShowDebugFaceColors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugFaceColors_MetaData), NewProp_bShowDebugFaceColors_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_Cropping = { "Cropping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFaceControl, Cropping), Z_Construct_UScriptStruct_FOWLCroppedFaces, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cropping_MetaData), NewProp_Cropping_MetaData) }; // 287722816
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_Faces = { "Faces", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOWLFaceControl, Faces), Z_Construct_UScriptStruct_FOWL360FaceRenderingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Faces_MetaData), NewProp_Faces_MetaData) }; // 1170579578
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOWLFaceControl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_bShowDebugFaceColors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_Cropping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewProp_Faces,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFaceControl_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOWLFaceControl_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	&NewStructOps,
	"OWLFaceControl",
	Z_Construct_UScriptStruct_FOWLFaceControl_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFaceControl_Statics::PropPointers),
	sizeof(FOWLFaceControl),
	alignof(FOWLFaceControl),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOWLFaceControl_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOWLFaceControl_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOWLFaceControl()
{
	if (!Z_Registration_Info_UScriptStruct_OWLFaceControl.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OWLFaceControl.InnerSingleton, Z_Construct_UScriptStruct_FOWLFaceControl_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OWLFaceControl.InnerSingleton;
}
// End ScriptStruct FOWLFaceControl

// Begin Enum EOWLPostProcessUpdateLocation
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation;
static UEnum* EOWLPostProcessUpdateLocation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation, (UObject*)Z_Construct_UPackage__Script_OWL360Camera(), TEXT("EOWLPostProcessUpdateLocation"));
	}
	return Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation.OuterSingleton;
}
template<> OWL360CAMERA_API UEnum* StaticEnum<EOWLPostProcessUpdateLocation>()
{
	return EOWLPostProcessUpdateLocation_StaticEnum();
}
struct Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "L_UpdateOn360.DisplayName", "360 Component" },
		{ "L_UpdateOn360.Name", "EOWLPostProcessUpdateLocation::L_UpdateOn360" },
		{ "L_UpdateOn360.Tooltip", "The post-process settings on the 360 capture component are the single source of truth. The Camera Component post process struct is updated from it." },
		{ "L_UpdateOnCamera.DisplayName", "Camera Component" },
		{ "L_UpdateOnCamera.Name", "EOWLPostProcessUpdateLocation::L_UpdateOnCamera" },
		{ "L_UpdateOnCamera.Tooltip", "The post-process settings on the camera component are the single source of truth. The 360 Capture Component post process struct is updated from the Camera post process." },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOWLPostProcessUpdateLocation::L_UpdateOn360", (int64)EOWLPostProcessUpdateLocation::L_UpdateOn360 },
		{ "EOWLPostProcessUpdateLocation::L_UpdateOnCamera", (int64)EOWLPostProcessUpdateLocation::L_UpdateOnCamera },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OWL360Camera,
	nullptr,
	"EOWLPostProcessUpdateLocation",
	"EOWLPostProcessUpdateLocation",
	Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation()
{
	if (!Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation.InnerSingleton, Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation.InnerSingleton;
}
// End Enum EOWLPostProcessUpdateLocation

// Begin Class UOWL360CaptureComponent Function CalculateAutoCrop
struct Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "CalculateAutoCrop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execCalculateAutoCrop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CalculateAutoCrop();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function CalculateAutoCrop

// Begin Class UOWL360CaptureComponent Function CaptureScene
struct Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Render the scene to the texture target immediately. This should not be used if bCaptureEveryFrame is enabled, or the scene capture will render redundantly. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Render the scene to the texture target immediately. This should not be used if bCaptureEveryFrame is enabled, or the scene capture will render redundantly." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "CaptureScene", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execCaptureScene)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CaptureScene();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function CaptureScene

// Begin Class UOWL360CaptureComponent Function ClearHiddenComponents
struct Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Clears the hidden list. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Clears the hidden list." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "ClearHiddenComponents", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execClearHiddenComponents)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearHiddenComponents();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function ClearHiddenComponents

// Begin Class UOWL360CaptureComponent Function ClearShowOnlyComponents
struct Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Clears the Show Only list. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Clears the Show Only list." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "ClearShowOnlyComponents", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execClearShowOnlyComponents)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearShowOnlyComponents();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function ClearShowOnlyComponents

// Begin Class UOWL360CaptureComponent Function GetOutputResolution
struct Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics
{
	struct OWL360CaptureComponent_eventGetOutputResolution_Parms
	{
		FIntPoint ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventGetOutputResolution_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "GetOutputResolution", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::OWL360CaptureComponent_eventGetOutputResolution_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::OWL360CaptureComponent_eventGetOutputResolution_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execGetOutputResolution)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FIntPoint*)Z_Param__Result=P_THIS->GetOutputResolution();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function GetOutputResolution

// Begin Class UOWL360CaptureComponent Function GetTargetCamera
struct Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics
{
	struct OWL360CaptureComponent_eventGetTargetCamera_Parms
	{
		UCameraComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventGetTargetCamera_Parms, ReturnValue), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "GetTargetCamera", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::OWL360CaptureComponent_eventGetTargetCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::OWL360CaptureComponent_eventGetTargetCamera_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execGetTargetCamera)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCameraComponent**)Z_Param__Result=P_THIS->GetTargetCamera();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function GetTargetCamera

// Begin Class UOWL360CaptureComponent Function HideActorComponents
struct Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics
{
	struct OWL360CaptureComponent_eventHideActorComponents_Parms
	{
		AActor* InActor;
		bool bIncludeFromChildActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/**\n\x09 * Adds all primitive components in the actor to our list of hidden components.\n\x09 * @param bIncludeFromChildActors Whether to include the components from child actors\n\x09 */" },
		{ "CPP_Default_bIncludeFromChildActors", "false" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Adds all primitive components in the actor to our list of hidden components.\n@param bIncludeFromChildActors Whether to include the components from child actors" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeFromChildActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static void NewProp_bIncludeFromChildActors_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeFromChildActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventHideActorComponents_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::NewProp_bIncludeFromChildActors_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventHideActorComponents_Parms*)Obj)->bIncludeFromChildActors = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::NewProp_bIncludeFromChildActors = { "bIncludeFromChildActors", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventHideActorComponents_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::NewProp_bIncludeFromChildActors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeFromChildActors_MetaData), NewProp_bIncludeFromChildActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::NewProp_bIncludeFromChildActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "HideActorComponents", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::OWL360CaptureComponent_eventHideActorComponents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::OWL360CaptureComponent_eventHideActorComponents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execHideActorComponents)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_GET_UBOOL(Z_Param_bIncludeFromChildActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HideActorComponents(Z_Param_InActor,Z_Param_bIncludeFromChildActors);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function HideActorComponents

// Begin Class UOWL360CaptureComponent Function HideComponent
struct Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics
{
	struct OWL360CaptureComponent_eventHideComponent_Parms
	{
		UPrimitiveComponent* InComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Adds the component to our list of hidden components. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Adds the component to our list of hidden components." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventHideComponent_Parms, InComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InComponent_MetaData), NewProp_InComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::NewProp_InComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "HideComponent", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::OWL360CaptureComponent_eventHideComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::OWL360CaptureComponent_eventHideComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execHideComponent)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_InComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HideComponent(Z_Param_InComponent);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function HideComponent

// Begin Class UOWL360CaptureComponent Function Is180Projection
struct Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics
{
	struct OWL360CaptureComponent_eventIs180Projection_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Whether the current projection type is stereo. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Whether the current projection type is stereo." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventIs180Projection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventIs180Projection_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "Is180Projection", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::OWL360CaptureComponent_eventIs180Projection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::OWL360CaptureComponent_eventIs180Projection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execIs180Projection)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Is180Projection();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function Is180Projection

// Begin Class UOWL360CaptureComponent Function IsFOVAdjustable
struct Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics
{
	struct OWL360CaptureComponent_eventIsFOVAdjustable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventIsFOVAdjustable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventIsFOVAdjustable_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "IsFOVAdjustable", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::OWL360CaptureComponent_eventIsFOVAdjustable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::OWL360CaptureComponent_eventIsFOVAdjustable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execIsFOVAdjustable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsFOVAdjustable();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function IsFOVAdjustable

// Begin Class UOWL360CaptureComponent Function IsStereoProjection
struct Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics
{
	struct OWL360CaptureComponent_eventIsStereoProjection_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Whether the current projection type is stereo. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Whether the current projection type is stereo." },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventIsStereoProjection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventIsStereoProjection_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "IsStereoProjection", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::OWL360CaptureComponent_eventIsStereoProjection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::OWL360CaptureComponent_eventIsStereoProjection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execIsStereoProjection)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsStereoProjection();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function IsStereoProjection

// Begin Class UOWL360CaptureComponent Function RayTracingEnabled
struct Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics
{
	struct OWL360CaptureComponent_eventRayTracingEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Internal" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventRayTracingEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventRayTracingEnabled_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "RayTracingEnabled", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::OWL360CaptureComponent_eventRayTracingEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::OWL360CaptureComponent_eventRayTracingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execRayTracingEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RayTracingEnabled();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function RayTracingEnabled

// Begin Class UOWL360CaptureComponent Function RemoveShowOnlyActorComponents
struct Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics
{
	struct OWL360CaptureComponent_eventRemoveShowOnlyActorComponents_Parms
	{
		AActor* InActor;
		bool bIncludeFromChildActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/**\n\x09* Removes an actor's components from the Show Only list.\n\x09* @param bIncludeFromChildActors Whether to remove the components from child actors\n\x09*/" },
		{ "CPP_Default_bIncludeFromChildActors", "false" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Removes an actor's components from the Show Only list.\n@param bIncludeFromChildActors Whether to remove the components from child actors" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeFromChildActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static void NewProp_bIncludeFromChildActors_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeFromChildActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventRemoveShowOnlyActorComponents_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventRemoveShowOnlyActorComponents_Parms*)Obj)->bIncludeFromChildActors = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors = { "bIncludeFromChildActors", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventRemoveShowOnlyActorComponents_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeFromChildActors_MetaData), NewProp_bIncludeFromChildActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "RemoveShowOnlyActorComponents", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::OWL360CaptureComponent_eventRemoveShowOnlyActorComponents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::OWL360CaptureComponent_eventRemoveShowOnlyActorComponents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execRemoveShowOnlyActorComponents)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_GET_UBOOL(Z_Param_bIncludeFromChildActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveShowOnlyActorComponents(Z_Param_InActor,Z_Param_bIncludeFromChildActors);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function RemoveShowOnlyActorComponents

// Begin Class UOWL360CaptureComponent Function RemoveShowOnlyComponent
struct Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics
{
	struct OWL360CaptureComponent_eventRemoveShowOnlyComponent_Parms
	{
		UPrimitiveComponent* InComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Removes a component from the Show Only list. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Removes a component from the Show Only list." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventRemoveShowOnlyComponent_Parms, InComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InComponent_MetaData), NewProp_InComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::NewProp_InComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "RemoveShowOnlyComponent", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::OWL360CaptureComponent_eventRemoveShowOnlyComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::OWL360CaptureComponent_eventRemoveShowOnlyComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execRemoveShowOnlyComponent)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_InComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveShowOnlyComponent(Z_Param_InComponent);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function RemoveShowOnlyComponent

// Begin Class UOWL360CaptureComponent Function ResetCrop
struct Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "ResetCrop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execResetCrop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetCrop();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function ResetCrop

// Begin Class UOWL360CaptureComponent Function SetOutputResolution
struct Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics
{
	struct OWL360CaptureComponent_eventSetOutputResolution_Parms
	{
		FIntPoint Res;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Res;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::NewProp_Res = { "Res", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventSetOutputResolution_Parms, Res), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::NewProp_Res,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "SetOutputResolution", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::OWL360CaptureComponent_eventSetOutputResolution_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::OWL360CaptureComponent_eventSetOutputResolution_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execSetOutputResolution)
{
	P_GET_STRUCT(FIntPoint,Z_Param_Res);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOutputResolution(Z_Param_Res);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function SetOutputResolution

// Begin Class UOWL360CaptureComponent Function ShowOnlyActorComponents
struct Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics
{
	struct OWL360CaptureComponent_eventShowOnlyActorComponents_Parms
	{
		AActor* InActor;
		bool bIncludeFromChildActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/**\n\x09* Adds all primitive components in the actor to our list of show-only components.\n\x09* @param bIncludeFromChildActors Whether to include the components from child actors\n\x09*/" },
		{ "CPP_Default_bIncludeFromChildActors", "false" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Adds all primitive components in the actor to our list of show-only components.\n@param bIncludeFromChildActors Whether to include the components from child actors" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeFromChildActors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static void NewProp_bIncludeFromChildActors_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeFromChildActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventShowOnlyActorComponents_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors_SetBit(void* Obj)
{
	((OWL360CaptureComponent_eventShowOnlyActorComponents_Parms*)Obj)->bIncludeFromChildActors = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors = { "bIncludeFromChildActors", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OWL360CaptureComponent_eventShowOnlyActorComponents_Parms), &Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeFromChildActors_MetaData), NewProp_bIncludeFromChildActors_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::NewProp_bIncludeFromChildActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "ShowOnlyActorComponents", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::OWL360CaptureComponent_eventShowOnlyActorComponents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::OWL360CaptureComponent_eventShowOnlyActorComponents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execShowOnlyActorComponents)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_GET_UBOOL(Z_Param_bIncludeFromChildActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowOnlyActorComponents(Z_Param_InActor,Z_Param_bIncludeFromChildActors);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function ShowOnlyActorComponents

// Begin Class UOWL360CaptureComponent Function ShowOnlyComponent
struct Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics
{
	struct OWL360CaptureComponent_eventShowOnlyComponent_Parms
	{
		UPrimitiveComponent* InComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Adds the component to our list of show-only components. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Adds the component to our list of show-only components." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OWL360CaptureComponent_eventShowOnlyComponent_Parms, InComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InComponent_MetaData), NewProp_InComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::NewProp_InComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "ShowOnlyComponent", nullptr, nullptr, Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::OWL360CaptureComponent_eventShowOnlyComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::OWL360CaptureComponent_eventShowOnlyComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execShowOnlyComponent)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_InComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowOnlyComponent(Z_Param_InComponent);
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function ShowOnlyComponent

// Begin Class UOWL360CaptureComponent Function TakeSnapshot
struct Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OWL360Capture" },
		{ "Comment", "/** Take a snapshot using the current snapshot settings */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Take a snapshot using the current snapshot settings" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOWL360CaptureComponent, nullptr, "TakeSnapshot", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOWL360CaptureComponent::execTakeSnapshot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TakeSnapshot();
	P_NATIVE_END;
}
// End Class UOWL360CaptureComponent Function TakeSnapshot

// Begin Class UOWL360CaptureComponent
void UOWL360CaptureComponent::StaticRegisterNativesUOWL360CaptureComponent()
{
	UClass* Class = UOWL360CaptureComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateAutoCrop", &UOWL360CaptureComponent::execCalculateAutoCrop },
		{ "CaptureScene", &UOWL360CaptureComponent::execCaptureScene },
		{ "ClearHiddenComponents", &UOWL360CaptureComponent::execClearHiddenComponents },
		{ "ClearShowOnlyComponents", &UOWL360CaptureComponent::execClearShowOnlyComponents },
		{ "GetOutputResolution", &UOWL360CaptureComponent::execGetOutputResolution },
		{ "GetTargetCamera", &UOWL360CaptureComponent::execGetTargetCamera },
		{ "HideActorComponents", &UOWL360CaptureComponent::execHideActorComponents },
		{ "HideComponent", &UOWL360CaptureComponent::execHideComponent },
		{ "Is180Projection", &UOWL360CaptureComponent::execIs180Projection },
		{ "IsFOVAdjustable", &UOWL360CaptureComponent::execIsFOVAdjustable },
		{ "IsStereoProjection", &UOWL360CaptureComponent::execIsStereoProjection },
		{ "RayTracingEnabled", &UOWL360CaptureComponent::execRayTracingEnabled },
		{ "RemoveShowOnlyActorComponents", &UOWL360CaptureComponent::execRemoveShowOnlyActorComponents },
		{ "RemoveShowOnlyComponent", &UOWL360CaptureComponent::execRemoveShowOnlyComponent },
		{ "ResetCrop", &UOWL360CaptureComponent::execResetCrop },
		{ "SetOutputResolution", &UOWL360CaptureComponent::execSetOutputResolution },
		{ "ShowOnlyActorComponents", &UOWL360CaptureComponent::execShowOnlyActorComponents },
		{ "ShowOnlyComponent", &UOWL360CaptureComponent::execShowOnlyComponent },
		{ "TakeSnapshot", &UOWL360CaptureComponent::execTakeSnapshot },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWL360CaptureComponent);
UClass* Z_Construct_UClass_UOWL360CaptureComponent_NoRegister()
{
	return UOWL360CaptureComponent::StaticClass();
}
struct Z_Construct_UClass_UOWL360CaptureComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Rendering" },
		{ "Comment", "/*\n\nThe Cubemap cameras are six:\nin the order specified here:\nhttps://github.com/google/spatial-media/blob/master/docs/spherical-video-v2-rfc.md#cubemap-projection-box-cbmp\nThese are written left-to-right, top-to-bottom\nie:\n[ 0, 1, 2 ]\n[ 3, 4, 5 ]\n\nWhere:\n0: Right\n1: Left\n2: Up\n3: Down\n4: Front\n5: Back\n*/" },
		{ "HideCategories", "Collision Object Physics SceneComponent Mobility Tags Activation Cooking Rendering Trigger PhysicsVolume" },
		{ "IncludePath", "OWL360CaptureComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "The Cubemap cameras are six:\nin the order specified here:\nhttps://github.com/google/spatial-media/blob/master/docs/spherical-video-v2-rfc.md#cubemap-projection-box-cbmp\nThese are written left-to-right, top-to-bottom\nie:\n[ 0, 1, 2 ]\n[ 3, 4, 5 ]\n\nWhere:\n0: Right\n1: Left\n2: Up\n3: Down\n4: Front\n5: Back" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextureTarget_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/**\n\x09* Render target to render the 360 projection onto\n\x09*/" },
		{ "DisplayName", "Render Target" },
		{ "DisplayPriority", "1" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Render target to render the 360 projection onto" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPauseRendering_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/** Tick if you want to pause rendering to the render target */" },
		{ "DisplayPriority", "2" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Tick if you want to pause rendering to the render target" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DomeAngle_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Field of view of the dome */" },
		{ "EditCondition", "ProjectionType == E360ProjectionType::CT_DomeMaster" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Field of view of the dome" },
		{ "UIMax", "360" },
		{ "UIMin", "10" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StereographicFOV_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Field of view of the stereographic projection */" },
		{ "EditCondition", "ProjectionType == E360ProjectionType::CT_Stereographic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Field of view of the stereographic projection" },
		{ "UIMax", "359" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectionType_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Output texture format */" },
		{ "DisplayName", "Projection Type" },
		{ "DisplayPriority", "3" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Output texture format" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputResolutionSettings_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Texture resolution for camera render output */" },
		{ "DisplayPriority", "5" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Texture resolution for camera render output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StereoEyeSeparation_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Set the gap between left eye and right eye in world units */" },
		{ "DevelopmentStatus", "Experimental" },
		{ "DisplayPriority", "4" },
		{ "EditCondition", "IsStereoProjection()" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Set the gap between left eye and right eye in world units" },
		{ "UIMin", "0.1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewportPreview_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/* Set camera preview in editor as the output render target while rendering */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "Set camera preview in editor as the output render target while rendering" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomHorizontalFOV_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "ClampMax", "360" },
		{ "ClampMin", "0" },
		{ "Comment", "/* Horizontal FOV of the Projection - only available with a Pro Movie Render Queue license */" },
		{ "EditCondition", "IsFOVAdjustable() && !Is180Projection()" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Horizontal FOV of the Projection - only available with a Pro Movie Render Queue license" },
		{ "UIMax", "360" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Custom180HorizontalFOV_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "ClampMax", "180" },
		{ "ClampMin", "0" },
		{ "Comment", "/* Horizontal FOV of the Projection - only available with a Pro Movie Render Queue license */" },
		{ "DisplayName", "Custom Horizontal FOV" },
		{ "EditCondition", "IsFOVAdjustable() && Is180Projection()" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Horizontal FOV of the Projection - only available with a Pro Movie Render Queue license" },
		{ "UIMax", "180" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomVerticalFOV_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "ClampMax", "180" },
		{ "ClampMin", "0" },
		{ "Comment", "/* Vertical FOV of the Projection - only available with a Pro Movie Render Queue license */" },
		{ "EditCondition", "IsFOVAdjustable()" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Vertical FOV of the Projection - only available with a Pro Movie Render Queue license" },
		{ "UIMax", "180" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputMask_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/* A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. - only available with a Pro Movie Render Queue license */" },
		{ "EditCondition", "ProjectionType != E360ProjectionType::CT_CubeMap" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. - only available with a Pro Movie Render Queue license" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FaceBlendPercent_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "ClampMax", "50.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/* Overlaps each constituent face, blending adjacent faces together. This is expensive as it requires a wider FOV for each cube face captured */" },
		{ "EditCondition", "ProjectionType != E360ProjectionType::CT_CubeMap" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Overlaps each constituent face, blending adjacent faces together. This is expensive as it requires a wider FOV for each cube face captured" },
		{ "UIMax", "50.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideInternalFaceDimensions_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Use a custom width/height (must be square) for the cube face renders that comprise the final output */" },
		{ "EditCondition", "ProjectionType != E360ProjectionType::CT_CubeMap" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Use a custom width/height (must be square) for the cube face renders that comprise the final output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverrideFaceDimension_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Custom width and height (must be square) for the cube face renders that comprise the final output */" },
		{ "EditCondition", "bOverrideInternalFaceDimensions" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Custom width and height (must be square) for the cube face renders that comprise the final output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessPipeline_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Type of Post Process applied to the output texture */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Type of Post Process applied to the output texture" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessUpdateLocation_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Select the point of truth for post-process settings */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Select the point of truth for post-process settings" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableBloom_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/* Enable this to disable bloom across all post-process (including post process volumes)\n\x09 This is useful for isolating the cause of seams which cannot be mitigated by increasing the face blend percentage */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Enable this to disable bloom across all post-process (including post process volumes)\n       This is useful for isolating the cause of seams which cannot be mitigated by increasing the face blend percentage" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPathTracing_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/** Enable path tracing - if this is disabled, you need to change your project settings to 'Enable RayTracing' */" },
		{ "EditCondition", "RayTracingEnabled()" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Enable path tracing - if this is disabled, you need to change your project settings to 'Enable RayTracing'" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualisationType_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShowFlagSettings_MetaData[] = {
		{ "Category", "Rendering Flags" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessSettings_MetaData[] = {
		{ "Category", "Post Process Settings" },
		{ "EditCondition", "PostProcessUpdateLocation == EOWLPostProcessUpdateLocation::L_UpdateOn360" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ShowOnlyInnerProperties", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessBlendWeight_MetaData[] = {
		{ "Category", "Post Process Settings" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "PostProcessUpdateLocation == EOWLPostProcessUpdateLocation::L_UpdateOn360" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NearClipPlane_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Camera" },
		{ "DisplayPriority", "14" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugFaceColors_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/* Enable this to preview the cubeface positions on your output render */" },
		{ "DisplayPriority", "11" },
		{ "EditCondition", "ProjectionType != E360ProjectionType::CT_CubeMap" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Enable this to preview the cubeface positions on your output render" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CubeFaceRotation_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/* Rotate the position of the internal faces used to stitch the 360 output together - modifying these values without a Pro Movie Render Queue license will trigger a watermark */" },
		{ "DisplayPriority", "10" },
		{ "EditCondition", "(ProjectionType == E360ProjectionType::CT_Equirectangular || ProjectionType == E360ProjectionType::CT_StereoEquiRectangular || ProjectionType == E360ProjectionType::CT_StereoVR180 || ProjectionType == E360ProjectionType::CT_Mono180 || ProjectionType == E360ProjectionType::CT_Stereographic)" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "Rotate the position of the internal faces used to stitch the 360 output together - modifying these values without a Pro Movie Render Queue license will trigger a watermark" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraRotation_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/* Control the orientation of the 360 camera without affecting the transform of the actor - modifying these values without a Pro Movie Render Queue license will trigger a watermark */" },
		{ "DisplayPriority", "12" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "Control the orientation of the 360 camera without affecting the transform of the actor - modifying these values without a Pro Movie Render Queue license will trigger a watermark" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableUpscaling_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/** Tick to enable plugins like DLSS -- warning certain anti-aliasing settings may cause crashes when screen percentage on this actor is adjusted. WARNING: this feature is experimental and\n\x09\x09may cause crashes especially in conjuction with the Seamless Bloom!! */" },
		{ "DevelopmentStatus", "Experimental" },
		{ "DisplayName", "Enable Upscaling (Experimental)" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Tick to enable plugins like DLSS -- warning certain anti-aliasing settings may cause crashes when screen percentage on this actor is adjusted. WARNING: this feature is experimental and\n              may cause crashes especially in conjuction with the Seamless Bloom!!" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPercentage_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "ClampMax", "200" },
		{ "ClampMin", "25" },
		{ "Comment", "/** ScreenPercentage affects impact of upscaling (ie DLSS, TAA ...) */" },
		{ "DevelopmentStatus", "Experimental" },
		{ "EditCondition", "bEnableUpscaling" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "ScreenPercentage affects impact of upscaling (ie DLSS, TAA ...)" },
		{ "UIMax", "200" },
		{ "UIMin", "25" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableViewState_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/** Disable the view state to get an FPS increase at the cost of temporal effects */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Disable the view state to get an FPS increase at the cost of temporal effects" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FaceControl_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LODDistanceFactor_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/** Scales the distance used by LOD. Set to values greater than 1 to cause the scene capture to use lower LODs than the main view to speed up the scene capture pass. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Scales the distance used by LOD. Set to values greater than 1 to cause the scene capture to use lower LODs than the main view to speed up the scene capture pass." },
		{ "UIMax", "10" },
		{ "UIMin", ".1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxViewDistanceOverride_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/** if > 0, sets a maximum render distance override.  Can be used to cull distant objects from a reflection if the reflecting plane is in an enclosed area like a hallway or room */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "if > 0, sets a maximum render distance override.  Can be used to cull distant objects from a reflection if the reflecting plane is in an enclosed area like a hallway or room" },
		{ "UIMax", "10000" },
		{ "UIMin", "100" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceCameraCut_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/** Forces the `bCameraCut` flag which disables inter-frame caching for certain Unreal post-processing, like TSR motion blur. Disable if you notice performance degradation or lack of inter-frame effects */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Forces the `bCameraCut` flag which disables inter-frame caching for certain Unreal post-processing, like TSR motion blur. Disable if you notice performance degradation or lack of inter-frame effects" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFollowSceneCaptureRenderPath_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Advanced" },
		{ "Comment", "/**\n\x09* Affects rendering path cine capture takes. Scene Capture takes a slightly different rendering route compared to viewport rendering\n\x09* for the purposes of optimization. If the results of cine capture are vastly different to what cine camera displays try disabling this.\n\x09*/" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Affects rendering path cine capture takes. Scene Capture takes a slightly different rendering route compared to viewport rendering\nfor the purposes of optimization. If the results of cine capture are vastly different to what cine camera displays try disabling this." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseShowOnlyList_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Alpha Settings" },
		{ "Comment", "/** Tick if you want to render selected primitives only */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Tick if you want to render selected primitives only" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HiddenComponents_MetaData[] = {
		{ "Comment", "/** The components won't rendered by current component.*/" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "The components won't rendered by current component." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HiddenActors_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Alpha Settings" },
		{ "Comment", "/** The actors to hide in the scene capture. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "The actors to hide in the scene capture." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShowOnlyComponents_MetaData[] = {
		{ "Comment", "/** The only components to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList. */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "The only components to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShowOnlyActors_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Alpha Settings" },
		{ "Comment", "/** The only actors to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList.*/" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "The only actors to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInvertAlpha_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Alpha Settings" },
		{ "Comment", "/** By default we invert the ue4's default alpha value of captured textures - you can disable it here */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "By default we invert the ue4's default alpha value of captured textures - you can disable it here" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OCIOConfiguration_MetaData[] = {
		{ "Category", "Color" },
		{ "Comment", "/**\n\x09* Open Color IO Configuration. Used to apply color transforms.\n\x09*/" },
		{ "DisplayName", "OpenColorIO Configuration" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Open Color IO Configuration. Used to apply color transforms." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnapshotSettings_MetaData[] = {
		{ "Category", "Off World Live Capture Settings" },
		{ "Comment", "/** Settings for taking snapshots */" },
		{ "DisplayName", "Snapshot" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Settings for taking snapshots" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSnapshotComplete_MetaData[] = {
		{ "Category", "Snapshot Settings" },
		{ "Comment", "/** Event that fires when a snapshot is taken successfully */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Event that fires when a snapshot is taken successfully" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InternalRTs_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReusedFaceRTs_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyeRT_MetaData[] = {
		{ "Comment", "/* Render targets for writing left and right render targets for stereo output */" },
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
		{ "ToolTip", "Render targets for writing left and right render targets for stereo output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightEyeRT_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaOnlyMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaOnlyMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaOnlyMaterialInverted_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaOnlyInvertedMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SnapshotTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWL360CaptureComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextureTarget;
	static void NewProp_bPauseRendering_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPauseRendering;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DomeAngle;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StereographicFOV;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ProjectionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ProjectionType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutputResolutionSettings;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StereoEyeSeparation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewportPreview;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CustomHorizontalFOV;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Custom180HorizontalFOV;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CustomVerticalFOV;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutputMask;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FaceBlendPercent;
	static void NewProp_bOverrideInternalFaceDimensions_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideInternalFaceDimensions;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OverrideFaceDimension;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PostProcessPipeline_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PostProcessPipeline;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PostProcessUpdateLocation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PostProcessUpdateLocation;
	static void NewProp_bDisableBloom_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableBloom;
	static void NewProp_bPathTracing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPathTracing;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VisualisationType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_VisualisationType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShowFlagSettings_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ShowFlagSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PostProcessSettings;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PostProcessBlendWeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NearClipPlane;
	static void NewProp_bShowDebugFaceColors_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugFaceColors;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CubeFaceRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraRotation;
	static void NewProp_bEnableUpscaling_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableUpscaling;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScreenPercentage;
	static void NewProp_bDisableViewState_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableViewState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FaceControl;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LODDistanceFactor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxViewDistanceOverride;
	static void NewProp_bForceCameraCut_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceCameraCut;
	static void NewProp_bFollowSceneCaptureRenderPath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFollowSceneCaptureRenderPath;
	static void NewProp_bUseShowOnlyList_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseShowOnlyList;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_HiddenComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HiddenComponents;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HiddenActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HiddenActors;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_ShowOnlyComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ShowOnlyComponents;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShowOnlyActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ShowOnlyActors;
	static void NewProp_bInvertAlpha_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInvertAlpha;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OCIOConfiguration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SnapshotSettings;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSnapshotComplete;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InternalRTs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InternalRTs;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReusedFaceRTs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReusedFaceRTs;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftEyeRT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightEyeRT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlphaOnlyMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlphaOnlyMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlphaOnlyMaterialInverted;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlphaOnlyInvertedMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SnapshotTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_CalculateAutoCrop, "CalculateAutoCrop" }, // 741919426
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_CaptureScene, "CaptureScene" }, // 2906348337
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_ClearHiddenComponents, "ClearHiddenComponents" }, // 437507651
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_ClearShowOnlyComponents, "ClearShowOnlyComponents" }, // 549753849
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_GetOutputResolution, "GetOutputResolution" }, // 577311839
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_GetTargetCamera, "GetTargetCamera" }, // 3968182304
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_HideActorComponents, "HideActorComponents" }, // 3966471445
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_HideComponent, "HideComponent" }, // 4016075635
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_Is180Projection, "Is180Projection" }, // 3332764100
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_IsFOVAdjustable, "IsFOVAdjustable" }, // 272590661
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_IsStereoProjection, "IsStereoProjection" }, // 1145074846
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_RayTracingEnabled, "RayTracingEnabled" }, // 2501682134
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyActorComponents, "RemoveShowOnlyActorComponents" }, // 2346686135
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_RemoveShowOnlyComponent, "RemoveShowOnlyComponent" }, // 810591008
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_ResetCrop, "ResetCrop" }, // 1002805022
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_SetOutputResolution, "SetOutputResolution" }, // 2701899724
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyActorComponents, "ShowOnlyActorComponents" }, // 547474411
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_ShowOnlyComponent, "ShowOnlyComponent" }, // 2048249770
		{ &Z_Construct_UFunction_UOWL360CaptureComponent_TakeSnapshot, "TakeSnapshot" }, // 399912420
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWL360CaptureComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_TextureTarget = { "TextureTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, TextureTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextureTarget_MetaData), NewProp_TextureTarget_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPauseRendering_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bPauseRendering = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPauseRendering = { "bPauseRendering", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPauseRendering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPauseRendering_MetaData), NewProp_bPauseRendering_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_DomeAngle = { "DomeAngle", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, DomeAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DomeAngle_MetaData), NewProp_DomeAngle_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_StereographicFOV = { "StereographicFOV", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, StereographicFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StereographicFOV_MetaData), NewProp_StereographicFOV_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ProjectionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ProjectionType = { "ProjectionType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ProjectionType), Z_Construct_UEnum_OWL360Camera_E360ProjectionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectionType_MetaData), NewProp_ProjectionType_MetaData) }; // 184384836
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OutputResolutionSettings = { "OutputResolutionSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, OutputResolutionSettings), Z_Construct_UScriptStruct_FOWL360ResolutionSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputResolutionSettings_MetaData), NewProp_OutputResolutionSettings_MetaData) }; // 165309397
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_StereoEyeSeparation = { "StereoEyeSeparation", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, StereoEyeSeparation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StereoEyeSeparation_MetaData), NewProp_StereoEyeSeparation_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ViewportPreview = { "ViewportPreview", nullptr, (EPropertyFlags)0x00120000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ViewportPreview), Z_Construct_UClass_UOWLViewportPreview_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewportPreview_MetaData), NewProp_ViewportPreview_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CustomHorizontalFOV = { "CustomHorizontalFOV", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, CustomHorizontalFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomHorizontalFOV_MetaData), NewProp_CustomHorizontalFOV_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_Custom180HorizontalFOV = { "Custom180HorizontalFOV", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, Custom180HorizontalFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Custom180HorizontalFOV_MetaData), NewProp_Custom180HorizontalFOV_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CustomVerticalFOV = { "CustomVerticalFOV", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, CustomVerticalFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomVerticalFOV_MetaData), NewProp_CustomVerticalFOV_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OutputMask = { "OutputMask", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, OutputMask), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputMask_MetaData), NewProp_OutputMask_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_FaceBlendPercent = { "FaceBlendPercent", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, FaceBlendPercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FaceBlendPercent_MetaData), NewProp_FaceBlendPercent_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bOverrideInternalFaceDimensions_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bOverrideInternalFaceDimensions = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bOverrideInternalFaceDimensions = { "bOverrideInternalFaceDimensions", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bOverrideInternalFaceDimensions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideInternalFaceDimensions_MetaData), NewProp_bOverrideInternalFaceDimensions_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OverrideFaceDimension = { "OverrideFaceDimension", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, OverrideFaceDimension), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverrideFaceDimension_MetaData), NewProp_OverrideFaceDimension_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessPipeline_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessPipeline = { "PostProcessPipeline", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, PostProcessPipeline), Z_Construct_UEnum_OWL360Camera_E360PostProcessPipeline, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessPipeline_MetaData), NewProp_PostProcessPipeline_MetaData) }; // 2728008759
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessUpdateLocation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessUpdateLocation = { "PostProcessUpdateLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, PostProcessUpdateLocation), Z_Construct_UEnum_OWL360Camera_EOWLPostProcessUpdateLocation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessUpdateLocation_MetaData), NewProp_PostProcessUpdateLocation_MetaData) }; // 785293617
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableBloom_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bDisableBloom = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableBloom = { "bDisableBloom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableBloom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableBloom_MetaData), NewProp_bDisableBloom_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPathTracing_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bPathTracing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPathTracing = { "bPathTracing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPathTracing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPathTracing_MetaData), NewProp_bPathTracing_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_VisualisationType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_VisualisationType = { "VisualisationType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, VisualisationType), Z_Construct_UEnum_OWLCamera_EOWLOutputBufferVisualisation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualisationType_MetaData), NewProp_VisualisationType_MetaData) }; // 1842689560
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowFlagSettings_Inner = { "ShowFlagSettings", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEngineShowFlagsSetting, METADATA_PARAMS(0, nullptr) }; // 3559122429
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowFlagSettings = { "ShowFlagSettings", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ShowFlagSettings), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShowFlagSettings_MetaData), NewProp_ShowFlagSettings_MetaData) }; // 3559122429
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessSettings = { "PostProcessSettings", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, PostProcessSettings), Z_Construct_UScriptStruct_FPostProcessSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessSettings_MetaData), NewProp_PostProcessSettings_MetaData) }; // 1858651484
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessBlendWeight = { "PostProcessBlendWeight", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, PostProcessBlendWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PostProcessBlendWeight_MetaData), NewProp_PostProcessBlendWeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_NearClipPlane = { "NearClipPlane", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, NearClipPlane), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NearClipPlane_MetaData), NewProp_NearClipPlane_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bShowDebugFaceColors_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bShowDebugFaceColors = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bShowDebugFaceColors = { "bShowDebugFaceColors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bShowDebugFaceColors_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugFaceColors_MetaData), NewProp_bShowDebugFaceColors_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CubeFaceRotation = { "CubeFaceRotation", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, CubeFaceRotation), Z_Construct_UScriptStruct_FOWLMultiRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CubeFaceRotation_MetaData), NewProp_CubeFaceRotation_MetaData) }; // 3367980913
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CameraRotation = { "CameraRotation", nullptr, (EPropertyFlags)0x0010000200000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, CameraRotation), Z_Construct_UScriptStruct_FOWLMultiRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraRotation_MetaData), NewProp_CameraRotation_MetaData) }; // 3367980913
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bEnableUpscaling_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bEnableUpscaling = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bEnableUpscaling = { "bEnableUpscaling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bEnableUpscaling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableUpscaling_MetaData), NewProp_bEnableUpscaling_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ScreenPercentage = { "ScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ScreenPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScreenPercentage_MetaData), NewProp_ScreenPercentage_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableViewState_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bDisableViewState = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableViewState = { "bDisableViewState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableViewState_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableViewState_MetaData), NewProp_bDisableViewState_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_FaceControl = { "FaceControl", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, FaceControl), Z_Construct_UScriptStruct_FOWLFaceControl, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FaceControl_MetaData), NewProp_FaceControl_MetaData) }; // 2114873683
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_LODDistanceFactor = { "LODDistanceFactor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, LODDistanceFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LODDistanceFactor_MetaData), NewProp_LODDistanceFactor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_MaxViewDistanceOverride = { "MaxViewDistanceOverride", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, MaxViewDistanceOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxViewDistanceOverride_MetaData), NewProp_MaxViewDistanceOverride_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bForceCameraCut_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bForceCameraCut = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bForceCameraCut = { "bForceCameraCut", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bForceCameraCut_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceCameraCut_MetaData), NewProp_bForceCameraCut_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bFollowSceneCaptureRenderPath_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bFollowSceneCaptureRenderPath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bFollowSceneCaptureRenderPath = { "bFollowSceneCaptureRenderPath", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bFollowSceneCaptureRenderPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFollowSceneCaptureRenderPath_MetaData), NewProp_bFollowSceneCaptureRenderPath_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bUseShowOnlyList_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bUseShowOnlyList = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bUseShowOnlyList = { "bUseShowOnlyList", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bUseShowOnlyList_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseShowOnlyList_MetaData), NewProp_bUseShowOnlyList_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenComponents_Inner = { "HiddenComponents", nullptr, (EPropertyFlags)0x0004000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenComponents = { "HiddenComponents", nullptr, (EPropertyFlags)0x0014008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, HiddenComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HiddenComponents_MetaData), NewProp_HiddenComponents_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenActors_Inner = { "HiddenActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenActors = { "HiddenActors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, HiddenActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HiddenActors_MetaData), NewProp_HiddenActors_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyComponents_Inner = { "ShowOnlyComponents", nullptr, (EPropertyFlags)0x0004000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyComponents = { "ShowOnlyComponents", nullptr, (EPropertyFlags)0x0014008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ShowOnlyComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShowOnlyComponents_MetaData), NewProp_ShowOnlyComponents_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyActors_Inner = { "ShowOnlyActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyActors = { "ShowOnlyActors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ShowOnlyActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShowOnlyActors_MetaData), NewProp_ShowOnlyActors_MetaData) };
void Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bInvertAlpha_SetBit(void* Obj)
{
	((UOWL360CaptureComponent*)Obj)->bInvertAlpha = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bInvertAlpha = { "bInvertAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWL360CaptureComponent), &Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bInvertAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInvertAlpha_MetaData), NewProp_bInvertAlpha_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OCIOConfiguration = { "OCIOConfiguration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, OCIOConfiguration), Z_Construct_UScriptStruct_FOpenColorIODisplayConfiguration, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OCIOConfiguration_MetaData), NewProp_OCIOConfiguration_MetaData) }; // 2804996687
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_SnapshotSettings = { "SnapshotSettings", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, SnapshotSettings), Z_Construct_UScriptStruct_FOWLSnapshotSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnapshotSettings_MetaData), NewProp_SnapshotSettings_MetaData) }; // 1520511220
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OnSnapshotComplete = { "OnSnapshotComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, OnSnapshotComplete), Z_Construct_UDelegateFunction_OWLCamera_OnSnapshotCompletionDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSnapshotComplete_MetaData), NewProp_OnSnapshotComplete_MetaData) }; // 1578038527
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_InternalRTs_Inner = { "InternalRTs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_InternalRTs = { "InternalRTs", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, InternalRTs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InternalRTs_MetaData), NewProp_InternalRTs_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ReusedFaceRTs_Inner = { "ReusedFaceRTs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ReusedFaceRTs = { "ReusedFaceRTs", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, ReusedFaceRTs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReusedFaceRTs_MetaData), NewProp_ReusedFaceRTs_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CameraMesh = { "CameraMesh", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, CameraMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraMesh_MetaData), NewProp_CameraMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_LeftEyeRT = { "LeftEyeRT", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, LeftEyeRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftEyeRT_MetaData), NewProp_LeftEyeRT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_RightEyeRT = { "RightEyeRT", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, RightEyeRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightEyeRT_MetaData), NewProp_RightEyeRT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyMaterial = { "AlphaOnlyMaterial", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, AlphaOnlyMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaOnlyMaterial_MetaData), NewProp_AlphaOnlyMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyMID = { "AlphaOnlyMID", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, AlphaOnlyMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaOnlyMID_MetaData), NewProp_AlphaOnlyMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyMaterialInverted = { "AlphaOnlyMaterialInverted", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, AlphaOnlyMaterialInverted), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaOnlyMaterialInverted_MetaData), NewProp_AlphaOnlyMaterialInverted_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyInvertedMID = { "AlphaOnlyInvertedMID", nullptr, (EPropertyFlags)0x0124080000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, AlphaOnlyInvertedMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaOnlyInvertedMID_MetaData), NewProp_AlphaOnlyInvertedMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_SnapshotTarget = { "SnapshotTarget", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWL360CaptureComponent, SnapshotTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SnapshotTarget_MetaData), NewProp_SnapshotTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWL360CaptureComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_TextureTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPauseRendering,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_DomeAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_StereographicFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ProjectionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ProjectionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OutputResolutionSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_StereoEyeSeparation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ViewportPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CustomHorizontalFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_Custom180HorizontalFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CustomVerticalFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OutputMask,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_FaceBlendPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bOverrideInternalFaceDimensions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OverrideFaceDimension,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessPipeline_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessPipeline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessUpdateLocation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessUpdateLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableBloom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bPathTracing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_VisualisationType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_VisualisationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowFlagSettings_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowFlagSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_PostProcessBlendWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_NearClipPlane,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bShowDebugFaceColors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CubeFaceRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CameraRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bEnableUpscaling,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ScreenPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bDisableViewState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_FaceControl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_LODDistanceFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_MaxViewDistanceOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bForceCameraCut,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bFollowSceneCaptureRenderPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bUseShowOnlyList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenComponents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_HiddenActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyComponents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ShowOnlyActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_bInvertAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OCIOConfiguration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_SnapshotSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_OnSnapshotComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_InternalRTs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_InternalRTs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ReusedFaceRTs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_ReusedFaceRTs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_CameraMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_LeftEyeRT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_RightEyeRT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyMaterialInverted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_AlphaOnlyInvertedMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWL360CaptureComponent_Statics::NewProp_SnapshotTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CaptureComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWL360CaptureComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CaptureComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWL360CaptureComponent_Statics::ClassParams = {
	&UOWL360CaptureComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOWL360CaptureComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CaptureComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360CaptureComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWL360CaptureComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWL360CaptureComponent()
{
	if (!Z_Registration_Info_UClass_UOWL360CaptureComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWL360CaptureComponent.OuterSingleton, Z_Construct_UClass_UOWL360CaptureComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWL360CaptureComponent.OuterSingleton;
}
template<> OWL360CAMERA_API UClass* StaticClass<UOWL360CaptureComponent>()
{
	return UOWL360CaptureComponent::StaticClass();
}
// End Class UOWL360CaptureComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOWLPostProcessUpdateLocation_StaticEnum, TEXT("EOWLPostProcessUpdateLocation"), &Z_Registration_Info_UEnum_EOWLPostProcessUpdateLocation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 785293617U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOWLFaceControl::StaticStruct, Z_Construct_UScriptStruct_FOWLFaceControl_Statics::NewStructOps, TEXT("OWLFaceControl"), &Z_Registration_Info_UScriptStruct_OWLFaceControl, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOWLFaceControl), 2114873683U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWL360CaptureComponent, UOWL360CaptureComponent::StaticClass, TEXT("UOWL360CaptureComponent"), &Z_Registration_Info_UClass_UOWL360CaptureComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWL360CaptureComponent), 3024873966U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_1896838097(TEXT("/Script/OWL360Camera"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CaptureComponent_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
