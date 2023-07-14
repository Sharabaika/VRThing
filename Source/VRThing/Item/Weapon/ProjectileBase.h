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
	float InitialImpulse;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> DamageEffect;

	
	// Subobjects //
	// ========== //

	// TODO sketchy
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPrimitiveComponent* Collision;

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
