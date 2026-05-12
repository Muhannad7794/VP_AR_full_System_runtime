// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "OWL360PipelineSettings.h"
#include "OWLTile.h"

struct FOWL360Resolution
{
	FIntPoint RenderTarget = {0,0};
	FIntPoint Face = {0,0};
	FIntPoint Output = {0, 0};
	FIntPoint Intermediate = {0, 0};
	FIntRect ViewRectangle = {0, 0};
	// pixels in from left and top where the cropped pixels start
	FIntPoint CropOffset = {0, 0};
	bool bUsesIntermediate = true;

public:
	FOWL360Resolution() = default;
	static FOWL360Resolution ForSingleTile(const FOWLTile& Tile);
	static FOWL360Resolution ForJointRender(FOWL360PipelineSettings& Settings, int FaceIndex = 0);
	static FOWL360Resolution ForStitch(FOWL360PipelineSettings& Settings);
	FString ToString() const;
};



