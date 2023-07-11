#include "InteractionDetector.h"

void UInteractionDetector::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

void UInteractionDetector::SetDetectedInteractable(UObject* Object)
{
	DetectedInteractable = Object;
}

void UInteractionDetector::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->Implements<UInteractableComponent>())
	{
		SetDetectedInteractable(OtherComp);
	}
}
