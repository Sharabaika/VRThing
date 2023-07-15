#pragma once
#include "CoreMinimal.h"
#include "VRThing/Abilities/GABase.h"
#include "GADeath.generated.h"

UCLASS()
class UGADeath : public UGABase
{
	GENERATED_BODY()

	// Lifecycle //
	// ========= //
	UGADeath();
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
