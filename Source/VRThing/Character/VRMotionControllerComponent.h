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

	UPROPERTY()
	float GripValue;
	
	UPROPERTY()
	float TriggerValue;

	
public:
	// Accessors //
	// ========= //
	UFUNCTION(BlueprintCallable)
	float GetGripValue() const { return GripValue; }

	UFUNCTION(BlueprintCallable)
	float GetTriggerValue() const { return TriggerValue;}
	
	
	// Lifecycle //
	// ========= //
	UVRMotionControllerComponent();
	void SetupPlayerInputComponent(APlayerController* InPlayerController, UInputComponent* InputComponent, ELeftRight InWhichHand);


private:
	
	void EnableFakeControllerInput();
	void DisableFakeControllerInput();
	
	void OnFakeX(float Value);
	void OnFakeY(float Value);
	void OnFakeZ(float Value);


	// Subroutines //
	// =========== //
	bool IsSuitableFakeInputHand() const;
	bool ShouldRotateFakeInput() const;
};