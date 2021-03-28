#include "MyIncreaseBombBlast.h"

AMyIncreaseBombBlast::AMyIncreaseBombBlast()
{

}

void AMyIncreaseBombBlast::ActivatePowerUp(AMyPlayer* Player)
{
	Player->IncreaseBombBlast();
}