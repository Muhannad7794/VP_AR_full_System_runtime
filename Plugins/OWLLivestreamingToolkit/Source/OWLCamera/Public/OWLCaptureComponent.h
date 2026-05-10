// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "CineCameraSettings.h"
#include "OpenColorIOColorSpace.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/SceneComponent.h"
#include "Widgets/SWindow.h"
#include "Widgets/SVirtualWindow.h"
#include "ShowFlags.h"
#include "Materials/Material.h"
#include "Containers/Ticker.h"
#include "Components/SceneCaptureComponent.h"

#include "OWLSnapshotSettings.h"
#include "OWLStereoRenderingTypes.h"

#include "OWLCaptureComponent.generated.h"

class UOWLViewportPreview;
class FSceneViewStateInterface;
class UCameraComponent;
struct FMinimalViewInfo;
class FWidgetRenderer;
class IBlendableInterface;
class ISceneViewExtension;
class AOWLStereoConvergencePlane;
class FOpenColorIODisplayExtension;

struct FPixelStats
{
	float minBrightness = FLT_MAX;
	float maxBrightness = -FLT_MAX;
	float avgBrightness = 0.0f;
	int32 totalPixels = 0;
	int32 nonZeroPixels = 0;
};

enum class EEyeIndex : uint8
{
	EI_Left = 0,
	EI_Right = 1,
	EI_Mono = 2
};

UENUM(BlueprintType)
enum class EOWLOutputBufferVisualisation : uint8
{
	BV_None UMETA(DisplayName="None"),
	BV_BaseColor UMETA(DisplayName="Base Color"),
	BV_CustomDepth UMETA(DisplayName="Custom Depth"),
	BV_CustomStencil UMETA(DisplayName="Custom Stencil"),
	BV_FinalImage UMETA(DisplayName="Final Image"),
	BV_ShadingModel UMETA(DisplayName="ShadingModel"),
	BV_MaterialAO UMETA(DisplayName="Material Ambient Occlusion"),
	BV_Metallic UMETA(DisplayName="Metallic"),
	BV_Opacity UMETA(DisplayName="Opacity"),
	BV_Roughness UMETA(DisplayName="Roughness"),
	BV_Anisotropy UMETA(DisplayName="Ansiotropy"),
	BV_SceneColor UMETA(DisplayName="Scene Color"),
	BV_SceneDepth UMETA(DisplayName="Scene Depth"),
	BV_SeparateTranslucencyRGB UMETA(DisplayName="Separate Translucency RGB"),
	BV_SeparateTranslucencyA UMETA(DisplayName="Separate Translucency Alpha"),
	BV_Specular UMETA(DisplayName="Specular"),
	BV_SubsurfaceColor UMETA(DisplayName="Subsurface Color"),
	BV_WorldNormal UMETA(DisplayName="World Normal"),
	BV_WorldTangent UMETA(DisplayName="World Tangent"),
	BV_AmbientOcclusion UMETA(DisplayName="Ambient Occlusion"),
	BV_CustomDepthWorldUnits UMETA(DisplayName="Custom Depth World Units"),
	BV_SceneDepthWorldUnits UMETA(DisplayName="Scene Depth World Units"),
	BV_Velocity UMETA(DisplayName="Velocity"),
	BV_PreTonemapHDRColor UMETA(DisplayName="Pre-Tonemap HDR Color"),
	BV_PostTonemapHDRColor UMETA(DisplayName="Post-Tonemap HDR Color"),
	BV_MattePass UMETA(DisplayName="Matte Pass (Hold Out)"),
	BV_MattePassInverted UMETA(DisplayName="Matte Pass (Garbage)"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCaptureComponentResized);


UCLASS(Blueprintable, hidecategories = (Collision, Object, Physics, SceneComponent, Mobility, Tags, Activation, Cooking, Rendering), ClassGroup = Rendering, meta = (BlueprintSpawnableComponent))
class OWLCAMERA_API UOWLCaptureComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UOWLCaptureComponent(const FObjectInitializer& ObjectInitializer);

	/**
	* Render target to render into and send to Spout
	* If left unset the render target will be generated automatically
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Off World Live Capture Settings", DisplayName="Render Target", meta=(EditCondition="!bUseRTOverride", EditConditionHides))
	TObjectPtr<UTextureRenderTarget2D> TextureTarget = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Off World Live Capture Settings" , meta=(EditCondition="!bHideBufferOption", EditConditionHides))
	EOWLOutputBufferVisualisation VisualisationType = EOWLOutputBufferVisualisation::BV_None;

	/**
	* Min: 64px, Max: 7680
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta = (NoSpinbox=true, EditCondition="!bUseRTOverride", EditConditionHides))
	int ResolutionX = 1920;

	/**
	* Min: 64px, Max: 4320
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta= (NoSpinbox=true, EditCondition="!bUseRTOverride", EditConditionHides))
	int ResolutionY = 1080;

	UPROPERTY(EditAnywhere, interp, Category = "Rendering Flags")
	TArray<struct FEngineShowFlagsSetting> ShowFlagSettings;

	/** Tick if you want to pause rendering to the render target */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	bool bPauseRendering = false;

	/** Tick to enable plugins like DLSS -- warning certain anti-aliasing settings may cause crashes when screen percentage on this actor is adjusted */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	bool bEnableUpscaling = false;

	/** ScreenPercentage affects impact of upscaling (ie DLSS, TAA ...) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta = (UIMin = "25", UIMax = "200", ClampMax="200", ClampMin="25", EditCondition="bEnableUpscaling"))
	float ScreenPercentage = 100;

	/** Enable path tracing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings", meta = (EditCondition="RayTracingEnabled()"))
	bool bPathTracing = false;

	UPROPERTY(EditAnywhere, Category="Off World Live Capture Settings", meta=(DisplayName="Snapshot"))
	FOWLSnapshotSettings SnapshotSettings;

	/* Stereo rendering configuration */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	FOWLStereoRenderingConfig StereoConfig;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Off World Live Capture Settings|UMG Rendering", meta=(EditCondition="!bUseRTOverride", EditConditionHides))
	bool bRenderHUD = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Off World Live Capture Settings|UMG Rendering", meta=(EditCondition="!bUseRTOverride", EditConditionHides))
	TSubclassOf<class UUserWidget> WidgetType;

	UPROPERTY()
	TObjectPtr<UUserWidget> WidgetToRender = nullptr;

	/** The components won't rendered by current component.*/
	UPROPERTY()
	TArray<TWeakObjectPtr<UPrimitiveComponent> > HiddenComponents;

	/** Rendering Scene view extensions can be important for correctly rendering landscapes etc, but can often cause unnecessary re-renders
	 when they are only expected to be executed in the viewport rendering cycle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Render Settings")
	bool bRenderSceneViewExtensions = true;

	/** The only components to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList. */
	UPROPERTY()
	TArray<TWeakObjectPtr<UPrimitiveComponent> > ShowOnlyComponents;

	/** Tick if you want to render selected primitives only */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Off World Live Capture Settings|Alpha Settings")
	bool bUseShowOnlyList;

	/** The actors to hide in the scene capture. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Off World Live Capture Settings|Alpha Settings")
	TArray<AActor*> HiddenActors;

	/** The only actors to be rendered by this scene capture, if PrimitiveRenderMode is set to UseShowOnlyList.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Off World Live Capture Settings|Alpha Settings")
	TArray<AActor*> ShowOnlyActors;

	/** By default we invert the ue4's default alpha value of captured textures - you can disable it here */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Off World Live Capture Settings|Alpha Settings")
	bool bInvertAlpha = true;

	/** Scales the distance used by LOD. Set to values greater than 1 to cause the scene capture to use lower LODs than the main view to speed up the scene capture pass. */
	UPROPERTY(EditAnywhere, Category = "Off World Live Capture Settings|Advanced", meta = (UIMin = ".1", UIMax = "10"))
	float LODDistanceFactor = 1.0f;

	/** if > 0, sets a maximum render distance override.  Can be used to cull distant objects from a reflection if the reflecting plane is in an enclosed area like a hallway or room */
	UPROPERTY(EditAnywhere, Category = "Off World Live Capture Settings|Advanced", meta = (UIMin = "100", UIMax = "10000"))
	float MaxViewDistanceOverride = -1;

	/* Set camera preview in editor as the output render target while rendering */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category = "Camera", meta=(ShowOnlyInnerProperties))
	UOWLViewportPreview* ViewportPreview = nullptr;

	/**
	* Open Color IO Configuration. Used to apply color transforms.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color", meta = (DisplayName = "OpenColorIO Configuration"))
	FOpenColorIODisplayConfiguration OCIOConfiguration;

public:
	UPROPERTY(BlueprintAssignable, Category="Off World Live Capture Settings", meta=(ToolTip="Triggered whenever the render target has been resized. This can be essential when triggering a media output stream on begin play"))
	FOnCaptureComponentResized OnTargetResized;

protected:
	UFUNCTION(BlueprintCallable, Category = "CaptureComponentInternal")
	bool RayTracingEnabled() const;

	void RenderView(
		FMinimalViewInfo BaseViewInfo,
		UTextureRenderTarget2D* OutputRT,
		FGameTime Time,
		EEyeIndex EyeIndex,
		TFunction<void(FRDGBuilder& Builder)> PreExec = nullptr,
		TFunction<void(FRHICommandListImmediate& RHICmdList)> PostExec = nullptr);

public:
	UFUNCTION(BlueprintPure, Category = "OWLCapture")
	virtual UCameraComponent* GetTargetCamera() const;

	/** Adds the component to our list of hidden components. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void HideComponent(UPrimitiveComponent* InComponent);

	/**
	 * Adds all primitive components in the actor to our list of hidden components.
	 * @param bIncludeFromChildActors Whether to include the components from child actors
	 */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void HideActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Clears the hidden list. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void ClearHiddenComponents();

	/** Adds the component to our list of show-only components and automatically enables bUseShowOnlyList. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void ShowOnlyComponent(UPrimitiveComponent* InComponent);

	/**
	 * Adds all primitive components in the actor to our list of show-only components and automatically enables bUseShowOnlyList.
	 */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void ShowOnlyActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Adds the component to our list of show-only components without automatically enabling bUseShowOnlyList. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void AddShowOnlyComponent(UPrimitiveComponent* InComponent);

	/**
	 * Adds all primitive components in the actor to our list of show-only components without automatically enabling bUseShowOnlyList.
	 */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void AddShowOnlyActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Removes a component from the Show Only list. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void RemoveShowOnlyComponent(UPrimitiveComponent* InComponent);

	/**
	 * Removes an actor's components from the Show Only list.
	 */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void RemoveShowOnlyActorComponents(AActor* InActor, const bool bIncludeFromChildActors = false);

	/** Clears the Show Only list. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void ClearShowOnlyComponents();

	/** Get Current UMG Widget
	 * might return nullptr if the WidgetType is not set */
	UFUNCTION(BlueprintCallable, Category = "UMGRendering")
	UUserWidget* GetCurrentUMGWidget();

	/** Render the scene to the texture target immediately. This should not be used if bCaptureEveryFrame is enabled, or the scene capture will render redundantly. */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture")
	void CaptureScene();

	/** Take a snapshot of the scene and output it as an image file created in the specified output path */
	UFUNCTION(BlueprintCallable, Category = "OWLCapture", DisplayName="Take Snapshot")
	void TakeSnapshot();

	/** Event that fires when a snapshot is taken successfully */
	UPROPERTY(BlueprintAssignable, Category = "Snapshot Settings")
	FOnSnapshotCompletionDelegate OnSnapshotCompleteCallback;

public:
	static ESceneCaptureSource SourceFromBufferType(EOWLOutputBufferVisualisation Viz);
	static const FName VisTypeToFname(EOWLOutputBufferVisualisation Type);

	static bool LandscapeInTheScene(UWorld* World);
public:
	FEngineShowFlags ShowFlags;
	int32 ViewModeIndex;
	// Used to increase FOV before capture
	float OverscanFactor = 1.0f;

public:
	DECLARE_MULTICAST_DELEGATE(FOnRenderFinished);
	FOnRenderFinished OnRenderFinished;

	FSceneViewStateInterface* GetViewState(int32 ViewIndex, const ERHIFeatureLevel::Type FeatureLevel);
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);

	virtual void BeginDestroy() override;
	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

	bool UsingShowOnly() const;
	bool UsingHideOnly() const;

	void AddPostProcessBlendable(TScriptInterface<IBlendableInterface> Blendable);
	void RemovePostProcessBlendable(TScriptInterface<IBlendableInterface> Blendable);

public:
	UPROPERTY(VisibleAnywhere, Category="Internal")
	bool bUseRTOverride = false;

	UPROPERTY(VisibleAnywhere, Category="Internal")
	bool bHideBufferOption = false;

	bool bRenderOnTick = true;
protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	bool OnGlobalTick(float DeltaTime);
	void OnViewportRendered(FViewport* RenderedViewport);

#if WITH_EDITOR
	FDelegateHandle EnterPIEHandle;
	FDelegateHandle ExitPIEHandle;
	void OnEnterPIE(bool bSimulating);
	void OnExitPIE(bool bSimulating);
	bool bPIEActive = false;
#endif

	/* Can be used to override and remove certain scene view extensions from capture component */
	virtual bool CanRenderSceneViewExtension(TSharedRef<ISceneViewExtension, ESPMode::ThreadSafe> SceneViewExtension);
	void RenderScene(UCameraComponent* TargetCamera, bool bForSnapshot = false, bool bWarmup = false, float TimeOffsetSeconds = 0);
	void SetupResolution(UCameraComponent* TargetCamera);
	void SetupViewFamily(class FSceneViewFamily& ViewFamily, const TArrayView<FMinimalViewInfo> Views, FLinearColor ClearColour, EEyeIndex EyeIndex);
	void SetupShowHideActors(class FSceneViewFamily& ViewFamily, FSceneView* View);
	bool SetupTextureTarget(UTextureRenderTarget2D* Target);
	bool SetupInternalRenderTarget(UTextureRenderTarget2D* Target, const ETextureRenderTargetFormat Format);
	/* Returns true and writes to Result when an override exists */
	virtual bool GetPostProcessSettingsOverride(FPostProcessSettings& Result, float& BlendWeight);

	void UpdateShowFlags();

	bool bUsesComposureLicence = false;

	bool bIgnoreConstrainAspectRatio = false;

	UPROPERTY()
	TObjectPtr<UMaterial> AlphaOnlyMaterial = nullptr;
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> AlphaOnlyMID = nullptr;

	UPROPERTY()
	TObjectPtr<UMaterial> AlphaOnlyMaterialInverted = nullptr;
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> AlphaOnlyInvertedMID = nullptr;

	FDelegateHandle PostOpaqueRenderHandle;
	bool bOnResolvedBound = false;

	/**
	 * The view state holds persistent scene rendering state and enables occlusion culling in scene captures.
	 * NOTE: This object is used by the rendering thread. When the game thread attempts to destroy it, FDeferredCleanupInterface will keep the object around until the RT is done accessing it.
	 * NOTE: It is not safe to put a FSceneViewStateReference in a TArray, which moves its contents around without calling element constructors during realloc.
	 */
	TIndirectArray<FSceneViewStateReference> ViewStates;
	float CurrentAspectRatio = 1.0f;
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> InternalRT = nullptr;
	UPROPERTY()
	TObjectPtr<UStaticMesh> CameraMesh = nullptr;
	UPROPERTY()
	TObjectPtr<UStaticMesh> CineCameraMesh = nullptr;


	// This is used by child components that don't want to allow the user
	// to specify render targets
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> OverrideRT = nullptr;

	UPROPERTY()
	TObjectPtr<UCameraComponent> OverrideCameraComponent = nullptr;

	// Store a map of blendables to hook onto post process struct before capture
	// this is primarily for use in composure passes
	TSet<TScriptInterface<IBlendableInterface>> Blendables;

	/* Render targets for writing left and right render targets for stereo output */
	UPROPERTY(Transient)
	UTextureRenderTarget2D* LeftEyeRT = nullptr;

	UPROPERTY(Transient)
	UTextureRenderTarget2D* RightEyeRT = nullptr;


private:
	void Finish_RenderThread(FRDGBuilder& GraphBuilder, UTextureRenderTarget2D* Target, FRHITexture* InSourceTexture, bool bInvertAlpha);
	void ResetViewStates();

	bool ShowOnlyActive() const;
	FIntPoint GetStereoResolution() const;

	float GetViewportRenderDelta();

	bool bViewportRenderedThisTick = false;
	FDateTime LastViewportRender;
	FDelegateHandle ViewportRenderedHandle;
	FTSTicker::FDelegateHandle GlobalTickHandle;

private:
	bool WrongAttachmentWarningIssued = false;
	FWidgetRenderer* WidgetRenderer = nullptr;
	TSharedPtr<SVirtualWindow> Window;
	TAtomic<bool> bRenderingThreadCompleted = false;
	TSharedPtr<FOpenColorIODisplayExtension, ESPMode::ThreadSafe> OpenColorIODisplayExtension;
private:
	void InitWidgetRenderer();
	void ReleaseRenderer();
	void RenderWidgetOnTick(float DeltaTime, UTextureRenderTarget2D* WidgetTarget);
	void RegenerateStereoTexture(UTextureRenderTarget2D*& Target, UTextureRenderTarget2D* OutputTarget);

	//-----------------------------------------------------------------------
	// Snapshot Functionality
	//-----------------------------------------------------------------------
protected:
	UPROPERTY(Transient)
	UTextureRenderTarget2D* SnapshotTexture = nullptr;

	void CreateSnapshotTexture();
	void OnSnapshotComplete(FString FullPath, bool bSuccess);

	//-----------------------------------------------------------------------
	// Stereoscopic Convergence Functionality
	//-----------------------------------------------------------------------
private:
	// Handles the convergence plane visualization
	UPROPERTY(Transient)
	AOWLStereoConvergencePlane* ConvergencePlane;

	UPROPERTY(Transient)
	AOWLStereoConvergencePlane* DetachedConvergencePlane = nullptr;

	float PreviousFocusDistance = 0.0f;
	ECameraFocusMethod PreviousFocusMethod = ECameraFocusMethod::Manual;
	bool bInitializedPreviousValues = false;
	bool bPendingConvergencePlaneUpdate = false;
	int32 ConvergencePlaneUpdateDelayFrames = 0;
	const int32 MaxConvergencePlaneUpdateDelayFrames = 2; // Wait up to 2 frames

	void RenderUMGForStereo(float DeltaTime);
	void EnsureStereoViewStatesAllocated();

#if WITH_EDITOR
	void OnBlueprintCompiled();
	FDelegateHandle OnBlueprintCompiledHandle;
#endif


public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConvergenceDistanceChanged, float, NewConvergenceDistance);

	/** Gets the convergence plane actor for direct manipulation in editor/sequencer */
	UFUNCTION(BlueprintCallable, Category = "Stereoscopic")
	AOWLStereoConvergencePlane* GetConvergencePlane() const { return ConvergencePlane; }

	UPROPERTY(BlueprintAssignable, Category = "Off World Live Capture Settings")
	FOnConvergenceDistanceChanged OnConvergenceDistanceChanged;

	/**
	 * Updates the stereo convergence distance and handles all necessary updates
	 * @param NewDistance - The new convergence distance in world units
	 * @param bUpdateCameraFocus - Whether to also update camera focus if in appropriate sync mode
	 */
	UFUNCTION(BlueprintCallable, Category = "OWL Stereoscopic")
	void SetStereoConvergenceDistance(float NewDistance, bool bUpdateCameraFocus = true);

	/**
	 * Updates the convergence distance to match the camera focus
	 */
	UFUNCTION(BlueprintCallable, Category = "OWL Stereoscopic")
	void SyncConvergenceWithFocus();

	/**
	 * Callback for when the convergence plane is manually adjusted
	 */
	UFUNCTION()
	void OnConvergencePlaneManipulated(float NewDistance);

protected:
	/**
	 * Updates the convergence plane visualization based on stereo config
	 */
	void UpdateConvergencePlaneVisualization();

	/**
	 * Creates a convergence plane actor for visualization if needed
	 */
	void CreateConvergencePlane();

	/**
	 * Updates material parameters related to convergence
	 */
	void UpdateConvergenceParameters();

	/**
	 * Applies the current stereo configuration
	 */
	void ApplyStereoConfig();

};

