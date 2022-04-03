#include "SpiderFactory.h"
#include "Spider.h"
#include "GameManager.h"
#include "SoundManager.h"

SpiderFactory* SpiderFactory::instance = nullptr;

SpiderFactory::SpiderFactory()
{
	activeSpiders = {};
}

void SpiderFactory::privCreateSpider(sf::Vector2f pos, int speed, SpiderSpawner* spawner)
{
	Spider* spiderInstance = mySpiderPool.GetSpider();
	spiderInstance->SetExternalManagement(RecycleSpider);
	spiderInstance->Initialize(pos, speed, spawner);
	activeSpiders.push_front(spiderInstance);
	SoundManager::SpiderLoopPlay();
}

void SpiderFactory::privRecycleSpider(GameObject* spiderInstance)
{
	activeSpiders.remove(static_cast<Spider*>(spiderInstance));
	mySpiderPool.ReturnSpider(static_cast<Spider*>(spiderInstance));
	if (activeSpiders.size() < 1)
		SoundManager::SpiderLoopStop();
}

void SpiderFactory::privFreezeActiveSpiders()
{
	for (std::list<Spider*>::const_iterator it = activeSpiders.begin(); it != activeSpiders.end(); it++)
		(*it)->Freeze();
	SoundManager::SpiderLoopStop();
}

void SpiderFactory::privDestroyActiveSpiders()
{
	for (std::list<Spider*>::const_iterator it = activeSpiders.begin(); it != activeSpiders.end(); it++)
		(*it)->MarkForDestroy();
}

void SpiderFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
