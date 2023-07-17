﻿#include "ItemPocket.h"
#include "VRThing/Item/InteractableItemBase.h"
#include "VRThing/Item/ItemGripComponent.h"

UItemPocket::UItemPocket()
	: Super()
{
	BoxExtent = {8.0f, 8.0f, 8.0f};
	SetHiddenInGame(false);
	UPrimitiveComponent::SetCollisionProfileName("ItemPocket");
	SetGenerateOverlapEvents(true);

	bDropItemOnDeactivate = true;
}

void UItemPocket::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);

	SetActive(true);
}

void UItemPocket::Deactivate()
{
	Super::Deactivate();

	if (!bDropItemOnDeactivate)
	{
		return;
	}

	if (auto* Item = RemoveItemFromStorage())
	{
		Item->RemoveFromPocket();
	}
}

bool UItemPocket::CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const
{
	return IsValid(StoredItem) && IsActive();
}

TScriptInterface<IInteractableComponent> UItemPocket::StartInteracting(UPlayerInteractionComponent* InteractionComponent)
{
	auto* Item = RemoveItemFromStorage();
	if (Item)
	{
		Item->RemoveFromPocket();
		return Item->GetMainGrip()->StartInteracting(InteractionComponent);
	}
	return nullptr;
}

bool UItemPocket::CanStoreItem(AInteractableItemBase* Item) const
{
	return IsValid(Item) && !Item->GetPocketOwner() && StoredItem == nullptr && IsActive();
}

void UItemPocket::StoreItem(AInteractableItemBase* Item)
{
	Item->PutInPocket(this);
	StoredItem = Item;
	ItemPlaced.Broadcast(Item);
}

AInteractableItemBase* UItemPocket::RemoveItemFromStorage()
{
	AInteractableItemBase* Item = StoredItem;
	StoredItem = nullptr;
	ItemRemoved.Broadcast(StoredItem);
	return Item;
}

void UItemPocket::OnOverlappedItemDroppedFromHand(AInteractableItemBase* DroppedItem,
	UPlayerInteractionComponent* PlayerInteractionComponent)
{
	if (CanStoreItem(DroppedItem))
	{
		StoreItem(DroppedItem);
	}
}

void UItemPocket::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto* Item = Cast<AInteractableItemBase>(OtherActor))
	{
		Item->DroppedFromHand.AddUObject(this, &ThisClass::OnOverlappedItemDroppedFromHand);
	}
}

void UItemPocket::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (auto* Item = Cast<AInteractableItemBase>(OtherActor))
	{
		Item->DroppedFromHand.RemoveAll(this);
	}
}
