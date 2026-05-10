// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaCache.h"
#include "IMediaControls.h"
#include "IMediaPlayer.h"
#include "IMediaSamples.h"
#include "IMediaTracks.h"
#include "IMediaView.h"
#include "MediaSampleSource.h"
#include "Containers/UnrealString.h"
#include "HAL/CriticalSection.h"
#include "Math/Color.h"
#include "Math/IntPoint.h"
#include "Math/Quat.h"
#include "Math/Range.h"
#include "Misc/Timespan.h"
#include "Templates/SharedPointer.h"
#include "UObject/ObjectMacros.h"

#include "OWLNDIFinder.h"
#include "OWLNDIReceiverManager.h" // For enums
#include "OpenColorIOColorSpace.h"
#include "OWLWatermarkWriter.h"
#include "AuthCoordinator.h"

// Forward declarations
class FMediaSamples;
class FNDIMediaTracks;
class FNDITextureSample;
class FNDIAudioSample;
class FOWLNDIReceiver;
class UTextureRenderTarget2D;
class UOpenColorIOConfiguration;
class IMediaEventSink;
class IMediaOptions;
struct FMediaPlayerOptions;

/**
 * Implements a media player for NDI (Network Device Interface) streams.
 * 
 * This player provides real-time video and audio streaming capabilities over IP networks
 * using the NDI protocol. It supports various video formats including SDR and HDR content,
 * with optional OCIO color management.
 */
class OWLNDI_API FOWLNDIMediaPlayer
	: public IMediaPlayer
	, public IMediaControls
	, public IMediaSamples  
	, public IMediaTracks
	, public IMediaView
	, public IMediaCache
{
public:
	/**
	 * Create and initialize a new instance.
	 *
	 * @param InEventSink The object that receives media events from this player.
	 */
	FOWLNDIMediaPlayer(IMediaEventSink& InEventSink);

	/** Virtual destructor. */
	virtual ~FOWLNDIMediaPlayer();

public:

	//~ IMediaPlayer interface

	virtual void Close() override;
	virtual IMediaCache& GetCache() override { return *this; }
	virtual IMediaControls& GetControls() override { return *this; }
	virtual IMediaSamples& GetSamples() override { return *this; }
	virtual IMediaTracks& GetTracks() override { return *this; }
	virtual IMediaView& GetView() override { return *this; }
	virtual FString GetInfo() const override;
	virtual FGuid GetPlayerPluginGUID() const override;
	virtual FString GetStats() const override;
	virtual FString GetUrl() const override;
	virtual bool Open(const FString& Url, const IMediaOptions* Options) override;
	virtual bool Open(const FString& Url, const IMediaOptions* Options, const FMediaPlayerOptions* PlayerOptions) override;
	virtual bool Open(const TSharedRef<FArchive, ESPMode::ThreadSafe>& Archive, const FString& OriginalUrl, const IMediaOptions* Options) override;
	virtual void TickFetch(FTimespan DeltaTime, FTimespan Timecode) override;
	virtual void TickInput(FTimespan DeltaTime, FTimespan Timecode) override;
	virtual FText GetMediaName() const override;

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

	//~ IMediaSamples interface

	virtual bool FetchAudio(TRange<FTimespan> TimeRange, TSharedPtr<IMediaAudioSample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchCaption(TRange<FTimespan> TimeRange, TSharedPtr<IMediaOverlaySample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchMetadata(TRange<FTimespan> TimeRange, TSharedPtr<IMediaBinarySample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchSubtitle(TRange<FTimespan> TimeRange, TSharedPtr<IMediaOverlaySample, ESPMode::ThreadSafe>& OutSample) override;
	virtual bool FetchVideo(TRange<FTimespan> TimeRange, TSharedPtr<IMediaTextureSample, ESPMode::ThreadSafe>& OutSample) override;
	virtual void FlushSamples() override;
	virtual bool PeekVideoSampleTime(FMediaTimeStamp& TimeStamp) override;

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

	//~ IMediaView interface

	virtual bool GetViewField(float& OutHorizontal, float& OutVertical) const override;
	virtual bool GetViewOrientation(FQuat& OutOrientation) const override;
	virtual bool SetViewField(float Horizontal, float Vertical, bool Absolute) override;
	virtual bool SetViewOrientation(const FQuat& Orientation, bool Absolute) override;

	//~ IMediaCache interface

	virtual bool QueryCacheState(EMediaCacheState State, TRangeSet<FTimespan>& OutTimeRanges) const override;
	virtual int32 GetSampleCount(EMediaCacheState State) const override;

public:

	//~ NDI-specific interface

	/** Get the name of the currently connected NDI source. */
	FString GetCurrentSourceName() const;

	/** Get all available NDI sources on the network. */
	TArray<FNDISource> GetAvailableSources() const;

	/** Set the active NDI source by name. */
	bool SetActiveSource(const FString& SourceName);

	/** Check if we're currently receiving data from an NDI source. */
	bool IsReceiving() const;

	/** Get current bandwidth usage in Mbps. */
	float GetCurrentBandwidth() const;

	/** Get frame drop rate as a percentage. */
	float GetFrameDropRate() const;

	/** Check if the current source supports PTZ camera control. */
	bool IsPTZSupported() const;

	/** Control PTZ pan and tilt (-1.0 to 1.0 for each axis). */
	bool PTZPanTilt(float Pan, float Tilt);

	/** Control PTZ zoom (0.0 to 1.0). */
	bool PTZZoom(float Zoom);

	/** Set tally lights on the source. */
	bool SetTallyState(bool bOnProgram, bool bOnPreview);

private:

	//~ Internal helper methods

	bool InitializeNDIReceiver(const FString& SourceName);

	void ShutdownNDIReceiver();

	void ProcessVideoFrame();

	void ProcessAudioFrame();

	TSharedPtr<FNDITextureSample, ESPMode::ThreadSafe> CreateVideoSample();

	TSharedPtr<FNDIAudioSample, ESPMode::ThreadSafe> CreateAudioSample();

	UTextureRenderTarget2D* GetOrCreateRenderTarget();

	void UpdateStreamFormat();

	bool DetermineSRGBFromNDIFormat(EOWLTexturePixelFormat NDIFormat) const;

private:

	//~ Core media player state

	/** The media event handler. */
	IMediaEventSink& EventSink;

	/** Current playback state. */
	EMediaState CurrentState;

	/** Current media status. */
	EMediaStatus CurrentStatus;

	/** Current playback time. */
	FTimespan CurrentTime;

	/** Duration of the media (infinite for live streams). */
	FTimespan CurrentDuration;

	/** Current playback rate. */
	float PlaybackRate;

	/** The media URL that was opened. */
	FString MediaUrl;

	//~ NDI-specific state

	/** The NDI receiver instance. */
	TSharedPtr<FOWLNDIReceiver, ESPMode::ThreadSafe> NDIReceiver;

	/** Critical section for NDI operations. */
	mutable FCriticalSection NDILock;

	/** Currently connected NDI source name. */
	FString CurrentSourceName;

	/** Whether to use the first available source if none specified. */
	bool bUseFirstAvailableSource;

	//~ Video processing

	/** 
	 * Render target for video processing.
	 * This is needed as an intermediate buffer for NDI video processing.
	 * NOTE: This is the only dummy object we still need. The NDI receiver architecture
	 * requires a render target to process video data into.
	 */
	UPROPERTY() // Kept UPROPERTY since we need GC tracking, but it's now safely managed
	UTextureRenderTarget2D* DummyRenderTarget;

	/** Current frame dimensions. */
	FIntPoint FrameDimensions;

	/** Current frame rate. */
	float FrameRate;

	/** Current pixel format. */
	EPixelFormat PixelFormat;

	/** Whether to convert gamma. */
	bool bConvertGamma;

	//~ Audio processing (NO MORE DUMMY SOUND WAVE! ?)

	/** Current audio sample rate. */
	int32 AudioSampleRate;

	/** Current number of audio channels. */
	int32 AudioChannels;

	/** Whether audio is enabled. */
	bool bAudioEnabled;

	/** Audio reference level for professional audio standards. */
	EOWLNDIAudioReferenceLevel AudioReferenceLevel;

	/** Custom audio scaling factor. */
	float CustomAudioScale;

	//~ OCIO color management

	/** Whether to use OCIO color conversion. */
	bool bUseOCIO;

	/** OCIO configuration to use. */
	UOpenColorIOConfiguration* OCIOConfiguration;

	/** Source color space for OCIO conversion. */
	FOpenColorIOColorSpace SourceColorSpace;

	/** Destination color space for OCIO conversion. */
	FOpenColorIOColorSpace DestinationColorSpace;

	//~ NDI settings

	/** NDI bandwidth setting. */
	EOWLNDIBandwidth Bandwidth;

	/** NDI color format preference. */
	EOWLNDIColorFormat ColorFormat;

	//~ Performance tracking

	/** Number of video frames received. */
	uint32 VideoFramesReceived;

	/** Number of audio frames received. */
	uint32 AudioFramesReceived;

	/** Number of frames dropped. */
	uint32 FramesDropped;

	/** Time of last received frame. */
	FDateTime LastFrameTime;

	//~ Media Framework integration

	/** The media sample collection. */
	TSharedPtr<FMediaSamples, ESPMode::ThreadSafe> Samples;

	/** The media track collection. */
	TSharedPtr<FNDIMediaTracks, ESPMode::ThreadSafe> Tracks;

	/** Cached world context for watermarking (obtained during GetOrCreateRenderTarget) */
	UPROPERTY()
	UWorld* CachedWorld;
	
	void ApplyWatermarkIfNeeded(UTextureRenderTarget2D* RenderTarget);
};

