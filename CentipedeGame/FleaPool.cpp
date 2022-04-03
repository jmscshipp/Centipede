#include "FleaPool.h"
#include "TEAL\CommonElements.h"
#include "Flea.h"

FleaPool::FleaPool()
{

}

FleaPool::~FleaPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaPool::GetFlea()
{
	Flea* fleaInstance;

	if (recycledItems.empty())
	{
		fleaInstance = new Flea();
	}
	else
	{
		fleaInstance = recycledItems.top();
		recycledItems.pop();
		fleaInstance->RegisterToCurrentScene();
	}
	return fleaInstance;
}

void FleaPool::ReturnFlea(Flea* fleaInstance)
{
	recycledItems.push(static_cast<Flea*>(fleaInstance));
}