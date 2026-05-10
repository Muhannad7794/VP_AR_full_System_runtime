// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOWLToolkit, Log, All);

class LIVESTREAMINGTOOLKIT_API FLivestreamingToolkitModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	// Hardware encoding related methods
	static bool IgnoreUnrealHardwareEncoding();
	static bool SuggestLoadingHardwareEncodersPlugin();
	static void SetHardwareEncodersPendingRestart();
	static bool IsHardwareEncodersPluginPendingRestart();
    
	// NDI related methods
	static bool IsNDIAvailable();
	static void* GetNDIDLLHandle();
	static int GetNDIVersionFound();

private:
	// Static state variables
	// Hardware encoding related
	static bool bHardwareEncodingModuleLoaded;
	static bool bIsNvidia;
	static bool bForceFfmpegOnlyPipeline;
	static bool bHardwareEncodersPendingRestart;
    
	// NDI related
	static bool bNDIAvailable;
	static void* NDIDLLHandle;
	static int NDIVersionFound;
    
	// Module state tracking
	bool bComposureLoaded = false;
	bool bMovieRenderQueueLoaded = false;

	// Module loading methods
	void LoadMediaOutput();
	void LoadNDI();
	void UnloadNDI();
	void LoadWebcam();
	void LoadComposureOrBindForLoad();
	void LoadComposure();
	void LoadMovieRenderQueue();
    
	// Event handlers
	void OnModulesChanged(FName InModuleName, EModuleChangeReason Reason);
	void OnFEngineLoopInitComplete();
    
	// Delegate handles
	FDelegateHandle OnFEngineLoopInitCompleteHandle;
	FDelegateHandle OnModulesChangedHandle;
	FDelegateHandle OnWorldAddedHandle;
	FDelegateHandle OnWorldDestroyedHandle;
};


