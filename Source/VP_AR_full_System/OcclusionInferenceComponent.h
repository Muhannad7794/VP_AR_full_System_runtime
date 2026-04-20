#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NNEModelData.h"
#include "NNERuntimeCPU.h" 
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Texture2D.h" // For creating the final mask texture
#include "OcclusionInferenceComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VP_AR_FULL_SYSTEM_API UOcclusionInferenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOcclusionInferenceComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Inference")
	UNNEModelData* ModelData;

	// The resulting Black and White Mask that we can use in Unreal materials!
	UPROPERTY(BlueprintReadOnly, Category = "AI Inference")
	UTexture2D* FinalMask;

	// Simplified: Now it only needs the camera feed as input
	UFUNCTION(BlueprintCallable, Category = "AI Inference")
	bool RunInference(UTextureRenderTarget2D* CameraInput);

private:
	TSharedPtr<UE::NNE::IModelInstanceCPU> ModelInstance;
	TArray<float> InputTensor;
	TArray<float> OutputTensor;
};