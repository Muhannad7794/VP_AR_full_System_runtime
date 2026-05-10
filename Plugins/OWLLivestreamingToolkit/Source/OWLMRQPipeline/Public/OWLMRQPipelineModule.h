// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#if WITH_EDITOR
#include "ISequencer.h"
#include "ISequencerModule.h"
#endif

DECLARE_LOG_CATEGORY_EXTERN(LogOWLMRQPipeline, Log, All);

class FOWLMRQPipelineModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
#if WITH_EDITOR
	FDelegateHandle OWLMixerTrackHandle;
#endif
};


