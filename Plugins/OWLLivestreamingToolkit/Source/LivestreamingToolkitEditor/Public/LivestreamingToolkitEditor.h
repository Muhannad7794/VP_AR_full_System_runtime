// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"

#include "SMediaInputWizard.h"
#include "SMediaOutputWizard.h"
#include "Widgets/SWidget.h"
#include "Framework/Commands/UICommandList.h"
#include "Editor/LevelEditor/Private/SLevelEditor.h"
#include "Modules/ModuleManager.h"
#include "Toolkits/AssetEditorToolkit.h"

class FToolBarBuilder;
class FMenuBuilder;

class FLivestreamingToolkitEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void UseMediaInputWizardButtonClicked();
	void UseMediaOutputWizardButtonClicked();
	void LogInButtonClicked();
	void LogOutButtonClicked();
	void MyAccountButtonClicked();
	void LicenseUtiltyClicked();
	void OnEditorViewportRendering();
	bool IsEditorViewportRenderingEnabled();
	void OnRuntimeViewportRendering();
	bool IsRuntimeViewportRenderingEnabled();
	bool IsAlwaysDisabled();
	void PluginVersionButtonClicked();
	void KnowledgeCentreButtonClicked();
	void VisitWebsiteButtonClicked();
	void VisitDiscordButtonClicked();
	void VideoTutorialsButtonClicked();

private:

	void RegisterMenus();
	bool IsLogInButtonVisible();
	bool IsLogOutButtonVisible();

	TSharedRef<SDockTab> MakeMediaOutputWizardTab( const FSpawnTabArgs& );
	TSharedRef<SWidget> GetMediaOutputWizard(const TSharedRef<SDockTab>& InParentTab);

	TSharedRef<SDockTab> MakeMediaInputWizardTab( const FSpawnTabArgs& );
	TSharedRef<SWidget> GetMediaInputWizard(const TSharedRef<SDockTab>& InParentTab);

	void Load();
	void Save();

private:
	const FName PlacementModeCategoryHandle = TEXT("OffWorldLive");
	void RegisterWizardTabSpawner();
	void RegisterAndMapPluginCommands();
	void RegisterDetailsCustomisation();
	void RegisterPlacementModeExtensions();
	void RegisterPlacementModeItems(const struct FPlacementCategoryInfo* Info);
	void UnregisterPlacementModeExtensions();

	TSharedPtr<class FUICommandList> PluginCommands;
	TSharedRef<SWidget> FillComboButton(TSharedPtr<class FUICommandList> Commands);
	FDelegateHandle OnUpgradeAvailableHandle;
	void OnUpgradeAvailable(FString NewVersion, FString DownloadURL);
	void OnNewUpdateDownloadNowClicked(FString DownloadURL);
	void OnNewUpdateRemindMeLaterClicked();
	void OnNewUpdateSkipVersionClicked();
	void OnOpenSourceLicensesClicked();
	void AddLicenceWidget(FMenuBuilder& MenuBuilder, const uint32 Feature, const uint32 BasicFeature = 0);

	FDelegateHandle OnEditorInitialised;
	void PopupDemoLicenceRequest(double Duration);

	/** Notification popup that new plugins are available */
	TWeakPtr<SNotificationItem> NewPluginsNotification;

	FString AvailableVersionHash = "";
	bool SkipVersion = false;

	FDelegateHandle OnFEngineLoopInitCompleteHandle;
	/** Holds the cine stream wizard singleton. */
	TWeakPtr<SMediaOutputWizard> MediaOutputWizardPtr;
	/** Holds the media input wizard singleton. */
	TWeakPtr<SMediaInputWizard> MediaInputWizardPtr;
};


