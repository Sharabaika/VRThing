#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "VRGameMode.generated.h"

class AVRPlayerState;

UCLASS()
class AVRGameMode : public AGameMode
{
	GENERATED_BODY()

	// Lifecycle //
	// ========= //
	virtual void BeginPlay() override;


	// Subroutines //
	// =========== //
	void OnCharacterRespawned(AVRPlayerState* Character);
};
