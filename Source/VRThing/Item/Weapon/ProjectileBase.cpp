#include "ProjectileBase.h"
#include "AbilitySystemComponent.h"
#include "Components/SphereComponent.h"
#include "VRThing/Misc/Macro.h"

AProjectileBase::AProjectileBase()
{
	INIT_COMPONENT(USphereComponent, Collision);
	SetRootComponent(Collision);
}

void AProjectileBase::Launch()
{
	Collision->AddImpulse(GetActorForwardVector()*InitialImpulse);
}
