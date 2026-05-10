// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Widgets/SWidget.h"
#include "Widgets/Input/SComboBox.h"
#include "IPropertyTypeCustomization.h"
#include "PropertyHandle.h"

class IDetailGroup;

class FNDIActiveSenderNames
{
public:
	static FNDIActiveSenderNames& Get();
	TArray<TSharedPtr<FString>> GetLatestActiveSenderNames(const FString CurrentName, const bool UseFirstActive);

public:
	DECLARE_EVENT_OneParam(FNDIActiveSenderNames, FOnCurrentSenderCheckedDelegate, bool);
	FOnCurrentSenderCheckedDelegate& OnCurrentSenderChecked() { return OnCurrentSenderCheckedDelegate; }
	FOnCurrentSenderCheckedDelegate OnCurrentSenderCheckedDelegate;
public:
	TArray<TSharedPtr<FString>> ActiveSenders;
	const FString UseFirstName = FString("Use first available sender");
};

class FNDIActiveSenderNamesCustomisation : public IPropertyTypeCustomization
{
public:
	FNDIActiveSenderNamesCustomisation();
	~FNDIActiveSenderNamesCustomisation();

	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

protected:
	TSharedRef<SWidget> OnGenerateWidget(TSharedPtr<FString> InItem);
	void OnSelectionChanged(TSharedPtr<FString> NameItem, ESelectInfo::Type SelectInfo);
	TSharedPtr<FString> GetSelectedName() const;
	void SetPropertyWithString(const FString Name);
	FText GetSelectedNameComboBoxContent() const;

protected:
	// Basic property handles
	TSharedPtr<IPropertyHandle> NameProperty;
	TSharedPtr<SComboBox<TSharedPtr<FString>>> NameComboBox;

private:
	// Callback for sender lost status
	void OnCurrentSenderCheckedCallback(bool IsLost);
	bool IsSenderLost = false;

	// Property handles for edit conditions
	TSharedPtr<IPropertyHandle> AudioSyncModeProperty;
	TSharedPtr<IPropertyHandle> AudioDelayMsProperty;
	TSharedPtr<IPropertyHandle> OnProgramProperty;
	TSharedPtr<IPropertyHandle> OnPreviewProperty;
	TSharedPtr<IPropertyHandle> ColorFormatProperty;
	// Audio reference level properties
	TSharedPtr<IPropertyHandle> AudioReferenceLevelProperty;
	TSharedPtr<IPropertyHandle> CustomAudioScaleProperty;

	// OCIO
	TSharedPtr<IPropertyHandle> UseOCIOProperty;
	TSharedPtr<IPropertyHandle> OCIOConfigurationProperty;
	TSharedPtr<IPropertyHandle> SourceColorSpaceProperty;
	TSharedPtr<IPropertyHandle> DestinationColorSpaceProperty;
	TSharedPtr<IPropertyHandle> ApplyGammaBeforeOCIOProperty;

	// Callback for property visibility
	void UpdatePropertyVisibility();
	void OnProgramPropertyChanged();
	void OnPreviewPropertyChanged();

	// Visibility state flags
	bool bShowCustomAudioScale = false;
	bool bShowAudioDelay = false;
	bool bColorSpaceEnabled = true;
	bool bColorRangeFullEnabled = true;

	// OCIO
	bool bShowOCIOConfiguration = false;
	bool bShowOCIOColorSpaces = false;
	bool bShowApplyGammaBeforeOCIO = false;
	TArray<TSharedPtr<FString>> SourceColorSpaceOptions;
	TArray<TSharedPtr<FString>> DestinationColorSpaceOptions;

	TSharedPtr<SComboBox<TSharedPtr<FString>>> SourceColorSpaceComboBox;
	TSharedPtr<SComboBox<TSharedPtr<FString>>> DestinationColorSpaceComboBox;

	void OnOCIOConfigurationChanged();
	void PopulateColorSpaceOptions();
	TSharedRef<SWidget> OnGenerateColorSpaceWidget(TSharedPtr<FString> InItem);
	void OnSourceColorSpaceChanged(TSharedPtr<FString> SelectedItem, ESelectInfo::Type SelectInfo);
	void OnDestinationColorSpaceChanged(TSharedPtr<FString> SelectedItem, ESelectInfo::Type SelectInfo);
	FText GetSelectedSourceColorSpace() const;
	FText GetSelectedDestinationColorSpace() const;
	FReply OnRefreshColorSpacesClicked();
};


