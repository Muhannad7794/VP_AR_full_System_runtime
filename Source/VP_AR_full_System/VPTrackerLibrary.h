#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VPTrackerLibrary.generated.h"

UCLASS()
class UVPTrackerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// This node will find the ZED plugin and force the network port open
	UFUNCTION(BlueprintCallable, Category = "VP Tracking")
	static void ForceStartZEDLiveLink(FString ConnectionString = TEXT("230.0.0.1:6666"));
};