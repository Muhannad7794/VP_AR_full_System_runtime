// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "MoviePipelineImagePassBase.h"
#include "OWLIntermediateIndex.h"
#include "DataTypes/OWLFaceBool.h"
#include "OWL360CaptureComponent.h"
#include "OWL360Camera/OWLTile.h"
#include "OWL360PipelineSettings.h"
#include "OWL360Resolution.h"
#include "OWL360CameraMoviePipelineData.generated.h"

#define OWL_COMPOSITE_PASS_IDENTIFIER TEXT("CameraComposite")

struct FOWLMRQOutputDesc
{
	FOWLMRQOutputDesc() = default;
	FOWLMRQOutputDesc(
		int FrameNumber,
		const FMoviePipelinePassIdentifier& PassIdentifier
	)
		: FrameNumber(FrameNumber),
		PassIdentifier(PassIdentifier) {}

	int FrameNumber = 0;
	FMoviePipelinePassIdentifier PassIdentifier;
public:
	bool operator==(const FOWLMRQOutputDesc& In) const = default;

	FString ToString() const
	{
		return FString::Printf(TEXT("Frame: %d, Id: %s_%s"), FrameNumber, *PassIdentifier.Name, *PassIdentifier.CameraName);
	}

	friend uint32 GetTypeHash(const FOWLMRQOutputDesc& Key)
	{
		return HashCombine(GetTypeHash(Key.FrameNumber), GetTypeHash(Key.PassIdentifier));
	}
};

struct FOWLCompositeSettings
{
	bool bComposite = false;
	bool bCameraActive = false;
	float Opacity = 1.;
	EOWLCompositeMode Mode = EOWLCompositeMode::CM_Over;

	FOWLCompositeSettings() = default;
	FOWLCompositeSettings(
		bool bComposite,
		bool bCameraActive = false,
		float Opacity = 1.0,
		EOWLCompositeMode Mode = EOWLCompositeMode::CM_Over)
	: bComposite(bComposite)
		,bCameraActive(bCameraActive)
		,Opacity(Opacity)
		,Mode(Mode) {};

	static FOWLCompositeSettings NoComposite() { return FOWLCompositeSettings(false, false, 1, EOWLCompositeMode::CM_Over); }

	FString ToString() const
	{
		return FString::Printf(
			TEXT("Composite Settings:\n\tEnabled: %s\n\tCameraActive: %s\n\tOpacity:%f\n\tMode:%s"),
			bComposite ? TEXT("Y") : TEXT("N"),
			bCameraActive ? TEXT("Y") : TEXT("N"),
			Opacity,
			*UEnum::GetValueAsString(Mode)
		);
	}
};

/**
 * @brief Relevant settings for setting up shaders and camera locations
 */
struct FInternal360Settings
{
	FQuat DomeCameraRotator;
	FQuat DomeShaderRotator;
	FQuat CameraRotation;
	FQuat CubeFaceRotation;
	E360ProjectionType Projection;
	FOWLFaceBool ShouldRender;
	FOWLFaceBool ReusedFaces;
	FOWLCroppedFaces Cropping;
	int CustomHorizontalFOV = 360;
	int CustomVerticalFOV = 180;
	double StereoEyeSeparation = 6.;
	int DomeAngle = 180;
	float FaceBlendPercent = 0;
	float StereographicFOVRadians = 2.09;

	FOWLCompositeSettings Composite;

	FIntPoint TilesPerFace;
	FIntPoint TileIndex;
	TMap<int, FOWLTilePreset> Tiles;

	FInternal360Settings() = default;
	FInternal360Settings(UOWL360CaptureComponent* InComponent, FOWL360PipelineSettings& Settings, FOWLCompositeSettings Composite);

	bool IsStereoProjection() const;
	bool Is180Projection() const;
	bool AdvancedFeaturesModified() const;

	bool IsFaceReused(int FaceIndex) const;
	bool IsCompatible(const FInternal360Settings& Comparison) const;
	FString ToString() const;
};

USTRUCT()
struct FOWLFoundSequenceCamera
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	FGuid Guid;
	UPROPERTY(SaveGame)
	FGuid ThreeSixtyGuid;
	// The sort order as of the original track
	UPROPERTY(SaveGame)
	int SortOrder = 0;
	UPROPERTY(SaveGame)
	FString Name;
	UPROPERTY(SaveGame)
	FString ParentSequenceName;
	UPROPERTY(SaveGame)
	bool bIs360 = false;

	TWeakObjectPtr<UOWL360CaptureComponent> Component = nullptr;
	TWeakObjectPtr<UCameraComponent> CameraComponent = nullptr;
	TWeakObjectPtr<ACameraActor> Actor = nullptr;

	UPROPERTY(SaveGame)
	FVector3d Location = FVector3d(0);
	UPROPERTY(SaveGame)
	FRotator Rotation = FRotator(0);

	TRange<FFrameNumber> Range = TRange<FFrameNumber>::All();

	FString GetID() const
	{
		return GetIDFromGuid(Guid, ParentSequenceName);
	}

	static FString GetIDFromGuid(const FGuid Guid, const FString& SequenceName)
	{
		if (!Guid.IsValid()) return "";
		return Guid.ToString() + "." + SequenceName;
	}

};



struct FOWLMRQCameraTransforms
{
	// game thread only access
	// store all camera current and prev camera locations for each camera to be rendered
	// then we can ignore the unreal `FrameInfo` struct which gets messy when we want to
	// composite all available cameras
	TMap<FString, FVector3d> CurrentCameraLocations;
	TMap<FString, FVector3d> PrevCameraLocations;
	TMap<FString, FRotator> CurrentCameraRotations;
	TMap<FString, FRotator> PrevCameraRotations;
	int CurrentFrame = -1;
	void Empty();
	void UpdateCameraRotationsForFrame(const int Frame, const TArray<FOWLFoundSequenceCamera>& FoundComponents);
	bool GetCurrentCameraTransform(const FString& CameraName, FVector3d& OutLocation, FRotator& OutRotation) const;
	bool GetPrevCameraTransform(const FString& CameraName, FVector3d& OutLocation, FRotator& OutRotation) const;
};
/**
 * @brief Payload specific to given face
 */
struct FOWL360CameraPassFacePayload : public UMoviePipelineImagePassBase::IViewCalcPayload
{
	FOWL360CameraPassFacePayload() = default;
	FOWL360CameraPassFacePayload(
		const bool bIsStereo,
		const int CameraIndex,
		const int LastFaceIndex,
		const int EyeIndex,
		const int FaceIndex,
		const float FOV,
		const FOWLIntermediateIndex& IntermediateIndex,
		const FMoviePipelineRenderPassMetrics& InSampleState,
		const FInternal360Settings& InSettings,
		const FOWLMRQCameraTransforms& CameraTransforms,
		const FOWLFoundSequenceCamera& CameraData,
		const TSet<int>& CameraIndicesToComposite);
	// Settings taken from the OWL 360 Capture Component
	FInternal360Settings CameraSettings;

	// From UE::MoviePipeline::FDeferredPassRenderStatePayload
	int32 CameraIndex;
	// N.B confusingly this is the tile index for the tiling on movie render queue deferred
	// NOT our separate face tiles
	FIntPoint TileIndex; // Will always be 1,1 if no history-per-tile is enabled
	int32 SceneViewIndex;

	// The camera location as defined by the actual sequence, consistent for all panes.
	FVector OriginalCameraLocation;
	// The camera location last frame, used to ensure camera motion vectors are right.
	FVector PrevOriginalCameraLocation;
	// The camera rotation as defined by the actual sequence
	FRotator OriginalCameraRotation;
	// The camera rotation last frame, used to ensure camera motion vectors are right.
	FRotator PrevOriginalCameraRotation;
	// The near clip plane distance from the camera.
	float NearClippingPlane;

	// The horizontal field of view this pane was rendered with
	float FieldOfView;

	// The actual rendering location for this pane, offset by the stereo eye if needed.
	FVector CameraLocation;
	FVector PrevCameraLocation;
	FRotator CameraRotation;
	FRotator PrevCameraRotation;

	// OWL360Camera
	int32 FaceIndex;
	int32 EyeIndex;
	bool bReuseForOtherEye;
	// quat combined from cube face rotation + face rotation + camera rotation
	FQuat RotationOffset;
	// inverse of the rotation, with values swizzled for shader axes compatibility
	FQuat RotationOffsetSwizzled;

	int FrameNumber;

	TSet<int> CameraIndicesToComposite;

	// When only partial faces are rendered
	// we need to know which is the last face to be rendered
	int32 LastFaceIndex;

	FOWLIntermediateIndex IntermediateIndex;

public:
	FOWLTilePreset GetTile() const;
	FString ToString();
};

/**
 * Payload that is embedded in the pixel data extracted from
 * the render target after `BeginRenderingViewFamilies` is executed and set to each
 * output merger
 */
struct OWLMRQPIPELINE_API FOWL360CameraImagePixelDataPayload : public FImagePixelDataPayload
{
	virtual TSharedRef<FImagePixelDataPayload> Copy() const override
	{
		auto Output = MakeShared<FOWL360CameraImagePixelDataPayload>(*this);
		Output->Resolution = Resolution;
		return Output;
	}

	virtual FIntPoint GetAccumulatorSize() const override
	{
		return Resolution.Intermediate;
	}

	virtual FIntPoint GetOverlapPaddedSize() const override
	{
		return Resolution.Intermediate;
	}

	virtual bool GetOverlapPaddedSizeIsValid(const FIntPoint InRawSize) const override
	{
		return InRawSize == Resolution.Intermediate;
	}

	virtual void GetWeightFunctionParams(MoviePipeline::FTileWeight1D& WeightFunctionX, MoviePipeline::FTileWeight1D& WeightFunctionY) const override
	{
		WeightFunctionX.InitHelper(0, Resolution.Intermediate.X, 0);
		WeightFunctionY.InitHelper(0, Resolution.Intermediate.Y, 0);
	}


	FOWL360CameraPassFacePayload Face;

	FOWL360Resolution Resolution;

	FString ShotName;

	EOWLInterpolationType InterpolationType = EOWLInterpolationType::EI_Bilinear;

	EOWLBitDepth BitDepth;

	FString OutputAlphaMaskFilePath;

	bool bExitOnFailure = true;

	FOWL360CameraImagePixelDataPayload(
		const FMoviePipelineRenderPassMetrics& InSampleState,
		const FMoviePipelinePassIdentifier& InPassIdentifier,
		const FOWL360CameraPassFacePayload& InFacePayload,
		const FOWL360PipelineSettings& Settings,
		const FOWL360Resolution& Resolution
	);
	FOWL360CameraImagePixelDataPayload(
		const FOWL360CameraPassFacePayload& InFacePayload
		);

	FString ToString();
};


