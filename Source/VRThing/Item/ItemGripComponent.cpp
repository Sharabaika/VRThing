#include "ItemGripComponent.h"
#include "VRThing/Character/Interaction/PlayerInteractionComponent.h"

UItemGripComponent::UItemGripComponent()
{
	UPrimitiveComponent::SetCollisionProfileName("InteractableComponent");
}

bool UItemGripComponent::CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const
{
	return !IsValid(CurrentInteractingComponent);
}

TScriptInterface<IInteractableComponent> UItemGripComponent::StartInteracting(UPlayerInteractionComponent* InteractionComponent)
{
	AInteractableItemBase* Item = GetInteractableItem();
	Item->GripBy(InteractionComponent);
	// TODO add grips registration, cast to something like IGripable
	
	CurrentInteractingComponent = InteractionComponent;
	return this;
}

void UItemGripComponent::EndInteracting()
{
	AInteractableItemBase* Item = GetInteractableItem();
	Item->DropFrom(CurrentInteractingComponent);

	CurrentInteractingComponent = nullptr;
}

void UItemGripComponent::StartTriggering(UPlayerInteractionComponent* InteractionComponent)
{
	AInteractableItemBase* Item = GetInteractableItem();
	Item->TriggerItem(InteractionComponent);
}

void UItemGripComponent::EndTriggering(UPlayerInteractionComponent* InteractionComponent)
{
	AInteractableItemBase* Item = GetInteractableItem();
	Item->StopTriggering(InteractionComponent);
}

AInteractableItemBase* UItemGripComponent::GetInteractableItem() const
{
	return GetOwner<AInteractableItemBase>();
}
