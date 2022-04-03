#ifndef _WaveManager
#define _WaveManager

#include "TEAL/CommonElements.h"

// forward declarations
class CentipedeSpawner;
class SoloCentipedeHeadSpawner;
class FleaSpawner;
class SpiderSpawner;
class ScorpionSpawner;

class WaveManager
{
public:
	WaveManager(); // big four
	WaveManager(const WaveManager&) = delete;
	WaveManager& operator = (const WaveManager&) = delete;
	~WaveManager();

	void Initialize();

	static FleaSpawner* GetFleaSpawner();
	void StartNewWave();

	// called by gamemanager during roundup
	void DisableSpawners();

	// managing flea spawning
	void UpdateMushroomCount(int newCount); // called by mushroom field
	void FleaReturned(); // called by flea when it dies

private:

	struct WaveData
	{
		// main centipede
		int mainCentiLength;
		int mainCentiSpeed;

		// solo centipede head
		int soloCentiCount;
		int soloCentiSpeed;

		// flea
		bool fleaOn;
		int fleaMushTriggerNum;
		int fleaMushSpawnChance;

		// scorpion
		bool scorpOn;
		int scorpSpeed;
		int scorpSpawnRate;

		// spider
		bool spiderOn;
		int spiderSpeed;
		int spiderSpawnRate;
	};

	static CentipedeSpawner* myCentipedeSpawner; // creates spawners
	static SoloCentipedeHeadSpawner* mySoloCentipedeHeadSpawner;
	static FleaSpawner* myFleaSpawner;
	static SpiderSpawner* mySpiderSpawner;
	static ScorpionSpawner* myScorpionSpawner;

	// flea stuff
	bool fleaCanSpawn;
	int currentMushroomCount;

	WaveData waves[10];
	void LoadWaveData(); // loads waves from text files
};

#endif _WaveManager