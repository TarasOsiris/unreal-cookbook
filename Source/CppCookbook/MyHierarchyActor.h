// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyHierarchyActor.generated.h"

UCLASS()
class CPPCOOKBOOK_API AMyHierarchyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyHierarchyActor();

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY()
	USceneComponent* ChildSceneComponent;

	UPROPERTY()
	UStaticMeshComponent* BoxOne;

	UPROPERTY()
	UStaticMeshComponent* BoxTwo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
