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
	UArrowComponent* MuzzleComponent;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UWeaponAttributeSet* WeaponAttributeSet;

	
public:
	// Accessors //
	// ========= //
	TSubclassOf<AProjectileBase> GetProjectileClass() const { return ProjectileClass; }

	USkeletalMeshComponent* GetMesh() const { return Cast<USkeletalMeshComponent>(PhysicsRoot); }
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	UPrimitiveComponent* GetMuzzleComponent() const { return MuzzleComponent; }
	
	
	// Lifecycle //
	// ========= //
	AWeaponBase(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;


	// Methods //
	// ======= //
	virtual void TriggerItem(UPlayerInteractionComponent* InteractionComponent) override;
};
