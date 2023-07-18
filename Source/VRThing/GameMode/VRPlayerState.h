#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "VRPlayerState.generated.h"

DECLARE_MULTICAST_DELEGATE(FVoidDelegate);

UCLASS()
class AVRPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	// Events //
	// ====== //
	FVoidDelegate PlayerRespawned;


	// Methods //
	// ======= //
	void NotifyPlayerRespawn();
};
