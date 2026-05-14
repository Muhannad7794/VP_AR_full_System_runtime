#include "occlusion_system/DepthReprojectionActor.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/World.h"

ADepthReprojectionActor::ADepthReprojectionActor()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    // Default values matching zed_streamer.py constants
    DepthMin_Metres = 0.5f;
    DepthMax_Metres = 6.0f;
    ImageWidth = 1920.0f;
    ImageHeight = 1080.0f;

    // Default intrinsics — these must be overwritten in the Details panel
    // with values from spatial_calibration.json before use
    Sony_FX = 1000.0f;
    Sony_FY = 1000.0f;
    Sony_CX = 960.0f;
    Sony_CY = 540.0f;

    ZED_FX = 1000.0f;
    ZED_FY = 1000.0f;
    ZED_CX = 960.0f;
    ZED_CY = 540.0f;

    // Default extrinsics from the calibration example in the README
    // translation_cm: [-7.71, -10.36, -4.11] → converted to metres
    ExtrinsicTranslation_Metres = FVector(-0.0771f, -0.1036f, -0.0411f);
    ExtrinsicRotation_Degrees = FVector(-0.33f, 1.94f, 0.35f);
}

void ADepthReprojectionActor::BeginPlay()
{
    Super::BeginPlay();

    if (!ReprojectionMaterial)
    {
        UE_LOG(LogTemp, Error, TEXT("ADepthReprojectionActor: ReprojectionMaterial is not assigned. Assign M_ZED_DepthReproject in the Details panel."));
        return;
    }

    if (!RT_ZED_Input)
    {
        UE_LOG(LogTemp, Error, TEXT("ADepthReprojectionActor: RT_ZED_Input is not assigned. Assign RT_ZED_SpoutDepth in the Details panel."));
        return;
    }

    if (!RT_ZED_Reprojected)
    {
        UE_LOG(LogTemp, Error, TEXT("ADepthReprojectionActor: RT_ZED_Reprojected is not assigned. Assign or create RT_ZED_Reprojected in the Details panel."));
        return;
    }

    // Create a dynamic material instance so scalar and vector parameters
    // can be set at runtime without affecting the base material asset.
    ReprojectionMID = UMaterialInstanceDynamic::Create(ReprojectionMaterial, this);

    if (!ReprojectionMID)
    {
        UE_LOG(LogTemp, Error, TEXT("ADepthReprojectionActor: Failed to create dynamic material instance."));
        return;
    }

    // Bind the ZED depth input texture to the material
    ReprojectionMID->SetTextureParameterValue(FName("ZEDDepthTex"), RT_ZED_Input);

    // Push all calibrated parameters to the material
    UpdateMaterialParameters();

    UE_LOG(LogTemp, Log, TEXT("ADepthReprojectionActor: Reprojection pipeline initialised. Depth range: %.2fm to %.2fm"), DepthMin_Metres, DepthMax_Metres);
}

void ADepthReprojectionActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!ReprojectionMID || !RT_ZED_Reprojected)
    {
        return;
    }

    // Execute the reprojection shader every frame by drawing the material
    // as a full-screen quad into the reprojected render target.
    // This is a GPU-side operation — no CPU pixel iteration occurs.
    UKismetRenderingLibrary::DrawMaterialToRenderTarget(
        GetWorld(),
        RT_ZED_Reprojected,
        ReprojectionMID
    );
}

void ADepthReprojectionActor::ComputeRotationMatrix(
    FVector& OutRow0,
    FVector& OutRow1,
    FVector& OutRow2) const
{
    // Convert degrees to radians
    const float DegToRad = PI / 180.0f;
    const float Rx_rad = ExtrinsicRotation_Degrees.X * DegToRad;
    const float Ry_rad = ExtrinsicRotation_Degrees.Y * DegToRad;
    const float Rz_rad = ExtrinsicRotation_Degrees.Z * DegToRad;

    // Precompute trig values
    const float cx = FMath::Cos(Rx_rad);
    const float sx = FMath::Sin(Rx_rad);
    const float cy = FMath::Cos(Ry_rad);
    const float sy = FMath::Sin(Ry_rad);
    const float cz = FMath::Cos(Rz_rad);
    const float sz = FMath::Sin(Rz_rad);

    // Rotation matrix R = Rz * Ry * Rx (XYZ Euler convention matching OpenCV output)
    // This matrix rotates a point from ZED camera space to Sony camera space.
    // R * P_zed + T = P_sony
    //
    // Row 0: [cy*cz,  cz*sx*sy - cx*sz,  cx*cz*sy + sx*sz]
    // Row 1: [cy*sz,  cx*cz + sx*sy*sz,  cx*sy*sz - cz*sx]
    // Row 2: [-sy,    cy*sx,             cx*cy            ]

    OutRow0 = FVector(
        cy * cz,
        cz * sx * sy - cx * sz,
        cx * cz * sy + sx * sz
    );

    OutRow1 = FVector(
        cy * sz,
        cx * cz + sx * sy * sz,
        cx * sy * sz - cz * sx
    );

    OutRow2 = FVector(
        -sy,
        cy * sx,
        cx * cy
    );

    // The HLSL inverse transform uses R^T (transpose) to go from Sony back to ZED.
    // R^T rows are R columns — this is computed in the HLSL Custom node directly
    // from the row vectors passed here, so only the forward R rows are needed.
}

void ADepthReprojectionActor::UpdateMaterialParameters()
{
    if (!ReprojectionMID)
    {
        return;
    }

    // Compute the rotation matrix from calibrated Euler angles
    FVector Row0, Row1, Row2;
    ComputeRotationMatrix(Row0, Row1, Row2);

    // Pass rotation matrix rows to HLSL as vector parameters.
    // The HLSL uses these to build both R and R^T for the backward warp.
    ReprojectionMID->SetVectorParameterValue(FName("R_Row0"), FLinearColor(Row0.X, Row0.Y, Row0.Z, 0.0f));
    ReprojectionMID->SetVectorParameterValue(FName("R_Row1"), FLinearColor(Row1.X, Row1.Y, Row1.Z, 0.0f));
    ReprojectionMID->SetVectorParameterValue(FName("R_Row2"), FLinearColor(Row2.X, Row2.Y, Row2.Z, 0.0f));

    // Pass extrinsic translation in metres
    ReprojectionMID->SetVectorParameterValue(
        FName("T_Metres"),
        FLinearColor(
            ExtrinsicTranslation_Metres.X,
            ExtrinsicTranslation_Metres.Y,
            ExtrinsicTranslation_Metres.Z,
            0.0f
        )
    );

    // Sony intrinsics in pixel units
    ReprojectionMID->SetScalarParameterValue(FName("Sony_FX"), Sony_FX);
    ReprojectionMID->SetScalarParameterValue(FName("Sony_FY"), Sony_FY);
    ReprojectionMID->SetScalarParameterValue(FName("Sony_CX"), Sony_CX);
    ReprojectionMID->SetScalarParameterValue(FName("Sony_CY"), Sony_CY);

    // ZED intrinsics in pixel units
    ReprojectionMID->SetScalarParameterValue(FName("ZED_FX"), ZED_FX);
    ReprojectionMID->SetScalarParameterValue(FName("ZED_FY"), ZED_FY);
    ReprojectionMID->SetScalarParameterValue(FName("ZED_CX"), ZED_CX);
    ReprojectionMID->SetScalarParameterValue(FName("ZED_CY"), ZED_CY);

    // Depth range matching zed_streamer.py constants
    ReprojectionMID->SetScalarParameterValue(FName("DepthMin_m"), DepthMin_Metres);
    ReprojectionMID->SetScalarParameterValue(FName("DepthMax_m"), DepthMax_Metres);

    // Image dimensions
    ReprojectionMID->SetScalarParameterValue(FName("ImageWidth"), ImageWidth);
    ReprojectionMID->SetScalarParameterValue(FName("ImageHeight"), ImageHeight);
}