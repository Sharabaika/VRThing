﻿#include "InteractableItemBase.h"
#include "ItemGripComponent.h"
#include "Components/BoxComponent.h"
#include "VRThing/Character/Interaction/ItemPocket.h"
#include "VRThing/Character/Interaction/PlayerInteractionComponent.h"
#include "VRThing/Misc/Macro.h"

FName AInteractableItemBase::PhysicsRootName(TEXT("PhysicsRoot"));

AInteractableItemBase::AInteractableItemBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	PhysicsRoot( ObjectInitializer.CreateDefaultSubobject<UPrimitiveComponent, UBoxComponent>(this, "PhysicsRoot") )
{
	SetRootComponent(PhysicsRoot);
	PhysicsRoot->SetCollisionProfileName("ItemPhysics");
	PhysicsRoot->SetSimulatePhysics(true);
	
	INIT_COMPONENT(UItemGripComponent, ItemGripComponent);
	ItemGripComponent->SetupAttachment(PhysicsRoot);
}

void AInteractableItemBase::GripBy(UPlayerInteractionComponent* InteractionComponent)
{
	SnapToHolder(InteractionComponent);
}

void AInteractableItemBase::DropFrom(UPlayerInteractionComponent* InteractionComponent)
{
	RemoveFromHolder();
	DroppedFromHand.Broadcast(this, InteractionComponent);
}

void AInteractableItemBase::TriggerItem(UPlayerInteractionComponent* InteractionComponent)
{
}

void AInteractableItemBase::StopTriggering(UPlayerInteractionComponent* InteractionComponent)
{
}

void AInteractableItemBase::PutInPocket(UItemPocket* Pocket)
{
	PocketOwner = Pocket;
	SetActorEnableCollision(false);
	SnapToHolder(Pocket);
}

void AInteractableItemBase::RemoveFromPocket()
{
	PocketOwner = nullptr;
	SetActorEnableCollision(true);
	RemoveFromHolder();
}

void AInteractableItemBase::SnapToHolder(USceneComponent* Holder)
{
	PhysicsRoot->SetSimulatePhysics(false);

	FAttachmentTransformRules AttachmentRules(
		EAttachmentRule::KeepRelative, EAttachmentRule::SnapToTarget,
		EAttachmentRule::KeepWorld, false);
	AttachToComponent(Holder, AttachmentRules);
	
	SetActorRelativeLocation(ItemGripComponent->GetRelativeLocation());
	SetActorRelativeRotation(ItemGripComponent->GetRelativeRotation().GetInverse());
}

void AInteractableItemBase::RemoveFromHolder()
{
	FDetachmentTransformRules DetachmentRules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, EDetachmentRule::KeepWorld, false);
	DetachFromActor(DetachmentRules);

	PhysicsRoot->SetSimulatePhysics(true);
}
