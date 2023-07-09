#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "UObject/Object.h"
#include "VRThing/Item/InteractableComponent.h"
#include "InteractionDetector.generated.h"

UCLASS()
class UInteractionDetector : public UCapsuleComponent
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<IInteractableComponent> DetectedInteractable;

public:
	virtual void BeginPlay() override;

	TScriptInterface<IInteractableComponent> GetDetectedInteractable() const { return DetectedInteractable; }
	void SetDetectedInteractable(IInteractableComponent* Value);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
