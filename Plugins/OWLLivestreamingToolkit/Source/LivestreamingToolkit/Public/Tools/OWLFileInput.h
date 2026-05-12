// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "OWLFileInput.generated.h"

USTRUCT(BlueprintType)
struct LIVESTREAMINGTOOLKIT_API FOWLFileInput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OWL File Input")
	FString Path;

	/* if true, stores the absolute path, if false, a path relative to project directory or executable */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OWL File Input")
	bool bAbsolutePath = false;
public:
	FString GetPath() const;
	bool IsEmpty() const;
};


