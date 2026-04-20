#include "OcclusionInferenceComponent.h"
#include "NNE.h" // The core Neural Network Engine

// Sets default values for this component's properties
UOcclusionInferenceComponent::UOcclusionInferenceComponent()
{
	// Set to false since our BP_OcclusionManager will drive the logic
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UOcclusionInferenceComponent::BeginPlay()
{
	Super::BeginPlay();

	// 1. Check if you actually assigned the ONNX file in the Blueprint
	if (!ModelData)
	{
		UE_LOG(LogTemp, Error, TEXT("Occlusion ModelData is null! Please assign it in the Blueprint Details panel."));
		return;
	}

	// 2. Fetch the ONNX Runtime Engine
	TWeakInterfacePtr<INNERuntimeCPU> Runtime = UE::NNE::GetRuntime<INNERuntimeCPU>(FString("NNERuntimeORTCpu"));
	if (!Runtime.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find NNERuntimeORTCpu. Is the NNE plugin enabled?"));
		return;
	}

	// 3. Create the Model from your specific .onnx ModelData (UPDATED FOR UE 5.3+)
	TSharedPtr<UE::NNE::IModelCPU> Model = Runtime->CreateModelCPU(ModelData);
	if (!Model.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse the Neural Network Model from ModelData."));
		return;
	}

	// 4. Create the Model Instance (UPDATED FOR UE 5.3+)
	ModelInstance = Model->CreateModelInstanceCPU();
	if (!ModelInstance.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create Model Instance."));
		return;
	}

	// 5. Verify the Model Instance is ready for inference
	UE_LOG(LogTemp, Warning, TEXT("SUCCESS! Neural Network Model Initialized and Ready for Inference."));
}

// Our custom AI function (We will add the pixel logic here next)
bool UOcclusionInferenceComponent::RunInference()
{
	return true;
}