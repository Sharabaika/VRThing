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
	TArray<TScriptInterface<IInteractableComponent>> DetectedInteractables;

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	TScriptInterface<IInteractableComponent> GetDesiredInteractable() const;
	void AddDetectedInteractable(UObject* Object);
	void RemoveDetectedInteractable(UObject* Object);
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
