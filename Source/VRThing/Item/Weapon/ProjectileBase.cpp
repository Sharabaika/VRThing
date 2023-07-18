#include "ProjectileBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "VRThing/Misc/Macro.h"

AProjectileBase::AProjectileBase()
{
	InitialVelocity = 1000.0f;
	MinVelocityFractionToDamage = 0.1f;
	
	INIT_COMPONENT(USphereComponent, Collision);
	SetRootComponent(Collision);
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	Collision->OnComponentHit.AddDynamic(this, &ThisClass::OnHit);
	SetLifeSpan(10.0f);
}

void AProjectileBase::Launch()
{
	Collision->SetPhysicsLinearVelocity(GetActorForwardVector()*InitialVelocity);
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	auto* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor);
	const float VelocityFraction = Collision->GetPhysicsLinearVelocity().Size() / InitialVelocity;
	if (AbilitySystemInterface && DamageEffect &&
		!bDidHit && VelocityFraction >= MinVelocityFractionToDamage)
	{
		FGameplayEffectContextHandle ContextHandle;
		ContextHandle.AddInstigator(GetInstigator(), GetOwner());
		ContextHandle.AddHitResult(Hit);
		ContextHandle.AddSourceObject(this);

		AbilitySystemInterface->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(DamageEffect->GetDefaultObject<UGameplayEffect>(), 1.0f, ContextHandle);

		bDidHit = true;
		Collision->OnComponentHit.RemoveAll(this);
	}
}
