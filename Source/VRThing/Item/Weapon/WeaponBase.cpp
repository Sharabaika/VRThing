#include "WeaponBase.h"
#include "WeaponAttributeSet.h"

AWeaponBase::AWeaponBase()
{
	INIT_COMPONENT(UAbilitySystemComponent, AbilitySystemComponent);	
	INIT_COMPONENT(UWeaponAttributeSet, WeaponAttributeSet);

	INIT_COMPONENT(UArrowComponent, MuzzleComponent);
	MuzzleComponent->SetupAttachment(RootComponent);
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
