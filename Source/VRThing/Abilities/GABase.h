#pragma once
#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GABase.generated.h"

UCLASS(Abstract)
class UGABase : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	// Lifecycle //
	// ========= //
	void FinishAbility();
};
