// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Misc/Paths.h"
#include "OWLSettings.generated.h"

/**
 *
 */
UCLASS(config=Game, defaultconfig, meta=(DisplayName="Off World Live"))
class LIVESTREAMINGTOOLKIT_API UOWLSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UOWLSettings();
#if WITH_EDITOR
	//~ UDeveloperSettings interface
	virtual FText GetSectionText() const override;
	
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	/* NDI Options */
	UPROPERTY(config, EditAnywhere, Category="NDI", meta=(
		ConsoleVariable="bAutoLaunchNDIInstaller", DisplayName="Launch NDI Installer Automatically",
		ToolTip = "If the NDI SDK is not installed, launch a prompt to download and run the SDK installer"
		))
	bool bAutoLaunchNDIInstaller = false;

	UPROPERTY(config, EditAnywhere, Category="Media Output", meta=(
		ConsoleVariable="bDisableHardwareEncoding", DisplayName="Disable Unreal NVEnc implementation",ConfigRestartRequired=true,
		ToolTip = "By default, OWL Media Output uses Unreal's implementation of the NVidia NVEnc hardware h264 encoder. By disabling it there is a slight frame-rate loss, but can enable you to run than one h264 media outputs."
		))
	bool bDisableHardwareEncoding = false;

	UPROPERTY(config, EditAnywhere, Category="Authentication", meta=(
		ConsoleVariable="bSuppressLoginPopup", DisplayName="Suppress login pop-up",
		ToolTip = "Without a machine (node-locked) license, users of the plugin are requested to sign in on our website by default. When ticked, this suppresses the launch of that website."
		))
	bool bSuppressLoginPopup = false;

	UPROPERTY(config, EditAnywhere, Category="Licensing", meta=(
		ConsoleVariable="bUseApplicationLicense", DisplayName="Enable application licenses",
		ToolTip = "Enable in order to disable default authentication for Off World Live and check for application licences instead in packaged games"
		))
	bool bUseApplicationLicense = false;

	UPROPERTY(config, EditAnywhere, Category="Licensing", meta=(
		ConsoleVariable="bEnableOWLDemoLicences", DisplayName="Check for demo licenses",
		ToolTip = "When enabled, a request will be made to the Off World Live servers to check whether there are any products with demo licenses available for you.\r\nIf available, they will be automatically enabled after authentication.",
		ConfigRestartRequired=false
		))
	bool bEnableOWLDemoLicences = false;

	UPROPERTY(config, BlueprintReadWrite, Category="Login Popups", meta=(
		ConsoleVariable="bDemoLicencePopupDismissed"
		))
	bool bDemoLicencePopupDismissed = false;

	UPROPERTY(EditAnywhere, Category="Camera Output", meta=(
			RelativePath,
			DisplayName="Camera Render Output Path",
			ToolTip = "The directory path where camera snapshots will be saved to."
			))
	FDirectoryPath CameraRenderOutputPath = FDirectoryPath(FPaths::Combine(*FPaths::ProjectSavedDir(), TEXT("OWLCameraOutput")));

private:
	UPROPERTY(config, EditAnywhere, Category="Camera Output", meta=(
		ConsoleVariable="OWLCameraRenderOutputPath",
		EditConditionHides, EditCondition="false" 
		))
	FString CameraRenderOutputPathString = CameraRenderOutputPath.Path;

	void SetCameraRenderOutputPath(FDirectoryPath NewPath);
	
public:
	bool static GetAutoLaunchNDIInstaller();
	bool static GetDisableHardwareEncoding();
	bool static GetSuppressLoginPopup();
	bool static GetUseApplicationLicense();
	FDirectoryPath static GetCameraRenderOutputPath();
};


