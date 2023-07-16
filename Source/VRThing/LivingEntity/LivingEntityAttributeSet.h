#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "VRThing/Misc/Macro.h"
#include "LivingEntityAttributeSet.generated.h"

UCLASS()
class ULivingEntityAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
protected:
	// State //
	// ===== //
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(ULivingEntityAttributeSet, Health);

	UPROPERTY()
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(ULivingEntityAttributeSet, Damage);

public:
	// Lifecycle //
	// ========= //
	ULivingEntityAttributeSet();
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
