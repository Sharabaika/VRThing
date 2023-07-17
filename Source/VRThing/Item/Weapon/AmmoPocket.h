#pragma once
#include "CoreMinimal.h"
#include "VRThing/Character/Interaction/ItemPocket.h"
#include "AmmoPocket.generated.h"

class AInteractableItemBase;

UCLASS()
class UAmmoPocket : public UItemPocket
{
	GENERATED_BODY()

protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AInteractableItemBase> ItemToSpawn;


	// Lifecycle //
	// ========= //
	UAmmoPocket();
	

	// Subroutines //
	// =========== //
	virtual bool CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const override;
	virtual AInteractableItemBase* RemoveItemFromStorage() override;
	virtual bool CanStoreItem(AInteractableItemBase* Item) const override;
};
