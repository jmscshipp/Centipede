#include "ExplosionTwoTilesFactory.h"
#include "ExplosionTwoTiles.h"

ExplosionTwoTilesFactory* ExplosionTwoTilesFactory::instance = nullptr;

ExplosionTwoTilesFactory::ExplosionTwoTilesFactory()
{

}

void ExplosionTwoTilesFactory::privCreateExplosionTwoTiles(sf::Vector2f pos)
{
	ExplosionTwoTiles* explosionInstance = myExplosionTwoTilesPool.GetExplosionTwoTiles();
	explosionInstance->SetExternalManagement(RecycleExplosionTwoTiles);
	explosionInstance->Initialize(pos);
}

void ExplosionTwoTilesFactory::privRecycleExplosionTwoTiles(GameObject* explosionInstance)
{
	myExplosionTwoTilesPool.ReturnExplosionTwoTiles(static_cast<ExplosionTwoTiles*>(explosionInstance));
}

void ExplosionTwoTilesFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
