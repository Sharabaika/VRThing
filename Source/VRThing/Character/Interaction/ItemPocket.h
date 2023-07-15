#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "VRThing/Item/InteractableComponent.h"
#include "VRThing/Item/InteractableItemBase.h"
#include "ItemPocket.generated.h"

UCLASS()
class UItemPocket : public UBoxComponent, public IInteractableComponent
{
	GENERATED_BODY()

	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AInteractableItemBase> ItemToSpawn;
	
	
public:
	UItemPocket();


	virtual TScriptInterface<IInteractableComponent> StartInteracting(UPlayerInteractionComponent* InteractionComponent) override;
};
