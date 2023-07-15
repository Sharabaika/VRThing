#pragma once
#include "CoreMinimal.h"
#include "VRThing/Misc/Enums.h"
#include "VRThing/Item/InteractableComponent.h"
#include "PlayerInteractionComponent.generated.h"


class UInteractionDetector;

UCLASS()
class UPlayerInteractionComponent : public USceneComponent
{
	GENERATED_BODY()

	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	TScriptInterface<IInteractableComponent> CurrentInteractable;	
	
	UPROPERTY(Transient)
	UInteractionDetector* Detector;
	
	UPROPERTY(Transient)
	TEnumAsByte<ELeftRight> WhichHand;

	
public:
	// Lifecycle //
	// ========= //
	virtual void BeginPlay() override;
	void SetupPlayerInputComponent(UInputComponent* InputComponent);
	void SetWhichHand(ELeftRight InWhichHand);
	void SetDetector(UInteractionDetector* InInteractionDetector);


protected:
	// Subroutines //
	// =========== //
	void TryToInteract();
	void StopInteracting();

	void InteractWith(TScriptInterface<IInteractableComponent> InteractableComponent);

	void TryToTrigger();
	void StopTriggering();

	
	// Input //
	// ===== //
	void OnGrip(float Value);
	void OnTrigger(float Value);
	
	
	// Fake Input //
	// ---------- //
	void OnFakeTriggerPressed();
	void OnFakeTriggerReleased();
	
	void OnFakeGripPressed();
	void OnFakeGripReleased();
};
