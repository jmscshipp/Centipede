#include "MushroomPool.h"
#include "TEAL\CommonElements.h"
#include "Mushroom.h"

MushroomPool::MushroomPool()
{

}

MushroomPool::~MushroomPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Mushroom* MushroomPool::GetMushroom()
{
	Mushroom* mushroomInstance;

	if (recycledItems.empty())
	{
		mushroomInstance = new Mushroom();
	}
	else
	{
		mushroomInstance = recycledItems.top();
		recycledItems.pop();
		mushroomInstance->RegisterToCurrentScene();
	}
	return mushroomInstance;
}

void MushroomPool::ReturnMushroom(Mushroom* mushroomInstance)
{
	recycledItems.push(static_cast<Mushroom*>(mushroomInstance));
}