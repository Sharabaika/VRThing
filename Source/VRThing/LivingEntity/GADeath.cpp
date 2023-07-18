#include "GADeath.h"
#include "AbilitySystemComponent.h"
#include "LivingEntity.h"
#include "Abilities/Tasks/AbilityTask_WaitDelay.h"

UGADeath::UGADeath()
{
	FAbilityTriggerData TriggerData;
	const static FGameplayTag DeathEventTag = FGameplayTag::RequestGameplayTag("Event.LivingEntity.Death");
	TriggerData.TriggerTag = DeathEventTag;
	AbilityTriggers.Add(TriggerData);

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	
	RespawnDelay = 5.0f;
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

	auto* Task = UAbilityTask_WaitDelay::WaitDelay(this, RespawnDelay);
	Task->OnFinish.AddDynamic(this, &ThisClass::OnDelayFinished);
	Task->ReadyForActivation();
}

void UGADeath::OnDelayFinished()
{
	const static FGameplayTag RespawnEventTag = FGameplayTag::RequestGameplayTag("Event.LivingEntity.Respawn");
	FGameplayEventData Payload;
	GetAbilitySystemComponentFromActorInfo()->HandleGameplayEvent(RespawnEventTag, &Payload);
	
	FinishAbility();
}
