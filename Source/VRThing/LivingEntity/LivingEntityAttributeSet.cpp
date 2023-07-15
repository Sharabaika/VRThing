#include "LivingEntityAttributeSet.h"

#include "GameplayEffectExtension.h"

ULivingEntityAttributeSet::ULivingEntityAttributeSet()
{
	InitHealth(100.0f);
}

void ULivingEntityAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		const float NewHealth = FMath::Max(GetHealth() - GetDamage(), 0.0f);
		const float OldHealth = GetHealth();
		SetHealth(NewHealth);
		
		if (NewHealth == 0.0f && OldHealth > 0.0f)
		{
			const static FGameplayTag DeathEventTag = FGameplayTag::RequestGameplayTag("Event.LivingEntity.Death");

			auto Context = Data.EffectSpec.GetContext();
			FGameplayEventData EventPayload;
			GetOwningAbilitySystemComponent()->HandleGameplayEvent(DeathEventTag, &EventPayload);
		}

		SetDamage(0.0f);
	}
}
