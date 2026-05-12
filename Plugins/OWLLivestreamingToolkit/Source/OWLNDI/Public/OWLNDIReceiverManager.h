// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "OWLTextureFormats.h"
#include "OWLNDISoundWave.h"
#include "NDIEnums.h"
#include "Engine/TextureRenderTarget2D.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "OpenColorIOColorSpace.h"
#include "OpenColorIOConfiguration.h"
#include "OpenColorIORendering.h"
#include "OWLNDIReceiverManager.generated.h"

/**
 * Enum for NDI bandwidth settings
 */
UENUM(BlueprintType)
enum class EOWLNDIBandwidth : uint8
{
	MetadataOnly UMETA(DisplayName = "Metadata Only", ToolTip = "Receive only metadata (<1 Mbps)"),
	AudioOnly UMETA(DisplayName = "Audio Only", ToolTip = "Receive metadata and audio (~1-2 Mbps)"),
	Lowest UMETA(DisplayName = "Lowest", ToolTip = "Receive proxy stream at 640x360 (~18-66 Mbps)"),
	Highest UMETA(DisplayName = "Highest", ToolTip = "Receive full resolution stream (~100-250 Mbps)")
};

/**
 * Enum for audio reference level standards
 */
UENUM(BlueprintType)
enum class EOWLNDIAudioReferenceLevel : uint8
{
	Default UMETA(DisplayName = "Default", ToolTip = "Full 16-bit range (default for gaming/streaming)"),
	SMPTE UMETA(DisplayName = "SMPTE", ToolTip = "SMPTE standard with 20 dB headroom for broadcast"),
	EBU UMETA(DisplayName = "EBU", ToolTip = "EBU standard with 18 dB headroom for European broadcast"),
	Manual UMETA(DisplayName = "Manual", ToolTip = "Custom scaling factor")
};

/**
 * Enum for NDI color format settings
 */
UENUM(BlueprintType)
enum class EOWLNDIColorFormat : uint8
{
	Best UMETA(DisplayName = "Best (Highest Available)",
				ToolTip = "Automatically select the highest quality format available from the source. Supports both SDR and HDR content."),
	Fastest UMETA(DisplayName = "Fastest (Choose fastest available quality)",
				ToolTip = "This format will try to decode the video using the fastest available color format for the incoming video signal.")
};

/**
 * Enum for audio synchronization modes
 */
UENUM(BlueprintType)
enum class EOWLNDIAudioSync : uint8
{
	Automatic UMETA(DisplayName = "Automatic", ToolTip = "Automatically sync audio and video"),
	Manual UMETA(DisplayName = "Manual", ToolTip = "Manually set audio delay")
};

/**
 * Enum for connection status reporting
 */
UENUM(BlueprintType)
enum class EOWLNDIConnectionStatus : uint8
{
	Disconnected UMETA(DisplayName = "Disconnected", ToolTip = "Not connected to any source"),
	Connecting UMETA(DisplayName = "Connecting", ToolTip = "Attempting to connect"),
	Connected UMETA(DisplayName = "Connected", ToolTip = "Successfully connected and receiving")
};

/**
 * Struct to handle NDI receive functionality and settings
 */
USTRUCT(BlueprintType)
struct OWLNDI_API FOWLNDIReceiverInterface
{
	GENERATED_BODY()

	FOWLNDIReceiverInterface();
	
public:
	//--------------------------------------
	// Color Management Settings (OCIO)
	//--------------------------------------

	/** If enabled, for 8bit textures, a gamma conversion will be applied to ensure that Unreal output matches color range on 3rd party programs */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Color Management")
	bool bConvertGamma = true;

	/** Enable OCIO color space conversion */
	UPROPERTY(BlueprintReadWrite, Category = "Color Management")
	bool bUseOCIO = false;

	/** OCIO Configuration Asset to use for color conversion */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Color Management",
		meta=(EditCondition="bUseOCIO", EditConditionHides))
	class UOpenColorIOConfiguration* OCIOConfiguration = nullptr;

	/** Source color space (what the NDI stream is in) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Color Management",
		meta=(EditCondition="bUseOCIO && OCIOConfiguration != nullptr", EditConditionHides))
	FOpenColorIOColorSpace SourceColorSpace;

	/** Destination color space (what we want to convert to) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Color Management",
		meta=(EditCondition="bUseOCIO && OCIOConfiguration != nullptr", EditConditionHides))
	FOpenColorIOColorSpace DestinationColorSpace;

	/** Whether to apply gamma correction before OCIO conversion */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Color Management",
		meta=(EditCondition="bUseOCIO", EditConditionHides))
	bool bApplyGammaBeforeOCIO = true;

	//--------------------------------------
	// Basic Settings
	//--------------------------------------

	/** Whether this receiver is active */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic",
		meta=(EditCondition="!bUnderExternalControl", EditConditionHides))
	bool Active = false;

	/** The name of the NDI source to connect to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FString Name = "";

	/** The render target to receive video frames to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic",
		meta=(EditCondition="!bUnderExternalControl", EditConditionHides))
	UTextureRenderTarget2D* RenderTarget = nullptr;


	//--------------------------------------
	// Performance Settings
	//--------------------------------------

	/** Controls bandwidth and resolution of received video */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Performance")
	EOWLNDIBandwidth Bandwidth = EOWLNDIBandwidth::Highest;

	/** Specify preferred video format to receive */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Performance")
	EOWLNDIColorFormat ColorFormat = EOWLNDIColorFormat::Best;

	//--------------------------------------
	// Advanced Settings
	//--------------------------------------

	/** The sound wave object for audio reception */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	class UOWLNDISoundWave* NDISoundWave = nullptr;

	/** Audio reference level standard for professional audio */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	EOWLNDIAudioReferenceLevel AudioReferenceLevel = EOWLNDIAudioReferenceLevel::Default;

	/** Custom audio scaling factor when using Manual reference level */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio",
		meta=(EditCondition="AudioReferenceLevel == EOWLNDIAudioReferenceLevel::Manual", EditConditionHides,
			ClampMin="0.1", ClampMax="1.0"))
	float CustomAudioScale = 1.0f;

	/** Controls audio/video synchronization */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio")
	EOWLNDIAudioSync AudioSyncMode = EOWLNDIAudioSync::Automatic;

	/** Manual audio delay in milliseconds */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Audio",
		meta=(EditCondition="AudioSyncMode == EOWLNDIAudioSync::Manual", EditConditionHides,
			ClampMin="-500", ClampMax="500"))
	float AudioDelayMs = 0.0f;


	/** Whether to allow receiving fielded video */
	// Removed from UPROPERTY as this setting is primarily controlled by the color format choice.
	// When ColorFormat is set to Fastest or BestQuality, NDI SDK ignores this setting and
	// automatically sets it to true for optimal performance. Setting to true here ensures
	// consistent behavior across all color formats and avoids user confusion.
	bool bAllowVideoFields = true;


	//--------------------------------------
	// Tally Settings
	//--------------------------------------

	/** Set tally state to show source it's visible in program */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tally")
	bool bOnProgram = false;

	/** Set tally state to show source it's visible in preview */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Tally")
	bool bOnPreview = false;

	//--------------------------------------
	// Status Information (Read-Only)
	//--------------------------------------

	/** Current connection status */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	EOWLNDIConnectionStatus ConnectionStatus = EOWLNDIConnectionStatus::Disconnected;

	/** Source information string */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	FString SourceInfo;

	/** Native resolution of connected source */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	FIntPoint SourceResolution = FIntPoint(0, 0);

	/** Frame rate of connected source */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	float SourceFrameRate = 0.0f;

	/** Current bandwidth usage in Mbps */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	float CurrentBandwidthMbps = 0.0f;

	/** Whether source supports PTZ control */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	bool bSourceSupportsPTZ = false;

	/** Whether source has web controls available */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Status")
	bool bSourceHasWebControls = false;

	//--------------------------------------
	// Internal Properties (Not Exposed to UI)
	//--------------------------------------

	/** Internal flag to track if receiver is under external control */
	UPROPERTY(VisibleAnywhere, Category = "Internal")
	bool bUnderExternalControl = false;

	/** Internal flag to track if receiver is running */
	bool IsRunning = false;

	/** Reference to the world */
	UPROPERTY()
	UWorld* World = nullptr;

	/** Flag to track if NDI availability has been checked */
	bool bHasCheckedNDIForActivation = false;

public:
	/** Initialize and start receiving */
	void Start(UWorld* InWorld);

	/** Stop receiving and clean up */
	void End();

	/** Process the next video frame */
	void ReceiveFrame();

	/** Reference to the NDI receiver implementation */
	TSharedPtr<class FOWLNDIReceiver> OWLNDIReceiver = nullptr;

	/** Currently active tally program state */
	bool ActiveOnProgram = false;

	/** Currently active tally preview state */
	bool ActiveOnPreview = false;

private:
	/** Check if the source name has changed */
	bool CheckNameChanged() const;

	/** Check if audio settings have changed */
	bool CheckAudioChanged() const;

	/** Check if bandwidth settings have changed */
	bool CheckBandwidthChanged() const;

	/** Check if color format settings have changed */
	bool CheckColorFormatChanged() const;

	/** Check if any tally settings have changed */
	bool CheckTallyChanged() const;

	/** Update status properties from receiver */
	void UpdateStatusProperties();

	bool CheckOCIOChanged() const;

private:
	/** Check if audio sync settings have changed */
	bool CheckAudioSyncChanged() const;

	/** Check if audio reference level settings have changed */
	bool CheckAudioReferenceChanged() const;

	/** Currently active custom audio scale */
	float ActiveCustomAudioScale = 1.0f;

	/** Currently active source name */
	FString ActiveName = "";

	/** Currently active sound wave */
	class UOWLNDISoundWave* ActiveNDISoundWave = nullptr;

	/** Currently active bandwidth setting */
	EOWLNDIBandwidth ActiveBandwidth = EOWLNDIBandwidth::Highest;

	/** Currently active audio reference level */
	EOWLNDIAudioReferenceLevel ActiveAudioReferenceLevel = EOWLNDIAudioReferenceLevel::Default;

	/** Currently active audio sync mode */
	EOWLNDIAudioSync ActiveAudioSyncMode = EOWLNDIAudioSync::Automatic;
    
	/** Currently active audio delay */
	float ActiveAudioDelayMs = 0.0f;

	/** Currently active color format setting */
	EOWLNDIColorFormat ActiveColorFormat = EOWLNDIColorFormat::Best;

	/** Track the last combination we warned about to avoid spam */
	EOWLNDIColorFormat LastWarnedColorFormat = EOWLNDIColorFormat::Best;
	bool bHasWarnedAboutIncompatibility = false;

	// OCIO
	bool ActiveUseOCIO = false;
	UOpenColorIOConfiguration* ActiveOCIOConfiguration = nullptr;
	FOpenColorIOColorSpace ActiveSourceColorSpace;
	FOpenColorIOColorSpace ActiveDestinationColorSpace;
};

/**
 * NDI Receiver Manager class to manage multiple NDI receivers
 */
UCLASS(BlueprintType, meta=(DisplayName="OWL NDI Receiver Manager"))
class OWLNDI_API AOWLNDIReceiverManager : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Array of NDI receivers managed by this component
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Off World Live NDI Receiver Settings")
	TArray<FOWLNDIReceiverInterface> NDIReceivers;

	/** Returns a list of NDI sources that are available at this moment in time. */
	UFUNCTION(BlueprintCallable, Category = "Off World Live NDI Receiver")
	TArray<struct FNDISource> GetAvailableNDISources();

	/** Constructor */
	AOWLNDIReceiverManager(const FObjectInitializer& ObjectInitializer);

	/* Activates an NDI receiver. True if found, false if not */
	UFUNCTION(BlueprintCallable, Category =  "Off World Live NDI Receiver")
	bool ActivateReceiver(int Index);

	/* Deactivates an NDI receiver. True if found, false if not */
	UFUNCTION(BlueprintCallable, Category =  "Off World Live NDI Receiver")
	bool DeactivateReceiver(int Index);

	//--------------------------------------
	// PTZ Camera Control Blueprint Functions
	//--------------------------------------

	/** Check if a receiver source supports PTZ control */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool IsPTZSupported(int32 ReceiverIndex);

	/** Control pan and tilt for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool PTZPanTilt(int32 ReceiverIndex, float Pan, float Tilt);

	/** Control zoom for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool PTZZoom(int32 ReceiverIndex, float Zoom);

	/** Store current position as a preset for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool PTZStorePreset(int32 ReceiverIndex, int32 PresetNumber);

	/** Recall a preset for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool PTZRecallPreset(int32 ReceiverIndex, int32 PresetNumber, float Speed = 1.0f);

	/** Set auto-focus for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool PTZAutoFocus(int32 ReceiverIndex);

	/** Control manual focus for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | PTZ")
	bool PTZManualFocus(int32 ReceiverIndex, float FocusValue);

	//--------------------------------------
	// Web Control Blueprint Functions
	//--------------------------------------

	/** Get web control URL for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | Advanced")
	FString GetWebControlURL(int32 ReceiverIndex);

	/** Open web control panel for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | Advanced")
	void OpenWebControlPanel(int32 ReceiverIndex);

	//--------------------------------------
	// Tally Control Blueprint Functions
	//--------------------------------------

	/** Set tally state for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | Tally")
	bool SetTallyState(int32 ReceiverIndex, bool bIsOnProgram, bool bIsOnPreview);

	//--------------------------------------
	// Performance and Diagnostics Blueprint Functions
	//--------------------------------------

	/** Get performance metrics for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | Diagnostics")
	void GetPerformanceMetrics(int32 ReceiverIndex, int32& FramesReceived, int32& FramesDropped);

	/** Get queue depths for a specific receiver */
	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | Diagnostics")
	void GetQueueDepths(int32 ReceiverIndex, int32& VideoFramesQueued, int32& AudioFramesQueued);

	UFUNCTION(BlueprintCallable, Category = "NDI Receiver | Diagnostics")
	float GetFrameDropRate(int32 ReceiverIndex);

private:
	/** Flag to track if editor receivers are closed */
	static bool ClosedEditorReceivers;

	/** Process each receiver at the end of frame */
	void OnEndFrame();

	/** Close all active receivers */
	void CloseAllReceivers();

	/** Helper method to check receiver validity */
	bool IsReceiverValid(int32 ReceiverIndex) const;

	TArray<FString> GetOCIOColorSpaces(UOpenColorIOConfiguration* Configuration);
	bool ValidateOCIOConfiguration(UOpenColorIOConfiguration* Configuration);

protected:
	/** Begin play */
	virtual void BeginPlay() override;

	/** End play */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Actor destroyed */
	virtual void Destroyed() override;

	/** Initialize properties */
	virtual void PostInitProperties() override;

	/** Clean up */
	virtual void BeginDestroy() override;

#if WITH_EDITOR
	/** Check if NDI is available */
	void CheckNDIAvailability();
#endif
};


