#include "HUDManager.h"
#include "CurrentScoreText.h"
#include "PlayerLifeText.h"
#include "ScoreText.h"
#include "GameManager.h"
#include "HighScoreManager.h"

HUDManager* HUDManager::instance = nullptr;

HUDManager::HUDManager()
{
	//scoreManager = GameManager::GetHighScoreManager();
	//for (int i = 0; i < 10; i++)
	//{
	//	highScores[i] = new ScoreText(sf::Vector2f(200.0f, 100.0f + 20.0f * i));
	//}
}

void HUDManager::privInitialize() // reset to start values
{

	currentScore = new CurrentScoreText();
	playerLife = new PlayerLifeText();
}
/*
void HUDManager::privShowHighScores()
{
	for (int i = 0; i < 10; i++)
	{
		highScores[i]->SetText(scoreManager->GetScoreAt(i));
	}
}

void HUDManager::privHideHighScores()
{
	for (int i = 0; i < 10; i++)
	{
		highScores[i]->SetText(0);
	}
}*/

void HUDManager::privUpdateCurrentScore(int val)
{
	currentScore->UpdateScore(val);
}

void HUDManager::privUpdatePlayerLife(int val)
{
	playerLife->UpdateLife(val);
}

void HUDManager::Terminate()
{
	delete instance;
	instance = nullptr;
}