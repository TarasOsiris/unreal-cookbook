// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ObjectUserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CPPCOOKBOOK_API UObjectUserProfile : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SayHi();
};
