// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorSpawnerSceneComponent.h"

// Sets default values for this component's properties
UMyActorSpawnerSceneComponent::UMyActorSpawnerSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMyActorSpawnerSceneComponent::Spawn() const
{
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		const FTransform ComponentTransform(this->GetComponentTransform());
		TheWorld->SpawnActor(ActorToSpawn, &ComponentTransform);
	}
}


// Called when the game starts
void UMyActorSpawnerSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UMyActorSpawnerSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
