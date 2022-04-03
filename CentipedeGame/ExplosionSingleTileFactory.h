#ifndef _ExplosionSingleTileFactory
#define _ExplosionSingleTileFactory

#include "TEAL/CommonElements.h"
#include "ExplosionSingleTilePool.h"

// forward declaration
class GameObject;

class ExplosionSingleTileFactory
{
private:
	static ExplosionSingleTileFactory* instance; // set up as singleton

	ExplosionSingleTileFactory(); // big four
	ExplosionSingleTileFactory(const ExplosionSingleTileFactory&) = delete;
	ExplosionSingleTileFactory& operator=(const ExplosionSingleTileFactory&) = delete;
	~ExplosionSingleTileFactory() = default;

	static ExplosionSingleTileFactory& Instance()
	{
		if (!instance)
			instance = new ExplosionSingleTileFactory();
		return *instance;
	};

	ExplosionSingleTilePool myExplosionSingleTilePool;

	void privCreateExplosionSingleTile(sf::Vector2f pos);
	void privRecycleExplosionSingleTile(GameObject* b);

public:
	static void CreateExplosionSingleTile(sf::Vector2f pos) { Instance().privCreateExplosionSingleTile(pos); };
	static void RecycleExplosionSingleTile(GameObject* explosionInstance) { Instance().privRecycleExplosionSingleTile(explosionInstance); };

	static void Terminate();
};


#endif _ExplosionSingleTileFactory