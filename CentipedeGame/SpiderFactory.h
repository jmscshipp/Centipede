#ifndef _SpiderFactory
#define _SpiderFactory

#include "TEAL/CommonElements.h"
#include <list>
#include "SpiderPool.h"

// forward declaration
class GameObject;
class SpiderSpawner;

class SpiderFactory
{
private:
	static SpiderFactory* instance; // set up as singleton

	SpiderFactory(); // big four
	SpiderFactory(const SpiderFactory&) = delete;
	SpiderFactory& operator=(const SpiderFactory&) = delete;
	~SpiderFactory() = default;

	static SpiderFactory& Instance()
	{
		if (!instance)
			instance = new SpiderFactory();
		return *instance;
	};

	SpiderPool mySpiderPool;
	std::list <Spider*> activeSpiders;

	void privCreateSpider(sf::Vector2f pos, int speed, SpiderSpawner* spawner);
	void privRecycleSpider(GameObject* spiderInstance);

	// end of level roundup, called by gamemanager
	void privFreezeActiveSpiders();
	void privDestroyActiveSpiders();

public:
	static void CreateSpider(sf::Vector2f pos, int speed, SpiderSpawner* spawner) { Instance().privCreateSpider(pos, speed, spawner); };
	static void RecycleSpider(GameObject* spiderInstance) { Instance().privRecycleSpider(spiderInstance); };
	
	// end of level roundup, called by gamemanager
	static void FreezeActiveSpiders() { Instance().privFreezeActiveSpiders(); };
	static void DestroyActiveSpiders() { Instance().privDestroyActiveSpiders(); };

	static void Terminate();
};


#endif _SpiderFactory