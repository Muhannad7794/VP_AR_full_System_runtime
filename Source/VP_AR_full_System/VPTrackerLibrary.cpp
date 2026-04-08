#include "VPTrackerLibrary.h"
#include "Features/IModularFeatures.h"
#include "ILiveLinkClient.h"
#include "LiveLinkSourceFactory.h"
#include "UObject/UObjectIterator.h"

void UVPTrackerLibrary::ForceStartZEDLiveLink(FString ConnectionString)
{
	// Get the core Unreal Engine Live Link System
	if (IModularFeatures::Get().IsModularFeatureAvailable(ILiveLinkClient::ModularFeatureName))
	{
		ILiveLinkClient* LiveLinkClient = &IModularFeatures::Get().GetModularFeature<ILiveLinkClient>(ILiveLinkClient::ModularFeatureName);

		// Search the engine for Stereolabs' hidden source factory
		for (TObjectIterator<UClass> It; It; ++It)
		{
			if (It->IsChildOf(ULiveLinkSourceFactory::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract))
			{
				FString FactoryName = It->GetName();
				if (FactoryName.Contains(TEXT("ZED")) || FactoryName.Contains(TEXT("Stereo")))
				{
					ULiveLinkSourceFactory* Factory = It->GetDefaultObject<ULiveLinkSourceFactory>();

					// Force the factory to open the network port using your IP
					TSharedPtr<ILiveLinkSource> NewSource = Factory->CreateSource(ConnectionString);
					if (NewSource.IsValid())
					{
						LiveLinkClient->AddSource(NewSource);
						UE_LOG(LogTemp, Warning, TEXT("VP_TRACKER: Successfully forced ZED Live Link Source creation!"));
						return;
					}
				}
			}
		}
		UE_LOG(LogTemp, Error, TEXT("VP_TRACKER: Failed to find the ZED Factory."));
	}
}