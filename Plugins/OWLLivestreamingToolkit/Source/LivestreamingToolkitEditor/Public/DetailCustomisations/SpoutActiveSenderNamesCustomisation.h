// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Widgets/SWidget.h"
#include "Widgets/Input/SComboBox.h"
#include "IPropertyTypeCustomization.h"
#include "OWLSpoutReceiver.h"
#include "PropertyHandle.h"

class IDetailGroup;

class FSpoutActiveSenderNames
{
public:
	static FSpoutActiveSenderNames& Get();
	TArray<TSharedPtr<FString>> GetLatestActiveSenderNames(const FString CurrentName, const bool UseFirstActive);

public:
	DECLARE_EVENT_OneParam(FActiveSenderNames, FOnCurrentSenderCheckedDelegate, bool);
	FOnCurrentSenderCheckedDelegate& OnCurrentSenderChecked() { return OnCurrentSenderCheckedDelegate; }
	FOnCurrentSenderCheckedDelegate OnCurrentSenderCheckedDelegate;
public:
	TArray<TSharedPtr<FString>> ActiveSenders;
	const FString& UseFirstName = FOWLSpoutNames::UseFirstAvailableSenderName;
};

class FSpoutActiveSenderNamesCustomisation : public IPropertyTypeCustomization
{
public:
	FSpoutActiveSenderNamesCustomisation();
	~FSpoutActiveSenderNamesCustomisation();

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
	TSharedPtr<IPropertyHandle> NameProperty;
	TSharedPtr<SComboBox<TSharedPtr<FString>>> NameComboBox;

private:
	void OnCurrentSenderCheckedCallback(bool IsLost);
	bool IsSenderLost = false;
};


