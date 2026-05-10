// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "OWL360CamCapture.generated.h"

UCLASS(hidecategories = (Collision, Attachment, Actor, CameraActor), meta=(DisplayName="OWL 360 Camera"))
class OWL360CAMERA_API AOWL360CameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	AOWL360CameraActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Interp, Category = "Off World Live 360 Camera", meta = (AllowPrivateAccess = "true"))
	class UOWL360CaptureComponent* CaptureComponent = nullptr;
};


