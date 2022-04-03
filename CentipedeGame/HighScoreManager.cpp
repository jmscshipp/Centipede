#include "HighScoreManager.h"

HighScoreManager::HighScoreManager()
{
	for (int i = 0; i < 10; i++)
	{
		scores[i] = 1100 - i * 100 + rand() % 20;
	}
}


int HighScoreManager::GetScoreAt(int i)
{
	return scores[i];
}

int HighScoreManager::GetHighestScore()
{
	return scores[0];
}

void HighScoreManager::AddNewScore(int newScore)
{
	for (int i = 0; i < 10; i++)
	{
		if (newScore > scores[i])
		{
			for (int j = 9; j > i; j--)
			{
				scores[j] = scores[j - 1];
			}
			scores[i] = newScore;
		}
	}
}