// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OWLCamera/Public/OWLStereoConvergencePlane.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOWLStereoConvergencePlane() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
OWLCAMERA_API UClass* Z_Construct_UClass_AOWLStereoConvergencePlane();
OWLCAMERA_API UClass* Z_Construct_UClass_AOWLStereoConvergencePlane_NoRegister();
OWLCAMERA_API UClass* Z_Construct_UClass_UOWLCaptureComponent_NoRegister();
OWLCAMERA_API UFunction* Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_OWLCamera();
// End Cross Module References

// Begin Delegate FOnConvergencePlaneManipulated
struct Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics
{
	struct _Script_OWLCamera_eventOnConvergencePlaneManipulated_Parms
	{
		float NewDistance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "/**\n * Delegate for when the convergence plane is manipulated by the user\n * The capture component will listen to this to update its internal state\n */" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Delegate for when the convergence plane is manipulated by the user\nThe capture component will listen to this to update its internal state" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::NewProp_NewDistance = { "NewDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OWLCamera_eventOnConvergencePlaneManipulated_Parms, NewDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::NewProp_NewDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OWLCamera, nullptr, "OnConvergencePlaneManipulated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::_Script_OWLCamera_eventOnConvergencePlaneManipulated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::_Script_OWLCamera_eventOnConvergencePlaneManipulated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnConvergencePlaneManipulated_DelegateWrapper(const FMulticastScriptDelegate& OnConvergencePlaneManipulated, float NewDistance)
{
	struct _Script_OWLCamera_eventOnConvergencePlaneManipulated_Parms
	{
		float NewDistance;
	};
	_Script_OWLCamera_eventOnConvergencePlaneManipulated_Parms Parms;
	Parms.NewDistance=NewDistance;
	OnConvergencePlaneManipulated.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnConvergencePlaneManipulated

// Begin Class AOWLStereoConvergencePlane
void AOWLStereoConvergencePlane::StaticRegisterNativesAOWLStereoConvergencePlane()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOWLStereoConvergencePlane);
UClass* Z_Construct_UClass_AOWLStereoConvergencePlane_NoRegister()
{
	return AOWLStereoConvergencePlane::StaticClass();
}
struct Z_Construct_UClass_AOWLStereoConvergencePlane_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OWLStereoConvergencePlane.h" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnConvergencePlaneManipulated_MetaData[] = {
		{ "Category", "Convergence Plane" },
		{ "Comment", "// Called when the plane is manipulated in the editor or viewport\n" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Called when the plane is manipulated in the editor or viewport" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwningCapture_MetaData[] = {
		{ "Comment", "// Weak reference to the owning capture component\n// We don't control the lifetime of this component\n" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Weak reference to the owning capture component\nWe don't control the lifetime of this component" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneMaterial_MetaData[] = {
		{ "Comment", "// Material instance that controls the plane's appearance\n" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Material instance that controls the plane's appearance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "Comment", "// Static mesh component for the plane\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Static mesh component for the plane" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneColor_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "// Current color of the plane\n" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Current color of the plane" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EdgeIntensity_MetaData[] = {
		{ "Category", "Appearance" },
		{ "Comment", "// Current edge intensity\n" },
		{ "ModuleRelativePath", "Public/OWLStereoConvergencePlane.h" },
		{ "ToolTip", "Current edge intensity" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConvergencePlaneManipulated;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_OwningCapture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneMesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EdgeIntensity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOWLStereoConvergencePlane>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_OnConvergencePlaneManipulated = { "OnConvergencePlaneManipulated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLStereoConvergencePlane, OnConvergencePlaneManipulated), Z_Construct_UDelegateFunction_OWLCamera_OnConvergencePlaneManipulated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnConvergencePlaneManipulated_MetaData), NewProp_OnConvergencePlaneManipulated_MetaData) }; // 302287490
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_OwningCapture = { "OwningCapture", nullptr, (EPropertyFlags)0x0014000000082008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLStereoConvergencePlane, OwningCapture), Z_Construct_UClass_UOWLCaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwningCapture_MetaData), NewProp_OwningCapture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_PlaneMaterial = { "PlaneMaterial", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLStereoConvergencePlane, PlaneMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneMaterial_MetaData), NewProp_PlaneMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_PlaneMesh = { "PlaneMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLStereoConvergencePlane, PlaneMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneMesh_MetaData), NewProp_PlaneMesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_PlaneColor = { "PlaneColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLStereoConvergencePlane, PlaneColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneColor_MetaData), NewProp_PlaneColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_EdgeIntensity = { "EdgeIntensity", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOWLStereoConvergencePlane, EdgeIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EdgeIntensity_MetaData), NewProp_EdgeIntensity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_OnConvergencePlaneManipulated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_OwningCapture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_PlaneMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_PlaneMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_PlaneColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::NewProp_EdgeIntensity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OWLCamera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::ClassParams = {
	&AOWLStereoConvergencePlane::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::Class_MetaDataParams), Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOWLStereoConvergencePlane()
{
	if (!Z_Registration_Info_UClass_AOWLStereoConvergencePlane.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOWLStereoConvergencePlane.OuterSingleton, Z_Construct_UClass_AOWLStereoConvergencePlane_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOWLStereoConvergencePlane.OuterSingleton;
}
template<> OWLCAMERA_API UClass* StaticClass<AOWLStereoConvergencePlane>()
{
	return AOWLStereoConvergencePlane::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOWLStereoConvergencePlane);
AOWLStereoConvergencePlane::~AOWLStereoConvergencePlane() {}
// End Class AOWLStereoConvergencePlane

// Begin Registration
struct Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLStereoConvergencePlane_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOWLStereoConvergencePlane, AOWLStereoConvergencePlane::StaticClass, TEXT("AOWLStereoConvergencePlane"), &Z_Registration_Info_UClass_AOWLStereoConvergencePlane, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOWLStereoConvergencePlane), 1683243265U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLStereoConvergencePlane_h_1879112373(TEXT("/Script/OWLCamera"),
	Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLStereoConvergencePlane_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_OWLCamera_Public_OWLStereoConvergencePlane_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
