#pragma once

#include "CoreMinimal.h"
#include "MyPowerUp.h"
#include "MyPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "MyIncreaseBombBlast.generated.h"

UCLASS()
class BOMBERMAN_API AMyIncreaseBombBlast : public AMyPowerUp
{
	GENERATED_BODY()
	
public:
	AMyIncreaseBombBlast();

protected:
	void ActivatePowerUp(AMyPlayer* Player);
};
