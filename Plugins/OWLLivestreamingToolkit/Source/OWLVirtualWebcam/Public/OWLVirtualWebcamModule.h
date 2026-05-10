// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOWLVirtualWebcam, Log, All);

class FOWLVirtualWebcamModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
#if WITH_EDITOR
	void OnLevelActorDeleted(AActor* DeletedActor);
	FDelegateHandle OnActorDeletedHandle;
#endif
	void* DLLHandle = nullptr;
};

class VirtualWebcamModuleStatus
{
public:
	static bool bIsInstalled;
	static bool Installed()
	{
		return bIsInstalled;
	}
};


