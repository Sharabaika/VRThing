#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRThing/Character/Interaction/PlayerInteractionComponent.h"
#include "InteractableItemBase.generated.h"


class UItemGripComponent;

UCLASS()
class AInteractableItemBase : public AActor
{
	GENERATED_BODY()
protected:
	// Subobjects //
	// ========== //
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMeshComponent;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UItemGripComponent* ItemGripComponent;


	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	UPlayerInteractionComponent* GrippedInteractionComponent;
	
	
public:
	// Lifecycle //
	// ========= //
	AInteractableItemBase();
		

	// Methods //
	// ======= //
	void GripBy(UPlayerInteractionComponent* InteractionComponent);
	void DropFrom(UPlayerInteractionComponent* InteractionComponent);

	void TriggerItem(UPlayerInteractionComponent* InteractionComponent);
	void StopTriggering(UPlayerInteractionComponent* InteractionComponent);

	
	// Subroutines //
	// =========== //;
};
