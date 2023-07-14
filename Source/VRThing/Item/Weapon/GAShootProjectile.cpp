#include "GAShootProjectile.h"

#include "ProjectileBase.h"
#include "WeaponBase.h"
#include "Tasks/GameplayTask_SpawnActor.h"

void UGAShootProjectile::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                         const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                         const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (auto* Weapon = Cast<AWeaponBase>(GetAvatarActorFromActorInfo()))
	{
		FTransform MuzzleTransform = Weapon->GetMuzzleComponent()->GetComponentTransform();
		TSubclassOf<AProjectileBase> ProjectileClass = Weapon->GetProjectileClass();

		auto* Projectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, MuzzleTransform.GetLocation(), MuzzleTransform.Rotator());
		Projectile->Launch();
	}
}