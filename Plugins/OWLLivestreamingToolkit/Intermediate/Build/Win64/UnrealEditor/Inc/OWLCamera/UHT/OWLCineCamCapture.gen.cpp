// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLCamera/Public/OWLCineCamCapture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLCineCamCapture() {}

// Begin Cross Module References
CINEMATICCAMERA_API UClass* Z_Construct_UClass_ACineCameraActor();
OWLCAMERA_API UClass* Z_Construct_UClass_AOWLCineCameraActor();
OWLCAMERA_API UClass* Z_Construct_UClass_AOWLCineCameraActor_NoRegister();
OWLCAMERA_API UClass* Z_Construct_UClass_UOWLCaptureComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OWLCamera();
// End Cross Module References

// Begin Class AOWLCineCameraActor
void AOWLCineCameraActor::StaticRegisterNativesAOWLCineCameraActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOWLCineCameraActor);
UClass* Z_Construct_UClass_AOWLCineCameraActor_NoRegister()
{
	return AOWLCineCameraActor::StaticClass();
}
struct Z_Construct_UClass_AOWLCineCameraActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "OWL Cine Camera" },
		{ "HideCategories", "Collision Attachment Actor Input Rendering AutoPlayerActivation Input Rendering" },
		{ "IncludePath", "OWLCineCamCapture.h" },
		{ "ModuleRelativePath", "Public/OWLCineCamCapture.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "OffWorldLive" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OWLCineCamCapture.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOWLCineCameraActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOWLCineCameraActor_Statics::NewProp_CaptureComponent = { "CaptureComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLCineCameraActor, CaptureComponent), Z_Construct_UClass_UOWLCaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureComponent_MetaData), NewProp_CaptureComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOWLCineCameraActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLCineCameraActor_Statics::NewProp_CaptureComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLCineCameraActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOWLCineCameraActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACineCameraActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLCamera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLCineCameraActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOWLCineCameraActor_Statics::ClassParams = {
	&AOWLCineCameraActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AOWLCineCameraActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AOWLCineCameraActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLCineCameraActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AOWLCineCameraActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOWLCineCameraActor()
{
	if (!Z_Registration_Info_UClass_AOWLCineCameraActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOWLCineCameraActor.OuterSingleton, Z_Construct_UClass_AOWLCineCameraActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOWLCineCameraActor.OuterSingleton;
}
template<> OWLCAMERA_API UClass* StaticClass<AOWLCineCameraActor>()
{
	return AOWLCineCameraActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOWLCineCameraActor);
AOWLCineCameraActor::~AOWLCineCameraActor() {}
// End Class AOWLCineCameraActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLCineCamCapture_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOWLCineCameraActor, AOWLCineCameraActor::StaticClass, TEXT("AOWLCineCameraActor"), &Z_Registration_Info_UClass_AOWLCineCameraActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOWLCineCameraActor), 3989057358U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLCineCamCapture_h_2457225579(TEXT("/Script/OWLCamera"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLCineCamCapture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLCineCamCapture_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
