// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "MyTarasMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=Experimental, meta = (BlueprintSpawnableComponent))
class CPPCOOKBOOK_API UMyTarasMeshComponent : public UMeshComponent
{
	GENERATED_BODY()

public:
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;

	TArray<int32> Indices;

	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = XXX)
	UMaterial* TheMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = XXX)
	int32 Boi;
	
	UMyTarasMeshComponent();
};
