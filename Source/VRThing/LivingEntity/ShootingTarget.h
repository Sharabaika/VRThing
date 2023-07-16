#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "LivingEntity.h"
#include "LivingEntityAttributeSet.h"
#include "ShootingTarget.generated.h"


UCLASS()
class AShootingTarget : public APawn, public IAbilitySystemInterface, public ILivingEntity
{
	GENERATED_BODY()

protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;
	
	
	// Subobjects //
	// ========== //
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMeshComponent;

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
	virtual void BeginPlay() override;


	// Methods //
	// ======= //
	virtual void Die() override;
};
