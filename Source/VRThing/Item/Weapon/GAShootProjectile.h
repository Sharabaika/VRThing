#pragma once
#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAShootProjectile.generated.h"

class AProjectileBase;

UCLASS()
class UGAShootProjectile : public UGameplayAbility
{
	GENERATED_BODY()
protected:
	// Accessors //
	// ========= //
	
	// does not compile otherwise:(
	virtual uint8 GetGameplayTaskDefaultPriority() const override { return FGameplayTasks::DefaultPriority; }


	// Lifecycle //
	// ========= //
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
