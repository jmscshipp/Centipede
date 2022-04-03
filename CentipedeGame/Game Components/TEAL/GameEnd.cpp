// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"

// singletons to terminate
#include "BulletFactory.h"
#include "FleaFactory.h"
#include "ScorpionFactory.h"
#include "SpiderFactory.h"
#include "MushroomFactory.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "ExplosionSingleTileFactory.h"
#include "ExplosionTwoTilesFactory.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"
#include "HUDManager.h"
#include "SoundManager.h"

void Game::GameEnd()
{
	FleaFactory::Terminate();
	ScorpionFactory::Terminate();
	SpiderFactory::Terminate();
	MushroomFactory::Terminate();
	BulletFactory::Terminate();
	CentipedeHeadFactory::Terminate();
	CentipedeBodyFactory::Terminate();
	ExplosionSingleTileFactory::Terminate();
	ExplosionTwoTilesFactory::Terminate();
	PlayerManager::Terminate();
	GameManager::Terminate();
	ScoreManager::Terminate();
	HUDManager::Terminate();
	SoundManager::Terminate();
}