#pragma once

#include "CoreMinimal.h"
#include "MyPowerUp.h"
#include "MyPlayer.h"
#include "MyMoreBombs.generated.h"

UCLASS()
class BOMBERMAN_API AMyMoreBombs : public AMyPowerUp
{
	GENERATED_BODY()
	
public:
	AMyMoreBombs();

protected:
	void ActivatePowerUp(AMyPlayer* Player);
};
