// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaPlayer.h"
#include "IMediaControls.h"
#include "IMediaSamples.h"
#include "IMediaTracks.h"
#include "IMediaView.h"
#include "IMediaCache.h"
#include "HAL/CriticalSection.h"
#include "Containers/Queue.h"
#include "MediaSamples.h"
#include "Math/Quat.h"
#include "OWLWatermarkWriter.h"
#include "AuthCoordinator.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"

class FMediaSamples;
class IMediaEventSink;
class IMediaOptions;
class FSpoutTextureSample;
class FSpoutTextureSamplePool;
class FSpoutMediaTracks;

/**
 * Implements a media player for Spout streams.
 * 
 * This player receives live video frames from Spout senders and integrates them
 * into Unreal's Media Framework, making them available to Media Textures,
 * UMG widgets, and other media consumers.
 */
class FOWLSpoutMediaPlayer 
	: public IMediaPlayer
	, protected IMediaControls
	, protected IMediaSamples  
	, protected IMediaTracks
	, protected IMediaView
	, protected IMediaCache
{
public:
	FOWLSpoutMediaPlayer(IMediaEventSink& InEventSink);

	/** Virtual destructor. */
	virtual ~FOWLSpoutMediaPlayer();

public:
	//~ IMediaPlayer interface
	virtual void Close() override;
	virtual IMediaCache& GetCache() override { return *this; }
	virtual IMediaControls& GetControls() override { return *this; }
	virtual FString GetInfo() const override;
	virtual FGuid GetPlayerPluginGUID() const override;
	virtual IMediaSamples& GetSamples() override { return *this; }
	virtual FString GetStats() const override;
	virtual IMediaTracks& GetTracks() override { return *this; }
	virtual FString GetUrl() const override;
	virtual IMediaView& GetView() override { return *this; }

	virtual bool Open(const FString& Url, const IMediaOptions* Options) override;
	virtual bool Open(const FString& Url, const IMediaOptions* Options, const FMediaPlayerOptions* PlayerOptions) override;
	virtual bool Open(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Archive, const FString& OriginalUrl, const IMediaOptions* Options) override;

	virtual void TickFetch(FTimespan DeltaTime, FTimespan Timecode) override;
	virtual void TickInput(FTimespan DeltaTime, FTimespan Timecode) override;

	virtual FText GetMediaName() const override;

public:
	//~ IMediaControls interface
	virtual bool CanControl(EMediaControl Control) const override;
	virtual FTimespan GetDuration() const override;
	virtual float GetRate() const override;
	virtual EMediaState GetState() const override;
	virtual EMediaStatus GetStatus() const override;
	virtual TRangeSet<float> GetSupportedRates(EMediaRateThinning Thinning) const override;
	virtual FTimespan GetTime() const override;
	virtual bool IsLooping() const override;
	virtual bool Seek(const FTimespan& Time) override;
	virtual bool SetLooping(bool Looping) override;
	virtual bool SetRate(float Rate) override;

public:
	//~ IMediaSamples interface
	virtual bool FetchAudio(TRange<FTimespan> TimeRange, TSharedPtr<IMediaAudioSample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchCaption(TRange<FTimespan> TimeRange, TSharedPtr<IMediaOverlaySample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchMetadata(TRange<FTimespan> TimeRange, TSharedPtr<IMediaBinarySample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchSubtitle(TRange<FTimespan> TimeRange, TSharedPtr<IMediaOverlaySample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchVideo(TRange<FTimespan> TimeRange, TSharedPtr<IMediaTextureSample, ESPMode::ThreadSafe>& OutSample) override;
	virtual void FlushSamples() override;
	virtual bool PeekVideoSampleTime(FMediaTimeStamp& TimeStamp) override;

public:
	//~ IMediaTracks interface
	virtual bool GetAudioTrackFormat(int32 TrackIndex, int32 FormatIndex, FMediaAudioTrackFormat& OutFormat) const override;
	virtual int32 GetNumTracks(EMediaTrackType TrackType) const override;
	virtual int32 GetNumTrackFormats(EMediaTrackType TrackType, int32 TrackIndex) const override;
	virtual int32 GetSelectedTrack(EMediaTrackType TrackType) const override;
	virtual FText GetTrackDisplayName(EMediaTrackType TrackType, int32 TrackIndex) const override;
	virtual int32 GetTrackFormat(EMediaTrackType TrackType, int32 TrackIndex) const override;
	virtual FString GetTrackLanguage(EMediaTrackType TrackType, int32 TrackIndex) const override;
	virtual FString GetTrackName(EMediaTrackType TrackType, int32 TrackIndex) const override;
	virtual bool GetVideoTrackFormat(int32 TrackIndex, int32 FormatIndex, FMediaVideoTrackFormat& OutFormat) const override;
	virtual bool SelectTrack(EMediaTrackType TrackType, int32 TrackIndex) override;
	virtual bool SetTrackFormat(EMediaTrackType TrackType, int32 TrackIndex, int32 FormatIndex) override;

public:
	//~ IMediaView interface
	virtual bool GetViewField(float& OutHorizontal, float& OutVertical) const override;
	virtual bool GetViewOrientation(FQuat& OutOrientation) const override;
	virtual bool SetViewField(float Horizontal, float Vertical, bool Absolute) override;
	virtual bool SetViewOrientation(const FQuat& Orientation, bool Absolute) override;

public:
	//~ IMediaCache interface
	virtual bool QueryCacheState(EMediaCacheState State, TRangeSet<FTimespan>& OutTimeRanges) const override;
	virtual int32 GetSampleCount(EMediaCacheState State) const override;

public:
	//~ Spout-specific interface
	FString GetCurrentSenderName() const;
	
	TArray<FString> GetAvailableSenders() const;
	
	bool SetActiveSender(const FString& SenderName);
	
	bool IsReceiving() const;

private:
	//~ Internal helper methods
	bool InitializeSpoutReceiver(const FString& SenderName);

	void ShutdownSpoutReceiver();

	void ProcessSpoutFrame();

	/** Create texture sample from current Spout frame. */
	TSharedPtr<FSpoutTextureSample, ESPMode::ThreadSafe> CreateVideoSample();

	UTextureRenderTarget2D* GetOrCreateRenderTarget();
	
	void ApplyWatermarkIfNeeded(UTextureRenderTarget2D* RenderTarget);

	/** Get proper world context for operations requiring it. */
	UWorld* GetWorldContext() const;

private:
	//~ Core media player state

	IMediaEventSink& EventSink;

	EMediaState CurrentState;

	EMediaStatus CurrentStatus;

	FTimespan CurrentTime;

	/** The duration of the currently loaded media (infinite for live streams). */
	FTimespan CurrentDuration;

	/** Current playback rate (always 1.0 for live streams). */
	float PlaybackRate;

	FString MediaUrl;

	//~ Spout-specific state

	FString CurrentSenderName;

	bool bUseFirstAvailableSender;

	bool bFixGamma;

	bool b8To16Bit;

	TSharedPtr<class FOWLSpoutReceiver> SpoutReceiver;

	mutable FCriticalSection SpoutLock;
	
	FIntPoint FrameDimensions;
	float FrameRate;
	EPixelFormat PixelFormat;
	
	uint32 FramesReceived;
	uint32 FramesDropped;
	FDateTime LastFrameTime;

	//~ Media Framework integration

	/** Media sample collection. */
	TSharedPtr<FMediaSamples, ESPMode::ThreadSafe> Samples;

	/** Track collection. */
	TSharedPtr<FSpoutMediaTracks, ESPMode::ThreadSafe> Tracks;
	
	/** Cached world context for watermarking. */
	UPROPERTY()
	UWorld* CachedWorld;

	/** 
	* Render target for video processing (created lazily with proper world context).
	* This is needed as an intermediate buffer for Spout video processing, matching NDI pattern.
	*/
	UPROPERTY()
	UTextureRenderTarget2D* DummyRenderTarget;
};

