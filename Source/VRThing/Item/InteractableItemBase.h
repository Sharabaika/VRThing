#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableItemBase.generated.h"

class UItemPocket;
class UItemGripComponent;
class UPlayerInteractionComponent;

DECLARE_MULTICAST_DELEGATE_TwoParams(FInteracableItemEvent, AInteractableItemBase* /* self */, UPlayerInteractionComponent*);

UCLASS()
class AInteractableItemBase : public AActor
{
	GENERATED_BODY()
protected:
	// Subobjects //
	// ========== //
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UPrimitiveComponent* PhysicsRoot;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UItemGripComponent* ItemGripComponent;


	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	UPlayerInteractionComponent* GrippedInteractionComponent;

	UPROPERTY(Transient)
	UItemPocket* PocketOwner;
	
	static FName PhysicsRootName;

public:
	// Events //
	// ====== //
	FInteracableItemEvent DroppedFromHand;
	
	
	// Accessors //
	// ========= //
	UItemGripComponent* GetMainGrip() const { return ItemGripComponent; }

	UItemPocket* GetPocketOwner() const { return PocketOwner; }
	
	
	// Lifecycle //
	// ========= //
	AInteractableItemBase(const FObjectInitializer& ObjectInitializer);
		

	// Methods //
	// ======= //
	void GripBy(UPlayerInteractionComponent* InteractionComponent);
	void DropFrom(UPlayerInteractionComponent* InteractionComponent);

	virtual void TriggerItem(UPlayerInteractionComponent* InteractionComponent);
	virtual void StopTriggering(UPlayerInteractionComponent* InteractionComponent);
	
	void PutInPocket(UItemPocket* Pocket);
	void RemoveFromPocket();

	
protected:
	// Subroutines //
	// =========== //
	void SnapToHolder(USceneComponent* Holder);
	void RemoveFromHolder();
};
