// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Private/OWL360PreviewCamComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360PreviewCamComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360PreviewCamComponent();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360PreviewCamComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin Class UOWL360PreviewCamComponent
void UOWL360PreviewCamComponent::StaticRegisterNativesUOWL360PreviewCamComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOWL360PreviewCamComponent);
UClass* Z_Construct_UClass_UOWL360PreviewCamComponent_NoRegister()
{
	return UOWL360PreviewCamComponent::StaticClass();
}
struct Z_Construct_UClass_UOWL360PreviewCamComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Camera" },
		{ "HideCategories", "CameraSettings Mobility Rendering LOD Trigger PhysicsVolume" },
		{ "HideFunctions", "SetFieldOfView SetAspectRatio" },
		{ "IncludePath", "OWL360PreviewCamComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/OWL360PreviewCamComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOWL360PreviewCamComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOWL360PreviewCamComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCameraComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360PreviewCamComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOWL360PreviewCamComponent_Statics::ClassParams = {
	&UOWL360PreviewCamComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00A800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOWL360PreviewCamComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOWL360PreviewCamComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOWL360PreviewCamComponent()
{
	if (!Z_Registration_Info_UClass_UOWL360PreviewCamComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOWL360PreviewCamComponent.OuterSingleton, Z_Construct_UClass_UOWL360PreviewCamComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOWL360PreviewCamComponent.OuterSingleton;
}
template<> OWL360CAMERA_API UClass* StaticClass<UOWL360PreviewCamComponent>()
{
	return UOWL360PreviewCamComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOWL360PreviewCamComponent);
UOWL360PreviewCamComponent::~UOWL360PreviewCamComponent() {}
// End Class UOWL360PreviewCamComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Private_OWL360PreviewCamComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOWL360PreviewCamComponent, UOWL360PreviewCamComponent::StaticClass, TEXT("UOWL360PreviewCamComponent"), &Z_Registration_Info_UClass_UOWL360PreviewCamComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOWL360PreviewCamComponent), 1976176890U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Private_OWL360PreviewCamComponent_h_2834373289(TEXT("/Script/OWL360Camera"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Private_OWL360PreviewCamComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Private_OWL360PreviewCamComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
