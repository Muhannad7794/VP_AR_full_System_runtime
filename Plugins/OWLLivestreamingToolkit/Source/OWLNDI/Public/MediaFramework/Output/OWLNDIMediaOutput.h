// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "MediaOutput.h"
#include "MediaCapture.h"
#include "Engine/TextureRenderTarget2D.h"
#include "NDIEnums.h"
#include "Sound/SoundSubmix.h"
#include "OWLNDIMediaOutput.generated.h"

/**
 * Output information for an NDI media capture.
 * This class appears in the Media Output dropdown in nDisplay and other UE systems.
 */
UCLASS(BlueprintType, meta = (DisplayName = "OWL NDI Output"))
class OWLNDI_API UOWLNDIMediaOutput : public UMediaOutput
{
	GENERATED_BODY()

public:
	// === LIFECYCLE ===
	UOWLNDIMediaOutput();

	// === PROPERTIES ===
	/** Name of the NDI sender. If empty, will use a default name based on the viewport. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NDI")
	FString NDISenderName = TEXT("UnrealNDI");

	/** 
	 * Video conversion format for NDI transmission.
	 * BGRA: Full quality 32-bit RGBA
	 * UYVY: Compressed 8-bit YUV 4:2:2  
	 * P216: High quality 10-bit YUV 4:2:2 (requires NDI 6.0+)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NDI")
	ENDIVideoConversionFormat VideoConversionFormat = ENDIVideoConversionFormat::NDIVCF_UYVY;

	/** 
	 * Capture audio along with video. Audio will be captured from the main audio device.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NDI")
	bool bCaptureAudio = false;

	/** 
	 * Optional submix to narrow down audio you send to the NDI stream.
	 * If not specified, captures from the main audio output.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NDI", meta = (EditCondition = "bCaptureAudio"))
	TObjectPtr<USoundSubmix> AudioSubmix = nullptr;

	/** 
	 * Priority sender - will take precedence if multiple senders try to use the same name.
	 * Useful when you want this sender to be the "main" sender.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NDI")
	bool bHasPriority = false;

protected:
	// === UMEDIAOUTPUT INTERFACE ===
	virtual FIntPoint GetRequestedSize() const override;
	virtual EPixelFormat GetRequestedPixelFormat() const override;
	virtual EMediaCaptureConversionOperation
	GetConversionOperation(EMediaCaptureSourceType InSourceType) const override;
	virtual UMediaCapture* CreateMediaCaptureImpl() override;
	virtual void BeginDestroy() override;
	virtual bool Validate(FString& OutFailureReason) const override;


#if WITH_EDITOR
	// === EDITOR INTERFACE ===
	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};


