// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

/**
 * Detail customization for UOWLNDIMediaSource to enable hot-swapping of NDI sources.
 */
class FOWLNDIMediaSourceCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	TWeakObjectPtr<class UOWLNDIMediaSource> MediaSourcePtr;
};

