// Copyright Off World Live Limited 2020-2025. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "OWLStereoRenderingTypes.generated.h"

UENUM(BlueprintType)
enum class EOWLStereoOutputViewMode : uint8
{
	SOVM_TopBottom UMETA(DisplayName="Top-Bottom"),
	SOVM_SideBySide UMETA(DisplayName="Side-by-Side"),
	SOVM_Anaglyph UMETA(DisplayName="Anaglyph"),
	SOVM_Interlace UMETA(DisplayName="Interlace"),
};

UENUM(BlueprintType)
enum class EOWLInterlaceType : uint8
{
	IT_Row UMETA(DisplayName = "Row Interlaced"),
	IT_Column UMETA(DisplayName = "Column Interlaced"),
	IT_Checkerboard UMETA(DisplayName = "Checkerboard")
};

UENUM(BlueprintType)
enum class EOWLAnaglyphType : uint8
{
	AT_RedCyan UMETA(DisplayName = "Red-Cyan"),
	AT_GreenMagenta UMETA(DisplayName = "Green-Magenta"),
	AT_YellowBlue UMETA(DisplayName = "Yellow-Blue")
};

UENUM(BlueprintType)
enum class EOWLStereoUMGMode : uint8
{
	SUMG_BothEyes UMETA(DisplayName="Both Eyes (Identical)"),
	SUMG_LeftEyeOnly UMETA(DisplayName="Left Eye Only"), 
	SUMG_RightEyeOnly UMETA(DisplayName="Right Eye Only"),
	SUMG_Disabled UMETA(DisplayName="Disabled")
};

// Configuration struct for stereo rendering settings
USTRUCT(BlueprintType)
struct FOWLStereoRenderingConfig
{
	GENERATED_BODY()

	/** Whether to enable stereoscopic output */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|General",
		meta = (DisplayName = "Enable Stereoscopic Output", 
		ToolTip = "Enables stereoscopic rendering for 3D displays and VR"))
	bool bIsStereo = false;
	
	// STEREOSCOPIC OUTPUT SETTINGS
	
	/** Select how stereoscopic 3D content is displayed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|General",
		meta = (DisplayName = "Output View Mode", 
		ToolTip = "Select how stereoscopic 3D content is displayed: Top-Bottom, Side-by-Side, Anaglyph (colored glasses), or Interlaced"))
	EOWLStereoOutputViewMode OutputViewMode = EOWLStereoOutputViewMode::SOVM_TopBottom;
	
	// ANAGLYPH SETTINGS
	
	/** Choose color filter combination for anaglyph glasses */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Anaglyph",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Anaglyph",
		DisplayName = "Anaglyph Type",
		ToolTip = "Choose color filter combination for anaglyph glasses: Red-Cyan (most common), Green-Magenta, or Yellow-Blue"))
	EOWLAnaglyphType AnaglyphType = EOWLAnaglyphType::AT_RedCyan;
	
	// SIDE-BY-SIDE SETTINGS
	
	/** Enable for cross-eye viewing method, disable for parallel viewing method */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Side-by-Side", 
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_SideBySide", 
		EditConditionHides,
		DisplayName = "Cross Eye Mode",
		ToolTip = "Enable for cross-eye viewing method, disable for parallel viewing method"))
	bool bCrossEyeMode = false;

	// INTERLACE SETTINGS
	
	/** Select interlace pattern type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Interlace",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace",
		DisplayName = "Interlace Type",
		ToolTip = "Select interlace pattern: Row (horizontal lines), Column (vertical lines), or Checkerboard pattern"))
	EOWLInterlaceType InterlaceType = EOWLInterlaceType::IT_Row;

	/** Size of each checkerboard cell in pixels */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Interlace",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace && InterlaceType == EOWLInterlaceType::IT_Checkerboard", 
		UIMin = "1.0", UIMax = "32.0", ClampMin = "1.0", ClampMax = "64.0",
		DisplayName = "Checkerboard Size",
		ToolTip = "Size of each checkerboard cell in pixels. Larger values create a coarser pattern"))
	float CheckerboardSize = 8.0f;

	/** Smoothness of transitions between left and right eye views */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Interlace",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace", 
		UIMin = "0.0", UIMax = "1.0",
		DisplayName = "Blend Factor",
		ToolTip = "Controls how smoothly left and right eye views blend together. Higher values create softer transitions"))
	float BlendFactor = 0.1f;

	/** Amount of anti-aliasing applied to reduce visible patterns */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Interlace",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace", 
		UIMin = "0.0", UIMax = "1.0",
		DisplayName = "Anti-Aliasing Amount",
		ToolTip = "Reduces visible jagged edges and patterns. Higher values create smoother but potentially blurrier results"))
	float AntiAliasingAmount = 0.2f;

	/** Fine-tune interlace pattern position */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Interlace",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace",
		DisplayName = "Pattern Offset",
		ToolTip = "Shifts the interlace pattern to fine-tune alignment. Useful for custom displays or to adjust for viewer position"))
	float PatternOffset = 0.5f;

	/** Swap which eye is shown in each interlaced segment */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|Interlace",
		meta = (EditCondition = "OutputViewMode == EOWLStereoOutputViewMode::SOVM_Interlace",
		DisplayName = "Swap Left Right",
		ToolTip = "Swaps which eye is shown in each interlaced segment. Toggle this if depth appears inverted"))
	bool bSwapLeftRight = false;

	// UMG/HUD SETTINGS

	/** How to render UMG widgets in stereo mode */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stereoscopic Output|UMG",
		meta = (DisplayName = "UMG Stereo Mode",
		ToolTip = "Controls how UMG widgets are rendered in stereoscopic mode"))
	EOWLStereoUMGMode UMGStereoMode = EOWLStereoUMGMode::SUMG_BothEyes;

	// CONVERGENCE EYE SETTINGS

	/** Physical separation between virtual cameras in world units */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence|Eye Settings",
		meta = (UIMin = "0.1", UIMax = "10.0", ClampMin = "0.01",
		DisplayName = "Eye Separation",
		ToolTip = "The physical separation between virtual cameras in world units (similar to IPD). Affects the strength of the 3D effect"))
	float EyeSeparation = 6.5f;

	/** Multiplier applied to eye separation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence|Eye Settings",
		meta = (UIMin = "0.01", UIMax = "10.0", ClampMin = "0.01",
		DisplayName = "Eye Separation Scale",
		ToolTip = "Multiplier applied to eye separation. Lower values reduce the 3D effect, higher values increase it"))
	float EyeSeparationScale = 1.0f;

	// CONVERGENCE DISTANCE SETTINGS

	/** Distance at which objects appear at screen depth */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence|Distance",
		meta = (UIMin = "10.0", UIMax = "10000.0", ClampMin = "0.1",
		DisplayName = "Convergence Distance",
		ToolTip = "Distance at which objects appear at screen depth (neither popping out nor recessed). Objects closer than this will appear to pop out"))
	float ConvergenceDistance = 250.0f;

	/** Auto-update convergence distance to match camera focus */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence|Distance",
		meta = (DisplayName = "Sync Convergence with Camera Focus",
		ToolTip = "When enabled, convergence distance will automatically update to match camera focus distance"))
	bool bSyncConvergenceWithFocus = false;

	// CONVERGENCE VISUALIZATION

	/** Display a visual indicator showing the convergence plane */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence|Visualization",
		meta = (DisplayName = "Show Convergence Plane",
		ToolTip = "Displays a visual indicator showing where the convergence plane is located in the scene"))
	bool bShowConvergencePlane = true;

	/** The color of the convergence plane visualization */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Convergence|Visualization",
		meta = (EditCondition = "bShowConvergencePlane",
		DisplayName = "Convergence Plane Color",
		ToolTip = "The color of the convergence plane visualization"))
	FLinearColor ConvergencePlaneColor = FLinearColor(0.2f, 0.5f, 1.0f, 1.0f);
};

