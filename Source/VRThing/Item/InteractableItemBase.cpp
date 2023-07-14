#include "InteractableItemBase.h"
#include "ItemGripComponent.h"
#include "VRThing/Character/Interaction/PlayerInteractionComponent.h"
#include "VRThing/Misc/Macro.h"

AInteractableItemBase::AInteractableItemBase()
	: Super()
{
	INIT_COMPONENT(USkeletalMeshComponent, SkeletalMeshComponent);
	SetRootComponent(SkeletalMeshComponent);
	
	INIT_COMPONENT(UItemGripComponent, ItemGripComponent);
	ItemGripComponent->SetupAttachment(RootComponent);
}

void AInteractableItemBase::GripBy(UPlayerInteractionComponent* InteractionComponent)
{
	SkeletalMeshComponent->SetSimulatePhysics(false);

	FAttachmentTransformRules AttachmentRules(
		EAttachmentRule::KeepRelative, EAttachmentRule::SnapToTarget,
		EAttachmentRule::KeepWorld, false);
	AttachToComponent(InteractionComponent, AttachmentRules);
	
	SetActorRelativeLocation(ItemGripComponent->GetRelativeLocation());
	SetActorRelativeRotation(ItemGripComponent->GetRelativeRotation().GetInverse());
}

void AInteractableItemBase::DropFrom(UPlayerInteractionComponent* InteractionComponent)
{
	FDetachmentTransformRules DetachmentRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false);
	DetachFromActor(DetachmentRules);
	
	SkeletalMeshComponent->SetSimulatePhysics(true);
}

void AInteractableItemBase::TriggerItem(UPlayerInteractionComponent* InteractionComponent)
{
}

void AInteractableItemBase::StopTriggering(UPlayerInteractionComponent* InteractionComponent)
{
}
