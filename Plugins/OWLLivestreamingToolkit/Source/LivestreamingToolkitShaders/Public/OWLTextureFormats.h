// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "OWLTextureFormats.generated.h"

enum class EOWLNDIColorSpace : uint8
{
	BT_601,
	BT_709,
	BT_2020,
	BT_2100,
	BT_2100_HLG,
	BT_2100_PQ
};

struct EOWLNDIColourLayout
{
	EOWLNDIColorSpace Primaries = EOWLNDIColorSpace::BT_709;
	EOWLNDIColorSpace Transfer = EOWLNDIColorSpace::BT_709;
	EOWLNDIColorSpace Matrix = EOWLNDIColorSpace::BT_709;
public:
	// Convenience methods
	bool IsHDR() const { return Transfer == EOWLNDIColorSpace::BT_2100_PQ || Transfer == EOWLNDIColorSpace::BT_2100_HLG; }

};

UENUM()
enum EOWLTexturePixelFormat
{
	OPX_BGRA UMETA(DisplayName = "BGRA 8Bit"),
	OPX_RGBA UMETA(DisplayName = "RGBA 8Bit"),
	OPX_UYVY UMETA(DisplayName = "UYVY 8bit"),
	// NDI formats -- unimplemented so far
	OPX_I420 UMETA(DisplayName = "I420 (NDI)"),
	OPX_P216 UMETA(DisplayName = "P216 (NDI)"),
	OPX_UYVA UMETA(DisplayName = "UYVA (NDI)"),
	OPX_PA16 UMETA(DisplayName = "PA16 (NDI)"),
	OPX_YV12 UMETA(DisplayName = "YV12 (NDI)"),
	OPX_NV12 UMETA(DisplayName = "NV12 (NDI)"),
	OPX_BGRX UMETA(DisplayName = "BGRX (NDI)"),
	OPX_RGBX UMETA(DisplayName = "RGBX (NDI)"),
	// End NDI
	OPX_None UMETA(DisplayName = "Unknown Format"),
};

UENUM()
enum EOWLPixelLayoutFormat
{
	OPL_BGRA UMETA(DisplayName = "BGRA"),
	OPL_RGBA UMETA(DisplayName = "RGBA"),
	OPL_UYVY UMETA(DisplayName = "UYVY"),
	OPL_P216 UMETA(DisplayName = "P216 (10-bit)"),
	OPL_Unknown UMETA(DisplayName = "Unknown Format"),
};

