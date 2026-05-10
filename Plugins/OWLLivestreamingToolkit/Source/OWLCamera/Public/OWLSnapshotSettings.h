// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "OWLSnapshotSettings.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSnapshotCompletionDelegate, FString, OutputPath, bool, bSuccess);

UENUM(BlueprintType)
enum class EOWLImageFormat : uint8
{
	PNG UMETA(DisplayName = "PNG"),
	// leaving room for expansion
};

USTRUCT(BlueprintType)
struct OWLCAMERA_API FOWLSnapshotSettings
{
	GENERATED_BODY()

	/** Directory path where snapshots will be saved */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings", meta=(AbsolutePath))
	FDirectoryPath OutputDirectory;

	/** Base filename for the snapshot (without extension) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings")
	FString FileName = "OWLSnapshot";

	/** Whether to automatically append timestamp to filename */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings", meta=(AdvancedDisplay))
	bool bAppendTimestamp = true;

	/** Format to save the snapshot in */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings")
	EOWLImageFormat ImageFormat = EOWLImageFormat::PNG;

	/** Number of warmup frames to render before taking the actual snapshot. Helps resolve temporal effects like clouds, TAA, and Lumen. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings", meta=(ClampMin="0", ClampMax="30", UIMin="0", UIMax="15"), meta=(AdvancedDisplay))
	int32 WarmupFrames = 5;

	/** Internal state tracking - not exposed to UI */
	bool bSnapshotInProgress = false;

	/** If true, shows notification popup when snapshot is taken */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings", meta=(AdvancedDisplay))
	bool bShowNotificationPopup = true;

	/** Duration of notification popup in seconds (0 = persistent until closed) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Snapshot Settings", meta=(EditCondition="bShowNotificationPopup", ClampMin="0.0", ClampMax="10.0"), meta=(AdvancedDisplay))
	float NotificationDuration = 3.0f;


public:
	/* Returns the absolute path of an available file name without overwriting previous */
	bool GetValidSnapshotFilePath(FString& OutputPath) const;

};

