#pragma once
#include "CoreMinimal.h"
#include "InteractableComponent.h"
#include "InteractableItemBase.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"
#include "ItemGripComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FItemGripInteractionDelegate, UItemGripComponent*, UPlayerInteractionComponent*);

UCLASS()
class UItemGripComponent : public USphereComponent, public IInteractableComponent
{
	GENERATED_BODY()

public:
	// Events //
	// ====== //
	FItemGripInteractionDelegate ItemGripped;
	FItemGripInteractionDelegate ItemReleased;

	FItemGripInteractionDelegate ItemTriggered;
	FItemGripInteractionDelegate ItemUntriggered;

	
protected:
	// Dependencies //
	// ============ //
	UPROPERTY()
	UPlayerInteractionComponent* CurrentInteractingComponent;


public:
	// Methods //
	// ======= //
	virtual bool CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const override;
	virtual void StartInteracting(UPlayerInteractionComponent* InteractionComponent) override;
	virtual void EndInteracting() override;

	virtual void StartTriggering(UPlayerInteractionComponent* InteractionComponent) override;
	virtual void EndTriggering(UPlayerInteractionComponent* InteractionComponent) override;

	AInteractableItemBase* GetInteractableItem() const;
};
