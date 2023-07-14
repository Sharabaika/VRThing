#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Components/ArrowComponent.h"
#include "VRThing/Item/InteractableItemBase.h"
#include "WeaponBase.generated.h"

class AProjectileBase;
class UWeaponAttributeSet;
class UGameplayAbility;

UCLASS()
class AWeaponBase : public AInteractableItemBase, public IAbilitySystemInterface
{
	GENERATED_BODY()
protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayAbility> TriggerAbility;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AProjectileBase> ProjectileClass;
	
	
	// Subobjects //
	// ========== //
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UWeaponAttributeSet* WeaponAttributeSet;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UArrowComponent* MuzzleComponent;

	
public:
	// Accessors //
	// ========= //
	TSubclassOf<AProjectileBase> GetProjectileClass() const { return ProjectileClass; }
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	UPrimitiveComponent* GetMuzzleComponent() const { return MuzzleComponent; }
	
	
	// Lifecycle //
	// ========= //
	AWeaponBase();
	virtual void BeginPlay() override;


	// Methods //
	// ======= //
	virtual void TriggerItem(UPlayerInteractionComponent* InteractionComponent) override;
};
