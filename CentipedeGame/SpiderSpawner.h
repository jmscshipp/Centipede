#ifndef _SpiderSpawner
#define _SpiderSpawner

#include "TEAL/CommonElements.h"

class SpiderSpawner : public GameObject
{
public:
	SpiderSpawner(); // big four
	SpiderSpawner(const SpiderSpawner&) = delete;
	SpiderSpawner& operator = (const SpiderSpawner&) = delete;
	~SpiderSpawner();

	void SetValues(bool onVal, int speedVal, int timerVal);
	virtual void Update();
	void Disable();
	void Enable();

private:
	bool on;
	int speed;
	int timer; // val that goes down
	int savedTimer; // doesn't change in update, used to compare

	int tileSize, gridWidth, gridHeight; // pulled from game settings

	void SpawnSpider();
};

#endif _SpiderSpawner