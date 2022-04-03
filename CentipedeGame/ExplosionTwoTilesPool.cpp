#include "ExplosionTwoTilesPool.h"
#include "TEAL\CommonElements.h"
#include "ExplosionTwoTiles.h"

ExplosionTwoTilesPool::ExplosionTwoTilesPool()
{

}

ExplosionTwoTilesPool::~ExplosionTwoTilesPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

ExplosionTwoTiles* ExplosionTwoTilesPool::GetExplosionTwoTiles()
{
	ExplosionTwoTiles* explosionTwoTilesInstance;

	if (recycledItems.empty())
	{
		explosionTwoTilesInstance = new ExplosionTwoTiles();
	}
	else
	{
		explosionTwoTilesInstance = recycledItems.top();
		recycledItems.pop();
		explosionTwoTilesInstance->RegisterToCurrentScene();
	}
	return explosionTwoTilesInstance;
}

void ExplosionTwoTilesPool::ReturnExplosionTwoTiles(ExplosionTwoTiles* explosionTwoTilesInstance)
{
	recycledItems.push(static_cast<ExplosionTwoTiles*>(explosionTwoTilesInstance));
}