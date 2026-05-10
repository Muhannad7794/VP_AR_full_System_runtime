// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "MovieRenderPipelineDataTypes.h"
#include "OWLEyeIndex.h"
#include "DataTypes/OWLFaceCrop.h"
#include "UObject/Interface.h"
#include "Templates/RefCounting.h"
#include "Rendering/SlateRenderer.h"
#include "RHIResources.h"
#include "OWLMRQ360Hooks.generated.h"

enum class EOWLMRQEyeIndex : uint8;
class UOWL360CameraMoviePipelinePass;
struct FOWL360CameraPassFacePayload;
class UMoviePipeline;

USTRUCT(BlueprintType)
struct FOWLMovieSampleState
{
	GENERATED_BODY()
public:
	FOWLMovieSampleState() = default;
	FOWLMovieSampleState(const FMoviePipelineFrameOutputState& InState);

public:
	// this is all taken from FMoviePipelineFrameOutputState so that it can be exposed to blueprints
	/**
	* The expected output frame count that the render is working towards creating.
	* This number accurately tracks the number of frames we have produced even if
	* the file written to disk uses a different number (due to relative frame numbers
	* or offset frames being added.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 OutputFrameNumber = 0;

	/** Which shot is this output state for? */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 ShotIndex = 0;

	/** How many shots total will we be outputting? */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 ShotCount = 0;

	/** Which sub-frame are we on when using Accumulation Frame rendering. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 TemporalSampleIndex = 0;

	/** How many temporal samples do we add together to produce one Output Frame? */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 TemporalSampleCount = 0;

	/**
	* The expected output frame count for this current shot that we're working towards
	* creating. Like OutputFrameNumber but relative to this shot. This should get reset between shots.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 ShotOutputFrameNumber = 0;

	/** The total number of samples (including warm ups) that have been sent to the GPU for this shot. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 ShotSamplesRendered = 0;

	/** The name of the currently active camera being rendered. May be empty. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	FString CameraName;

	/** Name used by the {camera_name} format tag. May be empty */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	FString CameraNameOverride;

	/** THe name of the currently active shot. May be empty if there is no shot track. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	FString ShotName;

	/**
	* This can be true when the fade value is 0 for the current camera.
	* If true, then the rendering for this frame should be skipped (ie: nothing submitted to the gpu, and the output merger not told to expect this frame).
	* This is used for rendering every Nth frame for rendering drafts. We still run the game thread logic for the skipped frames (which is relatively cheap)
	* and simply omit rendering them. This increases consistency with non-skipped renders, and will be useful for consistency when rendering on a farm.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	bool bSkipRendering = false;

	/**
	* If true, and a IRenderCaptureProvider is available, trigger a capture of the rendering process of this frame.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	bool bCaptureRendering = false;

	/**
	* If this is true, then the frame will be rendered but the results discarded and not sent to the accumulator. This is used for render warmup frames
	* or gpu-based feedback loops. Ignored if bSkipRendering is true.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	bool bDiscardRenderResult = false;


	/** The closest frame number (in Display Rate) on the Sequence. May be duplicates in the case of different output framerate or Play Rate tracks. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 SourceFrameNumber = 0;

	/** The closest time code version of the SourceFrameNumber on the Sequence. May be a duplicate in the case of different output framerate or Play Rate tracks. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	FTimecode SourceTimeCode;

	/**
	* The closest frame number (in Display Rate) on the Sequence adjusted for the effective output rate. These numbers will not line up with the frame
	* in the source Sequence if the output frame rate differs from the Sequence display rate. May be a duplicate in the event of Play Rate tracks.
	*/
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 EffectiveFrameNumber = 0;

	/** The closest time code version of the EffectiveFrameNumber. May be a duplicate in the event of Play Rate tracks. */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	FTimecode EffectiveTimeCode;

	/** Metadata to attach to the output file (if supported by the output container) */
	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	TMap<FString, FString> FileMetadata;


	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 CurrentShotSourceFrameNumber = 0;

	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	FTimecode CurrentShotSourceTimeCode;

	UPROPERTY(BlueprintReadOnly, Category="Sample State")
	int32 CameraIndex = 0;

	FMoviePipelineFrameOutputState::FTimeData TimeData;
};

USTRUCT(BlueprintType)
struct FOWL360HookStitchInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category="Stitch Info")
	int FrameNumber = 0;

	UPROPERTY(BlueprintReadOnly, Category="Stitch Info")
	int SceneViewIndex = 0;

	UPROPERTY(BlueprintReadOnly, Category="Stitch Info")
	int CameraIndex= 0;

	UPROPERTY(BlueprintReadOnly, Category="Stitch Info")
	FIntPoint Resolution = {0,0};

	FMoviePipelineRenderPassMetrics SampleState;
};

USTRUCT(BlueprintType)
struct FOWL360HookTileInfo : public FOWL360HookStitchInfo
{
	GENERATED_BODY()
public:
	FOWL360HookTileInfo() = default;
	FOWL360HookTileInfo(const FOWL360CameraPassFacePayload& InFace, FIntPoint Resolution, const FMoviePipelineRenderPassMetrics& SampleState);
public:
	UPROPERTY(BlueprintReadOnly, Category="Tile Info")
	FOWLFaceCrop Crop;

	UPROPERTY(BlueprintReadOnly, Category="Tile Info")
	EOWL360FaceIndex Face = EOWL360FaceIndex::Left;

	UPROPERTY(BlueprintReadOnly, Category="Tile Info")
	EOWLMRQEyeIndex Eye = EOWLMRQEyeIndex::Left;

	UPROPERTY(BlueprintReadOnly, Category="Tile Info")
	FIntPoint TileIndex = {0,0};

	UPROPERTY(BlueprintReadOnly, Category="Tile Info")
	FIntPoint TotalTiles = {0,0};
};

UENUM(Blueprintable)
enum EOWL360MRQPassType
{
	PT_Combined UMETA(DisplayName="Combined Render Pass"),
	PT_SingleFacePass UMETA(DisplayName="Single Face Pass"),
	PT_StitchPass UMETA(DisplayName="Stitch Pass"),
};

typedef TFunction<bool(const FMoviePipelineRenderPassMetrics& SampleState, const FIntPoint& OutputResolution, TArray64<FColor>& OutData)> TExecuteAdditionalPassCallback_8Bit;
typedef TFunction<bool(const FMoviePipelineRenderPassMetrics& SampleState, const FIntPoint& OutputResolution, TArray64<FFloat16Color>& OutData)> TExecuteAdditionalPassCallback_16Bit;
typedef TFunction<bool(const FMoviePipelineRenderPassMetrics& SampleState, const FIntPoint& OutputResolution, TArray64<FLinearColor>& OutData)> TExecuteAdditionalPassCallback_32Bit;

UCLASS(Blueprintable, Abstract)
class OWLMRQPIPELINE_API UOWLMRQ360Hooks : public UObject
{
	GENERATED_BODY()

public:
	~UOWLMRQ360Hooks() = default;

public:
	UPROPERTY(BlueprintReadOnly, Category="OWL Hooks")
	TEnumAsByte<EOWL360MRQPassType> PassType = EOWL360MRQPassType::PT_Combined;

public:
	// BLUEPRINTABLE API
	/* Called when the movie render pipeline is being setup */
	UFUNCTION(BlueprintNativeEvent, Category="OWL Hooks")
	void Setup_GameThread(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline);

	/* Called when the movie pipeline is shutting down */
	UFUNCTION(BlueprintNativeEvent, Category="OWL Hooks")
	void TearDown_GameThread(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline);

	/* Called before any tiles have been rendered and after setup */
	UFUNCTION(BlueprintNativeEvent, Category="OWL Hooks")
	void PreRenderCamera_GameThread(const int CameraIndex, const FOWLMovieSampleState& SampleState, const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline, const class UOWL360CaptureComponent* CaptureComponent);

	/* Called before submitting a render for a frame on the game thread. Can be used to add optional blend materials etc for a given tile / face */
	UFUNCTION(BlueprintNativeEvent, Category="OWL Hooks")
	void ModifyTilePostProcess_GameThread(const FPostProcessSettings& CurrentPostProcessSettings, FPostProcessSettings& PostProcessSettings, const FOWL360HookTileInfo& TileInfo, const UMoviePipeline* Pipeline );

public:
	// C++ API -- Sadly blueprints can only run on game thread :(
	/* Method called when the 360 stitch has completed and can happen on any task thread */
	virtual void PostStitch_TaskThread(TArray<FLinearColor>& OutputData, const FOWL360HookStitchInfo& FrameInfo) {};

	/* Called after an individual tile has been rendered on the render thread */
	virtual void PostTileRender_RenderThread(FRHICommandListImmediate& RHICmdList, FTextureRHIRef TileTarget, const FOWL360HookTileInfo& TileInfo) {};

	/* Only called when `Composite Cameras` is enabled. Called after composite of multiple cameras has occurred */
	virtual void PostComposite_TaskThread(TArray<FLinearColor>& OutputData, const FOWL360HookStitchInfo& FrameInfo) {};

public:
	// C++ Implementations of blueprints
	virtual void Setup_GameThread_Implementation(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline ) {};

	/* Called when the movie pipeline is shutting down */
	virtual void TearDown_GameThread_Implementation(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline ) {};

	/* Called before any tiles have been rendered and after setup */
	virtual void PreRenderCamera_GameThread_Implementation(const int CameraIndex, const FOWLMovieSampleState& SampleState, const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline, const class UOWL360CaptureComponent* CaptureComponent) {};

	/* Called before submitting a render for a frame on the game thread. Can be used to add optional blend materials etc for a given tile / face */
	virtual void ModifyTilePostProcess_GameThread_Implementation(const FPostProcessSettings& CurrentPostProcessSettings, FPostProcessSettings& PostProcessSettings, const FOWL360HookTileInfo& TileInfo, const UMoviePipeline* Pipeline) {};

public:
	// API for MRQ Access to this class
	void AppendAdditionalPasses(TArray<FMoviePipelinePassIdentifier>& RenderPassIdentifiers);

	bool ExecuteAdditionalPasses_TaskThread(
		TWeakPtr<MoviePipeline::IMoviePipelineOutputMerger>& OutputMerger,
		const TSharedRef<FImagePixelDataPayload, ESPMode::ThreadSafe>& SrcPayload,
		const FIntPoint& Resolution,
		int SortOrder);


protected:
	/* Add an additional custom output to the render queue. For EXR files this will be a new layer. Set bSuccess to false in the callback to fail and shutdown the pipeline.
	 * The output resolution of the pixel data must match the resolution parameter exactly.
	 * The callback is executed only on 360 Passes with stitching (ie Stitch Pass and OWL 180 / 360 main pass) and is executed
	 * after the stitch on the task thread. The `TArray64` color array will already have been set to the correct length, but without pixel data
	 *
	 * These should be called from C++ in the `Setup_GameThread_Implementation`
	 */
	void AddRenderPass_8Bit(const FMoviePipelinePassIdentifier& PassIdentifier, const TExecuteAdditionalPassCallback_8Bit& TaskThreadCallback);
	void AddRenderPass_16Bit(const FMoviePipelinePassIdentifier& PassIdentifier, const TExecuteAdditionalPassCallback_16Bit& TaskThreadCallback);
	void AddRenderPass_32Bit(const FMoviePipelinePassIdentifier& PassIdentifier, const TExecuteAdditionalPassCallback_32Bit& TaskThreadCallback);

private:
	TMap<FMoviePipelinePassIdentifier, TExecuteAdditionalPassCallback_8Bit> ExtraPasses_8Bit;
	TMap<FMoviePipelinePassIdentifier, TExecuteAdditionalPassCallback_16Bit> ExtraPasses_16Bit;
	TMap<FMoviePipelinePassIdentifier, TExecuteAdditionalPassCallback_32Bit> ExtraPasses_32Bit;
};

