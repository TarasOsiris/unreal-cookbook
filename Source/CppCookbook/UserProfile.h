// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h"

/**
 
   Blueprintable: This means that you want to be able to construct a Blueprint
   from the Class Viewer inside the UE4 Editor (when you right-click, Create Blueprint
   Class… becomes available).
   
	BlueprintType: Using this keyword implies that the UCLASS is usable as
	a variable from another Blueprint.
 */
UCLASS(Blueprintable, BlueprintType)
class CPPCOOKBOOK_API AUserProfile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	float HpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject> UClassOfPlayer; // Displays any UClasses deriving from UObject in a dropdown menu in Blueprints

	// Displays string names of UCLASSes that derive from
	// the GameMode C++ base class
	UPROPERTY(EditAnywhere, meta=(MetaClass="GameMode"), Category = Unit)
	FStringClassReference UClassGameMode;

	UFUNCTION(BlueprintCallable)
	void SayHello();
	
	UFUNCTION(BlueprintCallable)
	void CreateObjectTest();
};
