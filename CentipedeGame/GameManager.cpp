#include "GameManager.h"
#include "WaveManager.h"
#include "PlayerManager.h"
#include "Player.h"
#include "MushroomField.h"
#include "HUDManager.h"
//#include "HighScoreManager.h"
#include "AttractorScene.h"

// factories, for freezing and deleting active critters during roundup
#include "CentipedeHeadFactory.h"
#include "FleaFactory.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "BulletFactory.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	activeCentipedeSegments = 0;
	myWaveManager = new WaveManager();
	//myHighScoreManager = new HighScoreManager();
}

void GameManager::privInitializeAttractorScene()
{
	//myWaveManager->StartNewWave();
	roundUpHappening = true;
	myWaveManager->Initialize();
	HUDManager::Initialize();
	PlayerManager::Initialize();
	roundUpHappening = false;
	//HUDManager::ShowHighScores();
}

void GameManager::privInitializeGameScene()
{
	roundUpHappening = true;
	myWaveManager->Initialize();
	PlayerManager::Initialize();
	HUDManager::Initialize();
	//HUDManager::HideHighScores();
	myWaveManager->StartNewWave();
	roundUpHappening = false; // so manager doesn't think wave is done because no centis spawned yet
}

WaveManager* GameManager::privGetWaveManager()
{
	return myWaveManager;
}
/*
HighScoreManager* GameManager::privGetHighScoreManager()
{
	return myHighScoreManager;
}
*/
void GameManager::privPlayerDeath()
{
	roundUpHappening = true;
	myWaveManager->DisableSpawners();
	CentipedeHeadFactory::FreezeActiveCentipedeHeads();
	SpiderFactory::FreezeActiveSpiders();
	ScorpionFactory::FreezeActiveScorpions();
	FleaFactory::FreezeActiveFleas();
	BulletFactory::FreezeActiveBullets();
	PlayerManager::LockBlaster();
	PlayerManager::GetCurrentPlayer()->GetMushrooomField()->RepairField();
}

void GameManager::privRestartWave()
{
	CentipedeHeadFactory::DestroyActiveCentipedeHeads();
	SpiderFactory::DestroyActiveSpiders();
	ScorpionFactory::DestroyActiveScorpions();
	FleaFactory::DestroyActiveFleas();
	BulletFactory::DestroyActiveBullets();
	int playerHealth = PlayerManager::PlayerLoseHealth();
	if (playerHealth < 0)
	{
		//myHighScoreManager->AddNewScore(PlayerManager::GetCurrentPlayer()->GetScore());
		SceneManager::ChangeScene(new AttractorScene());
	}
	else
	{
		roundUpHappening = false;
		HUDManager::UpdatePlayerLife(playerHealth);
		PlayerManager::ResetBlaster();
		myWaveManager->FleaReturned();
		myWaveManager->StartNewWave();
	}
}

void GameManager::NextWave()
{
	Trace::out("wave complete\n");
	PlayerManager::WaveComplete();
	myWaveManager->StartNewWave();
}

void GameManager::privIncrementSegmentNum(int numAdded)
{
	activeCentipedeSegments += numAdded;
}

void GameManager::privDecrementSegmentNum()
{
	activeCentipedeSegments--;
	if (activeCentipedeSegments <= 0 && !roundUpHappening)
		NextWave();
}

GameManager::~GameManager()
{
	delete myWaveManager;
	//delete myHighScoreManager;
}

void GameManager::Terminate()
{
	delete instance;
	instance = nullptr;
}