#pragma once
#include "CoreMinimal.h"
#include "VRThing/Abilities/GABase.h"
#include "GAAutoDropMag.generated.h"

class AWeaponBase;

UCLASS()
class UGAAutoDropMag : public UGABase
{
	GENERATED_BODY()

	// Dependencies //
	// ============ //
	UPROPERTY(Transient)
	AWeaponBase* Weapon;

	
	// Lifecycle //
	// ========= //
	UGAAutoDropMag();
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;


	// Event Responses //
	// =============== //
	void OnAmmoChanged(const FOnAttributeChangeData& ChangeData);
};
