// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLCamera/Public/OWLViewportPreview.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLViewportPreview() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FPostProcessSettings();
OWLCAMERA_API UClass* Z_Construct_UClass_UOWLViewportPreview();
OWLCAMERA_API UClass* Z_Construct_UClass_UOWLViewportPreview_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLCamera();
// End Cross Module References

// Begin Class UOWLViewportPreview
void UOWLViewportPreview::StaticRegisterNativesUOWLViewportPreview()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWLViewportPreview);
UClass* Z_Construct_UClass_UOWLViewportPreview_NoRegister()
{
	return UOWLViewportPreview::StaticClass();
}
struct Z_Construct_UClass_UOWLViewportPreview_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OWLViewportPreview.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewOutputInViewport_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Preview" },
		{ "Comment", "/* Set the viewport camera preview window to show the contents of the render target onto which the camera has rendered */" },
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
		{ "ToolTip", "Set the viewport camera preview window to show the contents of the render target onto which the camera has rendered" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHidePreviewWhenPaused_MetaData[] = {
		{ "Category", "Off World Live Capture Settings|Preview" },
		{ "Comment", "/* When rendering is paused, hide render target from the preview, showing the viewport camera output */" },
		{ "EditCondition", "bPreviewOutputInViewport" },
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
		{ "ToolTip", "When rendering is paused, hide render target from the preview, showing the viewport camera output" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMaterialPreview_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransparentSquare_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewPPSettings_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Texture_MetaData[] = {
		{ "ModuleRelativePath", "Public/OWLViewportPreview.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bPreviewOutputInViewport_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewOutputInViewport;
	static void NewProp_bHidePreviewWhenPaused_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHidePreviewWhenPaused;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMaterialPreview;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TransparentSquare;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviewPPSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWLViewportPreview>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bPreviewOutputInViewport_SetBit(void* Obj)
{
	((UOWLViewportPreview*)Obj)->bPreviewOutputInViewport = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bPreviewOutputInViewport = { "bPreviewOutputInViewport", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLViewportPreview), &Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bPreviewOutputInViewport_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreviewOutputInViewport_MetaData), NewProp_bPreviewOutputInViewport_MetaData) };
void Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bHidePreviewWhenPaused_SetBit(void* Obj)
{
	((UOWLViewportPreview*)Obj)->bHidePreviewWhenPaused = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bHidePreviewWhenPaused = { "bHidePreviewWhenPaused", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOWLViewportPreview), &Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bHidePreviewWhenPaused_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHidePreviewWhenPaused_MetaData), NewProp_bHidePreviewWhenPaused_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_PreviewMaterial = { "PreviewMaterial", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLViewportPreview, PreviewMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterial_MetaData), NewProp_PreviewMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_DynamicMaterialPreview = { "DynamicMaterialPreview", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLViewportPreview, DynamicMaterialPreview), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicMaterialPreview_MetaData), NewProp_DynamicMaterialPreview_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_TransparentSquare = { "TransparentSquare", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLViewportPreview, TransparentSquare), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransparentSquare_MetaData), NewProp_TransparentSquare_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_PreviewPPSettings = { "PreviewPPSettings", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLViewportPreview, PreviewPPSettings), Z_Construct_UScriptStruct_FPostProcessSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewPPSettings_MetaData), NewProp_PreviewPPSettings_MetaData) }; // 1858651484
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLViewportPreview, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraComponent_MetaData), NewProp_CameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOWLViewportPreview, Texture), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Texture_MetaData), NewProp_Texture_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOWLViewportPreview_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bPreviewOutputInViewport,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_bHidePreviewWhenPaused,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_PreviewMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_DynamicMaterialPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_TransparentSquare,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_PreviewPPSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_CameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOWLViewportPreview_Statics::NewProp_Texture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLViewportPreview_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOWLViewportPreview_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLCamera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLViewportPreview_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWLViewportPreview_Statics::ClassParams = {
	&UOWLViewportPreview::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOWLViewportPreview_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOWLViewportPreview_Statics::PropPointers),
	0,
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWLViewportPreview_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWLViewportPreview_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWLViewportPreview()
{
	if (!Z_Registration_Info_UClass_UOWLViewportPreview.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWLViewportPreview.OuterSingleton, Z_Construct_UClass_UOWLViewportPreview_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWLViewportPreview.OuterSingleton;
}
template<> OWLCAMERA_API UClass* StaticClass<UOWLViewportPreview>()
{
	return UOWLViewportPreview::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWLViewportPreview);
UOWLViewportPreview::~UOWLViewportPreview() {}
// End Class UOWLViewportPreview

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLViewportPreview_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWLViewportPreview, UOWLViewportPreview::StaticClass, TEXT("UOWLViewportPreview"), &Z_Registration_Info_UClass_UOWLViewportPreview, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWLViewportPreview), 987590134U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLViewportPreview_h_661271418(TEXT("/Script/OWLCamera"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLViewportPreview_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLViewportPreview_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
