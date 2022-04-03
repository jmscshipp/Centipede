#include "ScorpionPool.h"
#include "TEAL\CommonElements.h"
#include "Scorpion.h"

ScorpionPool::ScorpionPool()
{

}

ScorpionPool::~ScorpionPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Scorpion* ScorpionPool::GetScorpion()
{
	Scorpion* scorpionInstance;

	if (recycledItems.empty())
	{
		scorpionInstance = new Scorpion();
	}
	else
	{
		scorpionInstance = recycledItems.top();
		recycledItems.pop();
		scorpionInstance->RegisterToCurrentScene();
	}
	return scorpionInstance;
}

void ScorpionPool::ReturnScorpion(Scorpion* scorpionInstance)
{
	recycledItems.push(static_cast<Scorpion*>(scorpionInstance));
}