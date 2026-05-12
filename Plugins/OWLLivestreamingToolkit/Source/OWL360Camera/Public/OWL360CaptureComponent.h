// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/SceneComponent.h"
#include "ShowFlags.h"
#include "GameTime.h"
#include "OWL360ResolutionSettings.h"
#include "OWLCaptureComponent.h"
#include "RenderUtils.h"
#include "Materials/Material.h"
#include "Components/SceneCaptureComponent.h"
#include "PostProcessing/PostProcessHelpers.h"
#include "OpenColorIOColorSpace.h"
#include "OWL360FaceRendering.h"
#include "DataTypes/OWLFaceBool.h"
#include "DataTypes/OWLFaceIndex.h"
#include "OWLSnapshotSettings.h"
#include "DataTypes/OWLMultiRotator.h"
#include "DataTypes/OWL360Projections.h"
#include "DataTypes/OWLFaceCrop.h"
#include "Containers/Ticker.h"
#include "OWL360CaptureComponent.generated.h"

class UOWLViewportPreview;
class FSceneViewStateInterface;
class UCameraComponent;
class IBlendableInterface;
class FOpenColorIODisplayExtension;
class FOffWorldPostProcess;
class UMaterial;
struct FMinimalViewInfo;

class OWL360CAMERA_API FOWLCanRender
{
public:
	void SetDisable360Tick();
	void SetEnable360Tick();
	bool Can360Tick();
private:
	TAtomic<bool> Enabled = true;
};

USTRUCT(BlueprintType)
struct FOWLFaceControl
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Face Control")
	bool bShowDebugFaceColors = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Face Control")
	FOWLCroppedFaces Cropping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Face Control")
	FOWL360FaceRenderingSettings Faces;
};

UENUM(Blueprintable)
enum class EOWLPostProcessUpdateLocation : uint8
{
	L_UpdateOn360 UMETA(DisplayName = "360 Component", Tooltip = "The post-process settings on the 360 capture component are the single source of truth. The Camera Component post process struct is updated from it."),
	L_UpdateOnCamera UMETA(DisplayName = "Camera Component", Tooltip = "The post-process settings on the camera component are the single source of truth. The 360 Capture Component post process struct is updated from the Camera post process."),
};

extern OWL360CAMERA_API FOWLCanRender* GOWL360CanRender;

/*

The Cubemap cameras are six:
in the order specified here:
https://github.com/google/spatial-media/blob/master/docs/spherical-video-v2-rfc.md#cubemap-projection-box-cbmp
These are written left-to-right, top-to-bottom
ie:
[ 0, 1, 2 ]
[ 3, 4, 5 ]

Where:
0: Right
1: Left
2: Up
3: Down
4: Front
5: Back
*/

UCLASS(Blueprintable, hidecategories = (Collision, Object, Physics, SceneComponent, Mobility, Tags, Activation, Cooking, Rendering), ClassGroup = Rendering, meta = (BlueprintSpawnableComponent))
class OWL360CAMERA_API UOWL360CaptureComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UOWL360CaptureComponent(const FObjectInitializer& ObjectInitializer);
	// defined to enable TUniquePtr with forward decs
	UOWL360CaptureComponent(FVTableHelper& Helper);
	~UOWL360CaptureComponent();
	virtual void PostLoad() override;

	/**
	* Render target to render the 360 projection onto
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", DisplayName="Render Target", meta=(DisplayPriority="1"))
	UTextureRenderTarget2D* TextureTarget = nullptr;

	/** Tick if you want to pause rendering to the render target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta=(DisplayPriority="2"))
	bool bPauseRendering = false;

	/* Field of view of the dome */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta=(EditCondition = "ProjectionType == E360ProjectionType::CT_DomeMaster", EditConditionHides, UIMin=10, UIMax=360))
	int DomeAngle = 180;

	/* Field of view of the stereographic projection */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta=(EditCondition = "ProjectionType == E360ProjectionType::CT_Stereographic", EditConditionHides, UIMin=1, UIMax=359))
	int StereographicFOV = 120;

	/* Output texture format */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", DisplayName = "Projection Type", meta=(DisplayPriority="3"))
	E360ProjectionType ProjectionType = E360ProjectionType::CT_EquiRectangular;

	/* Texture resolution for camera render output */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta=(DisplayPriority="5"))
	FOWL360ResolutionSettings OutputResolutionSettings;

	/* Set the gap between left eye and right eye in world units */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings", Experimental, meta = (UIMin = "0.1", EditCondition="IsStereoProjection()", EditConditionHides,DisplayPriority="4"))
	float StereoEyeSeparation = 6.5;

	/* Set camera preview in editor as the output render target while rendering */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category = "Camera", meta=(ShowOnlyInnerProperties))
	UOWLViewportPreview* ViewportPreview = nullptr;

	/* Horizontal FOV of the Projection - only available with a Pro Movie Render Queue license */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced", meta=(ClampMin = "0", ClampMax="360", UIMin="0", UIMax="360", EditCondition="IsFOVAdjustable() && !Is180Projection()", EditConditionHides))
	int CustomHorizontalFOV = 360;

	/* Horizontal FOV of the Projection - only available with a Pro Movie Render Queue license */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced", DisplayName="Custom Horizontal FOV", meta=(ClampMin = "0", ClampMax="180", UIMin="0", UIMax="180", EditCondition="IsFOVAdjustable() && Is180Projection()", EditConditionHides))
	int Custom180HorizontalFOV = 180;

	/* Vertical FOV of the Projection - only available with a Pro Movie Render Queue license */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced", meta=(ClampMin = "0", ClampMax="180", UIMin="0", UIMax="180", EditCondition="IsFOVAdjustable()", EditConditionHides))
	int CustomVerticalFOV = 180;

	/* A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. - only available with a Pro Movie Render Queue license */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced", meta=(EditCondition = "ProjectionType != E360ProjectionType::CT_CubeMap", EditConditionHides))
	UTexture2D* OutputMask = nullptr;

	/* Overlaps each constituent face, blending adjacent faces together. This is expensive as it requires a wider FOV for each cube face captured */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta = (EditCondition = "ProjectionType != E360ProjectionType::CT_CubeMap", EditConditionHides, ClampMin = "0.0", ClampMax = "50.0", UIMin = "0.0", UIMax = "50.0"))
	float FaceBlendPercent = 0;

	/* Use a custom width/height (must be square) for the cube face renders that comprise the final output */
	UPROPERTY(EditAnywhere, Category = "Off World Live Capture Settings", meta = (EditCondition = "ProjectionType != E360ProjectionType::CT_CubeMap", EditConditionHides))
	bool bOverrideInternalFaceDimensions = false;

	/* Custom width and height (must be square) for the cube face renders that comprise the final output */
	UPROPERTY(EditAnywhere, Category = "Off World Live Capture Settings", meta = (EditCondition="bOverrideInternalFaceDimensions"))
	int OverrideFaceDimension = 480;

	/* Type of Post Process applied to the output texture */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	E360PostProcessPipeline PostProcessPipeline = E360PostProcessPipeline::PPM_Tonemapper;

	/* Select the point of truth for post-process settings */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	EOWLPostProcessUpdateLocation PostProcessUpdateLocation = EOWLPostProcessUpdateLocation::L_UpdateOn360;

	/* Enable this to disable bloom across all post-process (including post process volumes)
	 This is useful for isolating the cause of seams which cannot be mitigated by increasing the face blend percentage */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	bool bDisableBloom = false;

	/** Enable path tracing - if this is disabled, you need to change your project settings to 'Enable RayTracing' */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta = (EditCondition="RayTracingEnabled()"))
	bool bPathTracing = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Off World Live Capture Settings")
	EOWLOutputBufferVisualisation VisualisationType = EOWLOutputBufferVisualisation::BV_None;

	UPROPERTY(EditAnywhere, interp, Category = "Rendering Flags")
	TArray<struct FEngineShowFlagsSetting> ShowFlagSettings;

	UPROPERTY(interp, Category = "Post Process Settings", meta=(ShowOnlyInnerProperties, EditCondition="PostProcessUpdateLocation == EOWLPostProcessUpdateLocation::L_UpdateOn360"))
	struct FPostProcessSettings PostProcessSettings;

	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Post Process Settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0", EditCondition="PostProcessUpdateLocation == EOWLPostProcessUpdateLocation::L_UpdateOn360"))
	float PostProcessBlendWeight = 1.0f;

	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings|Camera" , meta=( DisplayPriority=14))
	float NearClipPlane = GNearClippingPlane;

	/* Enable this to preview the cubeface positions on your output render */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced" , meta=( EditCondition = "ProjectionType != E360ProjectionType::CT_CubeMap", EditConditionHides, DisplayPriority=11))
	bool bShowDebugFaceColors = false;

	/* Rotate the position of the internal faces used to stitch the 360 output together - modifying these values without a Pro Movie Render Queue license will trigger a watermark */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced", meta=( EditCondition = "(ProjectionType == E360ProjectionType::CT_Equirectangular || ProjectionType == E360ProjectionType::CT_StereoEquiRectangular || ProjectionType == E360ProjectionType::CT_StereoVR180 || ProjectionType == E360ProjectionType::CT_Mono180 || ProjectionType == E360ProjectionType::CT_Stereographic)", EditConditionHides, DisplayPriority=10, ShowOnlyInnerProperties))
	FOWLMultiRotator CubeFaceRotation;

	/* Control the orientation of the 360 camera without affecting the transform of the actor - modifying these values without a Pro Movie Render Queue license will trigger a watermark */
	UPROPERTY(EditAnywhere, Interp, BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced", meta=( DisplayPriority=12, ShowOnlyInnerProperties))
	FOWLMultiRotator CameraRotation;

	/** Tick to enable plugins like DLSS -- warning certain anti-aliasing settings may cause crashes when screen percentage on this actor is adjusted. WARNING: this feature is experimental and
		may cause crashes especially in conjuction with the Seamless Bloom!! */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", Experimental, DisplayName="Enable Upscaling (Experimental)")
	bool bEnableUpscaling = false;

	/** ScreenPercentage affects impact of upscaling (ie DLSS, TAA ...) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", Experimental, meta = (UIMin = "25", UIMax = "200", ClampMin="25", ClampMax="200", EditCondition="bEnableUpscaling"))
	float ScreenPercentage = 100;

	/** Disable the view state to get an FPS increase at the cost of temporal effects */
	UPROPERTY(BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced")
	bool bDisableViewState = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	FOWLFaceControl FaceControl;

	UFUNCTION(BlueprintCallable, Category = "Off World Live Capture Settings")
	void CalculateAutoCrop();

	UFUNCTION(BlueprintCallable, Category = "Off World Live Capture Settings")
	void ResetCrop();

	/** Scales the distance used by LOD. Set to values greater than 1 to cause the scene capture to use lower LODs than the main view to speed up the scene capture pass. */
	UPROPERTY(EditAnywhere, Category = "Off World Live Capture Settings|Advanced", meta = (UIMin = ".1", UIMax = "10"))
	float LODDistanceFactor = 1.0f;

	/** if > 0, sets a maximum render distance override.  Can be used to cull distant objects from a reflection if the reflecting plane is in an enclosed area like a hallway or room */
	UPROPERTY(EditAnywhere, Category = "Off World Live Capture Settings|Advanced", meta = (UIMin = "100", UIMax = "10000"))
	float MaxViewDistanceOverride = -1;

	/** Forces the `bCameraCut` flag which disables inter-frame caching for certain Unreal post-processing, like TSR motion blur. Disable if you notice performance degradation or lack of inter-frame effects */
	UPROPERTY(BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced")
	bool bForceCameraCut = false;

	/**
	* Affects rendering path cine capture takes. Scene Capture takes a slightly different rendering route compared to viewport rendering
	* for the purposes of optimization. If the results of cine capture are vastly different to what cine camera displays try disabling this.
	*/
	UPROPERTY(BlueprintReadWrite, Category = "Off World Live Capture Settings|Advanced")
	bool bFollowSceneCaptureRenderPath;

	/** Tick if you want to render selected primitives only */
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Off World Live Capture Settings|Alpha Settings")
	bool bUseShowOnlyList = false;

	/** The components won't rendered by current component.*/
	UPROPERTY()
	TArray<TWeakObjectPtr<UPrimitiveComponent> > HiddenComponents;

	/** The actors to hide in the scene capture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Alpha Settings")
	TArray<AActor*> HiddenActors;

	/** The only components to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList. */
	UPROPERTY()
	TArray<TWeakObjectPtr<UPrimitiveComponent> > ShowOnlyComponents;

	/** The only actors to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Alpha Settings")
	TArray<AActor*> ShowOnlyActors;

	/** By default we invert the ue4's default alpha value of captured textures - you can disable it here */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Alpha Settings")
	bool bInvertAlpha = true;


	/**
	* Open Color IO Configuration. Used to apply color transforms.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color", meta = (DisplayName = "OpenColorIO Configuration"))
	FOpenColorIODisplayConfiguration OCIOConfiguration;

public:
	/** Render the scene to the texture target immediately. This should not be used if bCaptureEveryFrame is enabled, or the scene capture will render redundantly. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void CaptureScene();

	/** Settings for taking snapshots */
	UPROPERTY(EditAnywhere, Category="Off World Live Capture Settings", meta=(DisplayName="Snapshot"))
	FOWLSnapshotSettings SnapshotSettings;

	/** Take a snapshot using the current snapshot settings */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void TakeSnapshot();

	/** Event that fires when a snapshot is taken successfully */
	UPROPERTY(BlueprintAssignable, Category = "Snapshot Settings")
	FOnSnapshotCompletionDelegate OnSnapshotComplete;

	UFUNCTION(BlueprintPure, Category = "OWL360Capture")
	UCameraComponent* GetTargetCamera() const;

	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	FIntPoint GetOutputResolution();

	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void SetOutputResolution(FIntPoint Res);

	/** Adds the component to our list of hidden components. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void HideComponent(UPrimitiveComponent* InComponent);

	/**
	 * Adds all primitive components in the actor to our list of hidden components.
	 * @param bIncludeFromChildActors Whether to include the components from child actors
	 */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void HideActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Adds the component to our list of show-only components. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void ShowOnlyComponent(UPrimitiveComponent* InComponent);

	/**
	* Adds all primitive components in the actor to our list of show-only components.
	* @param bIncludeFromChildActors Whether to include the components from child actors
	*/
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void ShowOnlyActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Removes a component from the Show Only list. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void RemoveShowOnlyComponent(UPrimitiveComponent* InComponent);

	/**
	* Removes an actor's components from the Show Only list.
	* @param bIncludeFromChildActors Whether to remove the components from child actors
	*/
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void RemoveShowOnlyActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Clears the Show Only list. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void ClearShowOnlyComponents();

	/** Clears the hidden list. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	void ClearHiddenComponents();

	/** Whether the current projection type is stereo. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	bool IsStereoProjection() const;

	/** Whether the current projection type is stereo. */
	UFUNCTION(BlueprintCallable, Category = "OWL360Capture")
	bool Is180Projection() const;

	UFUNCTION(BlueprintCallable, Category = "OWL360Internal")
	bool RayTracingEnabled() const;

public:
	FEngineShowFlags ShowFlags;
	int32 ViewModeIndex;
	float EffectiveBleedPercent = 1.0;
	float FOVAngle = 90;
public:
	DECLARE_MULTICAST_DELEGATE(FOnRenderFinished);
	FOnRenderFinished OnRenderFinished;

	FSceneViewStateInterface* GetViewState(int32 ViewIndex, const ERHIFeatureLevel::Type FeatureLevel, int32 Eye);
	void EmptyViewStates();

	virtual void BeginDestroy() override;
	virtual void OnRegister() override;
	virtual void OnUnregister() override;

	bool UsingShowOnly() const;
	bool UsingHideOnly() const;

	void AddPostProcessBlendable(TScriptInterface<IBlendableInterface> Blendable);
	void RemovePostProcessBlendable(TScriptInterface<IBlendableInterface> Blendable);

	bool GetAllFaceRenderTargets(TArray<UTextureRenderTarget2D*>& OutRenderTargets) const;
	void GetPostProcessSettings(struct FPostProcessSettings& OutSettings, float& OutBlendWeight);

	static FVector GetFaceCameraLocation(
		const E360ProjectionType& Projection,
		const FVector& CameraLocation,
		const FQuat& ForwardCameraRotation,
		const float ShiftDistance,
		EOWL360FaceIndex FaceIndex, EEyeIndex EyeIndex
	);
	static FQuat GetFaceCameraRotation(
		const FQuat& ForwardCameraRotation,
		EOWL360FaceIndex FaceIndex
	);

	static void SetupFaceRendering(
		const E360ProjectionType& ProjectionType,
		FOWLFaceBool ShouldRenderFaceInternal
	);
	static void SetupDomeMasterRotations(
		const float& DomeAngle,
		FQuat& DomeShaderRotator,
		FQuat& DomeCameraRotator,
		FOWLFaceBool& ShouldRenderFaceInternal);

	static float GetProjectionAspectRatio(const E360ProjectionType& ProjectionType, bool bRenderSingleFace = false);
	static FIntPoint CalculateAutoPanelSize(const E360ProjectionType& ProjectionType, const FOWL360ResolutionSettings& Resolution, const float& FaceBlendPercent);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif

public:
	static void ApplyShowHiddenToView(const UOWL360CaptureComponent* CaptureComponent, FSceneView* &View);

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	bool OnGlobalTick(float DeltaTime);
	void OnViewportRendered(FViewport* RenderedViewport);
	bool IsAttachedTo360CameraActor() const;
	void RenderScene(bool bForSnapshot = false, bool bWarmup = false, float TimeOffsetSeconds = 0);
	void RenderView(
		FMinimalViewInfo View,
		UTextureRenderTarget2D* OutputRT,
		FGameTime Time,
		EEyeIndex EyeIndex,
		bool bIsSnapshot,
		TFunction<void(FRDGBuilder& GraphBuilder)> PreExecute,
		TFunction<void(FRHICommandListImmediate& RHICmdList)> PostExecute);
	void DrawFace(
		int32 FaceIndex,
		FMinimalViewInfo BaseViewInfo,
		FGameTime Time,
		FMatrix ViewRotationMatrix, int32 EyeIndex, bool bForSnapshot);
	void SetupViewFamily(
		FSceneViewFamily& ViewFamily,
		const int32 FaceIndex,
		const int32 EyeIndex,
		const FMinimalViewInfo& BaseViewInfo, const FMatrix& ViewRotationMatrix);
	bool SetupTextureTarget();
	bool SetupInternalRenderTargets(bool bForSnapshot);
	void EmptyRenderTargets();
	void SetFOVAngle();
	void UpdateShowFlags();
	void RegenerateStereoTexture(UTextureRenderTarget2D*& Target, UTextureRenderTarget2D* SourceTarget);
	void SetAspectRatio();
protected:
#if WITH_EDITOR
	FDelegateHandle EnterPIEHandle;
	FDelegateHandle ExitPIEHandle;
	void OnEnterPIE(bool bSimulating);
	void OnExitPIE(bool bSimulating);
	bool bPIEActive = false;
#endif

public:
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);
protected:
	/**
	 * The view state holds persistent scene rendering state and enables occlusion culling in scene captures.
	 * NOTE: This object is used by the rendering thread. When the game thread attempts to destroy it, FDeferredCleanupInterface will keep the object around until the RT is done accessing it.
	 * NOTE: It is not safe to put a FSceneViewStateReference in a TArray, which moves its contents around without calling element constructors during realloc.
	 */
	TIndirectArray<FSceneViewStateReference> ViewStates;
	bool bViewStatesCleared = true;
	UPROPERTY(Transient)
	TArray<UTextureRenderTarget2D*> InternalRTs;
	UPROPERTY(Transient)
	TArray<UTextureRenderTarget2D*> ReusedFaceRTs;
	UPROPERTY()
	UStaticMesh* CameraMesh = nullptr;

	/* Render targets for writing left and right render targets for stereo output */
	UPROPERTY(Transient)
	UTextureRenderTarget2D* LeftEyeRT = nullptr;

	UPROPERTY(Transient)
	UTextureRenderTarget2D* RightEyeRT = nullptr;

	UPROPERTY()
	TObjectPtr<UMaterial> AlphaOnlyMaterial = nullptr;
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> AlphaOnlyMID = nullptr;

	UPROPERTY()
	TObjectPtr<UMaterial> AlphaOnlyMaterialInverted = nullptr;
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> AlphaOnlyInvertedMID = nullptr;

	// Store a map of blendables to hook onto post process struct before capture
	// this is primarily for use in composure passes
	TSet<TScriptInterface<IBlendableInterface>> Blendables;

	float OverscanPercent = 1.0f;

protected:
	void OnSnapshotCompleteInternal(FString OutputPath, bool bSuccess);

	// Copy across post process from 360 to camera component or vice versa
	void UpdatePostProcessSettings();

private:
	bool ShowOnlyActive() const;

	UFUNCTION()
	bool IsFOVAdjustable() const;

	void CleanUpAfterAFrame();

private:
/**
 * Snapshot
 */
	EPixelFormat LastPixelFormat = EPixelFormat::PF_FloatRGBA;
	bool InternalRTsValid() const;

	UPROPERTY(Transient)
	UTextureRenderTarget2D* SnapshotTarget = nullptr;

	void CreateSnapshotTarget();
	void CleanupSnapshotTarget();

private:
	bool bFirstPausedTickPassed = true;
	bool bViewportRenderedThisTick = false;
	FDelegateHandle ViewportRenderedHandle;
	FTSTicker::FDelegateHandle OnGlobalTickHandle;
	/** This scene view extension is used to get ahold of views during the setup process. */

	E360ProjectionType ActiveProjectionType = E360ProjectionType::CT_EquiRectangular;
	// regardless of the output format, we increase the FOV
	// by this amount in order to compensate for artifacts
	// such as motion blur
	FIntPoint PanelSize;
	static const FQuat FaceOrientations[6];
	TUniquePtr<FOffWorldPostProcess> BloomShader = nullptr;

	FOWLFaceBool FaceAlreadyClear;

	// for disabling faces automatically
	// as dome master projection narrows without impacting
	// user overrides
	FOWLFaceBool ShouldRenderFaceInternal;

	FQuat DomeShaderRotator = FRotator(0,0,0).Quaternion();
	FQuat DomeCameraRotator = FRotator(0,0,0).Quaternion();

	FPostProcessSettings RendererPostProcessSettings;

	FLinearColor OWLFilterTints[6];
	float OWLFilterSizes[6];
	float OWLBloomIntensity;
	float OWLBloomThreshold;
	float OWLBloomSizeScale;

	bool bWrongAttachmentWarningIssued = false;

	TSharedPtr<FOpenColorIODisplayExtension, ESPMode::ThreadSafe> OpenColorIODisplayExtension;
};


