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
bool UOcclusionInferenceComponent::RunInference(UTextureRenderTarget2D* CameraInput)
{
	if (!ModelInstance.IsValid() || !CameraInput) return false;

	const int32 Width = 640;
	const int32 Height = 360;
	const int32 Channels = 3;
	const int32 NumClasses = 2;

	InputTensor.SetNumUninitialized(1 * Channels * Height * Width);
	OutputTensor.SetNumUninitialized(1 * NumClasses * Height * Width);

	FRenderTarget* RenderTarget = CameraInput->GameThread_GetRenderTargetResource();
	if (!RenderTarget) return false;

	TArray<FColor> RawPixels;
	RenderTarget->ReadPixels(RawPixels);
	if (RawPixels.Num() != Width * Height) return false;

	for (int32 y = 0; y < Height; ++y)
	{
		for (int32 x = 0; x < Width; ++x)
		{
			int32 PixelIndex = y * Width + x;
			FColor Pixel = RawPixels[PixelIndex];
			InputTensor[0 * (Width * Height) + PixelIndex] = ((Pixel.R / 255.0f) - 0.485f) / 0.229f;
			InputTensor[1 * (Width * Height) + PixelIndex] = ((Pixel.G / 255.0f) - 0.456f) / 0.224f;
			InputTensor[2 * (Width * Height) + PixelIndex] = ((Pixel.B / 255.0f) - 0.406f) / 0.225f;
		}
	}

	TArray<UE::NNE::FTensorShape> InputShapes;
	InputShapes.Add(UE::NNE::FTensorShape::Make({ 1, (uint32)Channels, (uint32)Height, (uint32)Width }));
	ModelInstance->SetInputTensorShapes(InputShapes);

	UE::NNE::FTensorBindingCPU InBinding;
	InBinding.Data = InputTensor.GetData();
	InBinding.SizeInBytes = InputTensor.Num() * sizeof(float);

	UE::NNE::FTensorBindingCPU OutBinding;
	OutBinding.Data = OutputTensor.GetData();
	OutBinding.SizeInBytes = OutputTensor.Num() * sizeof(float);

	TArray<UE::NNE::FTensorBindingCPU> InputBindings = { InBinding };
	TArray<UE::NNE::FTensorBindingCPU> OutputBindings = { OutBinding };

	if (ModelInstance->RunSync(InputBindings, OutputBindings) != UE::NNE::IModelInstanceCPU::ERunSyncStatus::Ok)
	{
		UE_LOG(LogTemp, Error, TEXT("Inference Failed!"));
		return false;
	}

	// --- NEW: TRANSLATE MATH INTO A BLACK & WHITE MASK ---

	// 1. Create the blank canvas if it doesn't exist yet
	if (!FinalMask)
	{
		FinalMask = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
		FinalMask->UpdateResource();
	}

	TArray<FColor> MaskPixels;
	MaskPixels.SetNumUninitialized(Width * Height);

	// 2. Read the AI's predicted probabilities
	for (int32 y = 0; y < Height; ++y)
	{
		for (int32 x = 0; x < Width; ++x)
		{
			int32 PixelIndex = y * Width + x;
			float BackgroundProb = OutputTensor[0 * (Width * Height) + PixelIndex];
			float ForegroundProb = OutputTensor[1 * (Width * Height) + PixelIndex];

			// If Foreground > Background, paint white (255). Else paint black (0).
			uint8 ColorVal = (ForegroundProb > BackgroundProb) ? 255 : 0;
			MaskPixels[PixelIndex] = FColor(ColorVal, ColorVal, ColorVal, 255);
		}
	}

	// 3. Lock the GPU memory, push the painted pixels, and unlock it
	void* TextureData = FinalMask->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureData, MaskPixels.GetData(), MaskPixels.Num() * sizeof(FColor));
	FinalMask->GetPlatformData()->Mips[0].BulkData.Unlock();
	FinalMask->UpdateResource();

	return true;
}