#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class FPSCPP_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)	float life = 100;
};
