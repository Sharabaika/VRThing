﻿#pragma once
#include "CoreMinimal.h"

#define DECLARE_NAME(Name) extern FName Name

namespace InputNames
{
	// Input //
	// ===== //
	DECLARE_NAME(Strafe);
	DECLARE_NAME(MoveFrontBack);
	DECLARE_NAME(Turn);

	DECLARE_NAME(GripLeft);
	DECLARE_NAME(GripRight);
	
	DECLARE_NAME(GripLeftAxis);
	DECLARE_NAME(GripRightAxis);
	
	DECLARE_NAME(TriggerLeft);
	DECLARE_NAME(TriggerRight);

	DECLARE_NAME(TriggerLeftAxis);
	DECLARE_NAME(TriggerRightAxis);

	// Fake input //
	// ========== //
	DECLARE_NAME(EnableFakeVRMode);

	DECLARE_NAME(FakeVRCamera_Pitch);
	
	DECLARE_NAME(FakeVRController_X);
	DECLARE_NAME(FakeVRController_Y);
	DECLARE_NAME(FakeVRController_Z);
}