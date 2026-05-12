// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "MediaSource.h"
#include "UObject/AssetRegistryTagsContext.h"

#if WITH_EDITOR
#include "MediaPlate.h"
#include "MediaPlateComponent.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "MediaPlaylist.h"
#endif

#include "OWLSpoutMediaSource.generated.h"

UCLASS(BlueprintType, hideCategories=(Platforms), meta=(MediaIOCustomLayout="Spout"))
class OWLSPOUT_API UOWLSpoutMediaSource : public UMediaSource
{
	GENERATED_BODY()

public:
	UOWLSpoutMediaSource();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout", AssetRegistrySearchable,
		meta=(GetOptions="GetAvailableSpoutSenderNames"))
	FString SpoutSenderName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout")
	bool bFixGamma;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spout", 
		meta=(DisplayName="Upgrade 8bit to 16"))
	bool b8To16Bit;

public:
	//~ UMediaSource interface
	virtual FString GetUrl() const override;
	virtual bool Validate() const override;

	virtual FName GetDesiredPlayerName() const override;
	virtual bool GetMediaOption(const FName& Key, bool DefaultValue) const override;
	virtual double GetMediaOption(const FName& Key, double DefaultValue) const override;
	virtual int64 GetMediaOption(const FName& Key, int64 DefaultValue) const override;
	virtual FString GetMediaOption(const FName& Key, const FString& DefaultValue) const override;
	virtual FText GetMediaOption(const FName& Key, const FText& DefaultValue) const override;
	virtual TSharedPtr<IMediaOptions::FDataContainer, ESPMode::ThreadSafe> GetMediaOption(
		const FName& Key,
		const TSharedPtr<IMediaOptions::FDataContainer, ESPMode::ThreadSafe>& DefaultValue) const override;
	virtual bool HasMediaOption(const FName& Key) const override;

	//~ UObject interface
	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
	virtual void BeginDestroy() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostLoad() override;
#endif

public:
	UFUNCTION(BlueprintCallable, Category = "Spout")
	FString GetSpoutSenderName() const { return SpoutSenderName; }
	
	UFUNCTION(BlueprintCallable, Category = "Spout")
	void SetSpoutSenderName(const FString& InSenderName);
	
	UFUNCTION(BlueprintCallable, Category = "Spout")
	static TArray<FString> GetAvailableSpoutSenders();
	
	UFUNCTION(BlueprintCallable, Category = "Spout")
	TArray<FText> GetValidationErrors() const;
	
	UFUNCTION()
	TArray<FString> GetAvailableSpoutSenderNames() const;

	UFUNCTION(BlueprintCallable, Category = "Spout")
	bool ChangeSpoutSender(const FString& NewSenderName, bool bMaintainPlaybackState = true);

#if WITH_EDITOR
private:
	void NotifyActiveMediaPlates();
	void OnPIEEnded(bool bIsSimulating);
	void OnMapOpened(const FString& Filename, bool bAsTemplate);
	
	UFUNCTION()
	void OnMediaPlayerClosed();
	
	void RegisterMediaPlayerCallbacks();
	void UnregisterMediaPlayerCallbacks();
	void BindPIEDelegates();
	void UnbindPIEDelegates();
	
	FDelegateHandle EndPIEDelegateHandle;
	FDelegateHandle MapOpenedDelegateHandle;
	TSet<TWeakObjectPtr<UMediaPlayer>> RegisteredMediaPlayers;
	bool bIgnoreMediaPlayerCloseEvents = false;
	
	FTimerHandle PendingReopenTimer;
	FTimerHandle PendingFlagResetTimer;
	FTimerHandle PendingDebounceTimer;
	FTimerHandle PendingMapOpenTimer;
#endif
};

