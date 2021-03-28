#pragma once

#include "CoreMinimal.h"
#include "MyPowerUp.h"
#include "MyPlayer.h"
#include "MySpeedBoost.generated.h"

UCLASS()
class BOMBERMAN_API AMySpeedBoost : public AMyPowerUp
{
	GENERATED_BODY()
	
public:
	AMySpeedBoost();

protected:
	void ActivatePowerUp(AMyPlayer* Player);
};