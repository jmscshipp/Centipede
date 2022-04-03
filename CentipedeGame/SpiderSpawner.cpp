#include "SpiderSpawner.h"
#include "SpiderFactory.h"
#include "GameSettings.h"

SpiderSpawner::SpiderSpawner()
{
	on = false;
	speed = 0;
	timer = 0;
	savedTimer = 0;

	tileSize = GameSettings::TILESIZE;
	gridWidth = GameSettings::GRIDWIDTH;
	gridHeight = GameSettings::GRIDHEIGHT;
}

SpiderSpawner::~SpiderSpawner()
{

}

void SpiderSpawner::Disable()
{
	on = false;
}

void SpiderSpawner::Enable()
{
	on = true;
}

void SpiderSpawner::Update()
{
	if (on)
	{
		if (timer <= 0)
		{
			SpawnSpider();
			timer = savedTimer;
		}
		timer--;
	}
}


void SpiderSpawner::SetValues(bool onVal, int speedVal, int timerVal)
{
	on = onVal;
	speed = speedVal;
	timer = timerVal;
	savedTimer = timerVal;
}

void SpiderSpawner::SpawnSpider()
{
	int side = rand() % 100;
	int yPos = ((gridHeight - GameSettings::PSPACESIZE) + (rand() % GameSettings::PSPACESIZE)) * tileSize;
	if (side < 50)
		side = 0;
	else
		side = gridWidth * tileSize;
	SpiderFactory::CreateSpider(sf::Vector2f((float)side, (float)yPos), speed, this); // spawn at random x location on edge of player space
}

