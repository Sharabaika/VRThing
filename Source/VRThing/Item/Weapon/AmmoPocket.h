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


	// Subroutines //
	// =========== //
	virtual AInteractableItemBase* RemoveItemFromStorage() override;
	virtual bool CanStoreItem(AInteractableItemBase* Item) const override;
};
