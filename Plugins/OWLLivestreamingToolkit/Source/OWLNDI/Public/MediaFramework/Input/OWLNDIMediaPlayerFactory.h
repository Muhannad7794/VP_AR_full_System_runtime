// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaPlayerFactory.h"
#include "Containers/Array.h"
#include "Containers/UnrealString.h"
#include "UObject/NameTypes.h"

class IMediaPlayer;

/**
 * Implements a factory for FOWLNDIMediaPlayer objects.
 * 
 * This factory registers with Unreal's Media Framework to handle NDI URLs
 * and creates appropriate media player instances for NDI streams.
 */
class FNDIMediaPlayerFactory : public IMediaPlayerFactory
{
public:
	//~ IMediaPlayerFactory interface
	
	virtual bool CanPlayUrl(const FString& Url, const IMediaOptions* Options, TArray<FText>* OutWarnings, TArray<FText>* OutErrors) const override;
	virtual TSharedPtr<IMediaPlayer, ESPMode::ThreadSafe> CreatePlayer(IMediaEventSink& EventSink) override;
	virtual FText GetDisplayName() const override;
	virtual FName GetPlayerName() const override;
	virtual FGuid GetPlayerPluginGUID() const override;
	virtual const TArray<FString>& GetSupportedPlatforms() const override;
	virtual bool SupportsFeature(EMediaFeature Feature) const override;

private:
	/** List of platforms that this factory supports. */
	TArray<FString> SupportedPlatforms;

	/** List of supported URI schemes. */
	TArray<FString> SupportedUriSchemes;
};

