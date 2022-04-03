#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "GameManager.h"
#include "SoundManager.h"

ScorpionFactory* ScorpionFactory::instance = nullptr;

ScorpionFactory::ScorpionFactory()
{
	activeScorpions = {};
}

void ScorpionFactory::privCreateScorpion(sf::Vector2f pos, int speed, ScorpionSpawner* manager)
{
	Scorpion* scorpionInstance = myScorpionPool.GetScorpion();
	scorpionInstance->SetExternalManagement(RecycleScorpion);
	scorpionInstance->Initialize(pos, speed, manager);
	activeScorpions.push_front(scorpionInstance);
	SoundManager::ScorpLoopPlay();
}

void ScorpionFactory::privRecycleScorpion(GameObject* scorpionInstance)
{
	activeScorpions.remove(static_cast<Scorpion*>(scorpionInstance));
	if (activeScorpions.size() < 1)
		SoundManager::ScorpLoopStop();
	myScorpionPool.ReturnScorpion(static_cast<Scorpion*>(scorpionInstance));
}

void ScorpionFactory::privFreezeActiveScorpions()
{
	for (std::list<Scorpion*>::const_iterator it = activeScorpions.begin(); it != activeScorpions.end(); it++)
		(*it)->Freeze();
	SoundManager::ScorpLoopStop();
}

void ScorpionFactory::privDestroyActiveScorpions()
{
	for (std::list<Scorpion*>::const_iterator it = activeScorpions.begin(); it != activeScorpions.end(); it++)
		(*it)->MarkForDestroy();
}

void ScorpionFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
