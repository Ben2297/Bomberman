#include "MySpeedBoost.h"

AMySpeedBoost::AMySpeedBoost()
{

}

void AMySpeedBoost::ActivatePowerUp(AMyPlayer* Player)
{
	Player->BoostSpeed();
}