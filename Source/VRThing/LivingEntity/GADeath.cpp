#include "GADeath.h"
#include "LivingEntity.h"

UGADeath::UGADeath()
{
	FAbilityTriggerData TriggerData;
	const static FGameplayTag DeathEventTag = FGameplayTag::RequestGameplayTag("Event.LivingEntity.Death");
	TriggerData.TriggerTag = DeathEventTag;
	AbilityTriggers.Add(TriggerData);
}

void UGADeath::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);
	
	ensure(ActorInfo->AvatarActor->Implements<ULivingEntity>());
}

void UGADeath::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	auto* LivingAvatar = Cast<ILivingEntity>(GetAvatarActorFromActorInfo());
	if (LivingAvatar)
	{
		LivingAvatar->Die();
	}

	FinishAbility();
}
