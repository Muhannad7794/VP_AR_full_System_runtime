// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SMediaOutputWizard.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIVESTREAMINGTOOLKITEDITOR_SMediaOutputWizard_generated_h
#error "SMediaOutputWizard.generated.h already included, missing '#pragma once' in SMediaOutputWizard.h"
#endif
#define LIVESTREAMINGTOOLKITEDITOR_SMediaOutputWizard_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CI_tmp_Plugins_OWLLivestreamingToolkit_Source_LivestreamingToolkitEditor_Public_SMediaOutputWizard_h


#define FOREACH_ENUM_EAUDIOSOURCETYPE(op) \
	op(EAudioSourceType::AS_Viewport) \
	op(EAudioSourceType::AS_Submix) \
	op(EAudioSourceType::AS_NoAudio) 

enum class EAudioSourceType : uint8;
template<> struct TIsUEnumClass<EAudioSourceType> { enum { Value = true }; };
template<> LIVESTREAMINGTOOLKITEDITOR_API UEnum* StaticEnum<EAudioSourceType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
