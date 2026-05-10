// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"

#include "OWLSpoutMediaOutputFactory.generated.h"

/**
 * Factory for creating OWL Spout Media Output assets.
 * This makes the Spout Media Output appear in the Content Browser and dropdowns.
 */
UCLASS(hidecategories=Object)
class LIVESTREAMINGTOOLKITEDITOR_API UOWLSpoutMediaOutputFactory : public UFactory
{
	GENERATED_BODY()

public:
	UOWLSpoutMediaOutputFactory();

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
	virtual FText GetDisplayName() const override;
	virtual FText GetToolTip() const override;
	virtual uint32 GetMenuCategories() const override;
};


