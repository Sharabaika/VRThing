#include "GAAutoDropMag.h"
#include "AbilitySystemComponent.h"
#include "MagReceiver.h"
#include "WeaponAttributeSet.h"
#include "WeaponBase.h"

UGAAutoDropMag::UGAAutoDropMag()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGAAutoDropMag::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);

	Weapon = Cast<AWeaponBase>(ActorInfo->AvatarActor);
	if (Weapon)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, false);
	}
}

void UGAAutoDropMag::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	GetAbilitySystemComponentFromActorInfo()-> GetGameplayAttributeValueChangeDelegate(UWeaponAttributeSet::GetCurrentAmmoAttribute()).AddUObject(this, &ThisClass::OnAmmoChanged);
}

void UGAAutoDropMag::OnAmmoChanged(const FOnAttributeChangeData& ChangeData)
{
	if (ChangeData.NewValue <= 0.0f)
	{
		Weapon->GetMagReceiver()->DropEmptyMag();
	}
}
