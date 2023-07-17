#include "AmmoPocket.h"
#include "VRThing/Item/InteractableItemBase.h"

UAmmoPocket::UAmmoPocket()
	: Super()
{
	bDropItemOnDeactivate = false;
}

bool UAmmoPocket::CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const
{
	return IsActive();
}

AInteractableItemBase* UAmmoPocket::RemoveItemFromStorage()
{
	return GetWorld()->SpawnActor<AInteractableItemBase>(ItemToSpawn);
}

bool UAmmoPocket::CanStoreItem(AInteractableItemBase* Item) const
{
	return false;
}
