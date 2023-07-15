#include "ItemPocket.h"
#include "VRThing/Item/ItemGripComponent.h"

UItemPocket::UItemPocket()
{

}

TScriptInterface<IInteractableComponent> UItemPocket::StartInteracting(UPlayerInteractionComponent* InteractionComponent)
{
	auto* Item = GetWorld()->SpawnActor<AInteractableItemBase>(ItemToSpawn);
	return Item->GetMainGrip()->StartInteracting(InteractionComponent);
}
