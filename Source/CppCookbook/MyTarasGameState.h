// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyTarasGameState.generated.h"

/**
 * 
 */
UCLASS()
class CPPCOOKBOOK_API AMyTarasGameState : public AGameState
{
	GENERATED_BODY()

	AMyTarasGameState();

	UFUNCTION()
	void SetScore(int32 NewScore);

	UFUNCTION()
	int32 GetScore();

private:
	UPROPERTY()
	int32 CurrentScore;
};
