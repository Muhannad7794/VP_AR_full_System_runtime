// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "PropertyHandle.h"
#include "IDetailChildrenBuilder.h"

class FOWLStereoRenderingConfigCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow,
					IPropertyTypeCustomizationUtils& CustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder,
					  IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> CachedStructPropertyHandle;
	TWeakObjectPtr<UObject> OwnerObject;

	// Helper methods for organization
	void AddModeSpecificProperties(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder,
					  TSharedRef<IPropertyHandle> OutputViewModeHandle, TSharedRef<IPropertyHandle> IsStereoHandle);
	void AddEyeConfigSection(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder,
					  TSharedRef<IPropertyHandle> IsStereoHandle);
	void AddConvergenceSection(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder,
					  TSharedRef<IPropertyHandle> IsStereoHandle);
    
	// New method for pattern offset dropdown menu
	TSharedRef<SWidget> GetPatternOffsetMenuContent(TSharedRef<IPropertyHandle> PatternOffsetHandle);

	// Helper to get property value as byte
	uint8 GetEnumValueAsByte(TSharedRef<IPropertyHandle> EnumHandle) const;
};

