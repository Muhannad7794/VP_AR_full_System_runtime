// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "OWLViewportPreview.generated.h"

class ACameraActor;
class UTextureRenderTarget2D;
class UTexture2D;
class UCameraComponent;
class UMaterial;
class UTexture;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable, DefaultToInstanced)
class OWLCAMERA_API UOWLViewportPreview : public UObject
{
	GENERATED_BODY()

	UOWLViewportPreview(const FObjectInitializer& ObjectInitializer);

public:
	/* Set the viewport camera preview window to show the contents of the render target onto which the camera has rendered */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Preview")
	bool bPreviewOutputInViewport = true;

	/* When rendering is paused, hide render target from the preview, showing the viewport camera output */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Off World Live Capture Settings|Preview", meta=(EditCondition="bPreviewOutputInViewport"))
	bool bHidePreviewWhenPaused = true;

	UPROPERTY()
	UMaterial* PreviewMaterial = nullptr;

	UPROPERTY()
	class UMaterialInstanceDynamic* DynamicMaterialPreview = nullptr;

	UPROPERTY()
	UTexture2D* TransparentSquare = nullptr;

	UPROPERTY()
	struct FPostProcessSettings PreviewPPSettings;

	UPROPERTY()
	UCameraComponent * CameraComponent = nullptr;

	UPROPERTY()
	UTextureRenderTarget2D* Texture = nullptr;


public:
	/* Remove the post process settings from the camera component */
	void SetTexture(class UTextureRenderTarget2D* Texture);
	void SetComponent(UCameraComponent* NewParent);
	void SetDefaultAspectRatio(float NewDefault) { DefaultAspectRatio = NewDefault; }
	void SetAspectRatio(FIntPoint InResolution) const;
	void SetAspectRatio(float NewAspectRatio) const;
	void SetFade(float InFade);
	void Setup();
	void Teardown();
	void SetPaused(bool bNewPaused);
	virtual void BeginDestroy() override;

public:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
public:
	bool bModifyAspectRatio = true;
protected:
	void UpdateAspectRatio(float NewRatio) const;
	void UpdateDynamicMaterialParams() const;
	bool ShouldShowPreview() const;
	bool bPaused = false;
	float DefaultAspectRatio = 1.0;
	float Fade = 1.0;
	bool bPostProcessSet = false;
};


