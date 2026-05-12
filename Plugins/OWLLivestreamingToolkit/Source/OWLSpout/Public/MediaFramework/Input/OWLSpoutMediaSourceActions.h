// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#if WITH_EDITOR

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "AssetRegistry/AssetData.h"

/**
 * Implements custom asset actions for UOWLSpoutMediaSource assets.
 */
class OWLSPOUT_API FOWLSpoutMediaSourceActions : public FAssetTypeActions_Base
{
public:
	//~ FAssetTypeActions_Base interface
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FText GetAssetDescription(const struct FAssetData& AssetData) const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
	virtual void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section) override;
    
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

private:
	/** Helper method to open assets with the property editor */
	void OpenWithPropertyEditor(const TArray<UObject*>& InObjects);
};

#endif // WITH_EDITOR

