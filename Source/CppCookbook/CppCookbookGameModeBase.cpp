// Copyright Epic Games, Inc. All Rights Reserved.


#include "CppCookbookGameModeBase.h"

#include "MyFancyActor.h"

void ACppCookbookGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));

	// Spawning actors
	FTransform SpawnLocation;
	GetWorld()->SpawnActor<AMyFancyActor>(AMyFancyActor::StaticClass(), SpawnLocation);
}
