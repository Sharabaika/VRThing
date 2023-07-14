#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "UObject/Object.h"
#include "VRThing/Misc/Macro.h"
#include "WeaponAttributeSet.generated.h"

UCLASS()
class UWeaponAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	// State //
	// ===== //
	UPROPERTY()
	FGameplayAttributeData CurrentAmmo;
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, CurrentAmmo);

	UPROPERTY()
	FGameplayAttributeData MaxAmmo;
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, MaxAmmo);


	// Lifecycle //
	// ========= //
	UWeaponAttributeSet();
};
