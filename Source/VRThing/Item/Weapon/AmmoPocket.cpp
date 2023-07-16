#include "AmmoPocket.h"
#include "VRThing/Item/InteractableItemBase.h"

AInteractableItemBase* UAmmoPocket::RemoveItemFromStorage()
{
	return GetWorld()->SpawnActor<AInteractableItemBase>(ItemToSpawn);
}

bool UAmmoPocket::CanStoreItem(AInteractableItemBase* Item) const
{
	return false;
}
