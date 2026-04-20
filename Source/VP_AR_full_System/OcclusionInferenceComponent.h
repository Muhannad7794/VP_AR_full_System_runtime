#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NNEModelData.h"
#include "NNERuntimeCPU.h" 
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

	// The node we will trigger in Blueprints every frame
	UFUNCTION(BlueprintCallable, Category = "AI Inference")
	bool RunInference();

private:
	// CHANGED: UE 5.4 now uses TSharedPtr instead of TUniquePtr!
	TSharedPtr<UE::NNE::IModelInstanceCPU> ModelInstance;

	// The raw float arrays holding the pixels going in, and the mask coming out
	TArray<float> InputTensor;
	TArray<float> OutputTensor;
};