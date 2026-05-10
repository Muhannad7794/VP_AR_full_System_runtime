// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaTracks.h"
#include "Containers/Array.h"
#include "Internationalization/Text.h"
#include "Math/IntPoint.h"
#include "OWLNDIReceiverManager.h"

/**
 * Implements media track collection for NDI streams.
 * 
 * NDI streams can have both video and audio tracks, so this implementation
 * provides comprehensive track management for live NDI streaming with
 * support for various formats and configurations.
 */
class FNDIMediaTracks : public IMediaTracks
{
public:
	/** Constructor. */
	FNDIMediaTracks();

	/** Destructor. */
	virtual ~FNDIMediaTracks();

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
	/**
	 * Initialize tracks with the given parameters.
	 * 
	 * @param InVideoDimensions Video frame dimensions.
	 * @param InVideoFrameRate Video frame rate.
	 * @param InVideoTypeName Video format type name (e.g., "BGRA8", "P216").
	 * @param InAudioSampleRate Audio sample rate in Hz.
	 * @param InAudioChannels Number of audio channels.
	 * @param InHasVideo Whether video track is available.
	 * @param InHasAudio Whether audio track is available.
	 */
	void Initialize(
		const FIntPoint& InVideoDimensions,
		float InVideoFrameRate,
		const FString& InVideoTypeName,
		int32 InAudioSampleRate,
		int32 InAudioChannels,
		bool InHasVideo = true,
		bool InHasAudio = true
	);

	/**
	 * Clear all tracks.
	 */
	void Reset();

	/**
	 * Update video track format (called when NDI source changes).
	 * 
	 * @param InDimensions New video frame dimensions.
	 * @param InFrameRate New video frame rate.
	 * @param InTypeName New video format type name.
	 */
	void UpdateVideoFormat(const FIntPoint& InDimensions, float InFrameRate, const FString& InTypeName = TEXT(""));

	/**
	 * Update audio track format (called when NDI source changes).
	 * 
	 * @param InSampleRate New audio sample rate.
	 * @param InChannels New number of audio channels.
	 */
	void UpdateAudioFormat(int32 InSampleRate, int32 InChannels);

	/**
	 * Set whether video track is available.
	 */
	void SetVideoAvailable(bool bAvailable);

	/**
	 * Set whether audio track is available.
	 */
	void SetAudioAvailable(bool bAvailable);

	/**
	 * Check if video track is available.
	 */
	bool IsVideoAvailable() const { return bHasVideo; }

	/**
	 * Check if audio track is available.
	 */
	bool IsAudioAvailable() const { return bHasAudio; }

private:
	/** Video track format information. */
	FMediaVideoTrackFormat VideoTrackFormat;

	/** Audio track format information. */
	FMediaAudioTrackFormat AudioTrackFormat;

	/** Whether video track is currently selected. */
	bool bVideoTrackSelected;

	/** Whether audio track is currently selected. */
	bool bAudioTrackSelected;

	/** Whether tracks have been initialized. */
	bool bInitialized;

	/** Whether video track is available. */
	bool bHasVideo;

	/** Whether audio track is available. */
	bool bHasAudio;

	/** Helper method to create default video track format. */
	void CreateDefaultVideoFormat();

	/** Helper method to create default audio track format. */
	void CreateDefaultAudioFormat();
};

