// Fill out your copyright notice in the Description page of Project Settings.


#include "UserProfile.h"

#include "CppCookbookGameModeBase.h"

void AUserProfile::SayHello()
{
	// Simple
	UE_LOG(LogTemp, Warning, TEXT("Some warning message"));

	// Variables
	int intVar = 5;
	float floatVar = 3.7f;
	FString fstringVar = "an fstring variable";
	UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar);

	// Using FString::Printf()
	FString name = "Tim";
	int32 mana = 450;
	FString string = FString::Printf(TEXT("Name = %s Mana =%d"), *name, mana);

	// Using FString::Format()
	FString name1 = "Tim";
	int32 mana1 = 450;
	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(name1));
	args.Add(FStringFormatArg(mana1));
	FString string1 = FString::Format(TEXT("Name = {0} Mana = {1}"), args);
	UE_LOG(LogTemp, Warning, TEXT( "Your string: %s" ), *string);
}

void AUserProfile::CreateObjectTest()
{
	ACppCookbookGameModeBase* GameMod = Cast<ACppCookbookGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMod)
	{
		UE_LOG(LogTemp, Warning, TEXT("Maboi 1"));
		UObjectUserProfile* MyBoi = NewObject<UObjectUserProfile>(GameMod->UPBlueprintClassName);
		UE_LOG(LogTemp, Warning, TEXT("Maboi 2"));
		MyBoi->ConditionalBeginDestroy();
		UE_LOG(LogTemp, Warning, TEXT("Maboi 3, %s"), *MyBoi->GetName());
	}
}
