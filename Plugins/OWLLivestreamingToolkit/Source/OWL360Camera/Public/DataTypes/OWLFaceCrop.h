// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "OWLFaceIndex.h"
#include "OWLFaceCrop.generated.h"

USTRUCT(BlueprintType)
struct OWL360CAMERA_API FOWLFaceCrop
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin=0, UIMax=0.99), Category="Crop")
	float Left = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin=0, UIMax=0.99), Category="Crop")
	float Right = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin=0, UIMax=0.99), Category="Crop")
	float Top = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (UIMin=0, UIMax=0.99), Category="Crop")
	float Bottom = 0;

	bool IsModified() const
	{
		return !(Left == 0 && Right == 0 && Top == 0 && Bottom == 0);
	}

	bool IsValid() const
	{
		if (Left + Right >= 0.99) return false;
		if (Top + Bottom >= 0.99) return false;
		return true;
	}

	FIntRect GetResizedRenderTargetRect(FIntPoint OriginalResolution) const;

	void ModifyProjectionMatrix(FMatrix& InProjection) const;

	FString ToString() const;
};

USTRUCT(BlueprintType)
struct OWL360CAMERA_API FOWLCroppedFaces
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crop")
	FOWLFaceCrop Front;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crop")
	FOWLFaceCrop Back;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crop")
	FOWLFaceCrop Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crop")
	FOWLFaceCrop Right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crop")
	FOWLFaceCrop Up;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crop")
	FOWLFaceCrop Down;

	TArray<FOWLFaceCrop> ToArray() const
	{
		TArray<FOWLFaceCrop> Out;
		Out.AddUninitialized(6);
		Out[(int)EOWL360FaceIndex::Front] = Front;
		Out[(int)EOWL360FaceIndex::Back] = Back;
		Out[(int)EOWL360FaceIndex::Left] = Left;
		Out[(int)EOWL360FaceIndex::Right] = Right;
		Out[(int)EOWL360FaceIndex::Up] = Up;
		Out[(int)EOWL360FaceIndex::Down] = Down;
		return Out;
	}

	bool IsValid() const;

	bool HasCrops() const;

	FOWLFaceCrop operator[](const int Index) const;

	FString ToString() const;
};


