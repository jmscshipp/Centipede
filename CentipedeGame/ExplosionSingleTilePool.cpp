#include "ExplosionSingleTilePool.h"
#include "TEAL\CommonElements.h"
#include "ExplosionSingleTile.h"

ExplosionSingleTilePool::ExplosionSingleTilePool()
{

}

ExplosionSingleTilePool::~ExplosionSingleTilePool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

ExplosionSingleTile* ExplosionSingleTilePool::GetExplosionSingleTile()
{
	ExplosionSingleTile* explosionSingleTileInstance;

	if (recycledItems.empty())
	{
		explosionSingleTileInstance = new ExplosionSingleTile();
	}
	else
	{
		explosionSingleTileInstance = recycledItems.top();
		recycledItems.pop();
		explosionSingleTileInstance->RegisterToCurrentScene();
	}
	return explosionSingleTileInstance;
}

void ExplosionSingleTilePool::ReturnExplosionSingleTile(ExplosionSingleTile* explosionSingleTileInstance)
{
	recycledItems.push(static_cast<ExplosionSingleTile*>(explosionSingleTileInstance));
}