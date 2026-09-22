#pragma once
#include "Subsystems/EngineSubsystem.h"
#include "ZEDLiveLinkSyncSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FZEDFrameArrived);

UCLASS()
class ZEDLIVELINK_API UZEDLiveLinkSyncSubsystem : public UEngineSubsystem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, Category = "ZED LiveLink Events")
    FZEDFrameArrived OnZEDFrameArrived;
};