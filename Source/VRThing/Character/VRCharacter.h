#pragma once
#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "VRThing/LivingEntity/LivingEntity.h"
#include "VRCharacter.generated.h"

class UWidgetInteractionComponent;
class ULivingEntityAttributeSet;
class UGameplayAbility;
class UAmmoPocket;
class UItemPocket;
class UInteractionDetector;
class UPlayerInteractionComponent;
class UVRCamera;
class UVRMotionControllerComponent;
class UPlayerMovementComponent;

DECLARE_MULTICAST_DELEGATE(FVoidDelegate);

UCLASS()
class AVRCharacter : public ACharacter, public IAbilitySystemInterface, public ILivingEntity
{
	GENERATED_BODY()

protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities;
	
	
	// Subobjects //
	// ========== //
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRCamera* VRCamera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRMotionControllerComponent* LeftMotionController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPlayerInteractionComponent* LeftInteractionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInteractionDetector* LeftInteractionDetector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UVRMotionControllerComponent* RightMotionController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPlayerInteractionComponent* RightInteractionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInteractionDetector* RightInteractionDetector;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAmmoPocket* AmmoPocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UItemPocket* ItemPocket;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	ULivingEntityAttributeSet* LivingEntityAttributes;
	
	
public:
	// Events //
	// ====== //
	FVoidDelegate PlayerRespawned;
	
	
	// Lifecycle //
	// ========= //
	AVRCharacter(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	

	// Methods //
	// ======= //
	UPlayerMovementComponent* GetPlayerMovementComponent();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	virtual void Die() override;
	virtual void Respawn() override;

protected:
	// Subroutines //
	// =========== //
	UFUNCTION(BlueprintImplementableEvent)
	void ShowDeathScreen();

	UFUNCTION(BlueprintImplementableEvent)
	void HideDeathScreen();
};