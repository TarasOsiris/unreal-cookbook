// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ObjectUserProfile.h"
#include "TarasColoredTexture.h"
#include "UserProfile.h"
#include "GameFramework/GameModeBase.h"
#include "CppCookbookGameModeBase.generated.h"

UENUM()
enum Status
{
	Stopped UMETA(DisplayName = "Stopped"),
	Moving UMETA(DisplayName = "Moving"),
	Attacking UMETA(DisplayName = "Attacking"),
};

/**
 * 
 */
UCLASS()
class CPPCOOKBOOK_API ACppCookbookGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
	TSubclassOf<AUserProfile> UPBlueprintClassName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames)
	TSubclassOf<UObjectUserProfile> UPBlueprintClassNameAnother;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	FTarasColoredTexture MyTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	TEnumAsByte<Status> Status;
};
