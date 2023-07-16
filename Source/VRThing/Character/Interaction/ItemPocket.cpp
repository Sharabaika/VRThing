#include "ItemPocket.h"
#include "VRThing/Item/InteractableItemBase.h"
#include "VRThing/Item/ItemGripComponent.h"

UItemPocket::UItemPocket()
	: Super()
{
	BoxExtent = {8.0f, 8.0f, 8.0f};
	SetHiddenInGame(false);
	UPrimitiveComponent::SetCollisionProfileName("ItemPocket");
	SetGenerateOverlapEvents(true);
}

void UItemPocket::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);
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
	return IsValid(Item) && !Item->GetPocketOwner() && StoredItem == nullptr;
}

void UItemPocket::StoreItem(AInteractableItemBase* Item)
{
	Item->PutInPocket(this);
	StoredItem = Item;
}

AInteractableItemBase* UItemPocket::RemoveItemFromStorage()
{
	AInteractableItemBase* Item = StoredItem;
	StoredItem = nullptr;
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
