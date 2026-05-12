// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "OWL360ResolutionSettings.h"
#include "OWLEyeIndex.h"
#include "DataTypes/OWL360Projections.h"
#include "Templates/SubclassOf.h"
#include "Tools/OWLFileInput.h"
#include "OWL360PipelineSettings.generated.h"

struct FOWLFoundSequenceCamera;
class UOWLMRQ360Hooks;
struct FOWLCroppedFaces;
struct FInternal360Settings;
enum class EMoviePipelineValidationState : uint8;
class UOWL360CaptureComponent;
struct FOWLTile;
struct FOWLTilePreset;
struct FOWLFaceCrop;

UENUM()
enum class EOWLBitDepth: uint8
{
	BT_8Bit = 0 UMETA(DisplayName="8 Bit"),
	BT_16Bit = 1 UMETA(DisplayName="16 Bit"),
	BT_32Bit = 2 UMETA(DisplayName="32 Bit"),
};

UENUM()
enum class EOWLCompositeMode: uint8
{
	CM_Over UMETA(DisplayName="Over (Alpha Compositing)"),
	CM_Multiply UMETA(DisplayName="Multiply"),
	CM_Add UMETA(DisplayName="Add (Linear Dodge)"),
	CM_Subtract UMETA(DisplayName="Subtract"),
	CM_Screen UMETA(DisplayName="Screen"),
	CM_Difference UMETA(DisplayName="Difference"),
};



USTRUCT(BlueprintType)
struct FOWL360TilingSettings
{
	GENERATED_BODY()
public:
	/* The position of this tile relative to the face, zero-indexed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiling", DisplayName="Index")
	FIntPoint Position  = {0,0};

	/* Total number of tiles on a give face */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiling")
	FIntPoint Total = {1,1};

	/* The percentage each tile should overlap with the adjacent tile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiling",  meta=(UIMin=0, UIMax=50))
	float OverlapPercent = 10;

	/* It may be useful to set a minimum dimension of the tile. This ensures that some post-process effects work correctly */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiling",  meta=(UIMin=0, UIMax=50))
	int MinimumTileDimension = 10;

public:
	FOWLTile ToTile(FIntPoint FaceResolution, const FOWLFaceCrop& Crop) const;
	FOWLTile ToTile(const FOWLTilePreset& Preset) const;
	FOWLTilePreset ToTilePreset(FIntPoint FaceResolution, const FOWLFaceCrop& Crop) const;
};

USTRUCT(BlueprintType)
struct FOWL360OutputSettings
{
	GENERATED_BODY()
public:
	/* Texture resolution for camera render output */
	UPROPERTY(EditAnywhere, Category = "Output", meta=(DisplayPriority="1"))
	FOWL360ResolutionSettings Resolution;

	/* Use a custom width/height (must be square) for the cube face renders that comprise the final output */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output")
	bool bOverrideInternalFaceDimensions = false;

	/* Custom width and height (must be square) for the cube face renders that comprise the final output */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output", meta=(EditCondition="bOverrideInternalFaceDimensions"))
	int OverrideFaceDimension = 480;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output", meta=(EditCondition="bIsTile", EditConditionHides))
	FOWL360TilingSettings Tiling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output|Tiling",  meta=(EditCondition = "false", EditConditionHides))
	bool bIsTile = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output|Mask")
	FOWLFileInput OutputMaskPath;

	UPROPERTY(meta=(DeprecatedProperty))
	bool bUseAbsoluteMaskPath_DEPRECATED = false;

	/* A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. NB. This does not apply to CubeMap projections*/
	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Use OutputMaskPath instead"))
	FFilePath OutputMaskFilePath_DEPRECATED;

	/* A 2D mask that can optionally be applied to a projection output to zero (make black) unwanted pixels. Currently this does not prevent these pixels being rendered, but will save disk usage on large renders. NB. This does not apply to CubeMap projections*/
	UPROPERTY( meta=(DeprecatedProperty, DeprecationMessage="Use OutputMaskPath instead"))
	FFilePath OutputMaskFilePathAbsolute_DEPRECATED;

	/* Where multiple 360 cameras are in a sequence, composite them together based on the `Fade` value set on the component. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output|Compositing")
	bool bCompositeCameras = false;

	/* Enable to render only left or right eye as a separate image. This pass should be duplicated and the 'eye' changed to render the stereo pair as separate image. This is a PRO only feature and will only work if the projection is stereo. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output|Stereo")
	bool bRenderOnlyOneEye = false;

	/* Select the eye to render when 'Render Only One Eye' active. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output|Stereo",  meta=(EditCondition = "bRenderOnlyOneEye"))
	EOWLMRQEyeIndex EyeToRender = EOWLMRQEyeIndex::Left;

	/* When rendering a sequence, do not attempt to continue rendering further frames if an error occurs */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Output|Error Handling")
	bool bExitOnFailure = true;

public:
	/* Even though paths may be stored as relative to the game directory, this method converts it back to absolute */
	FString GetAbsoluteOutputMaskPath() const;
};

UENUM(BlueprintType)
enum class EOWLInterpolationType : uint8
{
	EI_Point = 0 UMETA(DisplayName="Point Sampling"),
	EI_Bilinear = 1 UMETA(DisplayName="Bilinear Sampling"),
	/* EI_Bicubic = 2 UMETA(DisplayName="Bicubic Sampling"), // TODO */
};


USTRUCT(BlueprintType)
struct FOWL360OptimisationSettings
{
	GENERATED_BODY()
public:
	/* To target specific outputs you may find you get a better result by forcing intermediate processing to a given bit rate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optimizations")
	EOWLBitDepth IntermediateBitDepth = EOWLBitDepth::BT_16Bit;

	/* Ensures that each frame completes before rendering the next. Very important with large resolutions */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optimizations")
	bool bDisableParallelRendering = false;

	/* Change the way face pixels are interpolated in the final render.
	 This can increase or decreases the pixel clarity  in the final stitch. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Optimizations")
	EOWLInterpolationType InterpolationType = EOWLInterpolationType::EI_Bilinear;

	/* Scene View States store large amount of temporal information to improve Nanite rendering, motion blur and other
	 intra-frame post-process optimisations. Disabling multiple view states reduces GPU load at the cost
	 of these effects. GPU Memory requirements are reduced at the cost of output quality. */
	UPROPERTY(BlueprintReadWrite, Category = "Optimizations")
	bool bDisableMultipleSceneViewStates = false;

	FOWL360OptimisationSettings();
};

USTRUCT(BlueprintType)
struct FOWL360RenderingSettings
{
	GENERATED_BODY()
public:
	// Path Tracing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	bool bPathTracing = false;

	/** When enabled, the path tracer will blend all spatial and temporal samples prior to the denoising and will disable post-processed motion blur.
     *  In this mode it is possible to use higher temporal sample counts to improve the motion blur quality.
     *  When this option is disabled, the path tracer will accumulate spatial samples, but denoise them prior to accumulation of temporal samples.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering", meta=(EditCondition = "bPathTracing", EditConditionHides))
    bool bReferenceMotionBlur = false;;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rendering")
	FOWL360OptimisationSettings Optimisations;

	/* Add one or multiple blueprints to apply transforms at various points in the stitching process. This is only available with a PRO MRQ license */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rendering|Advanced")
	TArray<TSubclassOf<UOWLMRQ360Hooks>> RenderingHooks;

	/* Ensures that frames are output to the MRQ writer (disk writer etc) in sequential order. This comes at a memory and slight performance cost */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rendering|Advanced")
	bool bMaintainFrameOrder = false;

public:
	TArray<TSubclassOf<UOWLMRQ360Hooks>> GetValidRenderingHooks() const;
};

USTRUCT(BlueprintType)
struct FOWL360PipelineSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Output", DisplayName="Output", Meta = (ShowOnlyInnerProperties, DisplayPriority="2"))
	FOWL360OutputSettings Output;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rendering", DisplayName="Rendering", Meta = (ShowOnlyInnerProperties))
	FOWL360RenderingSettings Rendering;

public:
	void ValidateState(TArray<FText>& ValidationResults, EMoviePipelineValidationState& ValidationState, bool bNoPro) const;
	void PathTracerValidation(TArray<FText>& ValidationResults, EMoviePipelineValidationState& ValidationState) const;
	static bool ResolutionImposesWatermark(FOWL360ResolutionSettings InRes);
	bool CheckIfPathTracerIsSupported() const;
	FIntPoint GetFaceResolution();
	FOWLCroppedFaces GetCropping();
	bool Find360Components(bool bDontCache = false);
	E360ProjectionType GetProjection();
	bool IsStereo();
	float GetFaceBlendPercent();
	FInternal360Settings ToInternalSettings();
	void UpdateResolution();

public:
	void SetFirstComponent(UOWL360CaptureComponent* Component);
	const TArray<FOWLFoundSequenceCamera>& GetCameraCutCameras() const;

	const TArray<FOWLFoundSequenceCamera>& GetFoundCameras() const;
	TWeakObjectPtr<UOWL360CaptureComponent> GetFirstComponent() const;

#if WITH_EDITOR
	void PostEditChange(FPropertyChangedChainEvent& PropertyChangedChainEvent, bool& bResolutionChanged);
#endif
private:
	TWeakObjectPtr<UOWL360CaptureComponent> FirstComponent = nullptr;
	TArray<FOWLFoundSequenceCamera> FoundCameras;
	TArray<FOWLFoundSequenceCamera> CameraCutCameras;

};


