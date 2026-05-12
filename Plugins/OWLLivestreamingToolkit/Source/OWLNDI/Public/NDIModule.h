// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"

class FNDIMediaPlayerFactory;
class FOWLNDIMediaSourceActions;

DECLARE_LOG_CATEGORY_EXTERN(LogOWLNDI, Log, All);

class FNDIModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static int32 GetDetectedNDIVersion() { return NDIVersionFound; }

private:

	void* NDIDLLHandle = nullptr;

	FDelegateHandle OnEndFrameHandle;

	void OnEndFrame();

	// Static variable to store the detected NDI version (4, 5, or 6)
	static int32 NDIVersionFound;

	/** Media player factory for NDI streams. */  // Fixed comment
	TSharedPtr<FNDIMediaPlayerFactory, ESPMode::ThreadSafe> MediaPlayerFactory;

	/** Asset actions for NDI media sources. */  // Fixed comment
	TSharedPtr<FOWLNDIMediaSourceActions> NDIMediaSourceActions;  // Fixed type
};

