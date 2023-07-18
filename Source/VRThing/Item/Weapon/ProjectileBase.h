#pragma once
#include "ProjectileBase.generated.h"

class UGameplayEffect;
UCLASS()
class AProjectileBase: public AActor
{
	GENERATED_BODY()
protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditDefaultsOnly)
	float InitialVelocity;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> DamageEffect;

	UPROPERTY(EditDefaultsOnly)
	float MinVelocityFractionToDamage;

	
	// Subobjects //
	// ========== //
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPrimitiveComponent* Collision;


	// State //
	// ===== //
	UPROPERTY()
	bool bDidHit;
	
	
public:
	// Lifecycle //
	// ========= //
	AProjectileBase();
	virtual void BeginPlay() override;
	
	
	// Methods //
	// ======= //
	virtual void Launch();

	
protected:
	// Event Responses //
	// =============== //
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
