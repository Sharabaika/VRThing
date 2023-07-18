#include "VRCharacter.h"
#include "AbilitySystemComponent.h"
#include "PlayerMovementComponent.h"
#include "VRCamera.h"
#include "VRMotionControllerComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "Interaction/InteractionDetector.h"
#include "Interaction/ItemPocket.h"
#include "Interaction/PlayerInteractionComponent.h"
#include "VRThing/GameMode/VRPlayerState.h"
#include "VRThing/Item/Weapon/AmmoPocket.h"
#include "VRThing/LivingEntity/LivingEntityAttributeSet.h"
#include "VRThing/Misc/Enums.h"
#include "VRThing/Misc/Macro.h"


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

	INIT_COMPONENT(UAmmoPocket, AmmoPocket);
	AmmoPocket->SetupAttachment(RootComponent);

	INIT_COMPONENT(UItemPocket, ItemPocket);
	ItemPocket->SetupAttachment(RootComponent);
	
	GetPlayerMovementComponent()->SetDependencies(VRCamera);

	
	INIT_COMPONENT(UAbilitySystemComponent, AbilitySystemComponent);
	INIT_COMPONENT(ULivingEntityAttributeSet, LivingEntityAttributes);

	bAlive = true;
}

void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();

	for (auto AbilityClas : GrantedAbilities)
	{
		GetAbilitySystemComponent()->GiveAbility(AbilityClas);
	}
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

void AVRCharacter::Die()
{	
	LeftInteractionComponent->Deactivate();
	RightInteractionComponent->Deactivate();
	ItemPocket->Deactivate();
	AmmoPocket->Deactivate();
	GetPlayerMovementComponent()->DisableMovement();

	SetIsAlive(false);
}

void AVRCharacter::Respawn()
{
	AbilitySystemComponent->CancelAllAbilities();
	GetPlayerState<AVRPlayerState>()->NotifyPlayerRespawn();

	SetLifeSpan(0.1f);
}

void AVRCharacter::SetIsAlive(bool bvalue)
{
	bAlive = bvalue;
	IsAliveChanged.Broadcast(bAlive);
}
