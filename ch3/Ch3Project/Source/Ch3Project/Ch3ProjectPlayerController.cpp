// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Ch3Project.h"
#include "Ch3ProjectPlayerController.h"

ACh3ProjectPlayerController::ACh3ProjectPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
