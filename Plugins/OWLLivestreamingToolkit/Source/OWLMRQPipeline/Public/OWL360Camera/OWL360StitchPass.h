// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "MoviePipelineImagePassBase.h"
#include "OWL360CameraMoviePipelinePass.h"
#include "OWL360StitchPass.generated.h"

class IOWL360IntermediateSamplerGetter;

UCLASS(Blueprintable)
class UOWL360StitchPass : public UOWL360CameraMoviePipelinePass
{
	GENERATED_BODY()
public:
	UOWL360StitchPass();

public:
	/* Delete the intermediate files once stitching has completed */
	UPROPERTY(EditAnywhere, Category="Stitching")
	bool bDeleteIntermediatesAfterStitch = false;
	/* Maximum number of stitches to run on separate threads concurrently. Lower this number if you run into RAM issues */
	UPROPERTY(EditAnywhere, Category="Stitching|Advanced", meta=(UIMin=0,UIMax=20, ClampMin=0, ClampMax=20))
	int MaxConcurrentStitches = 2;


public:
	virtual TUniquePtr<IOWL360IntermediateSamplerGetter> GetSamplerGetter() override;

public:
	virtual void SetupImpl(const MoviePipeline::FMoviePipelineRenderPassInitSettings& InPassInitSettings) override;
	virtual void RenderSample_GameThreadImpl(const FMoviePipelineRenderPassMetrics& InSampleState) override;
	virtual void SetupJobController() override;

public:
#if WITH_EDITOR
	virtual FText GetDisplayText() const override { return NSLOCTEXT("MovieRenderPipeline", "DeferredBasePassSetting_DisplayName_OWL360CameraS", "OWL Stitch [Auto]"); }
#endif
protected:
	void TriggerMergers(
		const FOWL360CameraPassFacePayload& Payload,
		const FMoviePipelineRenderPassMetrics& InSampleState,
		const FMoviePipelinePassIdentifier& LayerPassIdentifier,
		const FOWL360Resolution& Resolution,
		const bool& bIsSecondaryPass);
};

