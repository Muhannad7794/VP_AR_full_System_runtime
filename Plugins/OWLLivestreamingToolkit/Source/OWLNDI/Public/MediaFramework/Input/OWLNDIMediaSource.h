// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "MediaSource.h"
#include "OWLNDIReceiverManager.h"
#include "UObject/AssetRegistryTagsContext.h"
#include "OpenColorIOColorSpace.h"
#include "NDIEnums.h"

#if WITH_EDITOR
#include "MediaPlate.h"
#include "MediaPlateComponent.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "MediaPlaylist.h"
#endif

#include "OWLNDIMediaSource.generated.h"

UCLASS(BlueprintType, hideCategories=(Platforms), meta=(MediaIOCustomLayout="NDI"))
class OWLNDI_API UOWLNDIMediaSource : public UMediaSource
{
	GENERATED_BODY()

public:
	UOWLNDIMediaSource();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NDI Connection", AssetRegistrySearchable,
		meta=(GetOptions="GetAvailableNDISourceNames"))
	FString NDISourceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
	EOWLNDIBandwidth Bandwidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
	EOWLNDIColorFormat ColorFormat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color Management")
	bool bConvertGamma;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color Management")
	bool bUseOCIO;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color Management",
		meta=(EditCondition="bUseOCIO", EditConditionHides))
	class UOpenColorIOConfiguration* OCIOConfiguration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color Management",
		meta=(EditCondition="bUseOCIO && OCIOConfiguration != nullptr", EditConditionHides))
	FOpenColorIOColorSpace SourceColorSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color Management",
		meta=(EditCondition="bUseOCIO && OCIOConfiguration != nullptr", EditConditionHides))
	FOpenColorIOColorSpace DestinationColorSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	bool bEnableAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio",
		meta=(EditCondition="bEnableAudio", EditConditionHides))
	EOWLNDIAudioReferenceLevel AudioReferenceLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio",
		meta=(EditCondition="bEnableAudio && AudioReferenceLevel == EOWLNDIAudioReferenceLevel::Manual", EditConditionHides,
			ClampMin="0.1", ClampMax="1.0"))
	float CustomAudioScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Advanced")
	bool bTallyOnProgram;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Advanced")
	bool bTallyOnPreview;

public:
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

	virtual void GetAssetRegistryTags(FAssetRegistryTagsContext Context) const override;
	virtual void BeginDestroy() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
	virtual void PostLoad() override;
#endif

public:
	UFUNCTION(BlueprintCallable, Category = "NDI")
	FString GetNDISourceName() const { return NDISourceName; }
	
	UFUNCTION(BlueprintCallable, Category = "NDI")
	void SetNDISourceName(const FString& InSourceName);
	
	UFUNCTION(BlueprintCallable, Category = "NDI")
	static TArray<struct FNDISource> GetAvailableNDISources();
	
	UFUNCTION(BlueprintCallable, Category = "NDI")
	TArray<FText> GetValidationErrors() const;
	
	UFUNCTION(BlueprintCallable, Category = "Color Management")
	TArray<FString> GetAvailableOCIOColorSpaces() const;
	
	UFUNCTION()
	TArray<FString> GetAvailableNDISourceNames() const;

	UFUNCTION(BlueprintCallable, Category = "NDI")
	bool ChangeNDISource(const FString& NewSourceName, bool bMaintainPlaybackState = true);

private:
	bool ValidateOCIOSettings() const;

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

