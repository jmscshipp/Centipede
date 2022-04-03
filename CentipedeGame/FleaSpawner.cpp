#include "FleaSpawner.h"
#include "FleaFactory.h"
#include "GameSettings.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"
#include "WaveManager.h"

FleaSpawner::FleaSpawner(WaveManager* manager)
{
	myManager = manager;
	on = false;
	mushroomThreshold = 0;
	mushroomDropChance = 0;
	gridWidth = GameSettings::GRIDWIDTH;
	gridHeight = GameSettings::GRIDHEIGHT;
}

FleaSpawner::~FleaSpawner()
{

}

void FleaSpawner::Disable()
{
	on = false;
}

void FleaSpawner::Enable()
{
	on = true;
}

void FleaSpawner::Update()
{

}
int FleaSpawner::GetMushroomThreshold() // called by wavemanager to make decisions about flea spawning
{
	return mushroomThreshold;
}

void FleaSpawner::SetValues(bool onVal, int thresholdVal, int dropChanceVal)
{
	on = onVal;
	mushroomThreshold = thresholdVal;
	mushroomDropChance = dropChanceVal;
}

void FleaSpawner::SpawnFlea()
{
	if (on)
	{
		int xTemp = 1 + (rand() % gridWidth - 1);
		sf::Vector2i gridPos = sf::Vector2i(xTemp * GameSettings::TILESIZE + GameSettings::TILESIZE / 2, GameSettings::TILESIZE / 2);
		FleaFactory::CreateFlea(sf::Vector2f((float)gridPos.x, (float)gridPos.y), mushroomDropChance, myManager); // spawn at random x location on top of screen
	}
}