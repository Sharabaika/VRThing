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
	
	
public:
	AInteractableItemBase();


	// Methods //
	// ======= //
	void GripBy(UItemGripComponent* ItemGripComponent, UPlayerInteractionComponent* InteractionComponent);
	void DropFrom(UPlayerInteractionComponent* InteractionComponent);
	

	// Subroutines //
	// =========== //;
};
