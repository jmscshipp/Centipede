#ifndef _ExplosionTwoTilesFactory
#define _ExplosionTwoTilesFactory

#include "TEAL/CommonElements.h"
#include "ExplosionTwoTilesPool.h"

// forward declaration
class GameObject;

class ExplosionTwoTilesFactory
{
private:
	static ExplosionTwoTilesFactory* instance; // set up as singleton

	ExplosionTwoTilesFactory(); // big four
	ExplosionTwoTilesFactory(const ExplosionTwoTilesFactory&) = delete;
	ExplosionTwoTilesFactory& operator=(const ExplosionTwoTilesFactory&) = delete;
	~ExplosionTwoTilesFactory() = default;

	static ExplosionTwoTilesFactory& Instance()
	{
		if (!instance)
			instance = new ExplosionTwoTilesFactory();
		return *instance;
	};

	ExplosionTwoTilesPool myExplosionTwoTilesPool;

	void privCreateExplosionTwoTiles(sf::Vector2f pos);
	void privRecycleExplosionTwoTiles(GameObject* b);

public:
	static void CreateExplosionTwoTiles(sf::Vector2f pos) { Instance().privCreateExplosionTwoTiles(pos); };
	static void RecycleExplosionTwoTiles(GameObject* explosionInstance) { Instance().privRecycleExplosionTwoTiles(explosionInstance); };

	static void Terminate();
};


#endif _ExplosionTwoTilesFactory