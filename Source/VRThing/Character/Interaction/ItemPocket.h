#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "VRThing/Item/InteractableComponent.h"
#include "ItemPocket.generated.h"

class AInteractableItemBase;

UCLASS()
class UItemPocket : public UBoxComponent, public IInteractableComponent
{
	GENERATED_BODY()

	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	AInteractableItemBase* StoredItem;

	
public:	
	UItemPocket();
	virtual void BeginPlay() override;


	// Methods //
	// ======= //
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
