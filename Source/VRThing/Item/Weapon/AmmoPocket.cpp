#include "AmmoPocket.h"
#include "VRThing/Item/InteractableItemBase.h"

bool UAmmoPocket::CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const
{
	return true;
}

AInteractableItemBase* UAmmoPocket::RemoveItemFromStorage()
{
	return GetWorld()->SpawnActor<AInteractableItemBase>(ItemToSpawn);
}

bool UAmmoPocket::CanStoreItem(AInteractableItemBase* Item) const
{
	return false;
}
