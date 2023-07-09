#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "VRCamera.generated.h"

UCLASS()
class UVRCamera : public UCameraComponent
{
	GENERATED_BODY()

public:
	// Lifecycle //
	// ========= //
	UVRCamera();
	void SetupInputComponent(UInputComponent* InputComponent);


protected:
	// Input //
	// ===== //
	void OnFakeCameraPitch(float Value);
};