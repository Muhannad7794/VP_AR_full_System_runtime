// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Widgets/Notifications/SNotificationList.h"

class SNotificationItem;

class OWLCAMERA_API FOWLSnapshotNotifier
{
public:
	static void ShowNotification(FString FullPath, float Duration = 5.0f);
	
	static void HideNotification();

private:
	/** Active notification item. Tracked to allow programmatic dismissal. */
	static TSharedPtr<SNotificationItem> ActiveNotification;
};

