#ifndef _MushroomPool
#define _MushroomPool

#include <stack>

// forward declaration
class Mushroom;

class MushroomPool
{
private:
	std::stack<Mushroom*> recycledItems;

public:
	MushroomPool(); // big four
	MushroomPool(const MushroomPool&) = delete;
	MushroomPool& operator=(const MushroomPool&) = delete;
	~MushroomPool();

	Mushroom* GetMushroom();
	void ReturnMushroom(Mushroom* mushroomInstance);
};


#endif _MushroomPool
