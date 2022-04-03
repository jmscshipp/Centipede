#include "CentipedeSpawner.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "GameSettings.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"

CentipedeSpawner::CentipedeSpawner()
{
	speed = 0;
	length = 0;
}

CentipedeSpawner::~CentipedeSpawner()
{

}


void CentipedeSpawner::SetValues(int speedVal, int lengthVal)
{
	speed = speedVal;
	length = lengthVal;
	SpawnCentipede();
}

void CentipedeSpawner::SpawnCentipede()
{
	// spawns centipede of 'length' in the middle top of screen
	CentipedeHeadFactory::CreateCentipedeHead(sf::Vector2i(GameSettings::TILESIZE / 2 + GameSettings::TILESIZE * (GameSettings::GRIDWIDTH / 2), -GameSettings::TILESIZE / 2), speed, length, PlayerManager::GetCurrentPlayer()->GetMushrooomField());
}

