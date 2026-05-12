// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

UENUM()
enum class EAudioSourceType : uint8
{
	AS_Viewport UMETA(DisplayName = "Yes - Viewport"),
	AS_Submix UMETA(DisplayName = "Yes - Submix"),
	AS_NoAudio UMETA(DisplayName = "No Audio"),
};
ENUM_RANGE_BY_FIRST_AND_LAST(EAudioSourceType, EAudioSourceType::AS_Viewport, EAudioSourceType::AS_NoAudio);

class LIVESTREAMINGTOOLKITEDITOR_API SMediaOutputWizard
	: public SCompoundWidget
{
public:

	SLATE_USER_ARGS(SMediaOutputWizard)
	{ }
	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

private:
	EVisibility GetCreatorPageVisibility() const;
	EVisibility GetDonePageVisibility() const;
	EVisibility GetAlphaWarningVisibility() const;
	EVisibility GetAudioWarningVisibility() const;
	bool GetCreateButtonEnabled() const;
	bool IsCreatorPage = true;
	bool IsMediaSenderSelected = false;
	TSharedPtr<STextBlock> EditorRestartWarning;

	TSharedPtr<STextBlock> OutputSelectionWarning_Alpha;
	TSharedPtr<STextBlock> OutputSelectionWarning_Audio;
	TSharedPtr<STextBlock> DoneText;
	TSharedPtr<STextBlock> DoneButtonText;
	FReply OnCreateButtonClicked();
	FReply OnRestartButtonClicked();

	bool CreateSetup();
	AActor* CreateCaptureActor(FString& UniqueCameraName) const;
	class AOWLSpoutSenderManager* FindOrCreateSpoutSenderManager() const;
	void CreateSpoutSender(UTextureRenderTarget2D* TextureTarget, FString UniqueCameraName);
	class AOWLNDISenderManager* FindOrCreateNDISenderManager() const;
	void CreateNDISender(UTextureRenderTarget2D* TextureTarget, FString UniqueCameraName);
	void CreateMediaOutput(UTextureRenderTarget2D* TextureTarget);
	void CreateVirtualCam(UTextureRenderTarget2D* TextureTarget);

	TSharedPtr<SComboBox<TSharedPtr<FString>>> CameraTypeComboBox;
	TArray<TSharedPtr<FString>> CameraTypeOptions;

	FString YesString = FString(TEXT("Yes"));
	FString NoString = FString(TEXT("No"));
	
	// Alpha Channel
	TSharedPtr<SComboBox<TSharedPtr<FString>>> AlphaBoolComboBox;
	FText GetAlphaBoolComboBoxSelectedText() const;
	void OnAlphaComboBoxSelectionChanged(TSharedPtr<FString> Item, ESelectInfo::Type Info);
	TSharedPtr<STextBlock> AlphaBoolWarning;
	TArray<TSharedPtr<FString>> AlphaBoolOptions;
	bool bNeedAlphaChannel = false;
	bool bRequireProjectSettingsChanges = false;
	
	// Audio
	TSharedPtr<SComboBox<TSharedPtr<EAudioSourceType>>> AudioComboBox;
	FText GetAudioBoolComboBoxSelectedText() const;
	void OnAudioComboBoxSelectionChanged(TSharedPtr<EAudioSourceType> Item, ESelectInfo::Type Info);
	TArray<TSharedPtr<EAudioSourceType>> AudioOptions;
	TSharedPtr<STextBlock> AudioWarning;
	FString GetSubmixText() const;
	EVisibility GetSubmixVisibility() const;
	void OnSubmixChanged(const FAssetData& AssetData);
	USoundSubmix* SelectedSubmix = nullptr;

	// Stream Name
	TSharedPtr<SEditableTextBox> StreamNameBox;
	TSharedPtr<STextBlock> StreamNameWarning;
	void OnStreamNameCommited(const FText& Text, ETextCommit::Type Arg);
	bool IsStreamNameValid() const;
	
	// Media Output Type
	TSharedPtr<SCheckBox> SpoutCheckBox;
	TSharedPtr<SCheckBox> NDICheckBox;
	TSharedPtr<SCheckBox> MediaOutputCheckBox;
	TSharedPtr<SCheckBox> VirtualCamCheckBox;

	FString CinecamName = FString(TEXT("OWL Cinecam"));
	FString Camera360Name = FString(TEXT("OWL 360 Camera"));
	FString ViewportCaptureName = FString(TEXT("OWL Viewport Capture"));

	FText GetCameraTypeComboBoxSelectedText() const;
	void OnCameraTypeComboBoxSelectionChanged(TSharedPtr<FString> Item, ESelectInfo::Type Info);
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

	bool CanCreateSetup() const;
	UTextureRenderTarget2D* GetRenderTarget(AActor* CaptureActor) const;
};

