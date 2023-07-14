#include "ShootingTarget.h"

AShootingTarget::AShootingTarget()
{
	INIT_COMPONENT(UAbilitySystemComponent, AbilitySystemComponent);

	INIT_COMPONENT(ULivingEntityAttributeSet, LivingEntityAttributes);
}
