#include "WeaponBase.h"
#include "MagReceiver.h"
#include "WeaponAttributeSet.h"

AWeaponBase::AWeaponBase(const FObjectInitializer& ObjectInitializer)
	: Super(
		ObjectInitializer.SetDefaultSubobjectClass<USkeletalMeshComponent>(AInteractableItemBase::PhysicsRootName)
		)
{	
	INIT_COMPONENT(UArrowComponent, MuzzleComponent);
	MuzzleComponent->SetupAttachment(PhysicsRoot);

	INIT_COMPONENT(UMagReceiver, MagReceiver);
	MagReceiver->SetupAttachment(PhysicsRoot);
	
	INIT_COMPONENT(UAbilitySystemComponent, AbilitySystemComponent);	
	INIT_COMPONENT(UWeaponAttributeSet, WeaponAttributeSet);
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->GiveAbility(TriggerAbility);
	AbilitySystemComponent->GiveAbility(ReloadAbility);
	for (auto Ability : GrantedAbilities)
	{
		AbilitySystemComponent->GiveAbility(Ability);
	}

	MagReceiver->ItemPlaced.AddUObject(this, &ThisClass::OnMagPlaced);
}

void AWeaponBase::TriggerItem(UPlayerInteractionComponent* InteractionComponent)
{
	Super::TriggerItem(InteractionComponent);

	if (TriggerAbility)
	{
		AbilitySystemComponent->TryActivateAbilityByClass(TriggerAbility);
	}
}

void AWeaponBase::OnMagPlaced(AInteractableItemBase* Mag)
{
	if (ReloadAbility)
	{
		AbilitySystemComponent->TryActivateAbilityByClass(ReloadAbility);
	}
}
