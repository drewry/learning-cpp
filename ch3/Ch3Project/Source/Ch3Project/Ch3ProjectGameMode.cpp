// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Ch3Project.h"
#include "Ch3ProjectGameMode.h"
#include "Ch3ProjectPlayerController.h"

ACh3ProjectGameMode::ACh3ProjectGameMode()
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = ACh3ProjectPlayerController::StaticClass();
}
