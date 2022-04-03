#ifndef _FleaFactory
#define _FleaFactory

#include "TEAL/CommonElements.h"
#include <list>
#include "FleaPool.h"

// forward declaration
class GameObject;
class WaveManager;

class FleaFactory
{
private:
	static FleaFactory* instance; // set up as singleton

	FleaFactory(); // big four
	FleaFactory(const FleaFactory&) = delete;
	FleaFactory& operator=(const FleaFactory&) = delete;
	~FleaFactory() = default;

	static FleaFactory& Instance()
	{
		if (!instance)
			instance = new FleaFactory();
		return *instance;
	};

	FleaPool myFleaPool;
	std::list <Flea*> activeFleas;

	void privCreateFlea(sf::Vector2f pos, int dropChance, WaveManager* manager);
	void privRecycleFlea(GameObject* fleaInstance);

	// end of level roundup, called by gamemanager
	void privFreezeActiveFleas();
	void privDestroyActiveFleas();

public:
	static void CreateFlea(sf::Vector2f pos, int dropChance, WaveManager* manager) { Instance().privCreateFlea(pos, dropChance, manager); };
	static void RecycleFlea(GameObject* fleaInstance) { Instance().privRecycleFlea(fleaInstance); };

	// end of level roundup, called by gamemanager
	static void FreezeActiveFleas() { Instance().privFreezeActiveFleas(); };
	static void DestroyActiveFleas() { Instance().privDestroyActiveFleas(); };

	static void Terminate();
};


#endif _FleaFactory