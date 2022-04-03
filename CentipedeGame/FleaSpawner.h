#ifndef _FleaSpawner
#define _FleaSpawner

#include "TEAL/CommonElements.h"

//forward declaration
class WaveManager;

class FleaSpawner : public GameObject
{
public:
	FleaSpawner(WaveManager* manager); // big four
	FleaSpawner(const FleaSpawner&) = delete;
	FleaSpawner& operator = (const FleaSpawner&) = delete;
	~FleaSpawner();

	int GetMushroomThreshold(); // called by wavemanager to make decisions about flea spawning
	void SetValues(bool onVal, int thresholdVal, int dropChanceVal);
	virtual void Update();
	void SpawnFlea(); // called by wavemanager
	void Disable();
	void Enable();

private:
	bool on;
	int mushroomThreshold; // how many mushrooms in pspace to trigger flea spawn
	int mushroomDropChance; // likelyhood of flea putting mushroom on current tile

	int gridWidth, gridHeight; // pulled from game settings
	WaveManager* myManager;

};

#endif _FleaSpawner