// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "MediaCapture.h"
#include "Engine/TextureRenderTarget2D.h"
#include "NDIEnums.h"
#include "Sound/SoundSubmix.h"
#include "RenderGraphBuilder.h"
#include "Containers/Ticker.h"
#include "Engine/Engine.h"
#include "OWLNDIMediaCapture.generated.h"

class UOWLNDIMediaOutput;
class FOWLNDISender;

/**
 * Implementation of media capture for NDI.
 * This class handles the actual capturing and sending of render targets via NDI.
 */
UCLASS(BlueprintType)
class OWLNDI_API UOWLNDIMediaCapture : public UMediaCapture
{
	GENERATED_BODY()

public:
	// === LIFECYCLE ===
	UOWLNDIMediaCapture();
	virtual ~UOWLNDIMediaCapture();

	// === CONFIGURATION ===
	/** Configure NDI settings (called by UOWLNDIMediaOutput) */
	void SetNDIConfiguration(const FString& InSenderName, 
		ENDIVideoConversionFormat InVideoFormat,
		bool InCaptureAudio, 
		USoundSubmix* InAudioSubmix,
		bool InHasPriority);

protected:
	// === INITIALIZATION ===
	virtual bool InitializeCapture() override;
	virtual bool PostInitializeCaptureViewport(TSharedPtr<FSceneViewport>& InSceneViewport) override;
	virtual bool PostInitializeCaptureRenderTarget(UTextureRenderTarget2D* InRenderTarget) override;
	virtual bool PostInitializeCaptureRHIResource(const FRHICaptureResourceDescription& InResourceDescription) override;

	// === FRAME CAPTURE PIPELINE (RENDER THREAD) ===
	virtual void OnRHIResourceCaptured_RenderingThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FTextureRHIRef InTexture
	) override;
	
	virtual void BeforeFrameCaptured_RenderingThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FTextureRHIRef InTexture
	) override;

	// === FRAME CAPTURE PIPELINE (ANY THREAD) ===
	virtual void OnRHIResourceCaptured_AnyThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		FTextureRHIRef InTexture
	) override;
	
	virtual void OnFrameCaptured_AnyThread(
		const FCaptureBaseData& InBaseData,
		TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> InUserData,
		const FMediaCaptureResourceData& InResourceData
	) override;
	
	virtual TSharedPtr<FMediaCaptureUserData, ESPMode::ThreadSafe> GetCaptureFrameUserData_GameThread() override;

	// === UPDATE OPERATIONS ===
	virtual bool UpdateSceneViewportImpl(TSharedPtr<FSceneViewport>& InSceneViewport) override;
	virtual bool UpdateRenderTargetImpl(UTextureRenderTarget2D* InRenderTarget) override;
	virtual bool UpdateAudioDeviceImpl(const FAudioDeviceHandle& InAudioDeviceHandle) override;

	// === CLEANUP ===
	virtual void StopCaptureImpl(bool bAllowPendingFrameToBeProcess) override;

	// === VALIDATION & CONFIGURATION ===
	virtual bool ValidateMediaOutput() const override;
	virtual FIntPoint GetCustomOutputSize(const FIntPoint& InSize) const override;
	virtual EPixelFormat GetCustomOutputPixelFormat(const EPixelFormat& InPixelFormat) const override;
	virtual EMediaCaptureResourceType GetCustomOutputResourceType() const override;

	// === CAPABILITY QUERIES ===
	virtual bool ShouldCaptureRHIResource() const override;
	virtual bool SupportsAnyThreadCapture() const override;
	virtual bool HasFinishedProcessing() const override;

	// === GPU MANAGEMENT ===
	virtual void SetValidSourceGPUMask(FRHIGPUMask InSourceGPUMask) override;

private:
	// === CONFIGURATION DATA ===
	FString NDISenderName;
	FString ActualSenderName;
	ENDIVideoConversionFormat VideoConversionFormat;
	bool bCaptureAudio;
	
	UPROPERTY()
	TObjectPtr<USoundSubmix> AudioSubmix;
	
	bool bHasPriority;
	bool bIsInitialized;

	// === NDI INTEGRATION ===
	FString SenderUUID; // UUID for the NDI sender controller

	TSharedPtr<FOWLNDISender, ESPMode::ThreadSafe> NDISenderRef;
	bool bSenderInitialized = false;

	// === RENDER TARGET MANAGEMENT ===
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> NDIRenderTarget;
	FIntPoint CaptureSize;
	EPixelFormat CapturePixelFormat;
	FThreadSafeBool bCreatingRenderTarget; // Prevents multiple RT creation attempts

	// === THREAD SAFETY ===
	mutable FCriticalSection CriticalSection;

	// === STATE MONITORING ===
	FTSTicker::FDelegateHandle StateMonitorHandle;
	EMediaCaptureState LastKnownState = EMediaCaptureState::Stopped;

	// === HELPER METHODS ===
	// Resource Management
	UTextureRenderTarget2D* CreateCompatibleRenderTarget(int32 Width, int32 Height, EPixelFormat PixelFormat);
	bool EnsureCompatibleRenderTarget_RenderThread(int32 Width, int32 Height, EPixelFormat PixelFormat);
	bool AreTexturesCompatible(FTextureRHIRef Source, FTextureRHIRef Dest) const;

	// NDI Operations
	void SendToNDIDirectly_RenderThread(FTextureRHIRef SourceTexture, const FCaptureBaseData& InBaseData);

	// State Management
	bool MonitorStateChanges(float DeltaTime);

	// Cleanup
	void CleanupNDISender();

	// Utilities
	FString GenerateUniqueUUID() const;
};

