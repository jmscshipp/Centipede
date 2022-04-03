#include "CommandScoreValue.h"
#include "ScoreManager.h"

CommandScoreValue::CommandScoreValue(int val)
	: points(val)
{
}

void CommandScoreValue::Execute()
{
	ScoreManager::AddScore(points);
}