#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NNEModelData.h"
#include "NNERuntimeCPU.h" 
#include "Engine/TextureRenderTarget2D.h" // Needed to read camera pixels
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
	// Drag and drop your imported ONNX Model Data here in the Unreal Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Inference")
	UNNEModelData* ModelData;

	// UPDATED: Now takes the live camera feed and a blank texture to draw the mask onto
	UFUNCTION(BlueprintCallable, Category = "AI Inference")
	bool RunInference(UTextureRenderTarget2D* CameraInput, UTextureRenderTarget2D* MaskOutput);

private:
	// The actual initialized neural network inside the engine
	TSharedPtr<UE::NNE::IModelInstanceCPU> ModelInstance;

	// The raw float arrays holding the pixels going in, and the mask coming out
	TArray<float> InputTensor;
	TArray<float> OutputTensor;
};