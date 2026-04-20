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

	// 1. Check if the ONNX file is assigned in the Blueprint
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

// The custom AI function
bool UOcclusionInferenceComponent::RunInference(UTextureRenderTarget2D* CameraInput, UTextureRenderTarget2D* MaskOutput)
{
	// 1. Safety Check: Ensure the AI and textures exist
	if (!ModelInstance.IsValid() || !CameraInput || !MaskOutput)
	{
		UE_LOG(LogTemp, Error, TEXT("Inference Failed: Missing Model or Render Targets."));
		return false;
	}

	// 2. Define the dimensions our MobileNetV3 expects
	const int32 Width = 640;
	const int32 Height = 360;
	const int32 Channels = 3;
	const int32 NumClasses = 2; // Output is Class 0 (Background) and Class 1 (Foreground)

	// 3. Resize our C++ arrays to hold the exact amount of pixels
	InputTensor.SetNumUninitialized(1 * Channels * Height * Width);
	OutputTensor.SetNumUninitialized(1 * NumClasses * Height * Width);

	// 4. Read the live camera pixels from the Render Target
	FRenderTarget* RenderTarget = CameraInput->GameThread_GetRenderTargetResource();
	if (!RenderTarget) return false;

	TArray<FColor> RawPixels;
	RenderTarget->ReadPixels(RawPixels);

	if (RawPixels.Num() != Width * Height)
	{
		UE_LOG(LogTemp, Error, TEXT("Camera Input is not exactly 640x360!"));
		return false;
	}

	// 5. Format pixels for PyTorch (NCHW Format & ImageNet Normalization)
	for (int32 y = 0; y < Height; ++y)
	{
		for (int32 x = 0; x < Width; ++x)
		{
			int32 PixelIndex = y * Width + x;
			FColor Pixel = RawPixels[PixelIndex];

			// PyTorch expects Channels First: All Reds, then all Greens, then all Blues
			int32 R_Index = 0 * (Width * Height) + PixelIndex;
			int32 G_Index = 1 * (Width * Height) + PixelIndex;
			int32 B_Index = 2 * (Width * Height) + PixelIndex;

			// Convert 0-255 color to PyTorch's strict floating point math
			InputTensor[R_Index] = ((Pixel.R / 255.0f) - 0.485f) / 0.229f;
			InputTensor[G_Index] = ((Pixel.G / 255.0f) - 0.456f) / 0.224f;
			InputTensor[B_Index] = ((Pixel.B / 255.0f) - 0.406f) / 0.225f;
		}
	}

	// 6. Lock in the Tensor Shape for Unreal Engine 5.4 NNE
	TArray<UE::NNE::FTensorShape> InputShapes;
	InputShapes.Add(UE::NNE::FTensorShape::Make({ 1, (uint32)Channels, (uint32)Height, (uint32)Width }));
	ModelInstance->SetInputTensorShapes(InputShapes);

	// 7. Bind the Memory
	UE::NNE::FTensorBindingCPU InBinding;
	InBinding.Data = InputTensor.GetData();
	InBinding.SizeInBytes = InputTensor.Num() * sizeof(float);

	UE::NNE::FTensorBindingCPU OutBinding;
	OutBinding.Data = OutputTensor.GetData();
	OutBinding.SizeInBytes = OutputTensor.Num() * sizeof(float);

	TArray<UE::NNE::FTensorBindingCPU> InputBindings = { InBinding };
	TArray<UE::NNE::FTensorBindingCPU> OutputBindings = { OutBinding };

	// 8. Run the AI!
	if (ModelInstance->RunSync(InputBindings, OutputBindings) != UE::NNE::IModelInstanceCPU::ERunSyncStatus::Ok)
	{
		UE_LOG(LogTemp, Error, TEXT("Neural Network Execution Failed during RunSync!"));
		return false;
	}

	// If we make it here, the AI successfully processed the image!
	UE_LOG(LogTemp, Warning, TEXT("Frame successfully processed by AI!"));
	return true;
}