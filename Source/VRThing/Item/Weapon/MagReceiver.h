#pragma once
#include "CoreMinimal.h"
#include "VRThing/Character/Interaction/ItemPocket.h"
#include "MagReceiver.generated.h"


UCLASS()
class UMagReceiver : public UItemPocket
{
	GENERATED_BODY()
protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AInteractableItemBase> AmmoClass;

	UPROPERTY(EditDefaultsOnly)
	bool bHideMagWhenPut;

	UPROPERTY(EditDefaultsOnly)
	bool bDestroyEmptyMags;
	

public:
	// Methods //
	// ======= //
	UMagReceiver();
	void DropEmptyMag();
	virtual bool CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const override;

	
protected:
	// Subroutines //
	// =========== //
	virtual bool CanStoreItem(AInteractableItemBase* Item) const override;
	virtual void StoreItem(AInteractableItemBase* Item) override;
};
