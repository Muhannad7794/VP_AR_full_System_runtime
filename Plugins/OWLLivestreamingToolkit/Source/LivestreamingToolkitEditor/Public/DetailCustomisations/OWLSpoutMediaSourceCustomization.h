// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

/**
 * Detail customization for UOWLSpoutMediaSource to enable hot-swapping of Spout senders.
 */
class FOWLSpoutMediaSourceCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	//~ IDetailCustomization interface
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	TWeakObjectPtr<class UOWLSpoutMediaSource> MediaSourcePtr;
};

