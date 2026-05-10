// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "MediaCapture.h"
#include "Engine/TextureRenderTarget2D.h"
#include "OWLSpoutSender.h"
#include "RenderGraphBuilder.h"
#include "Containers/Ticker.h"
#include "Engine/Engine.h"
#include "OWLSpoutMediaCapture.generated.h"

class UOWLSpoutMediaOutput;

/**
 * Implementation of media capture for Spout.
 * This class handles the actual capturing and sending of render targets via Spout.
 */
UCLASS(BlueprintType)
class OWLSPOUT_API UOWLSpoutMediaCapture : public UMediaCapture
{
	GENERATED_BODY()

public:
	// === LIFECYCLE ===
	UOWLSpoutMediaCapture();
	virtual ~UOWLSpoutMediaCapture();

	// === CONFIGURATION ===
	/** Configure Spout settings (called by UOWLSpoutMediaOutput) */
	void SetSpoutConfiguration(const FString& InSenderName, bool InFixGamma, bool InHasPriority);

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
	FString SpoutSenderName;
	FString ActualSenderName;
	bool bFixGamma;
	bool bHasPriority;
	bool bIsInitialized;

	// === SPOUT INTEGRATION ===
	TSharedPtr<FOWLSpoutSender, ESPMode::ThreadSafe> DirectSpoutSender;
	FString SenderUUID; // UUID for the sender controller

	TSharedPtr<FOWLSpoutSender, ESPMode::ThreadSafe> SpoutSenderRef;
	bool bSenderInitialized = false;

	// === RENDER TARGET MANAGEMENT ===
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> SpoutRenderTarget;
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

	// Spout Operations
	void SendToSpoutDirectly_RenderThread(FTextureRHIRef SourceTexture, const FCaptureBaseData& InBaseData);

	// State Management
	bool MonitorStateChanges(float DeltaTime);

	// Cleanup
	void CleanupSpoutSender();

	// Utilities
	FString GenerateUniqueUUID() const;
};


