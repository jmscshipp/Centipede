#ifndef _ExplosionTwoTilesPool
#define _ExplosionTwoTilesPool

#include <stack>

// forward declaration
class ExplosionTwoTiles;

class ExplosionTwoTilesPool
{
private:
	std::stack<ExplosionTwoTiles*> recycledItems;

public:
	ExplosionTwoTilesPool(); // big four
	ExplosionTwoTilesPool(const ExplosionTwoTilesPool&) = delete;
	ExplosionTwoTilesPool& operator=(const ExplosionTwoTilesPool&) = delete;
	~ExplosionTwoTilesPool();

	ExplosionTwoTiles* GetExplosionTwoTiles();
	void ReturnExplosionTwoTiles(ExplosionTwoTiles* explosionTwoTilesInstance);
};


#endif _ExplosionTwoTilesPool