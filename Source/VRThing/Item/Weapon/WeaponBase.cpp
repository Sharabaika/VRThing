#include "WeaponBase.h"
#include "WeaponAttributeSet.h"

AWeaponBase::AWeaponBase(const FObjectInitializer& ObjectInitializer)
	: Super(
		ObjectInitializer.SetDefaultSubobjectClass<USkeletalMeshComponent>(AInteractableItemBase::PhysicsRootName)
		)
{	
	INIT_COMPONENT(UArrowComponent, MuzzleComponent);
	MuzzleComponent->SetupAttachment(PhysicsRoot);
	
	INIT_COMPONENT(UAbilitySystemComponent, AbilitySystemComponent);	
	INIT_COMPONENT(UWeaponAttributeSet, WeaponAttributeSet);
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->GiveAbility(TriggerAbility);
}

void AWeaponBase::TriggerItem(UPlayerInteractionComponent* InteractionComponent)
{
	Super::TriggerItem(InteractionComponent);

	AbilitySystemComponent->TryActivateAbilityByClass(TriggerAbility);
}
