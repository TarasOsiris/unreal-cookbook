// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWarriorCharacter.h"

// Sets default values
AMyWarriorCharacter::AMyWarriorCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyWarriorCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyWarriorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyWarriorCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &AMyWarriorCharacter::Forward);
	PlayerInputComponent->BindAxis("Back", this, &AMyWarriorCharacter::Back);
}

void AMyWarriorCharacter::Forward(float amount)
{
	if (Controller && amount)
	{
		// Moves the player forward by an amount in forward direction
		AddMovementInput(GetActorForwardVector(), amount);
	}
}
void AMyWarriorCharacter::Back(float amount)
{
	if (Controller && amount)
	{
		// Moves the player forward by an amount in backward direction
		AddMovementInput(-GetActorForwardVector(), amount);
	}
}
