﻿#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableItemBase.generated.h"

class UItemGripComponent;
class UPlayerInteractionComponent;

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
	
	static FName PhysicsRootName;

public:
	// Accessors //
	// ========= //
	UItemGripComponent* GetMainGrip() const { return ItemGripComponent; }
	
	
	// Lifecycle //
	// ========= //
	AInteractableItemBase(const FObjectInitializer& ObjectInitializer);
		

	// Methods //
	// ======= //
	void GripBy(UPlayerInteractionComponent* InteractionComponent);
	void DropFrom(UPlayerInteractionComponent* InteractionComponent);

	virtual void TriggerItem(UPlayerInteractionComponent* InteractionComponent);
	virtual void StopTriggering(UPlayerInteractionComponent* InteractionComponent);
};
