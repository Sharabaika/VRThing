#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

class UItemPocket;
class UInteractionDetector;
class UPlayerInteractionComponent;
class UVRCamera;
class UVRMotionControllerComponent;
class UPlayerMovementComponent;

UCLASS()
class AVRCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Subobjects //
	// ========== //
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRCamera* VRCamera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRMotionControllerComponent* LeftMotionController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPlayerInteractionComponent* LeftInteractionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInteractionDetector* LeftInteractionDetector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRMotionControllerComponent* RightMotionController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPlayerInteractionComponent* RightInteractionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInteractionDetector* RightInteractionDetector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UItemPocket* AmmoPocket;
	
public:	
	// Lifecycle //
	// ========= //
	AVRCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	

	// Methods //
	// ======= //
	UPlayerMovementComponent* GetPlayerMovementComponent();
};