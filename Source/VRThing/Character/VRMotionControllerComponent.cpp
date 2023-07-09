#include "VRMotionControllerComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "VRThing/Misc/Enums.h"
#include "VRThing/Misc/Names.h"


UVRMotionControllerComponent::UVRMotionControllerComponent()
	: Super{}
{
}

void UVRMotionControllerComponent::SetupPlayerInputComponent(APlayerController* InPlayerController, UInputComponent* InputComponent, ELeftRight InWhichHand)
{
	PlayerController = InPlayerController;
	WhichHand = InWhichHand;
	const int32 WhichHandInt{ static_cast<int32>(WhichHand) };
	
	// Fake input
	InputComponent->BindAction(InputNames::EnableFakeVRMode, IE_Pressed, this, &ThisClass::EnableFakeControllerInput);
	InputComponent->BindAction(InputNames::EnableFakeVRMode, IE_Released, this, &ThisClass::DisableFakeControllerInput);
	
	FakeVRControllerInputComponent = NewObject<UInputComponent>(
			PlayerController,
			FName{ TEXT("Motion Controller Keyboard Mouse Rotation Input"), WhichHandInt},
			RF_Transient);
	FakeVRControllerInputComponent->Priority = 1;
	
	FakeVRControllerInputComponent->BindAxis(InputNames::FakeVRController_X, this, &ThisClass::OnFakeX);
	FakeVRControllerInputComponent->BindAxis(InputNames::FakeVRController_Y, this, &ThisClass::OnFakeY);
	FakeVRControllerInputComponent->BindAxis(InputNames::FakeVRController_Z, this, &ThisClass::OnFakeZ);
}


void UVRMotionControllerComponent::EnableFakeControllerInput()
{
	if (IsSuitableFakeInputHand())
	{
		PlayerController->PushInputComponent(FakeVRControllerInputComponent);
	}
}

void UVRMotionControllerComponent::DisableFakeControllerInput()
{
	
	PlayerController->PopInputComponent(FakeVRControllerInputComponent);
}

void UVRMotionControllerComponent::OnFakeX(float Value)
{
	if (ShouldRotateFakeInput())
	{
		AddLocalRotation(FRotator{Value, 0, 0});
	}
	else
	{
		AddLocalOffset(FVector::XAxisVector*Value);
	}
}

void UVRMotionControllerComponent::OnFakeY(float Value)
{
	if (ShouldRotateFakeInput())
	{
		AddLocalRotation(FRotator{0, Value, 0});
	}
	else
	{
		AddLocalOffset(FVector::YAxisVector*Value);
	}
}

void UVRMotionControllerComponent::OnFakeZ(float Value)
{
	if (ShouldRotateFakeInput())
	{
		AddLocalRotation(FRotator{0, 0, Value});
	}
	else
	{
		AddLocalOffset(FVector::ZAxisVector*Value);
	}
}

bool UVRMotionControllerComponent::IsSuitableFakeInputHand() const
{
	return WhichHand == ELeftRight::Right != PlayerController->PlayerInput->IsAltPressed();
}

bool UVRMotionControllerComponent::ShouldRotateFakeInput() const
{
	return PlayerController->PlayerInput->IsPressed(EKeys::ThumbMouseButton2);
}