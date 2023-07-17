﻿#include "PlayerInteractionComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "InteractionDetector.h"
#include "VRThing/Misc/Enums.h"
#include "VRThing/Misc/Names.h"


void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	SetActive(true);
}

void UPlayerInteractionComponent::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	const int32 WhichHandInt{ static_cast<int32>(WhichHand) };

	// Fake input
	const static FName GripNames[]{InputNames::GripLeft, InputNames::GripRight };
	const FName GripName{ GripNames[WhichHandInt] };
	InputComponent->BindAction(GripName, IE_Pressed, this, &ThisClass::OnFakeGripPressed)
		.bConsumeInput = false;
	InputComponent->BindAction(GripName, IE_Released, this, &ThisClass::OnFakeGripReleased)
		.bConsumeInput = false;

	const static FName TriggerNames[]{InputNames::TriggerLeft, InputNames::TriggerRight };
	const FName TriggerName{ TriggerNames[WhichHandInt] };
	InputComponent->BindAction(TriggerName, IE_Pressed, this, &ThisClass::OnFakeTriggerPressed)
		.bConsumeInput = false;
	InputComponent->BindAction(TriggerName, IE_Released, this, &ThisClass::OnFakeTriggerReleased)
		.bConsumeInput = false;

	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		// Native
		const static FName GripAxisNames[]{InputNames::GripLeftAxis, InputNames::GripRightAxis };
		InputComponent->BindAxis(GripAxisNames[WhichHandInt], this, &ThisClass::OnGrip);
		
		const static FName TriggerAxisNames[]{InputNames::TriggerLeftAxis, InputNames::TriggerRightAxis };
		InputComponent->BindAxis(TriggerAxisNames[WhichHandInt], this, &ThisClass::OnTrigger);
	}
}

void UPlayerInteractionComponent::SetWhichHand(ELeftRight InWhichHand)
{
	WhichHand = InWhichHand;
}

void UPlayerInteractionComponent::SetDetector(UInteractionDetector* InInteractionDetector)
{
	Detector = InInteractionDetector;
}

void UPlayerInteractionComponent::Deactivate()
{
	Super::Deactivate();

	StopInteracting();
}

void UPlayerInteractionComponent::TryToInteract()
{
	TScriptInterface<IInteractableComponent> Interactable = Detector->GetDesiredInteractable();
	if (Interactable && Interactable->CanInteractWith(this) && IsActive())
	{
		InteractWith(Interactable);
	}
}

void UPlayerInteractionComponent::StopInteracting()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->EndInteracting();
		CurrentInteractable = nullptr;
	}
}

void UPlayerInteractionComponent::InteractWith(TScriptInterface<IInteractableComponent> InteractableComponent)
{
	CurrentInteractable = InteractableComponent->StartInteracting(this);
}

void UPlayerInteractionComponent::TryToTrigger()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->StartTriggering(this);
	}
}

void UPlayerInteractionComponent::StopTriggering()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->EndTriggering(this);
	}
}

void UPlayerInteractionComponent::OnGrip(float Value)
{
}

void UPlayerInteractionComponent::OnTrigger(float Value)
{
}

void UPlayerInteractionComponent::OnFakeTriggerPressed()
{
	TryToTrigger();
}

void UPlayerInteractionComponent::OnFakeTriggerReleased()
{
	StopTriggering();
}

void UPlayerInteractionComponent::OnFakeGripPressed()
{
	TryToInteract();
}

void UPlayerInteractionComponent::OnFakeGripReleased()
{
	StopInteracting();
}
