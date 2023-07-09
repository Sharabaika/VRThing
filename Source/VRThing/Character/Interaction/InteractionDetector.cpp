#include "InteractionDetector.h"

void UInteractionDetector::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

void UInteractionDetector::SetDetectedInteractable(IInteractableComponent* Value)
{
	DetectedInteractable.SetInterface(Value);
}

void UInteractionDetector::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto* Interactable = Cast<IInteractableComponent>(OtherComp);
	if (OtherComp)
	{
		SetDetectedInteractable(Interactable);
	}
}
