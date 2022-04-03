#include "ScorpionSpawner.h"
#include "ScorpionFactory.h"
#include "GameSettings.h"

ScorpionSpawner::ScorpionSpawner()
{
	on = false;
	speed = 0;
	timer = 0;
	savedTimer = 0;
}

ScorpionSpawner::~ScorpionSpawner()
{

}
void ScorpionSpawner::Disable()
{
	on = false;
}

void ScorpionSpawner::Enable()
{
	on = true;
}

void ScorpionSpawner::Update()
{
	if (on)
	{
		if (timer <= 0)
		{
			SpawnScorpion();
			timer = savedTimer;
		}
		timer--;
	}
}


void ScorpionSpawner::SetValues(bool onVal, int speedVal, int timerVal)
{
	on = onVal;
	speed = speedVal;
	timer = timerVal;
	savedTimer = timerVal;
}

void ScorpionSpawner::SpawnScorpion()
{
	int side = rand() % 100;
	sf::Vector2f worldPos;
	if (side < 50)
		worldPos = sf::Vector2f((float)(GameSettings::TILESIZE / 2), (float)(rand() % (GameSettings::GRIDHEIGHT / 2) * GameSettings::TILESIZE + GameSettings::TILESIZE / 2));
	else
		worldPos = sf::Vector2f((float)(GameSettings::GRIDWIDTH * GameSettings::TILESIZE - GameSettings::TILESIZE / 2), (float)(rand() % (GameSettings::GRIDHEIGHT / 2) * GameSettings::TILESIZE + GameSettings::TILESIZE / 2));
	ScorpionFactory::CreateScorpion(sf::Vector2f(worldPos.x, worldPos.y), speed, this); // spawn at random x location on top of screen
}

