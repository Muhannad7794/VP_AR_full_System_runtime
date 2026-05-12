// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "OWLSpoutMediaSourceFactory.generated.h"

/**
 * Implements a factory for UOWLSpoutMediaSource objects.
 * This makes "Spout Media Source" appear in the Content Browser's right-click "Media" menu.
 */
UCLASS()
class LIVESTREAMINGTOOLKITEDITOR_API UOWLSpoutMediaSourceFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
	virtual FText GetDisplayName() const override;
	//~ End UFactory Interface
};

