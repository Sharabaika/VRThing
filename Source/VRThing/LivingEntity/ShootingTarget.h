#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "LivingEntityAttributeSet.h"
#include "GameFramework/Actor.h"
#include "ShootingTarget.generated.h"

class UAbilitySystemComponent;
UCLASS()
class VRTHING_API AShootingTarget : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:
	// Subobjects //
	// ========== //
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	ULivingEntityAttributeSet* LivingEntityAttributes;
	
	
public:
	// Accessors //
	// ========= //
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	
	// Lifecycle //
	// ========= //
	AShootingTarget();
};
