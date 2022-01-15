// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTarasGameState.h"

AMyTarasGameState::AMyTarasGameState()
{
	CurrentScore = 0;
}

int32 AMyTarasGameState::GetScore()
{
	return CurrentScore;
}

void AMyTarasGameState::SetScore(int32 NewScore)
{
	CurrentScore = NewScore;
}
