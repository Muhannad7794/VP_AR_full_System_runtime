// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "MoviePipelineImagePassBase.h"
#include "OWL360CameraMoviePipelinePass.h"
#include "OWL360Camera/OWLEyeIndex.h"
#include "OWL360SingleFacePass.generated.h"

class FOWLWriteToDiskMerger;

UCLASS(Blueprintable)
class UOWL360SingleFacePass : public UOWL360CameraMoviePipelinePass
{
	GENERATED_BODY()
public:
	UOWL360SingleFacePass();
	~UOWL360SingleFacePass() = default;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Output")
	EOWL360FaceIndex FaceToRender = EOWL360FaceIndex::Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Output")
	EOWLMRQEyeIndex EyeIndex = EOWLMRQEyeIndex::Left;

	/* When not empty, only render a specific camera from the sequence */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Output")
	FGuid CameraGuid = FGuid();

	/* In addition to the .owli intermediate files, write exr files and accompanying human-readable metadata text files */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Output")
	bool bWriteIntermediateDebugFiles = false;

public:
#if WITH_EDITOR
	virtual FText GetDisplayText() const override { return NSLOCTEXT("MovieRenderPipeline", "DeferredBasePassSetting_DisplayName_OWL360CameraS", "OWL Single Face [Auto]"); }
	virtual FText GetFooterText(UMoviePipelineExecutorJob* InJob) const override;
#endif
	virtual void ValidateStateImpl() override;
	virtual void SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings) override;
	virtual void RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleState) override;
	virtual void SetOutputResolution(UMoviePipelinePrimaryConfig* ExistingConfig) override;

protected:
	virtual bool RendersOnlyOneFace() override { return true; };
	virtual bool UseAndAwaitIntermediateStore() override { return false;};
	virtual int32 GetEyeIndex() override;
	virtual EOWL360FaceIndex GetSingleFaceIndex() override { return FaceToRender; };
	virtual TArray<FGuid> GetCameraGuids() const override;
	virtual void SetupMergers(E360ProjectionType Projection) override;
	virtual TWeakPtr<FOWL360CameraBlenderBase, ESPMode::ThreadSafe> GetBlenderBaseOutputMerger(E360ProjectionType Projection) const override { return nullptr; };
	virtual TWeakPtr<MoviePipeline::IMoviePipelineOutputMerger, ESPMode::ThreadSafe> GetOutputMerger(E360ProjectionType Projection) const override;
	virtual void TeardownImpl() override;
	TSharedPtr<FOWLWriteToDiskMerger> WriteToDiskMerger;
	virtual void PostInitProperties() override;
	virtual bool ShouldRenderOverlay() override final;
	virtual bool PushExpectedOutputFrame(E360ProjectionType Projection, const FOWLMRQOutputDesc& ExpectedOutput) override { return true;};
protected:
	bool DirectoryContainsMatchingIntermediates() const;
	FOWL360Resolution Resolution;
};


