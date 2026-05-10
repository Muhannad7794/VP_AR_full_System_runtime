// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "CineCameraActor.h"
#include "OWLCineCamCapture.generated.h"

UCLASS(hidecategories = (Collision, Attachment, Actor), meta=(DisplayName="OWL Cine Camera"))
class OWLCAMERA_API AOWLCineCameraActor : public ACineCameraActor
{
	GENERATED_BODY()

public:
	AOWLCineCameraActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Category = OffWorldLive, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UOWLCaptureComponent* CaptureComponent = nullptr;
};


