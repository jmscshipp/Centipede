#include "ScoreManager.h"
#include "CommandScoreValue.h"
#include "CommandScoreDistance.h"
#include "PlayerManager.h"
#include "Player.h"

ScoreManager* ScoreManager::instance = nullptr;

CommandScore* ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	CommandScore* pCmd = nullptr;

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = new CommandScoreValue(FleaDeath);
		break;
	case ScoreEvents::ScorpionKilled:
		pCmd = new CommandScoreValue(ScorpionDeath);
		break;
	case ScoreEvents::MushroomKilled:
		pCmd = new CommandScoreValue(MushroomDeath);
		break;
	case ScoreEvents::SpiderKilled:
		pCmd = new CommandScoreDistance(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;
	case ScoreEvents::MushroomRegenKilled:
		pCmd = new CommandScoreValue(MushroomRegenDeath);
		break;
	case ScoreEvents::CentiBodyKilled:
		pCmd = new CommandScoreValue(CentiBody);
		break;
	case ScoreEvents::CentiHeadKilled:
		pCmd = new CommandScoreValue(CentiHead);
		Trace::out("!! created command score for head\n");
		break;
	default:
		break;
	}

	return pCmd;
}

void ScoreManager::AddScore(int val)
{
	PlayerManager::GetCurrentPlayer()->AddToScore(val);
}

void ScoreManager::SendScoreCmd(CommandScore* c)
{
	c->Execute();
}

void ScoreManager::Terminate()
{
	delete instance;
	instance = nullptr;
}