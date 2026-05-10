// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWL360Camera/Public/OWL360CamCapture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWL360CamCapture() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACameraActor();
OWL360CAMERA_API UClass* Z_Construct_UClass_AOWL360CameraActor();
OWL360CAMERA_API UClass* Z_Construct_UClass_AOWL360CameraActor_NoRegister();
OWL360CAMERA_API UClass* Z_Construct_UClass_UOWL360CaptureComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWL360Camera();
// End Cross Module References

// Begin Class AOWL360CameraActor
void AOWL360CameraActor::StaticRegisterNativesAOWL360CameraActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOWL360CameraActor);
UClass* Z_Construct_UClass_AOWL360CameraActor_NoRegister()
{
	return AOWL360CameraActor::StaticClass();
}
struct Z_Construct_UClass_AOWL360CameraActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "OWL 360 Camera" },
		{ "HideCategories", "Collision Attachment Actor CameraActor Input Rendering" },
		{ "IncludePath", "OWL360CamCapture.h" },
		{ "ModuleRelativePath", "Public/OWL360CamCapture.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Off World Live 360 Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OWL360CamCapture.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOWL360CameraActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOWL360CameraActor_Statics::NewProp_CaptureComponent = { "CaptureComponent", nullptr, (EPropertyFlags)0x00100002000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWL360CameraActor, CaptureComponent), Z_Construct_UClass_UOWL360CaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureComponent_MetaData), NewProp_CaptureComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOWL360CameraActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWL360CameraActor_Statics::NewProp_CaptureComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWL360CameraActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOWL360CameraActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACameraActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OWL360Camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWL360CameraActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOWL360CameraActor_Statics::ClassParams = {
	&AOWL360CameraActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AOWL360CameraActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AOWL360CameraActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOWL360CameraActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AOWL360CameraActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOWL360CameraActor()
{
	if (!Z_Registration_Info_UClass_AOWL360CameraActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOWL360CameraActor.OuterSingleton, Z_Construct_UClass_AOWL360CameraActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOWL360CameraActor.OuterSingleton;
}
template<> OWL360CAMERA_API UClass* StaticClass<AOWL360CameraActor>()
{
	return AOWL360CameraActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOWL360CameraActor);
AOWL360CameraActor::~AOWL360CameraActor() {}
// End Class AOWL360CameraActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CamCapture_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOWL360CameraActor, AOWL360CameraActor::StaticClass, TEXT("AOWL360CameraActor"), &Z_Registration_Info_UClass_AOWL360CameraActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOWL360CameraActor), 745601012U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CamCapture_h_3653212824(TEXT("/Script/OWL360Camera"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CamCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWL360Camera_Public_OWL360CamCapture_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
