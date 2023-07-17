#pragma once
#include "CoreMinimal.h"
#include "VRThing/Abilities/GABase.h"
#include "GARespawn.generated.h"

UCLASS()
class UGARespawn : public UGABase
{
	GENERATED_BODY()

	// Lifecycle //
	// ========= //
	UGARespawn();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
