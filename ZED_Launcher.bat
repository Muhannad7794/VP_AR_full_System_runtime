@echo off
:: -----------------------------------------------------------------------
:: PLUG-AND-PLAY LAUNCHER FOR VP TRACKING
:: Place this file next to your .uproject file!
:: -----------------------------------------------------------------------

:: 1. Find the .uproject file in this folder
for %%f in (*.uproject) do set "PROJECT_FILE=%%~ff"

:: 2. Check if Unreal 5.4 is installed in the default location
set "UE_EXE=C:\Program Files\Epic Games\UE_5.4\Engine\Binaries\Win64\UnrealEditor.exe"

if not exist "%UE_EXE%" (
    echo ERROR: Could not find Unreal Engine 5.4 at default location.
    echo Please edit this script to point to your Engine installation.
    pause
    exit /b
)

:: 3. Launch with Tracking Flags
echo Launching %PROJECT_FILE% ...
"%UE_EXE%" "%PROJECT_FILE%"