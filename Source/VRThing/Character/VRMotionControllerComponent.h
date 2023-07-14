#pragma once
#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "VRThing/Misc/Enums.h"
#include "VRMotionControllerComponent.generated.h"

UCLASS()
class UVRMotionControllerComponent : public UMotionControllerComponent
{
	GENERATED_BODY()
	
	// Dependencies //
	// ============ //	
	UPROPERTY(Transient)
	APlayerController* PlayerController;


	// Subobjects //
	// ========== //
	UPROPERTY(Transient)
	UInputComponent* FakeVRControllerInputComponent;


	// State //
	// ===== //
	UPROPERTY()
	TEnumAsByte<ELeftRight> WhichHand;

	
public:
	// Lifecycle //
	// ========= //
	UVRMotionControllerComponent();
	void SetupPlayerInputComponent(APlayerController* InPlayerController, UInputComponent* InputComponent, ELeftRight InWhichHand);


private:
	// Subroutines //
	// =========== //
	void EnableFakeControllerInput();
	void DisableFakeControllerInput();
	
	void OnFakeX(float Value);
	void OnFakeY(float Value);
	void OnFakeZ(float Value);
	
	bool IsSuitableFakeInputHand() const;
	bool ShouldRotateFakeInput() const;
};