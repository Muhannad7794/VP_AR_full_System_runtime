// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "OWLMRQ360Hooks.h"
#include "CoreMinimal.h"
#include "OWLBurnInHooks.generated.h"

class UUserWidget;
class SVirtualWindow;
class FWidgetRenderer;
class UMoviePipeline;
class UTextureRenderTarget2D;

UENUM(Blueprintable)
enum class EOWLBurnInAlignment : uint8
{
	AL_TopLeft UMETA(DisplayName="Top Left"),
	AL_TopRight UMETA(DisplayName="Top Right"),
	AL_TopCenter UMETA(DisplayName="Top Center"),
	AL_BottomLeft UMETA(DisplayName="Bottom Left"),
	AL_BottomRight UMETA(DisplayName="Bottom Right"),
	AL_BottomCenter UMETA(DisplayName="Bottom Center"),
	AL_Center UMETA(DisplayName="Center"),
	AL_Custom UMETA(DisplayName="Custom"),
};
/**
 * This class enables you to render custom widgets on top
 * of the stitched 360 content. Optionally it can be added
 * as a separate pass with transparency in your EXR output
 */
UCLASS(Blueprintable, BlueprintType, MinimalAPI, Abstract)
class UOWLBurnInHooks :  public UOWLMRQ360Hooks
{
	GENERATED_BODY()
public:
	UOWLBurnInHooks(const FObjectInitializer& ObjectInitializer) { };
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Burn In")
	EOWLBurnInAlignment Alignment = EOWLBurnInAlignment::AL_TopLeft;


	/* Position of the top left of the Burn in UI on the final output */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Burn In", meta=(EditCondition="Alignment == EOWLBurnInAlignment::AL_Custom"))
	FIntPoint TopLeft = {0, 0};

	/* Width of the widget in pixels */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Burn In", meta=(UIMax="3500", ClampMax="3500", UIMin="30", ClampMin="30"))
	int WidgetWidth = 1280;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Burn In", meta=(UIMax="3500", ClampMax="3500", UIMin="30", ClampMin="30"))
	int WidgetHeight = 720;

	/* Do not composite this onto the main color output, instead export it as a layer to EXR etc */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Burn In")
	bool bExportAsSeparatePass = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Burn In")
	TSubclassOf<class UUserWidget> WidgetType;

public:
	UFUNCTION(BlueprintNativeEvent, Category="Burn In")
	void UpdateWidgetPreRender(const FOWLMovieSampleState& SampleState, const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline, const UOWL360CaptureComponent* CaptureComponent);

protected:
	UPROPERTY(Transient)
	UTextureRenderTarget2D* BurnInTarget = nullptr;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Burn In")
	TObjectPtr<UUserWidget> WidgetToRender = nullptr;

public:
	virtual void Setup_GameThread_Implementation(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline) override;
	virtual void PreRenderCamera_GameThread_Implementation(
		const int CameraIndex,
		const FOWLMovieSampleState& SampleState,
		const UOWL360CameraMoviePipelinePass* OWLPass,
		const UMoviePipeline* Pipeline,
		const UOWL360CaptureComponent* CaptureComponent) override;
	virtual void TearDown_GameThread_Implementation(const UOWL360CameraMoviePipelinePass* OWLPass, const UMoviePipeline* Pipeline) override;
	virtual void UpdateWidgetPreRender_Implementation(
		const FOWLMovieSampleState& SampleState,
		const UOWL360CameraMoviePipelinePass* OWLPass,
		const UMoviePipeline* Pipeline,
		const UOWL360CaptureComponent* CaptureComponent) {};

	virtual void PostComposite_TaskThread(TArray<FLinearColor>& OutputData, const FOWL360HookStitchInfo& FrameInfo) override;
public:
	// UOBject API
	virtual void BeginDestroy() override;

protected:
	FIntPoint GetWidgetOffset(const FIntPoint& StitchResolution) const;
	void CleanupWidgetRenderer();
protected:
	// Game thread only
	TSharedPtr<SVirtualWindow> Window;
	FWidgetRenderer* WidgetRenderer = nullptr;
	TSet<int> UIGeneratedForFrame;

	// shared across task thread and game thread
	TMap<int,TSharedPtr<FImage>> ImageStore;
	FCriticalSection ImageStoreMutex;

};


