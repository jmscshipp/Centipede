#include "SpiderPool.h"
#include "TEAL\CommonElements.h"
#include "Spider.h"

SpiderPool::SpiderPool()
{

}

SpiderPool::~SpiderPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderPool::GetSpider()
{
	Spider* spiderInstance;

	if (recycledItems.empty())
	{
		spiderInstance = new Spider();
	}
	else
	{
		spiderInstance = recycledItems.top();
		recycledItems.pop();
		spiderInstance->RegisterToCurrentScene();
	}
	return spiderInstance;
}

void SpiderPool::ReturnSpider(Spider* spiderInstance)
{
	recycledItems.push(static_cast<Spider*>(spiderInstance));
}