// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/IDelegateInstance.h"
#include "Engine/TextureRenderTarget2D.h"
#include "OWLViewportCapture.generated.h"

class FSceneViewport;
class FWidgetRenderer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnViewportCaptureResized);

UCLASS(hidecategories = (Collision, Attachment, Actor), meta=(DisplayName="OWL Viewport Capture"))
class OWLCAMERA_API AOWLViewportCapture : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	UTextureRenderTarget2D* TextureTarget = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	bool PauseRendering = false;

	/* Capture widgets (Standalone / Packaged / PIE only -- will do nothing in editor) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	bool bCaptureWidgets = false;

	UPROPERTY(BlueprintAssignable, Category = "Off World Live Capture Settings", meta=(Tooltip="Event hook for handling updates when the resolution changes. When streaming from a packaged game viewport, this is useful to only start the media output after the initial resize."))
	FOnViewportCaptureResized OnTargetResized;

	/* Unreal internally works in Linear colorspace then applies sRGB conversion after UI render. Untick this if you require the raw linear values */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings")
	bool bFixGamma = true;

public:
	AOWLViewportCapture();
	virtual void BeginDestroy() override;

protected:
	virtual bool ShouldTickIfViewportsOnly() const override;

public:
	virtual void Tick(float DeltaTime) override;
	void RenderViewportToTexture_RT(FRHICommandListImmediate& RHICmdList, const FSceneViewport* SourceViewport, bool bApplyLinearSrgb);

private:
	void UpdateTextureTargetResolution(FIntPoint ExpectedResolution);

	// Widget capture optimization
	uint32 LastUIStateHash = 0;
	uint32 LastWidgetUpdateFrame = 0;

	FWidgetRenderer* WidgetRenderer = nullptr;
	void ReleaseWidgetRenderer();

private:
	FCriticalSection AccessingCapturingSource;

	UPROPERTY(Transient, meta=(HideInDetailPanel))
	UTextureRenderTarget2D* IntermediateTarget = nullptr;
};


