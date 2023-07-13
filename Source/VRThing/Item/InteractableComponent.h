#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableComponent.generated.h"

class UPlayerInteractionComponent;

UINTERFACE()
class UInteractableComponent : public UInterface
{
	GENERATED_BODY()
};

class IInteractableComponent
{
	GENERATED_BODY()
public:
	virtual bool CanInteractWith(UPlayerInteractionComponent* InteractionComponent) const { return true; }
	virtual int GetInteractionPriority() const { return 0; }
	
	virtual void StartInteracting(UPlayerInteractionComponent* InteractionComponent){}
	virtual void EndInteracting(){}

	virtual void StartTriggering(UPlayerInteractionComponent* InteractionComponent){}
	virtual void EndTriggering(UPlayerInteractionComponent* InteractionComponent){}
};
