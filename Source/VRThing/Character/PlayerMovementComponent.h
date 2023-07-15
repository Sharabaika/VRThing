#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"


UCLASS()
class UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	USceneComponent* CameraComponent;

	
public:
	// Lifecycle //
	// ========= //
	UPlayerMovementComponent(const FObjectInitializer& ObjectInitializer);
	void SetDependencies(USceneComponent* InCameraComponent);
	

	// Methods //
	// ======= //
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	
protected:
	// Subroutines //
	// =========== //

	// Input //
	// ----- //
	void OnStrafe(float Amount);
	void OnMoveFrontBack(float Amount);
	
	void OnTurn(float Amount);
	void AddYaw(float Amount);
};