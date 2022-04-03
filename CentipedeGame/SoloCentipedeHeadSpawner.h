#ifndef _SoloCentipedeHeadSpawner
#define _SoloCentipedeHeadSpawner

#include "TEAL/CommonElements.h"

class SoloCentipedeHeadSpawner : public GameObject
{
public:
	SoloCentipedeHeadSpawner(); // big four
	SoloCentipedeHeadSpawner(const SoloCentipedeHeadSpawner&) = delete;
	SoloCentipedeHeadSpawner& operator = (const SoloCentipedeHeadSpawner&) = delete;
	~SoloCentipedeHeadSpawner();

	void SetValues(int speedval, int amountVal);

private:
	int speed;
	int amount; // how many solo heads

	void SpawnSoloCentipedeHead();
};

#endif _SoloCentipedeHeadSpawner