// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaTextureSample.h"
#include "MediaObjectPool.h"
#include "Math/IntPoint.h"
#include "Misc/Timespan.h"
#include "RHI.h"

/**
 * Implements a media texture sample for Spout streams.
 * 
 * This class wraps an RHI texture received from Spout and presents it
 * to the Media Framework as a texture sample. It handles the lifetime
 * and format details of Spout textures.
 */
class FSpoutTextureSample : public IMediaTextureSample, public IMediaPoolable
{
public:
	/** Constructor. */
	FSpoutTextureSample();

	/** Virtual destructor. */
	virtual ~FSpoutTextureSample();

public:
	//~ IMediaTextureSample interface

	virtual const void* GetBuffer() override;
	virtual FIntPoint GetDim() const override;
	virtual FTimespan GetDuration() const override;
	virtual EMediaTextureSampleFormat GetFormat() const override;
	virtual FIntPoint GetOutputDim() const override;
	virtual uint32 GetStride() const override;
	virtual FMediaTimeStamp GetTime() const override;
	virtual bool IsCacheable() const override;
	virtual bool IsOutputSrgb() const override;
	virtual FRHITexture* GetTexture() const override;

	// REMOVED: GetTexture2D() - not part of IMediaTextureSample interface

public:
	//~ IMediaPoolable interface

	virtual void ShutdownPoolable() override;

public:
	/**
	 * Initialize the sample with Spout texture data.
	 *
	 * @param InTexture The RHI texture received from Spout.
	 * @param InDimensions The dimensions of the texture.
	 * @param InFormat The pixel format of the texture.
	 * @param InTime The timestamp for this sample.
	 * @param InDuration The duration this sample should be displayed.
	 * @param InbIsSRGB Whether the texture uses sRGB color space.
	 */
	bool Initialize(
		FRHITexture2D* InTexture,
		const FIntPoint& InDimensions,
		EPixelFormat InFormat,
		const FMediaTimeStamp& InTime,
		const FTimespan& InDuration,
		bool InbIsSRGB = false
	);

	/**
	 * Check if this sample has been initialized.
	 */
	bool IsInitialized() const { return Texture.IsValid(); }

private:
	/** The RHI texture containing the Spout frame data. */
	FTexture2DRHIRef Texture;

	/** Dimensions of the texture. */
	FIntPoint Dimensions;

	/** Pixel format of the texture. */
	EPixelFormat PixelFormat;

	/** The timestamp of this sample. */
	FMediaTimeStamp TimeStamp;

	/** The duration this sample should be displayed. */
	FTimespan Duration;

	/** Whether this texture uses sRGB color space. */
	bool bIsSRGB;

	/** Cached format for Media Framework. */
	EMediaTextureSampleFormat CachedSampleFormat;

	/** Convert EPixelFormat to EMediaTextureSampleFormat. */
	EMediaTextureSampleFormat ConvertPixelFormat(EPixelFormat InPixelFormat) const;
};

