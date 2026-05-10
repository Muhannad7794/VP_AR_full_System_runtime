// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "RHIResources.h"
#include "OWLTextureFormats.h"
#include "GlobalShader.h"
#include "Shader.h"
#include "ShaderParameterMacros.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "ShaderParameterStruct.h"
#include "TextureResource.h"
#include "RHIStaticStates.h"
#include "RHI.h"

class UTextureRenderTarget2D;
class FRHICommandListImmediate;
class UOpenColorIOConfiguration;
struct FOpenColorIOColorSpace;


class FLinearToSrgbPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FLinearToSrgbPS)
	SHADER_USE_PARAMETER_STRUCT(FLinearToSrgbPS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()


public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}

	FLinearToSrgbPS::FParameters* AllocateAndSetParameters(FRDGBuilder& GraphBuilder, FRDGTextureRef InputTexture, FRDGTextureRef OutputTexture);
};

template <bool ConvertSrgbToLinear>
class FInputTextureConvertPS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FInputTextureConvertPS)

	SHADER_USE_PARAMETER_STRUCT(FInputTextureConvertPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(uint32, DoubleSRGBConversion)
		SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::ES3_1);
	}

	FInputTextureConvertPS::FParameters* AllocateAndSetParameters(FRDGBuilder& GraphBuilder, FRDGTextureRef InputTexture, FRDGTextureRef OutputTexture, bool bDoubleSRGBConversion=false);

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("CONVERT_SRGB_TO_LINEAR"), ConvertSrgbToLinear);
	}
};

class LIVESTREAMINGTOOLKITSHADERS_API FOWLMediaUtils
{
public:
	/* Converts the RenderTextureTarget to a different format and applies sRGB gamma */
	static bool ConvertFormatAndLinearToSrgb_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		UTextureRenderTarget2D* SourceRenderTarget,
		FTexture2DRHIRef& ReadbackTexture,
		EOWLPixelLayoutFormat VideoConversionFormat,
		EPixelFormat ForcedFormat = EPixelFormat::PF_Unknown);

	static bool InputFormatConvert_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		const FTexture2DRHIRef& SourceTexture,
		UTextureRenderTarget2D* DestinationRenderTarget,
		bool bConvertSrgbToLinear = false,
		bool bDoubleSrgbConversion = false
	);

	/** Apply OCIO color space transformation to a render target (Game Thread) */
	static bool ApplyOCIOColorTransform_GameThread(
		UTextureRenderTarget2D* RenderTarget,
		UOpenColorIOConfiguration* OCIOConfig,
		const FOpenColorIOColorSpace& SourceSpace,
		const FOpenColorIOColorSpace& DestSpace);
};

class LIVESTREAMINGTOOLKITSHADERS_API FOWLNDIReceiverShader
{
public:
	FOWLNDIReceiverShader();
	~FOWLNDIReceiverShader();
	bool Apply_RenderThread(
		FRHICommandListImmediate& RHICmdList,
		UTextureRenderTarget2D* DestRenderTarget,
		uint32 LineStride,
		const uint8* SrcData,
		FIntPoint Resolution,
		EOWLTexturePixelFormat InPixelFormat,
		EOWLNDIColourLayout ColourLayout,
		bool bConvertGamma);

	bool ApplyP2X16_RT(
		FRHICommandListImmediate& RHICmdList,
		UTextureRenderTarget2D* DestRenderTarget,
		uint32 SrcPitch,
		const uint8* SrcData,
		FIntPoint Resolution,
		const EOWLNDIColourLayout& ColourLayout,
		bool bConvertGamma, bool bHasAlpha);

	bool ApplyRGBorBGR_RT(
		FRHICommandListImmediate& RHICmdList,
		UTextureRenderTarget2D* DestRenderTarget,
		uint32 LineStride,
		const uint8* SrcData,
		FIntPoint Resolution,
		bool bConvertGamma,
		bool bHasAlpha, bool bSwizzleRGB
	);

	bool ApplyUYVA_RT(
		FRHICommandListImmediate& RHICmdList,
		UTextureRenderTarget2D* DestRenderTarget,
		uint32 UYVYPitch,
		const uint8* UYVYData,
		const uint8* AlphaData,
		uint32 AlphaPitch,
		FIntPoint Resolution,
		bool bConvertGamma);

	bool ApplyUYVY_RT(
		FRHICommandListImmediate& RHICmdList,
		UTextureRenderTarget2D* DestRenderTarget,
		uint32 SrcPitch,
		const uint8* SrcData,
		FIntPoint Resolution,
		bool bConvertGamma);

private:
	TRefCountPtr<FRHITexture2D> InputTarget;

	// Textures for P216 / PA16 processing
	TRefCountPtr<FRHITexture2D> YPlaneTarget;
	TRefCountPtr<FRHITexture2D> UVPlaneTarget;
	TRefCountPtr<FRHITexture2D> AlphaPlaneTarget;

	// For UYVA alpha plane
	TRefCountPtr<FRHITexture2D> UYVAAlphaTarget;

	// For UYVY intermediate RGB processing
	TRefCountPtr<FRHITexture2D> UYVYIntermediateTarget;
};


