// Copyright Off World Live Limited 2020-2025. All rights reserved.

#pragma once

#include "MoviePipelineDeferredPasses.h"
#include "MoviePipelineImagePassBase.h"
#include "MovieRenderPipelineDataTypes.h"
#include "OWL360CaptureComponent.h"
#include "OWL360PipelineSettings.h"
#include "OWL360CameraMoviePipelineData.h"
#include "OWL360PipelineLauncher.h"
#include "OWL360Resolution.h"
#if WITH_EDITOR
#include "Utils/OWLMessageGatherer.h"
#endif
#include "OWL360CameraMoviePipelinePass.generated.h"

class UMoviePipelineOutputSetting;
class AOWL360CameraActor;
class FOWL360CameraBlenderBase;
class IOWL360IntermediateSamplerGetter;
class FSceneViewStateInterface;
class UOWL360PipelineLauncher;
class FOWLConcurrentJobController;

struct FOWLIntermediateStore;
struct F360InternalSettings;

UCLASS(BlueprintType)
class OWLMRQPIPELINE_API UOWL360CameraMoviePipelinePass : public UMoviePipelineDeferredPassBase
{
	GENERATED_BODY()

public:
	UOWL360CameraMoviePipelinePass();
	~UOWL360CameraMoviePipelinePass();

public:
	/* Uses an existing pipeline pass to populate the same settings */
	void PopulateFrom(const UOWL360CameraMoviePipelinePass* InSetting);

public:
	virtual void GetViewShowFlags(FEngineShowFlags& OutShowFlag, EViewModeIndex& OutViewModeIndex) const override;

	virtual void ValidateStateImpl() override;
	virtual void SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings) override;
	virtual void RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleState) override;
	virtual void TeardownImpl() override;
	virtual void ShutdownAfterError() override;

#if WITH_EDITOR
	virtual FText GetDisplayText() const override { return NSLOCTEXT("MovieRenderPipeline", "DeferredBasePassSetting_DisplayName_OWL360Camera", "OWL 180 / 360 Rendering"); }
	virtual FText GetFooterText(UMoviePipelineExecutorJob* InJob) const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif

	// FGCObject Interface
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);
	// ~FGCObject Interface


	virtual int32 GetOutputFileSortingOrder() const override { return 0; }
	virtual bool IsAntiAliasingSupported() const { return Settings.Rendering.bPathTracing ? false : !bDisableMultisampleEffects; }

public:
	virtual void SetOutputResolution(class UMoviePipelinePrimaryConfig* ExistingConfig = nullptr);

	TMap<uint32, FSceneViewStateReference> ViewStates;
	TMap<uint32, uint32> FaceGroups;
	TMap<uint32, TArray<uint32>> ChildFaceGroups;

protected:
	TSharedPtr<FOWL360CameraBlenderBase> OWLBlender;
	E360ProjectionType ActiveBlender;

	TMap<FIntPoint, TWeakObjectPtr<UTextureRenderTarget2D>> ViewRenderTargets;

protected:
	// Overrideable methods for controlling outputs
	/* Override method and return false here when you want just one face to pass through the system */
	virtual bool RendersOnlyOneFace() { return false; };
	/* Return false here when eaces do not need to be joined into an intermediate cubemap */
	virtual bool UseAndAwaitIntermediateStore() { return true; }
	virtual EOWL360FaceIndex GetSingleFaceIndex() { return EOWL360FaceIndex::Left;}
	virtual int32 GetEyeIndex() { return 0; }
	/* Get specific cameras to render from the sequence. If empty, assume all cameras */
	virtual TArray<FGuid> GetCameraGuids() const { return {};}
	virtual void SetupMergers(E360ProjectionType Projection);
	virtual TWeakPtr<MoviePipeline::IMoviePipelineOutputMerger, ESPMode::ThreadSafe> GetOutputMerger(E360ProjectionType Projection) const;
	virtual TWeakPtr<FOWL360CameraBlenderBase, ESPMode::ThreadSafe> GetBlenderBaseOutputMerger(E360ProjectionType Projection) const;
	virtual TUniquePtr<IOWL360IntermediateSamplerGetter> GetSamplerGetter();
	virtual void SetupJobController();
	virtual void PostInitProperties() override;
	void SubmitBlankSingleCameraRender(const FMoviePipelineRenderPassMetrics& InSampleState, UOWL360CaptureComponent* Component);

protected:
	TFunction<void(TUniquePtr<FImagePixelData>&&)> GetSurfaceQueueCallback(
		TSharedRef<FOWL360CameraImagePixelDataPayload, ESPMode::ThreadSafe> FramePayload,
		MoviePipeline::FImageSampleAccumulationArgs AccumulationArgs,
		TSharedPtr<FAccumulatorPool::FAccumulatorInstance, ESPMode::ThreadSafe> SampleAccumulator,
		FString PassName,
		int FrameNumber,
		int SpatialIndex,
		bool bReuseForOtherEye,
		FIntPoint CropOffset
		);

	TFunction<void(TUniquePtr<FImagePixelData>&&)> MakeForwardingEndpoint(
		const FMoviePipelinePassIdentifier InPassIdentifier,
		const FMoviePipelineRenderPassMetrics& InSampleState,
		const FOWL360CameraPassFacePayload InFacePayload, const FOWL360Resolution& Resolution
	);

	bool GetOutputSettings(UMoviePipelinePrimaryConfig* ExistingConfig, UMoviePipelineOutputSetting*& OutputSettings);

	FSceneViewStateInterface* GetViewState(const int32 CameraIndex, const int32 SceneViewIndex, const int32 FaceViewIndex, const int32 Eye, const ERHIFeatureLevel::Type FeatureLevel);
	void SetProjectionMatrix(FSceneViewInitOptions &ViewInitOptions, FMoviePipelineRenderPassMetrics& InOutSampleState, const
							UOWL360CaptureComponent* CaptureComponent360, FOWL360CameraPassFacePayload* Payload) const;

	void Add360Metadata(FMoviePipelineRenderPassMetrics& InOutSampleState, const FOWLFoundSequenceCamera& Data);

	void SetOutputPassOutputResolution(FIntPoint Resolution);
	TWeakObjectPtr<UTextureRenderTarget2D> GetOrCreateLocalViewRenderTarget(const FIntPoint& InSize, EOWLBitDepth BitDepth);
	TArray<FString> GetLocalStencilLayerNames() const;
	virtual void WaitUntilTasksComplete() override;
	bool HasStencilLayers() const;
	bool HasHooks() const;
	TArray<UOWLMRQ360Hooks*> GetRenderingHooks();
	bool bWarnedAboutHooks = false;
protected:
	UPROPERTY()
	bool bFirstInitialised = false;

	TArray<FString> LocalUniqueStencilLayerNames;

	void PostRendererSubmissionByFace(
		const FMoviePipelineRenderPassMetrics& InSampleState,
		const FMoviePipelinePassIdentifier InPassIdentifier,
		const FOWL360CameraPassFacePayload& InFacePayload,
		const FOWL360Resolution& Resolution,
		FCanvas& InCanvas,
		bool bSecondaryLayer);
	static int32 GetCompositeViewStateIndex(int32 CameraIndex, int32 EyeIndex, int32 SceneViewIndex, int32 FaceIndex);
	virtual void GatherOutputPassesImpl(TArray<FMoviePipelinePassIdentifier>& ExpectedRenderPasses) override;
	TSharedPtr<FSceneViewFamilyContext> SetupViewFamily(
		FMoviePipelineRenderPassMetrics& InOutSampleState,
		FOWL360CameraPassFacePayload* OptPayload,
		UOWL360CaptureComponent* CaptureComponent360,
		const FInternal360Settings CameraSettings,
		const FOWL360Resolution& Resolution,
		const FOWLFoundSequenceCamera& CameraData,
		bool bStencilPass = false);

	float GetFOV() const;

	virtual bool ShouldRenderOverlay();
	bool ShouldRenderOverlay_Base();
	bool HasPostProcessPasses();
	bool ResolutionImposesWatermark() const;

	TSharedPtr<FOWLIntermediateStore> IntermediateStore = nullptr;

	bool bPassUpdated = false;

	bool bPrevious360PauseState = false;

	static bool CanPushFrame(const FMoviePipelineRenderPassMetrics& SampleState);
	virtual bool PushExpectedOutputFrame(const E360ProjectionType Projection, const FOWLMRQOutputDesc& ExpectedOutput);

	// used to block when parallel rendering disabled
	TAtomic<int32> LastFaceComplete = -1;
	/* Only Accessed on game thread. A counter incremented */
	int32 LastFaceSubmitted = -1;
	/* If bDisableParallelRendering this blocks until render result */
	void BlockForFace();

	bool ShouldRenderCamera(const int& CameraIndex, const FOWLCompositeSettings& CompositeSettings) const;

	bool GetSequence360Components(TArray<FOWLFoundSequenceCamera>& FoundComponents) const;

	void GetSequenceCameraData(
		FFrameTime CurrentTime,
		TArray<FOWLFoundSequenceCamera>& SequenceCameras,
		TArray<FOWLCompositeSettings>& CompositeSettingsPerCamera,
		int32& NumCameras, UOWL360CaptureComponent*& FirstMatch);

	FFrameTime GetCurrentSequenceTime(const FMoviePipelineRenderPassMetrics& SampleState) const;

	bool FindComponentsFromSidecars(TArray<FOWLFoundSequenceCamera>& FoundComponents) const;
	void UpdateInSampleStateSidecars(FMoviePipelineRenderPassMetrics& SampleState, TArray<FOWLFoundSequenceCamera> Cameras, int CurrentCameraIndex);

	TSharedPtr<FOWLConcurrentJobController> JobController;

	FMoviePipelinePassIdentifier UpdateIdentifierForComposite(const FMoviePipelinePassIdentifier& Identifier) const;
protected:
	FOWLMRQCameraTransforms CameraTransforms;
public:
	// Blueprint API
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", Meta = (ShowOnlyInnerProperties))
	FOWL360PipelineSettings Settings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "High Resolution Renders", meta = (ShowOnlyInnerProperties))
	FOWL360PipelineLauncher Launcher;

	UPROPERTY(EditAnywhere, Category = "Output")
	bool bIncludeAlpha = true;
private:
	UPROPERTY()
	TArray<UOWLMRQ360Hooks*> RenderingHooks;
	bool bRenderingHooksInstantiated = false;
public:
	UFUNCTION(BlueprintSetter)
	void SetCustomOutputResolution(FIntPoint InRes);
#if WITH_EDITOR
private:
	TUniquePtr<FOWLMessageGatherer> MessageGatherer = nullptr;
#endif
};

