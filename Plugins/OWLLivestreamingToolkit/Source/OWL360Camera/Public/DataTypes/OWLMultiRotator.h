// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "OWLMultiRotator.generated.h"

/* This struct exists so that these values can be keyed in the sequencer.
 * The source of truth should be the individual `FRotator` and the array
 * exists purely for the user to manipulate. When updated
 */
USTRUCT(BlueprintType)
struct OWL360CAMERA_API FOWLMultiRotator
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_0_Pitch = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_0_Yaw = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_0_Roll = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_1_Pitch = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_1_Yaw = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_1_Roll = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_2_Pitch = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_2_Yaw = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_2_Roll = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_3_Pitch = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_3_Yaw = 0;

	UPROPERTY(BlueprintReadWrite, Interp, Category="Rotation")
	float Rotation_3_Roll = 0;

public:
	FQuat ToQuat(bool bAscending);

};

