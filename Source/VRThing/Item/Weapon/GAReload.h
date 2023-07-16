#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VRThing/Abilities/GABase.h"
#include "GAReload.generated.h"

UCLASS()
class UGAReload : public UGABase
{
	GENERATED_BODY()
protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> RefillAmmoEffect;


	// Lifecycle //
	// ========= //
	UGAReload();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
};
