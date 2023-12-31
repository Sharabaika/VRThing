﻿#include "GAShootProjectile.h"

#include "ProjectileBase.h"
#include "WeaponBase.h"
#include "Tasks/GameplayTask_SpawnActor.h"

UGAShootProjectile::UGAShootProjectile()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGAShootProjectile::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                         const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                         const FGameplayEventData* TriggerEventData)
{
	auto* Weapon = Cast<AWeaponBase>(GetAvatarActorFromActorInfo());
	if (CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		FTransform MuzzleTransform = Weapon->GetMuzzleComponent()->GetComponentTransform();
		TSubclassOf<AProjectileBase> ProjectileClass = Weapon->GetProjectileClass();

		auto* Projectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, MuzzleTransform.GetLocation(), MuzzleTransform.Rotator());
		Projectile->Launch();
	}

	FinishAbility();
}
