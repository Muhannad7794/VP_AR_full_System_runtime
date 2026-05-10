// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "OWLTextureFormats.h"
#include "OWLNDISoundWave.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include "RHICommandList.h"
#include "Processing.NDI.Lib.h"
#include "Processing.NDI.Lib.cplusplus.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "OWLTextureFormats.h"
#include "OWLNDIReceiverManager.h"
#include "Containers/CircularQueue.h"

// Forward declarations
class FOWLNDIReceiverShader;
class UOpenColorIOConfiguration;
struct FOpenColorIOColorSpace;
enum class EOWLNDIColorFormat : uint8;
enum class EOWLNDIBandwidth : uint8;
class FXmlNode;

// Queued video frame structure (audio uses FrameSync directly)
struct FOWLQueuedVideoFrame
{
	NDIlib_video_frame_v2_t Frame;
	double ReceiveTime;
	double TargetDisplayTime;
	NDIlib_framesync_instance_t FrameSyncInstance; // Needed for cleanup since we get frames from FrameSync

	FOWLQueuedVideoFrame() : ReceiveTime(0.0), TargetDisplayTime(0.0), FrameSyncInstance(nullptr)
	{
		FMemory::Memzero(&Frame, sizeof(Frame));
	}

	~FOWLQueuedVideoFrame()
	{
		// NDI frames from FrameSync must be freed properly
		if (Frame.p_data && FrameSyncInstance)
		{
			NDIlib_framesync_free_video(FrameSyncInstance, &Frame);
		}
	}

	// Move constructor/assignment to handle NDI frame ownership
	FOWLQueuedVideoFrame(FOWLQueuedVideoFrame&& Other) noexcept
	{
		Frame = Other.Frame;
		ReceiveTime = Other.ReceiveTime;
		TargetDisplayTime = Other.TargetDisplayTime;
		FrameSyncInstance = Other.FrameSyncInstance;

		// Clear the source to prevent double-free
		FMemory::Memzero(&Other.Frame, sizeof(Other.Frame));
		Other.FrameSyncInstance = nullptr;
	}

	FOWLQueuedVideoFrame& operator=(FOWLQueuedVideoFrame&& Other) noexcept
	{
		if (this != &Other)
		{
			// Clean up current frame
			if (Frame.p_data && FrameSyncInstance)
			{
				NDIlib_framesync_free_video(FrameSyncInstance, &Frame);
			}

			// Move from other
			Frame = Other.Frame;
			ReceiveTime = Other.ReceiveTime;
			TargetDisplayTime = Other.TargetDisplayTime;
			FrameSyncInstance = Other.FrameSyncInstance;

			// Clear the source
			FMemory::Memzero(&Other.Frame, sizeof(Other.Frame));
			Other.FrameSyncInstance = nullptr;
		}
		return *this;
	}

	// Delete copy constructor/assignment - NDI frames can't be copied
	FOWLQueuedVideoFrame(const FOWLQueuedVideoFrame&) = delete;
	FOWLQueuedVideoFrame& operator=(const FOWLQueuedVideoFrame&) = delete;
};

struct FOWLNDIFrameMetadata
{
	EOWLNDIColourLayout Colour;
	bool bMetadataPresent = false;

	FOWLNDIFrameMetadata() = default;
	FOWLNDIFrameMetadata(const FString& Metadata);

	void ParseXML(const FString& Metadata);
	void ParseNdiColorInfoNode(const FXmlNode* Node);
	static EOWLNDIColorSpace FromString(const FString& ColorSpace);
};

class OWLNDI_API FOWLNDIReceiver
{
	// Declare friendship to allow FOWLNDIReceiverInterface to access private members
	friend struct FOWLNDIReceiverInterface;

public:
	FOWLNDIReceiver();
	~FOWLNDIReceiver();

	bool Init(FString Name, UOWLNDISoundWave* InNDISoundWave = nullptr,
	          EOWLNDIColorFormat ColorFormat = EOWLNDIColorFormat::Best,
	          EOWLNDIBandwidth Bandwidth = EOWLNDIBandwidth::Highest,
	          bool bAllowVideoFields = false);

	void DeInit();

	void ReceiveVideoFrame(
		UTextureRenderTarget2D* DstTarget,
		bool bConvertGamma,
		bool bInUseOCIO = false,
		UOpenColorIOConfiguration* InOCIOConfig = nullptr,
		const FOpenColorIOColorSpace& InSourceSpace = FOpenColorIOColorSpace(),
		const FOpenColorIOColorSpace& InDestSpace = FOpenColorIOColorSpace()
	);

	/** Apply OCIO color conversion to the render target */
	void ApplyOCIOConversion(UTextureRenderTarget2D* RenderTarget,
	                         UOpenColorIOConfiguration* OCIOConfig,
	                         const FOpenColorIOColorSpace& SourceSpace,
	                         const FOpenColorIOColorSpace& DestSpace);

	int32 ReceiveAudioFrame(uint8* PCMData, const int32 SamplesNeeded);

	// PTZ Camera Control Methods
	bool IsPTZSupported() const;
	bool PTZPanTilt(float Pan, float Tilt);
	bool PTZZoom(float Zoom);
	bool PTZStorePreset(int32 PresetNumber);
	bool PTZRecallPreset(int32 PresetNumber, float Speed);
	bool PTZAutoFocus();
	bool PTZManualFocus(float FocusValue);

	// Tally Control
	bool SetTallyState(bool bIsOnProgram, bool bIsOnPreview);

	// Web Control
	FString GetWebControlURL() const;
	bool HasWebControls() const;

	// Status and Performance
	void GetPerformanceMetrics(int32& FramesReceived, int32& FramesDropped) const;
	void GetQueueDepths(int32& VideoFramesQueued, int32& AudioFramesQueued) const;
	FIntPoint GetSourceResolution() const;
	float GetSourceFrameRate() const;
	float GetCurrentBandwidth() const;
	float GetFrameDropRate() const;

	void SetAudioReferenceLevel(EOWLNDIAudioReferenceLevel ReferenceLevel, float CustomScale = 1.0f);

	EOWLNDIAudioReferenceLevel GetAudioReferenceLevel() const { return AudioReferenceLevel; }
	EOWLTexturePixelFormat GetCurrentVideoFormat() const { return CurrentVideoFormat; }

	/**
	 * @param DelayMs Manual video delay in milliseconds (positive = video later, negative = video earlier)
	 */
	void SetAudioSyncMode(EOWLNDIAudioSync SyncMode, float DelayMs = 0.0f);

	void GetVideoQueueStatistics(int32& VideoQueueDepth, int32& VideoDropped) const;

private:
	NDIlib_recv_instance_t Receiver = {nullptr};
	NDIlib_framesync_instance_t FrameSync = {nullptr}; // Used for audio only
	FString ReceiverName;
	bool Initialised = false;

	/**
	 * Video processing components (queue-based for precise timing)
	 */
	TSharedPtr<FOWLNDIReceiverShader, ESPMode::ThreadSafe> ReceiverShader;
	EOWLTexturePixelFormat CurrentVideoFormat;
	TAtomic<uint32> FrameWidth;
	TAtomic<uint32> FrameHeight;
	FCriticalSection Video_CS;
	bool Video_Initialised = false;
	EOWLNDIColorFormat ActiveColorFormat = EOWLNDIColorFormat::Best;

	/**
	 * Video queue for precise timing control
	 */
	TCircularQueue<TSharedPtr<FOWLQueuedVideoFrame>> VideoFrameQueue;
	static constexpr int32 MAX_VIDEO_QUEUE_SIZE = 120; // 2 seconds at 60fps
	static constexpr float MAX_DELAY_MS = 500.0f;

	// Video timing control
	double BaseTimeReference = 0.0;
	float ActiveVideoDelayMs = 0.0f; // Applied delay for video

	// Video queue statistics
	mutable uint32 QueuedVideoFramesDropped = 0;

	UOWLNDISoundWave* NDISoundWave = nullptr;
	FCriticalSection Audio_CS;
	bool Audio_Initialised = false;

	EOWLNDIAudioReferenceLevel AudioReferenceLevel = EOWLNDIAudioReferenceLevel::Default;
	float CustomAudioScale = 1.0f;
	float CurrentAudioScale = 1.0f;
	EOWLNDIAudioSync AudioSyncMode = EOWLNDIAudioSync::Automatic;

	/**
	 * Frame rate tracking (actual values from NDI)
	 */
	TAtomic<int32> FrameRateN; // Numerator
	TAtomic<int32> FrameRateD; // Denominator

	uint64 TotalBytesReceived = 0;
	double BandwidthMeasurementStartTime = 0.0;
	TAtomic<float> MeasuredBandwidthMbps;
	FCriticalSection BandwidthCS;
	const double BandwidthUpdateInterval = 1.0; // Update bandwidth calculation every second

	/**
	 * OCIO color management
	 */
	bool bUseOCIO = false;
	UOpenColorIOConfiguration* OCIOConfiguration = nullptr;
	FOpenColorIOColorSpace SourceColorSpace;
	FOpenColorIOColorSpace DestinationColorSpace;

	bool bHasEmittedPixelWarning = false;
	bool bHasEmittedConversionError = false;

	static EOWLTexturePixelFormat NDIToOWLFormat(NDIlib_FourCC_video_type_e VideoFormat);
	void UpdateAudioScaling();
	void UpdateTallyState();
	bool ConvertNDIPerformanceMetrics(int32& FramesReceived, int32& FramesDropped) const;

	void ProcessVideoFrameByFormat_RT(
		UTextureRenderTarget2D* DstTarget,
		const NDIlib_video_frame_v2_t& VideoFrame,
		bool bConvertGamma);

	void ReceiveAndQueueVideoFrames();
	bool ShouldDisplayVideoFrame(const FOWLQueuedVideoFrame& Frame) const;
	void DisplayQueuedVideoFrame(const FOWLQueuedVideoFrame& Frame, UTextureRenderTarget2D* DstTarget, bool bConvertGamma);
	void CleanupExpiredVideoFrames();
	void ClearVideoQueue();

	int32 ProcessAudioFrameWithFrameSync(uint8* PCMData, const int32 SamplesNeeded);

	/**
	* Frame-behind OCIO processing members
	*/
	UTextureRenderTarget2D* PreviousFrameForOCIO = nullptr;
	bool bPendingOCIOConversion = false;

	// Store OCIO settings for the pending frame
	bool bPendingUseOCIO = false;
	UOpenColorIOConfiguration* PendingOCIOConfiguration = nullptr;
	FOpenColorIOColorSpace PendingSourceColorSpace;
	FOpenColorIOColorSpace PendingDestinationColorSpace;
};


