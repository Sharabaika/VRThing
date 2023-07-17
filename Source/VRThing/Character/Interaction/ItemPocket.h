﻿#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "VRThing/Item/InteractableComponent.h"
#include "ItemPocket.generated.h"

class AInteractableItemBase;

DECLARE_MULTICAST_DELEGATE_OneParam(FInteractableItemDelegate, AInteractableItemBase*);

UCLASS()
class UItemPocket : public UBoxComponent, public IInteractableComponent
{
	GENERATED_BODY()
protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bDropItemOnDeactivate;
	
	
	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	AInteractableItemBase* StoredItem;

	
public:
	// Events //
	// ====== //
	FInteractableItemDelegate ItemPlaced;
	FInteractableItemDelegate ItemRemoved;
	

	// Lifecycle //
	// ========= //
	UItemPocket();
	virtual void BeginPlay() override;

	virtual void Deactivate() override;

	// Methods //
	// ======= //
	virtual bool CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const override;
	virtual TScriptInterface<IInteractableComponent> StartInteracting(UPlayerInteractionComponent* InteractionComponent) override;
	

protected:
	// Subroutines //
	// =========== //
	virtual bool CanStoreItem(AInteractableItemBase* Item) const;
	virtual void StoreItem(AInteractableItemBase* Item);
	virtual AInteractableItemBase* RemoveItemFromStorage();
	

	// Event responses //
	// =============== //
	void OnOverlappedItemDroppedFromHand(AInteractableItemBase* DroppedItem, UPlayerInteractionComponent* PlayerInteractionComponent);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
