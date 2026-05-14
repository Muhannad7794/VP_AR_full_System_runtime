#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "DepthReprojectionActor.generated.h"

/**
 * ADepthReprojectionActor
 *
 * Reprojects the ZED depth map from ZED camera space into Sony camera space
 * every frame using the calibrated stereo extrinsic matrix (R, T) and both
 * cameras' intrinsic matrices from the offline spatial calibration pipeline.
 *
 * The output render target RT_ZED_Reprojected contains the ZED depth values
 * correctly aligned to the Sony camera perspective. This render target is
 * consumed by the compositing material for per-pixel depth comparison against
 * the CG scene depth, enabling geometrically accurate AR occlusion.
 *
 * All calibrated parameters are exposed as instance-editable properties so
 * they can be updated when the physical rig configuration changes without
 * recompiling the project.
 */
UCLASS()
class VP_AR_FULL_SYSTEM_API ADepthReprojectionActor : public AActor
{
    GENERATED_BODY()

public:
    ADepthReprojectionActor();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // -------------------------------------------------------------------------
    // Render Targets
    // -------------------------------------------------------------------------

    /** Raw ZED depth map received via Spout. Normalised grayscale [0,1].
     *  Assign RT_ZED_SpoutDepth here. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Targets")
    UTextureRenderTarget2D* RT_ZED_Input;

    /** Output render target in Sony camera space. This is what the compositing
     *  material samples for the real-world depth comparison.
     *  Assign RT_ZED_Reprojected here. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Targets")
    UTextureRenderTarget2D* RT_ZED_Reprojected;

    /** The reprojection material asset (M_ZED_DepthReproject).
     *  This material contains the HLSL Custom node that performs the warp. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Targets")
    UMaterialInterface* ReprojectionMaterial;

    // -------------------------------------------------------------------------
    // Sony Camera Intrinsics — from spatial_calibration.json, camera_matrix field
    // Values are in pixel units at the calibration resolution (1920x1080).
    // -------------------------------------------------------------------------

    /** Sony focal length in pixels along X axis (fx from Sony camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Sony Intrinsics")
    float Sony_FX;

    /** Sony focal length in pixels along Y axis (fy from Sony camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Sony Intrinsics")
    float Sony_FY;

    /** Sony principal point X in pixels (cx from Sony camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Sony Intrinsics")
    float Sony_CX;

    /** Sony principal point Y in pixels (cy from Sony camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Sony Intrinsics")
    float Sony_CY;

    // -------------------------------------------------------------------------
    // ZED Camera Intrinsics — from spatial_calibration.json, camera_matrix field
    // Values are in pixel units at the calibration resolution (1920x1080).
    // -------------------------------------------------------------------------

    /** ZED focal length in pixels along X axis (fx from ZED camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | ZED Intrinsics")
    float ZED_FX;

    /** ZED focal length in pixels along Y axis (fy from ZED camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | ZED Intrinsics")
    float ZED_FY;

    /** ZED principal point X in pixels (cx from ZED camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | ZED Intrinsics")
    float ZED_CX;

    /** ZED principal point Y in pixels (cy from ZED camera_matrix). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | ZED Intrinsics")
    float ZED_CY;

    // -------------------------------------------------------------------------
    // Extrinsic Parameters — from spatial_calibration.json, extrinsics field
    // These define the rigid transform from ZED camera space to Sony camera space.
    // R and T are from cv2.stereoCalibrate output.
    // -------------------------------------------------------------------------

    /** Extrinsic rotation expressed as Euler angles in degrees (XYZ order).
     *  Source: rotation_degrees field in spatial_calibration.json.
     *  Example: X=-0.33, Y=1.94, Z=0.35 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Extrinsics")
    FVector ExtrinsicRotation_Degrees;

    /** Extrinsic translation in metres (converted from the cm values in the JSON).
     *  Source: translation_cm divided by 100.
     *  Example: X=-0.0771, Y=-0.1036, Z=-0.0411 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Extrinsics")
    FVector ExtrinsicTranslation_Metres;

    // -------------------------------------------------------------------------
    // Depth Range — must match the constants in zed_streamer.py exactly
    // -------------------------------------------------------------------------

    /** Minimum depth in metres. Matches DEPTH_MIN_M in zed_streamer.py. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Range")
    float DepthMin_Metres;

    /** Maximum depth in metres. Matches DEPTH_MAX_M in zed_streamer.py. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Range")
    float DepthMax_Metres;

    /** Image width in pixels. Must match both cameras' capture resolution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Range")
    float ImageWidth;

    /** Image height in pixels. Must match both cameras' capture resolution. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Depth Reprojection | Range")
    float ImageHeight;

private:
    /** Dynamic material instance created from ReprojectionMaterial at BeginPlay. */
    UPROPERTY()
    UMaterialInstanceDynamic* ReprojectionMID;

    /**
     * Computes the 3x3 rotation matrix from ExtrinsicRotation_Degrees using
     * XYZ Euler angle convention matching the output of the offline calibration
     * pipeline. Returns the matrix as three row vectors for HLSL consumption.
     */
    void ComputeRotationMatrix(FVector& OutRow0, FVector& OutRow1, FVector& OutRow2) const;

    /**
     * Pushes all calibrated parameters to the dynamic material instance.
     * Called at BeginPlay and whenever parameters change.
     */
    void UpdateMaterialParameters();
};