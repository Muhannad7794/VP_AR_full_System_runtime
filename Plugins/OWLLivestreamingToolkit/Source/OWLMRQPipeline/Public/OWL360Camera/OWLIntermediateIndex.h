// Copyright Off World Live Limited 2020-2025. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "HAL/Platform.h"

struct FOWLIntermediateIndex
{
	int FrameNumber;
	int CameraIndex;
	int TemporalPassIndex;
	int SpatialPassIndex;
	int SceneViewIndex;
	uint32 Hash() const ;
	FString ToString() const;
	bool operator==(FOWLIntermediateIndex A) const;
	friend uint32 GetTypeHash(FOWLIntermediateIndex Index)
	{
		return Index.Hash();
	}
public:
	FOWLIntermediateIndex() = default;
	FOWLIntermediateIndex(
		const int& CameraIndex,
		const int& FrameNumber,
		const int& TemporalPassIndex,
		const int& SpatialPassIndex,
		const int& SceneViewIndex):
	FrameNumber(FrameNumber),
	CameraIndex(CameraIndex),
	TemporalPassIndex(TemporalPassIndex),
	SpatialPassIndex(SpatialPassIndex),
	SceneViewIndex(SceneViewIndex) {}
};

