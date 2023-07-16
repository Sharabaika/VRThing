#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "InteractionDetector.generated.h"

class IInteractableComponent;

UCLASS()
class UInteractionDetector : public UCapsuleComponent
{
	GENERATED_BODY()

protected:
	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	TArray<TScriptInterface<IInteractableComponent>> DetectedInteractables;


public:
	// Lifecycle //
	// ========= //
	UInteractionDetector();
	virtual void BeginPlay() override;


	// Methods //
	// ======= //
	UFUNCTION(BlueprintCallable)
	TScriptInterface<IInteractableComponent> GetDesiredInteractable() const;


protected:
	// Subroutines //
	// =========== //
	void AddDetectedInteractable(UObject* Object);
	void RemoveDetectedInteractable(UObject* Object);


	// Event responses //
	// =============== //
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
