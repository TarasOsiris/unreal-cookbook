#include "TarasColoredTexture.generated.h"

USTRUCT(BlueprintType)
struct FTarasColoredTexture
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	UTexture* Texture;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
	FLinearColor Color;
};
