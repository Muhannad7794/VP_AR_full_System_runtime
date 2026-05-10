// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "MediaSource.h"
#include "MediaPlate.h"

class SOWLMediaPlayerSourceWidget;
class UOWLNDISoundWave;
class AMediaPlate;

UENUM()
enum class EMediaInputLocation : uint8
{
	ML_MediaPlate UMETA(DisplayName = "Unreal Media Plate"),
	ML_Material UMETA(DisplayName = "Material"),
	ML_Plane UMETA(DisplayName = "Plane")
};
ENUM_RANGE_BY_FIRST_AND_LAST(EMediaInputLocation, EMediaInputLocation::ML_Material, EMediaInputLocation::ML_Plane);

UENUM()
enum class EMediaInputType : uint8
{
	MT_Spout UMETA(DisplayName = "Spout"),
	MT_NDI UMETA(DisplayName = "NDI"),
	MT_MonitorCapture UMETA(DisplayName = "Monitor Capture"),
	MT_WindowCapture UMETA(DisplayName = "Window Capture"),
	MT_MediaSource UMETA(DisplayName = "Media Source"),
	/* MT_RTSP UMETA(DisplayName = "RTSP (Real-Time Streaming Protocol)"), */
};
ENUM_RANGE_BY_FIRST_AND_LAST(EMediaInputType, EMediaInputType::MT_Spout, EMediaInputType::MT_MediaSource);

class LIVESTREAMINGTOOLKITEDITOR_API SMediaInputWizard : public SCompoundWidget
{
public:
	SLATE_USER_ARGS(SMediaInputWizard)
	{ }
	SLATE_END_ARGS()

public:

	void Construct( const FArguments& InArgs );

private:
	EVisibility GetCreatorPageVisibility() const;
	EVisibility GetDonePageVisibility() const;
	EVisibility GetMediaInputSourceVisibility() const;

	bool GetCreateButtonEnabled() const;
	FReply OnCreateButtonClicked();
	FReply OnRestartButtonClicked();
	FReply OnRefreshSourceButtonClicked();

	void PopulateOptions();
	void RepopulateMediaLocations();
	bool CanCreateSetup();
	bool CreateSetup();

	const float CameraSpawnDistance = 500.0f;
	FTransform GetEditorCameraSpawnTransform(float DistanceFromCamera) const;

	class AOWLSpoutReceiverManager* FindOrCreateSpoutReceiverManager() const;
	void CreateSpoutReceiver(UTextureRenderTarget2D* TextureTarget) const;
	class AOWLNDIReceiverManager* FindOrCreateNDIReceiverManager() const;
	void CreateNDIReceiver(UTextureRenderTarget2D* TextureTarget, UOWLNDISoundWave* CreatedSoundWave) const;
	class AOWLScreenCapture* CreateScreenCapture(UTextureRenderTarget2D* TextureTarget) const;

	UTextureRenderTarget2D* CreateRenderTarget(FString& OutAssetName);
	UMaterial* CreateMaterialFromRenderTarget(UTextureRenderTarget2D* RenderTarget) const;
	AStaticMeshActor* CreatePlaneActor(UMaterial* Material);
	AMediaPlate* CreateMediaPlate();
	void CreateSoundWave(UOWLNDISoundWave* &InWave, USoundCue* &InCue);
	void UpdatePlaneMeshScale(AActor* MeshActor, UTexture* RenderTarget);
	void SetMeshScale(AActor* MeshActor, FIntPoint Resolution);
	bool SetMediaPlateSource(AMediaPlate* MediaPlate);

	const FString CreatedAssetFolderPath = TEXT("/Game/MediaInputWizard/");
	FString GetUniqueAssetName(const FString& AssetName) const;

	bool IsCreatorPage = true;

	TSharedPtr<SComboBox<TSharedPtr<EMediaInputLocation>>> MediaLocationComboBox;
	FText GetMediaLocationComboBoxSelectedText() const;
	TArray<TSharedPtr<EMediaInputLocation>> MediaLocationOptions;
	TArray<TSharedPtr<EMediaInputLocation>> BaseMediaLocationOptions;

	const FString YesString = FString(TEXT("Yes"));
	const FString NoString = FString(TEXT("No"));

	// Alpha Channel
	TSharedPtr<SComboBox<TSharedPtr<FString>>> AlphaBoolComboBox;
	FText GetAlphaBoolComboBoxSelectedText() const;
	TArray<TSharedPtr<FString>> AlphaBoolOptions;

	// Audio
	TSharedPtr<SComboBox<TSharedPtr<FString>>> AudioBoolComboBox;
	FText GetAudioBoolComboBoxSelectedText() const;
	TArray<TSharedPtr<FString>> AudioBoolOptions;
	TSharedPtr<STextBlock> AudioBoolWarning;

	// Media Input Type
	TSharedPtr<SComboBox<TSharedPtr<EMediaInputType>>> MediaInputTypeComboBox;
	FText GetMediaInputTypeComboBoxSelectedText() const;
	void OnMediaInputTypeComboBoxSelectionChanged(TSharedPtr<EMediaInputType> Item, ESelectInfo::Type Info);
	TArray<TSharedPtr<EMediaInputType>> MediaInputTypeOptions;
	EMediaInputType SelectedMediaInputType = EMediaInputType::MT_Spout;

	// Media Input Source
	TSharedPtr<SComboBox<TSharedPtr<FString>>> MediaInputSourceComboBox;
	FText GetMediaInputSourceComboBoxSelectedText() const;
	TArray<TSharedPtr<FString>> MediaInputSourceOptions;
	TSharedPtr<STextBlock> MediaInputSourceWarning;
	bool bMediaInputSourceWarningActive = false;
	TSharedPtr<SOWLMediaPlayerSourceWidget> MediaPlayerSourceWidget;

	FText GetMediaInputAssetName() const;

	// Done Page
	TSharedPtr<STextBlock> DoneText;
	TSharedPtr<STextBlock> DoneButtonText;

	FTimerHandle TimerHandle_AfterMeshCreated;

	// Media Player
	FString SelectedMediaFilePath = "";
	FText SelectedStreamURL;
	bool bMediaPlayerAutoplay = true;
	bool bMediaPlayerLoop = true;
	bool bMediaPlayerIsFile = true;
	bool bUseAudio = true;

	// Media Framework
	bool SetMediaPlateMediaSource(AMediaPlate* MediaPlate);
	UMediaSource* CreateNDIMediaSource();
	UMediaSource* CreateSpoutMediaSource();
};

