/**
 * Component: UKinematicDescriptorComponent
 * Purpose: Master ingestion and computation node for Embodied Interaction.
 * Reads raw skeletal data, applies the 1 Euro Filter, computes the 4 continuous
 * Laban Movement Analysis (LMA) descriptors, routes data to rendering subsystems,
 * and actively governs the kinematic spatial physics of the AR grid.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "kinematicEI_system/OneEuroFilter.h"
#include "KinematicDescriptorComponent.generated.h"

class UMaterialParameterCollection;
class UNiagaraComponent;
class USkeletalMeshComponent;
class AActor;

UCLASS(ClassGroup = (KinematicEI), meta = (BlueprintSpawnableComponent))
class VP_AR_FULL_SYSTEM_API UKinematicDescriptorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UKinematicDescriptorComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // -----------------------------------------------------------------------
    // Core System Architecture References
    // -----------------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    USkeletalMeshComponent* TrackedSkeleton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UMaterialParameterCollection* GlobalMPC;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    UNiagaraComponent* ParticleSystem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|References")
    TArray<AActor*> ARCubes;

    // -----------------------------------------------------------------------
    // Tuning Parameters
    // -----------------------------------------------------------------------

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics")
    float AttractorSpringConstant = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics")
    float RepulsorForceMultiplier = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KinematicEI|Physics")
    float BaseDragCoefficient = 10.0f;

    // -----------------------------------------------------------------------
    // State and Operations
    // -----------------------------------------------------------------------

    UFUNCTION(BlueprintCallable, Category = "KinematicEI|Operations")
    void ToggleSystemMode();

private:
    bool bIsEIActive;

    // 1 Euro Filters for core spatial joints
    FOneEuroFilterVector FilterSpine;
    FOneEuroFilterVector FilterLWrist;
    FOneEuroFilterVector FilterRWrist;

    // LMA State Variables
    float CurrentEffort;
    float CurrentExpansiveness;
    float CurrentWeight;
    float CurrentFlow;

    FVector PrevFilteredRWrist;
    FVector PrevRWristVelocity;

    // Physics Anchor Storage
    TMap<AActor*, FVector> CubeHomeLocations;

    // Helper functions
    void ReadAndFilterKinematics(float DeltaTime, FVector& OutSpine, FVector& OutLWrist, FVector& OutRWrist);
    void ComputeLMADescriptors(float DeltaTime, const FVector& Spine, const FVector& LWrist, const FVector& RWrist);
    void UpdateRenderSubsystems(const FVector& PelvisLocation);
    void ExecuteKinematicPhysics();
};