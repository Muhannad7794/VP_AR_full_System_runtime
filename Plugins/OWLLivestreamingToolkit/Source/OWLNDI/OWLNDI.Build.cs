// Copyright Off World Live Limited, 2020-2025. All rights reserved.

using UnrealBuildTool;
using System.IO;
using EpicGames.Core;

public class OWLNDI : ModuleRules
{
	public OWLNDI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		bUsePrecompiled = GetOffWorldBoolean("UsePrecompiled", true);

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);

		PrivateIncludePaths.AddRange(
			new string[]
			{
				"ThirdParty/NDIRaw/Includes",
				"OWLNDI/Private",
				"LivestreamingToolkit/Private/Tools",
				"LivestreamingToolkit/Public/Tools",
				"LivestreamingToolkit/Private/Telemetry",
				"LivestreamingToolkit/Private/ServerAuth"
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"NDIRaw",
				"OpenColorIO",
				"MediaIOCore",
				"Media",
				"MediaAssets",
				"MediaPlate",
				// ... add other public dependencies that you statically link with here ...
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"RHI",
				"RHICore",
				"AudioExtensions",
				"RenderCore",
				"Renderer",
				"Projects",
				"NDIRaw",
				"LivestreamingToolkitShaders",
				"LivestreamingToolkit",
				"Json",
				"JsonUtilities",
				"XmlParser",
				"MediaUtils",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...
			}
		);

		if (Target.Type == TargetType.Editor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"UnrealEd", // Editor-only dependency
					"AssetTools", // Editor-only for asset actions
					"ToolMenus", // Editor-only for FToolMenuSection
					"MediaPlayerEditor", // For media source editor toolkit
					"EditorStyle", // For editor styling
					"EditorWidgets", // For editor widgets
					"ContentBrowser", // For content browser integration
				}
			);
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);

		if ((Target.Platform == UnrealTargetPlatform.Win64))
		{
		}

		if (Target.bBuildEditor)
		{
			PrivateIncludePaths.AddRange(
				new string[]
				{
				}
			);

			PublicIncludePaths.AddRange(
				new string[]
				{
				}
			);

			// Add editor-only dependencies
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
				}
			);
		}
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
