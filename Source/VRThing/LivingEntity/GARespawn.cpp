#include "GARespawn.h"
#include "LivingEntity.h"

UGARespawn::UGARespawn()
{
	FAbilityTriggerData TriggerData;
	const static FGameplayTag RespawnEventTag = FGameplayTag::RequestGameplayTag("Event.LivingEntity.Respawn");
	TriggerData.TriggerTag = RespawnEventTag;
	AbilityTriggers.Add(TriggerData);

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGARespawn::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (auto* LivingAvatar = Cast<ILivingEntity>(GetAvatarActorFromActorInfo()))
	{
		LivingAvatar->Respawn();
	}

	FinishAbility();
}
