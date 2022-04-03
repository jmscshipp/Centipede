#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "TEAL/CommonElements.h"
#include <list>
#include "ScorpionPool.h"

// forward declaration
class GameObject;
class ScorpionSpawner;

class ScorpionFactory
{
private:
	static ScorpionFactory* instance; // set up as singleton

	ScorpionFactory(); // big four
	ScorpionFactory(const ScorpionFactory&) = delete;
	ScorpionFactory& operator=(const ScorpionFactory&) = delete;
	~ScorpionFactory() = default;

	static ScorpionFactory& Instance()
	{
		if (!instance)
			instance = new ScorpionFactory();
		return *instance;
	};

	ScorpionPool myScorpionPool;
	std::list <Scorpion*> activeScorpions;

	void privCreateScorpion(sf::Vector2f pos, int speed, ScorpionSpawner* spawner);
	void privRecycleScorpion(GameObject* scorpionInstance);

	// end of level roundup, called by gamemanager
	void privFreezeActiveScorpions();
	void privDestroyActiveScorpions();

public:
	static void CreateScorpion(sf::Vector2f pos, int speed, ScorpionSpawner* spawner) { Instance().privCreateScorpion(pos, speed, spawner); };
	static void RecycleScorpion(GameObject* scorpionInstance) { Instance().privRecycleScorpion(scorpionInstance); };
	
	// end of level roundup, called by gamemanager
	static void FreezeActiveScorpions() { Instance().privFreezeActiveScorpions(); };
	static void DestroyActiveScorpions() { Instance().privDestroyActiveScorpions(); };

	static void Terminate();
};


#endif _ScorpionFactory