#include "ProjectileBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "VRThing/Misc/Macro.h"

AProjectileBase::AProjectileBase()
{
	INIT_COMPONENT(USphereComponent, Collision);
	SetRootComponent(Collision);
}

void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	Collision->OnComponentHit.AddDynamic(this, &ThisClass::OnHit);
}

void AProjectileBase::Launch()
{
	Collision->AddImpulse(GetActorForwardVector()*InitialImpulse);
}

void AProjectileBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	auto* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (AbilitySystemInterface && DamageEffect)
	{
		FGameplayEffectContextHandle ContextHandle;
		ContextHandle.AddInstigator(GetInstigator(), GetOwner());
		ContextHandle.AddHitResult(Hit);
		ContextHandle.AddSourceObject(this);

		AbilitySystemInterface->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(DamageEffect->GetDefaultObject<UGameplayEffect>(), 1.0f, ContextHandle);
	}
}
