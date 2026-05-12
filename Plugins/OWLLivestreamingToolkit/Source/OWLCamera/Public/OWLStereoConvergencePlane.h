// Copyright Off World Live Limited 2020-2025. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "OWLStereoConvergencePlane.generated.h"

// Forward declarations
class UOWLCaptureComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;

/**
 * Delegate for when the convergence plane is manipulated by the user
 * The capture component will listen to this to update its internal state
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConvergencePlaneManipulated, float, NewDistance);

UCLASS()
class OWLCAMERA_API AOWLStereoConvergencePlane : public AActor
{
	GENERATED_BODY()

public:
	AOWLStereoConvergencePlane();

	// Called when the plane is manipulated in the editor or viewport
	UPROPERTY(BlueprintAssignable, Category = "Convergence Plane")
	FOnConvergencePlaneManipulated OnConvergencePlaneManipulated;

	// Weak reference to the owning capture component
	// We don't control the lifetime of this component
	UPROPERTY(Transient)
	TWeakObjectPtr<UOWLCaptureComponent> OwningCapture;

	// Called when the owning capture component is set
	void OnOwningCaptureSet();

	// Updates the plane appearance and position based on the parent's stereo config
	void UpdateFromStereoConfig();

	// Updates the plane's position from the convergence distance
	void UpdatePlanePosition(float ConvergenceDistance);

	// Updates the plane's full state (position and size) based on camera properties
	void UpdatePlaneSize(float FOV, float Distance, float AspectRatio);

	// Updates the color of the plane
	void SetPlaneColor(FLinearColor NewColor);

	// Updates the edge intensity of the plane
	void SetEdgeIntensity(float NewIntensity);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// Material instance that controls the plane's appearance
	UPROPERTY(Transient)
	UMaterialInstanceDynamic* PlaneMaterial;

	// Static mesh component for the plane
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlaneMesh;

	// Current color of the plane
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FLinearColor PlaneColor;

	// Current edge intensity
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance", meta = (UIMin = "0.0", UIMax = "1.0"))
	float EdgeIntensity;

	// Ensures the plane is hidden from all captures
	void HideFromCapture();
	
#if WITH_EDITOR
	// Handle editor movement of the actor
	virtual void PostEditMove(bool bFinished) override;

	// Handle property changes in the editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	// Calculates the new convergence distance when the plane is moved in the editor
	void NotifyDistanceFromLocation();

	void ResetToValidPosition();

	bool IsMovementValid() const;
#endif
};


