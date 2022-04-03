#ifndef _ScorpionSpawner
#define _ScorpionSpawner

#include "TEAL/CommonElements.h"

class ScorpionSpawner : public GameObject
{
public:
	ScorpionSpawner(); // big four
	ScorpionSpawner(const ScorpionSpawner&) = delete;
	ScorpionSpawner& operator = (const ScorpionSpawner&) = delete;
	~ScorpionSpawner();

	void SetValues(bool onVal, int speedVal, int timerVal);
	virtual void Update();
	void Disable();
	void Enable();

private:
	bool on;
	int speed;
	int timer; // val that goes down
	int savedTimer; // doesn't change in update, used to compare

	void SpawnScorpion();
};

#endif _ScorpionSpawner