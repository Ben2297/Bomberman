#include "MyMoreBombs.h"

AMyMoreBombs::AMyMoreBombs()
{

}

void AMyMoreBombs::ActivatePowerUp(AMyPlayer* Player)
{
	Player->MoreBombs();
}