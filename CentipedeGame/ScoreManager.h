#ifndef _ScoreManager
#define _ScoreManager

// forward declaration
class CommandScore;

class ScoreManager
{
private:
	// Score values;
	static const int FleaDeath = 200;
	static const int ScorpionDeath = 1000;
	static const int MushroomDeath = 1; // mushroom killed during gameplay
	static const int MushroomRegenDeath = 5; // damaged mushroom killed during regen

	static const int SpiderDeathFar = 300;
	static const int SpiderDistFar = 9999;

	static const int SpiderDeathMedium = 600;
	static const int SpiderDistMedium = 99;

	static const int SpiderDeathNear = 900;
	static const int SpiderDistNear = 9;

	static const int CentiHead = 100;
	static const int CentiBody = 10;

	static ScoreManager* instance;

	static ScoreManager& Instance()
	{
		if (!instance)
			instance = new ScoreManager;
		return *instance;
	};

public:
	// events
	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomRegenKilled, SpiderKilled, CentiHeadKilled, CentiBodyKilled };

	static void AddScore(int val);

	static CommandScore* GetScoreCommand(ScoreEvents ev);

	static void SendScoreCmd(CommandScore* c);
	static void Terminate();
};

#endif _ScoreManager