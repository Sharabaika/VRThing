#include "VRCamera.h"
#include "VRThing/Misc/Names.h"


UVRCamera::UVRCamera()
	: Super()
{
}

void UVRCamera::SetupInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAxis(InputNames::FakeVRCamera_Pitch, this, &ThisClass::OnFakeCameraPitch);
}

void UVRCamera::OnFakeCameraPitch(float Value)
{
	AddLocalRotation(FRotator{Value, 0, 0});
}