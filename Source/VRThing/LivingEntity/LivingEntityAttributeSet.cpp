#include "LivingEntityAttributeSet.h"

ULivingEntityAttributeSet::ULivingEntityAttributeSet()
{
	InitHealth(100.0f);
}

void ULivingEntityAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	
}
