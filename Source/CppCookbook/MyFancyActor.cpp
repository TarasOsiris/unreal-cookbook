// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFancyActor.h"

// Sets default values
AMyFancyActor::AMyFancyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	// The string is of the format "{ObjectType}'/Path/To/Asset.Asset'". Note the use of single quotes in the string.
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AMyFancyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyFancyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
