#include "InteractableItemBase.h"
#include "ItemGripComponent.h"
#include "VRThing/Misc/Macto.h"

AInteractableItemBase::AInteractableItemBase()
	: Super()
{
	INIT_COMPONENT(USkeletalMeshComponent, SkeletalMeshComponent);
	SetRootComponent(SkeletalMeshComponent);
	
	INIT_COMPONENT(UItemGripComponent, ItemGripComponent);
	ItemGripComponent->SetupAttachment(RootComponent);
}

void AInteractableItemBase::GripBy(UItemGripComponent* ItemGrip,
	UPlayerInteractionComponent* InteractionComponent)
{
	SkeletalMeshComponent->SetSimulatePhysics(false);

	FAttachmentTransformRules AttachmentRules(
		EAttachmentRule::KeepRelative, EAttachmentRule::SnapToTarget,
		EAttachmentRule::KeepWorld, false);
	AttachToComponent(InteractionComponent, AttachmentRules);
	
	SetActorRelativeLocation(ItemGrip->GetRelativeLocation());
	SetActorRelativeRotation(ItemGrip->GetRelativeRotation().GetInverse());
}

void AInteractableItemBase::DropFrom(UPlayerInteractionComponent* InteractionComponent)
{
	FDetachmentTransformRules DetachmentRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false);
	DetachFromActor(DetachmentRules);
	
	SkeletalMeshComponent->SetSimulatePhysics(true);
}
