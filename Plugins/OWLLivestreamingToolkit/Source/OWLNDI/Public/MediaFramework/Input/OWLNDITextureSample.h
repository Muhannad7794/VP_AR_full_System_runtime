// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "IMediaTextureSample.h"
#include "MediaObjectPool.h"
#include "Math/IntPoint.h"
#include "Misc/Timespan.h"
#include "RHI.h"
#include "OWLTextureFormats.h"

/**
 * Implements a media texture sample for NDI streams.
 * 
 * This class wraps an RHI texture received from NDI and presents it
 * to the Media Framework as a texture sample. It handles the lifetime
 * and format details of NDI textures, including HDR formats like P216.
 */
class FNDITextureSample : public IMediaTextureSample, public IMediaPoolable
{
public:
	/** Constructor. */
	FNDITextureSample();

	/** Virtual destructor. */
	virtual ~FNDITextureSample();

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

public:
	//~ IMediaPoolable interface

	virtual void ShutdownPoolable() override;

public:
	/**
	 * Initialize the sample with NDI texture data.
	 *
	 * @param InTexture The RHI texture received from NDI.
	 * @param InDimensions The dimensions of the texture.
	 * @param InFormat The pixel format of the texture.
	 * @param InNDIFormat The original NDI pixel format.
	 * @param InTime The timestamp for this sample.
	 * @param InDuration The duration this sample should be displayed.
	 * @param InbIsSRGB Whether the texture uses sRGB color space.
	 * @param InbIsHDR Whether this is an HDR texture (P216, etc.).
	 */
	bool Initialize(
		FRHITexture2D* InTexture,
		const FIntPoint& InDimensions,
		EPixelFormat InFormat,
		EOWLTexturePixelFormat InNDIFormat,
		const FMediaTimeStamp& InTime,
		const FTimespan& InDuration,
		bool InbIsSRGB = false,
		bool InbIsHDR = false
	);

	/**
	 * Check if this sample has been initialized.
	 */
	bool IsInitialized() const { return Texture.IsValid(); }

	/**
	 * Get the original NDI pixel format.
	 */
	EOWLTexturePixelFormat GetNDIFormat() const { return NDIFormat; }

	/**
	 * Check if this is an HDR texture.
	 */
	bool IsHDR() const { return bIsHDR; }

private:
	/** The RHI texture containing the NDI frame data. */
	FTexture2DRHIRef Texture;

	/** Dimensions of the texture. */
	FIntPoint Dimensions;

	/** Pixel format of the texture. */
	EPixelFormat PixelFormat;

	/** Original NDI pixel format. */
	EOWLTexturePixelFormat NDIFormat;

	/** The timestamp of this sample. */
	FMediaTimeStamp TimeStamp;

	/** The duration this sample should be displayed. */
	FTimespan Duration;

	/** Whether this texture uses sRGB color space. */
	bool bIsSRGB;

	/** Whether this is an HDR texture. */
	bool bIsHDR;

	/** Cached format for Media Framework. */
	EMediaTextureSampleFormat CachedSampleFormat;

	/** Convert EPixelFormat to EMediaTextureSampleFormat. */
	EMediaTextureSampleFormat ConvertPixelFormat(EPixelFormat InPixelFormat) const;

	/** Convert NDI format to Media Framework format. */
	EMediaTextureSampleFormat ConvertNDIFormat(EOWLTexturePixelFormat InNDIFormat) const;
};

