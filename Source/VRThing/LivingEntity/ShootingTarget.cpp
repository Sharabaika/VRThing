#include "ShootingTarget.h"

AShootingTarget::AShootingTarget()
{
	INIT_COMPONENT(USkeletalMeshComponent, SkeletalMeshComponent);
	SetRootComponent(SkeletalMeshComponent);
	
	INIT_COMPONENT(UAbilitySystemComponent, AbilitySystemComponent);

	INIT_COMPONENT(ULivingEntityAttributeSet, LivingEntityAttributes);
}

void AShootingTarget::BeginPlay()
{
	Super::BeginPlay();

	for (auto AbilityClas : GrantedAbilities)
	{
		GetAbilitySystemComponent()->GiveAbility(AbilityClas);
	}
}

void AShootingTarget::Die()
{
	SkeletalMeshComponent->SetSimulatePhysics(true);
}
