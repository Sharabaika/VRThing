#include "InteractionDetector.h"
#include "VRThing/Item/InteractableComponent.h"
#include "Algo/MaxElement.h"

UInteractionDetector::UInteractionDetector()
{
	UPrimitiveComponent::SetCollisionProfileName("PlayerInteractionDetector");
	SetGenerateOverlapEvents(true);
}

void UInteractionDetector::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);
}

TScriptInterface<IInteractableComponent> UInteractionDetector::GetDesiredInteractable() const
{
	const TScriptInterface<IInteractableComponent>* DesiredInteractable = Algo::MaxElementBy(
		DetectedInteractables, [](TScriptInterface<IInteractableComponent> Interactable)
		{
			return Interactable->GetInteractionPriority();
		});

	return DesiredInteractable ? *DesiredInteractable : nullptr;
}

void UInteractionDetector::AddDetectedInteractable(UObject* Object)
{
	DetectedInteractables.Add(Object);
}

void UInteractionDetector::RemoveDetectedInteractable(UObject* Object)
{
	DetectedInteractables.Remove(Object);
}

void UInteractionDetector::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->Implements<UInteractableComponent>())
	{
		AddDetectedInteractable(OtherComp);
	}
}

void UInteractionDetector::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp->Implements<UInteractableComponent>())
	{
		RemoveDetectedInteractable(OtherComp);
	}
}