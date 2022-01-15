// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyTarasAction.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="Base class for any Action type"))
class CPPCOOKBOOK_API UMyTarasAction : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Properties)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Properties)
	FKey ShortcutKey;
};
