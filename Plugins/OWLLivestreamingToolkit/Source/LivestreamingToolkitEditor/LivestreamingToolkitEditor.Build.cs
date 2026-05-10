// Copyright Off World Live Limited, 2020-2022. All rights reserved.

using UnrealBuildTool;
using System.IO;
using EpicGames.Core;

public class LivestreamingToolkitEditor : ModuleRules
{
	public LivestreamingToolkitEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		bUsePrecompiled = GetOffWorldBoolean("UsePrecompiled", true);

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
		);

		PrivateIncludePaths.AddRange(
			new string[] {
				"LivestreamingToolkit/Private",
				// ... add other private include paths required here ...
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"RenderCore",
				"OpenColorIO",
				"OpenColorIOEditor",
				"MediaPlate",
				"MediaAssets",
				"AudioMixer",
				// ... add other public dependencies that you statically link with here ...
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"AssetRegistry",
				"CoreUObject",
				"InputCore",
				"Projects",
				"UnrealEd",
				"ToolMenus",
				"Engine",
				"SlateCore",
				"LivestreamingToolkit",
				"OWLCamera",
				"OWLSpout",
				"EditorStyle",
				"RHI",
				"RHICore",
				"CinematicCamera",
				"PlacementMode",
				"OWLBranding",
				"OWLNDI",
				"OWL360Camera",
				"OWLComposure",
				"OWLMedia",
				"BlueprintGraph",
				"OWLVirtualWebcam",
				"OWLScreenCapture",
				"PropertyEditor",
				"GameProjectGeneration",
				"MediaAssets",
				"AudioEditor", 
				"MediaPlate",
				"DesktopWidgets",
				"AudioMixer",
				// ... add private dependencies that you statically link with here ...
			}
		);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
	public JsonObject GetOffWorldSettings()
	{
		string RootDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../"));
		string UPluginPath = Path.Combine(RootDir, "OWLLivestreamingToolkit.uplugin");
		string RawString = File.ReadAllText(UPluginPath);
		JsonObject UPluginJson = JsonObject.Parse(RawString);
		return UPluginJson.GetObjectField("OffWorldLive");
	}
	public bool GetOffWorldBoolean(string Key, bool defaultValue = false)
	{
		try
		{
			return GetOffWorldSettings().GetBoolField(Key);
		}
		catch
		{
			return defaultValue;
		}
	}
}

