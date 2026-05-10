// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "DataTypes/OWLFaceCrop.h"

struct FOWL360CameraPassFacePayload;
struct FOWLFaceCrop;

// Summary information for a tile
// that can alter per-face
struct FOWLTilePreset
{
public:
	FIntPoint Total;
	FIntPoint FaceResolution;
	float OverlapPercent = 10;
	int MinimumTileDimension = 10;
	FOWLFaceCrop Crop;
public:
	FOWLTilePreset() = default;
	FOWLTilePreset(FIntPoint Total, FIntPoint FaceResolution, float OverlapPercent, int MinimumTileDimension, FOWLFaceCrop Crop)
		: Total(Total),
		FaceResolution(FaceResolution),
		OverlapPercent(OverlapPercent),
		MinimumTileDimension(MinimumTileDimension),
		Crop(Crop)
	{};

	FIntPoint Resolution() const;
	FIntRect ViewRectangle() const;
	bool HasCrop() const;

	FString ToString() const;

};

struct FOWLTile
{
public:
	FOWLTile() = default;
	FOWLTile(FIntPoint Index,
		FIntPoint TotalTiles,
		FIntPoint FaceResolution,
		float OverlapPercent,
		int MinimumTileDimension,
		const FOWLFaceCrop& Crop);

	static FOWLTile FromPreset(const FIntPoint& Index, const FOWLTilePreset& Reference);
	static FOWLTile FromPreset(const FOWL360CameraPassFacePayload& FacePayload, int FaceIndex);


	FIntPoint FaceToTilePixel(const FIntPoint& FacePixel) const;

public:
	float OverlapPercent = 10;
	int MinTileDimension = 0;
	FIntPoint Index = {0,0};
	FVector2d UVMin = {0,0};
	FVector2d UVMax = {1,1};
	FIntPoint PixelMin = {0,0};
	FIntPoint PixelMax = {1,1};
	FIntPoint Resolution = {0,0};
	// resolution of combined tiles
	FIntPoint FaceResolution = {1, 1};
	FIntPoint Total = {1, 1};
	FIntRect NoOverlapRegion = {0, 0, 1, 1};
	FIntPoint OverscanPixels = {0,0};

	bool ShouldRender() const { return bShouldRender; };
	bool ContainsPixel(FIntPoint InPixel) const;

	FString ToString() const;
public:
	/* Generates a projection matrix for a given tile */
	FMatrix ModifyProjectionMatrix(FMatrix InProjection) const;
private:
	bool bShouldRender = true;
	// Given crop parameters applied to the face, does this tile
	// need to be rendered
	bool ShouldRender(FOWLFaceCrop InCrop) const;
	static FIntPoint ExpandToFill(int PixelsRequired, int Min, int Max, int FaceMax);
	void UpdateOverlapUVResolution();
};


