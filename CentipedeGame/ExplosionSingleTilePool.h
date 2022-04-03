#ifndef _ExplosionSingleTilePool
#define _ExplosionSingleTilePool

#include <stack>

// forward declaration
class ExplosionSingleTile;

class ExplosionSingleTilePool
{
private:
	std::stack<ExplosionSingleTile*> recycledItems;

public:
	ExplosionSingleTilePool(); // big four
	ExplosionSingleTilePool(const ExplosionSingleTilePool&) = delete;
	ExplosionSingleTilePool& operator=(const ExplosionSingleTilePool&) = delete;
	~ExplosionSingleTilePool();

	ExplosionSingleTile* GetExplosionSingleTile();
	void ReturnExplosionSingleTile(ExplosionSingleTile* explosionSingleTileInstance);
};


#endif _ExplosionSingleTilePool
