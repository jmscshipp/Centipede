#include "FleaFactory.h"
#include "Flea.h"
#include "GameManager.h"
#include "SoundManager.h"

FleaFactory* FleaFactory::instance = nullptr;

FleaFactory::FleaFactory()
{
	activeFleas = {};
}

void FleaFactory::privCreateFlea(sf::Vector2f pos, int dropChance, WaveManager* manager)
{
	Flea* fleaInstance = myFleaPool.GetFlea();
	fleaInstance->SetExternalManagement(RecycleFlea);
	fleaInstance->Initialize(pos, dropChance, manager);
	activeFleas.push_front(fleaInstance);
	SoundManager::FleaPlay();
}

void FleaFactory::privRecycleFlea(GameObject* fleaInstance)
{
	activeFleas.remove(static_cast<Flea*>(fleaInstance)); // does fleaInstance actually need to come in as GameObject?
	myFleaPool.ReturnFlea(static_cast<Flea*>(fleaInstance));
	if (activeFleas.size() < 1)
		SoundManager::FleaStop();
}

void FleaFactory::privFreezeActiveFleas()
{
	for (std::list<Flea*>::const_iterator it = activeFleas.begin(); it != activeFleas.end(); it++)
		(*it)->Freeze();
	SoundManager::FleaStop();
}

void FleaFactory::privDestroyActiveFleas()
{
	for (std::list<Flea*>::const_iterator it = activeFleas.begin(); it != activeFleas.end(); it++)
		(*it)->MarkForDestroy();
}

void FleaFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
