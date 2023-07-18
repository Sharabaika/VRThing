#include "VRGameMode.h"
#include "VRPlayerState.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "VRThing/Character/VRCharacter.h"

void AVRGameMode::BeginPlay()
{
	Super::BeginPlay();

	for (auto* Player : GameState->PlayerArray)
	{
		if (auto* VRPlayerState = Cast<AVRPlayerState>(Player))
		{
			VRPlayerState->PlayerRespawned.AddUObject(this, &ThisClass::OnCharacterRespawned, VRPlayerState);
		}
	}
}

void AVRGameMode::OnCharacterRespawned(AVRPlayerState* Player)
{
	AController* Controller = Player->GetPawn()->GetController();
	Controller->UnPossess();
	RestartPlayer(Controller);
}
