// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "NDIEnums.generated.h"


UENUM(BlueprintType, META = (DisplayName = "NDI Video Conversion Format"))
enum class ENDIVideoConversionFormat : uint8 {
	NDIVCF_BGRA UMETA(DisplayName = "BGRA"),
	NDIVCF_UYVY UMETA(DisplayName = "UYVY"),
};

class OWLNDI_API FOWLNDINames
{
public:
	static inline const FString UseFirstAvailableSenderName = TEXT("Use first available sender");
};


