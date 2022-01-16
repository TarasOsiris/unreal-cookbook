// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MyActorSpawnerSceneComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CPPCOOKBOOK_API UMyActorSpawnerSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyActorSpawnerSceneComponent();
	
	UFUNCTION(BlueprintCallable)
	void Spawn() const;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
