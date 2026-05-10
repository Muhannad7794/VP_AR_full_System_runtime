// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaTracks.h"
#include "Containers/Array.h"
#include "Internationalization/Text.h"
#include "Math/IntPoint.h"

/**
 * Implements media track collection for Spout streams.
 * 
 * Spout streams typically have a single video track with no audio,
 * so this implementation provides a simplified track management
 * for live video streaming.
 */
class FSpoutMediaTracks : public IMediaTracks
{
public:
	/** Constructor. */
	FSpoutMediaTracks();

	/** Destructor. */
	virtual ~FSpoutMediaTracks();

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
	 * Initialize the video track with the given parameters.
	 * 
	 * @param InDimensions Video frame dimensions.
	 * @param InFrameRate Video frame rate.
	 * @param InTypeName Format type name (e.g., "RGBA8", "BGRA8").
	 */
	void Initialize(const FIntPoint& InDimensions, float InFrameRate, const FString& InTypeName);

	/**
	 * Clear all tracks.
	 */
	void Reset();

	/**
	 * Update video track format (called when Spout sender changes).
	 * 
	 * @param InDimensions New video frame dimensions.
	 * @param InFrameRate New video frame rate.
	 */
	void UpdateVideoFormat(const FIntPoint& InDimensions, float InFrameRate);

private:
	/** Video track format information. */
	FMediaVideoTrackFormat VideoTrackFormat;

	/** Whether video track is currently selected. */
	bool bVideoTrackSelected;

	/** Whether tracks have been initialized. */
	bool bInitialized;
};

