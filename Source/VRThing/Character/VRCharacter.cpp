#include "VRCharacter.h"
#include "PlayerMovementComponent.h"
#include "VRCamera.h"
#include "VRMotionControllerComponent.h"
#include "Interaction/InteractionDetector.h"
#include "Interaction/PlayerInteractionComponent.h"
#include "VRThing/Misc/Enums.h"
#include "VRThing/Misc/Macto.h"


AVRCharacter::AVRCharacter(const FObjectInitializer& ObjectInitializer)
	: Super{ ObjectInitializer
		.SetDefaultSubobjectClass<UPlayerMovementComponent>(CharacterMovementComponentName)
		}
{
	INIT_COMPONENT(UVRCamera, VRCamera);
	VRCamera->SetupAttachment(RootComponent);

	
	INIT_COMPONENT(UVRMotionControllerComponent, LeftMotionController);
	LeftMotionController->SetupAttachment(RootComponent);
	LeftMotionController->MotionSource = "Left";
	
	INIT_COMPONENT(UPlayerInteractionComponent, LeftInteractionComponent);
	LeftInteractionComponent->SetupAttachment(LeftMotionController);
	LeftInteractionComponent->SetWhichHand(Left);

	INIT_COMPONENT(UInteractionDetector, LeftInteractionDetector);
	LeftInteractionDetector->SetupAttachment(LeftInteractionComponent);
	
	LeftInteractionComponent->SetDetector(LeftInteractionDetector);

	
	INIT_COMPONENT(UVRMotionControllerComponent, RightMotionController);
	RightMotionController->SetupAttachment(RootComponent);
	RightMotionController->MotionSource = "Right";

	INIT_COMPONENT(UPlayerInteractionComponent, RightInteractionComponent);
	RightInteractionComponent->SetupAttachment(RightMotionController);
	RightInteractionComponent->SetWhichHand(Right);

	INIT_COMPONENT(UInteractionDetector, RightInteractionDetector);
	RightInteractionDetector->SetupAttachment(RightInteractionComponent);
	
	RightInteractionComponent->SetDetector(RightInteractionDetector);
	
	
	GetPlayerMovementComponent()->SetDependencies(VRCamera);
}

void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->Priority = 0;
	
	GetPlayerMovementComponent()->SetupPlayerInputComponent(PlayerInputComponent);

	VRCamera->SetupInputComponent(PlayerInputComponent);
	
	APlayerController* PlayerController = GetController<APlayerController>();
	LeftMotionController->SetupPlayerInputComponent(PlayerController, PlayerInputComponent, ELeftRight::Left);
	RightMotionController->SetupPlayerInputComponent(PlayerController, PlayerInputComponent, ELeftRight::Right);

	LeftInteractionComponent->SetupPlayerInputComponent(InputComponent);
	RightInteractionComponent->SetupPlayerInputComponent(InputComponent);
}

UPlayerMovementComponent* AVRCharacter::GetPlayerMovementComponent()
{
	return Cast<UPlayerMovementComponent>(GetCharacterMovement());
}