#pragma once
#include "CoreMinimal.h"
#include "VRThing/Abilities/GABase.h"
#include "GAShootProjectile.generated.h"

class AProjectileBase;

UCLASS()
class UGAShootProjectile : public UGABase
{
	GENERATED_BODY()
	
protected:
	// Lifecycle //
	// ========= //
	UGAShootProjectile();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
