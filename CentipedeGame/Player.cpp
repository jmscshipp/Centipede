#include "Player.h"
#include "GameSettings.h"
#include "MushroomField.h"
#include "WaveManager.h"
#include "HUDManager.h"

Player::Player()
{

}

void Player::Initialize()
{
	score = 0;
	life = GameSettings::PLAYERSTARTHEALTH;
	waveNum = 0;
	myMushroomField = new MushroomField();
}

MushroomField* Player::GetMushrooomField() // called by centipede, flea to place mushrooms
{
	if (myMushroomField == nullptr)
	{
		Trace::out("\n\nALERT ALERTER PLAYER HAS NO FIELD\n\n");
	}
	return myMushroomField;
}

int Player::GetScore()
{
	return score;
}

int Player::GetWaveNum()
{
	return waveNum;
}

void Player::IncrementWaveNum()
{
	waveNum++;
}

void Player::AddToScore(int val)
{
	score += val;
	HUDManager::UpdateCurrentScore(score);
	Trace::out("current player score: %d\n", score);
}

int Player::LoseLife()
{
	Trace::out("previous health: %d\n", life);
	return --life;
}

Player::~Player()
{

}

