// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "MediaOutput.h"
#include "MediaCapture.h"
#include "Engine/TextureRenderTarget2D.h"
#include "OWLSpoutMediaOutput.generated.h"

/**
 * Output information for a Spout media capture.
 * This class appears in the Media Output dropdown in nDisplay and other UE systems.
 */
UCLASS(BlueprintType, meta = (DisplayName = "OWL Spout Output"))
class OWLSPOUT_API UOWLSpoutMediaOutput : public UMediaOutput
{
	GENERATED_BODY()

public:
	// === LIFECYCLE ===
	UOWLSpoutMediaOutput();

	// === PROPERTIES ===
	/** Name of the Spout sender. If empty, will use a default name based on the viewport. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	FString SpoutSenderName;

	/** 
	 * Apply gamma correction to match Unreal's viewport appearance.
	 * Unreal manages files in linear color space but applies linear to sRGB conversion.
	 * Enable this to make your Spout output look the same as the viewport.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	bool bFixGamma;

	/** 
	 * Priority sender - will take precedence if multiple senders try to use the same name.
	 * Useful when you want this sender to be the "main" sender.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	bool bHasPriority;

protected:
	// === UMEDIAOUTPUT INTERFACE ===
	virtual FIntPoint GetRequestedSize() const override;
	virtual EPixelFormat GetRequestedPixelFormat() const override;
	virtual EMediaCaptureConversionOperation
	GetConversionOperation(EMediaCaptureSourceType InSourceType) const override;
	virtual UMediaCapture* CreateMediaCaptureImpl() override;
	virtual void BeginDestroy() override;

#if WITH_EDITOR
	// === EDITOR INTERFACE ===
	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};

