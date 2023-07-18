#include "VRPlayerState.h"

void AVRPlayerState::NotifyPlayerRespawn()
{
	PlayerRespawned.Broadcast();
}
