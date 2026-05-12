// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "OWL360ResolutionSettings.h"

class FOWL360ResolutionSettingsDetailsCustomization : public IPropertyTypeCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

protected:
	int GetXResolution() const;
	void SetXResolution(const int NewXResolution) ;
	int GetYResolution() const;
	void SetYResolution(const int NewYResolution) ;
	bool GetIsCustomResolution() const;
	void SetIsCustomResolution(const bool IsCustomResolution);
	float GetAspectRatio() const;
	void Notify();

	FOWL360ResolutionSettings* GetPtr() const;

	bool bIsCustomResolution = false;

	TSharedPtr<IPropertyHandle> Property;
};


