#include "PlayerManager.h"
#include "Player.h"
#include "BugBlaster.h"
#include "KeyBoardInput.h"

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{
	player1 = new Player();
	currentPlayer = player1;
}

void PlayerManager::privInitialize()
{
	blaster = new BugBlaster();
	blasterControl = new KeyboardInput(blaster);
	currentPlayer->Initialize();
}

void PlayerManager::privSwap()
{
	
}

Player* PlayerManager::privGetCurrentPlayer()
{
	return currentPlayer;
}

void PlayerManager::privWaveComplete()
{
	currentPlayer->IncrementWaveNum();
}

sf::Vector2f PlayerManager::privGetBlasterPos()
{
	return blaster->GetPos();
}

void PlayerManager::privResetBlaster()
{
	blaster->Reset();
}

void PlayerManager::privLockBlaster()
{
	blaster->LockShooting();
}

int PlayerManager::privPlayerLoseHealth()
{
	return currentPlayer->LoseLife();
}

PlayerManager::~PlayerManager()
{
	delete player1;
}

void PlayerManager::Terminate()
{
	delete instance;
	instance = nullptr;
}
