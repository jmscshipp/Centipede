#include "ExplosionSingleTileFactory.h"
#include "ExplosionSingleTile.h"

ExplosionSingleTileFactory* ExplosionSingleTileFactory::instance = nullptr;

ExplosionSingleTileFactory::ExplosionSingleTileFactory()
{

}

void ExplosionSingleTileFactory::privCreateExplosionSingleTile(sf::Vector2f pos)
{
	ExplosionSingleTile* explosionInstance = myExplosionSingleTilePool.GetExplosionSingleTile();
	explosionInstance->SetExternalManagement(RecycleExplosionSingleTile);
	explosionInstance->Initialize(pos);
}

void ExplosionSingleTileFactory::privRecycleExplosionSingleTile(GameObject* explosionInstance)
{
	myExplosionSingleTilePool.ReturnExplosionSingleTile(static_cast<ExplosionSingleTile*>(explosionInstance));
}

void ExplosionSingleTileFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
