// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaAudioSample.h"
#include "MediaObjectPool.h"
#include "Misc/Timespan.h"
#include "OWLNDIReceiverManager.h"

/**
 * Implements a media audio sample for NDI streams.
 * 
 * This class wraps audio data received from NDI and presents it
 * to the Media Framework as an audio sample. It handles various
 * NDI audio formats and reference level standards.
 */
class FNDIAudioSample : public IMediaAudioSample, public IMediaPoolable
{
public:
	FNDIAudioSample();

	virtual ~FNDIAudioSample();

public:
	//~ IMediaAudioSample interface

	virtual const void* GetBuffer() override;
	virtual uint32 GetChannels() const override;
	virtual FTimespan GetDuration() const override;
	virtual EMediaAudioSampleFormat GetFormat() const override;
	virtual uint32 GetFrames() const override;
	virtual uint32 GetSampleRate() const override;
	virtual FMediaTimeStamp GetTime() const override;
	

public:
	//~ IMediaPoolable interface

	virtual void ShutdownPoolable() override;

public:
	/**
	 * Initialize the sample with NDI audio data.
	 *
	 * @param InBuffer Pointer to the audio data buffer.
	 * @param InBufferSize Size of the audio data in bytes.
	 * @param InChannels Number of audio channels.
	 * @param InSampleRate Sample rate in Hz.
	 * @param InFrames Number of audio frames.
	 * @param InTime The timestamp for this sample.
	 * @param InDuration The duration of this audio sample.
	 * @param InReferenceLevel Audio reference level standard used.
	 */
	bool Initialize(
		const void* InBuffer,
		uint32 InBufferSize,
		uint32 InChannels,
		uint32 InSampleRate,
		uint32 InFrames,
		const FMediaTimeStamp& InTime,
		const FTimespan& InDuration,
		EOWLNDIAudioReferenceLevel InReferenceLevel = EOWLNDIAudioReferenceLevel::Default
	);

	/**
	 * Check if this sample has been initialized.
	 */
	bool IsInitialized() const { return Buffer.Num() > 0; }

	/**
	 * Get the audio reference level used for this sample.
	 */
	EOWLNDIAudioReferenceLevel GetReferenceLevel() const { return ReferenceLevel; }

private:
	/** Internal buffer holding the audio data. */
	TArray<uint8> Buffer;

	/** Number of audio channels. */
	uint32 Channels;

	/** Sample rate in Hz. */
	uint32 SampleRate;

	/** Number of audio frames. */
	uint32 Frames;

	/** The timestamp of this sample. */
	FMediaTimeStamp TimeStamp;

	/** The duration of this audio sample. */
	FTimespan Duration;

	/** Audio reference level standard used. */
	EOWLNDIAudioReferenceLevel ReferenceLevel;

	/** Cached format for Media Framework. */
	EMediaAudioSampleFormat CachedSampleFormat;
};

