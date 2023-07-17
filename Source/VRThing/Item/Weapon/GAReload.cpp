#include "GAReload.h"
#include "AbilitySystemComponent.h"

UGAReload::UGAReload()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGAReload::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (RefillAmmoEffect)
	{
		GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectToSelf(RefillAmmoEffect->GetDefaultObject<UGameplayEffect>(), 0, MakeEffectContext(Handle, ActorInfo));
	}

	FinishAbility();
}
