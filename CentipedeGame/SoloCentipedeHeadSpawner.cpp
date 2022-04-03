#include "SoloCentipedeHeadSpawner.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "GameSettings.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"

SoloCentipedeHeadSpawner::SoloCentipedeHeadSpawner()
{
	speed = 0;
	amount = 0;
}

SoloCentipedeHeadSpawner::~SoloCentipedeHeadSpawner()
{

}


void SoloCentipedeHeadSpawner::SetValues(int speedVal, int amountVal)
{
	speed = speedVal;
	amount = amountVal;
	Trace::out("amount is %d\n", amount);
	if (amount > 0)
		SpawnSoloCentipedeHead();
}

void SoloCentipedeHeadSpawner::SpawnSoloCentipedeHead()
{
	for (int i = 0; i < amount; i++)
	{
		// generates random values on top of grid
		int xVal = GameSettings::TILESIZE / 2 + (rand() % GameSettings::GRIDWIDTH) * GameSettings::TILESIZE;
		CentipedeHeadFactory::CreateCentipedeHead(sf::Vector2i(xVal, -GameSettings::TILESIZE / 2), speed, 1, PlayerManager::GetCurrentPlayer()->GetMushrooomField());
	}
}

