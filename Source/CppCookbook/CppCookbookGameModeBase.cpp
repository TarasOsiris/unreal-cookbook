// Copyright Epic Games, Inc. All Rights Reserved.


#include "CppCookbookGameModeBase.h"

#include "MyFancyActor.h"

void ACppCookbookGameModeBase::DestroyActorFunction()
{
	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy();
	}
}

void ACppCookbookGameModeBase::SpawnActor()
{
	// Spawning actors
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AMyFancyActor>(AMyFancyActor::StaticClass(), SpawnLocation);

	// Delete actor after 10 seconds
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ACppCookbookGameModeBase::DestroyActorFunction, 10);
}

void ACppCookbookGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 6, FColor::Red,TEXT("Actor Spawning"));

	SpawnActor();
}
