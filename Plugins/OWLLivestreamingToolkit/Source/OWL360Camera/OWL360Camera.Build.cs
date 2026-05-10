// Copyright Off World Live Limited, 2020-2022. All rights reserved.

using UnrealBuildTool;
using System.Net;
using System.IO;
using System;
using EpicGames.Core;

public class OWL360Camera : ModuleRules
{
	public OWL360Camera(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		bUsePrecompiled = GetOffWorldBoolean("UsePrecompiled", true);
		PublicDefinitions.Add("OFFWORLDLIVE_DEBUG=" + (GetOffWorldBoolean("Debug", false) ? "1" : "0"));

		PublicIncludePaths.AddRange(
			new string[] {
			});

		string EngineDir = Path.GetFullPath(Target.RelativeEnginePath);
		PrivateIncludePaths.AddRange(
				new string[] {
					Path.Combine(EngineDir, "Source/Runtime/Renderer/Internal"),
					"OWLCamera/Private",
					"OWL360Camera/Private",
					"OWL360Camera/Private/PostProcessing",
					"LivestreamingToolkitShaders/Private",
					"LivestreamingToolkit/Private/Telemetry",
					"LivestreamingToolkit/Private/ServerAuth",
					"LivestreamingToolkit/Private/Tools",
				}
		);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"RHI",
				"RHICore",
				"Renderer",
				"RenderCore",
				"Json",
				"JsonUtilities",
				"HTTP",
				"ApplicationCore",
				"Media",
				"MediaAssets",
				"MediaUtils",
				"LivestreamingToolkitShaders",
				"OWLCamera",
				"OpenColorIO",
				// ... add other public dependencies that you statically link with here ...
			});


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Renderer",
				"ImageWrapper",
				"RenderCore",
				"Projects",
				"Media",
				"MediaAssets",
				"MediaUtils",
				"EngineSettings",
				"LivestreamingToolkitShaders",
				"LivestreamingToolkit",
				"OWLBranding",
				// ... add private dependencies that you statically link with here ...
			});

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(new string[]{
				"UnrealEd",
				"Slate",
				"SlateCore",
				"EditorStyle",
			});
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
	public string GetOffWorldString(string Key, string defaultValue = "")
	{
		try
		{
			return GetOffWorldSettings().GetStringField(Key);
		}
		catch
		{
			return defaultValue;
		}
	}
}

