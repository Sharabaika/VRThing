#pragma once
#include "ProjectileBase.generated.h"

UCLASS()
class AProjectileBase: public AActor
{
	GENERATED_BODY()
protected:
	// Configuration //
	// ============= //
	UPROPERTY(EditAnywhere)
	float InitialImpulse;


	// Subobjects //
	// ========== //

	// TODO sketchy
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UPrimitiveComponent* Collision;

public:
	// Lifecycle //
	// ========= //
	AProjectileBase();

	
	// Methods //
	// ======= //
	virtual void Launch();	
};
