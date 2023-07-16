#include "MagReceiver.h"
#include "VRThing/Item/InteractableItemBase.h"

UMagReceiver::UMagReceiver()
	: Super()
{
	bHideMagWhenPut = true;
}

void UMagReceiver::DropEmptyMag()
{
	AInteractableItemBase* Item = RemoveItemFromStorage();
	if (!Item)
	{
		return;
	}
	
	if (bDestroyEmptyMags)
	{
		Item->Destroy();	
	}
	else
	{
		Item->RemoveFromPocket();
	}
}

bool UMagReceiver::CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const
{
	return false;
}

bool UMagReceiver::CanStoreItem(AInteractableItemBase* Item) const
{
	return IsValid(Item) && Item->IsA(AmmoClass);
}

void UMagReceiver::StoreItem(AInteractableItemBase* Item)
{
	Super::StoreItem(Item);
	Item->SetActorHiddenInGame(bHideMagWhenPut);
}
