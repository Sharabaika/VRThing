#include "ItemGripComponent.h"
#include "VRThing/Character/Interaction/PlayerInteractionComponent.h"

bool UItemGripComponent::CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const
{
	return !IsValid(CurrentInteractingComponent);
}

void UItemGripComponent::StartInteracting(UPlayerInteractionComponent* InteractionComponent)
{
	AInteractableItemBase* Item = GetInteractableItem();
	Item->GripBy(this, InteractionComponent);
	// TODO add grips registration, cast to something like IGripable
	
	CurrentInteractingComponent = InteractionComponent;
}

void UItemGripComponent::EndInteracting(UPlayerInteractionComponent* InteractionComponent)
{
	AInteractableItemBase* Item = GetInteractableItem();
	Item->DropFrom(InteractionComponent);

	CurrentInteractingComponent = nullptr;
}

AInteractableItemBase* UItemGripComponent::GetInteractableItem() const
{
	return GetOwner<AInteractableItemBase>();
}
