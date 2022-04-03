#ifndef _CentipedeSpawner
#define _CentipedeSpawner

#include "TEAL/CommonElements.h"

class CentipedeSpawner : public GameObject
{
public:
	CentipedeSpawner(); // big four
	CentipedeSpawner(const CentipedeSpawner&) = delete;
	CentipedeSpawner& operator = (const CentipedeSpawner&) = delete;
	~CentipedeSpawner();

	void SetValues(int speedval, int lengthVal);

private:
	int speed;
	int length;

	void SpawnCentipede();
};

#endif _CentipedeSpawner