#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LivingEntity.generated.h"

UINTERFACE()
class ULivingEntity : public UInterface
{
	GENERATED_BODY()
};

class ILivingEntity
{
	GENERATED_BODY()
public:

	virtual void Die() = 0;
};
