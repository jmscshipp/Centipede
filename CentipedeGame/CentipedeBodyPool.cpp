#include "CentipedeBodyPool.h"
#include "TEAL\CommonElements.h"
#include "CentipedeBody.h"

CentipedeBodyPool::CentipedeBodyPool()
{

}

CentipedeBodyPool::~CentipedeBodyPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeBody* CentipedeBodyPool::GetCentipedeBody()
{
	CentipedeBody* centipedeBodyInstance;

	if (recycledItems.empty())
	{
		centipedeBodyInstance = new CentipedeBody();
	}
	else
	{
		centipedeBodyInstance = recycledItems.top();
		recycledItems.pop();
		centipedeBodyInstance->RegisterToCurrentScene();
	}
	return centipedeBodyInstance;
}

void CentipedeBodyPool::ReturnCentipedeBody(CentipedeBody* centipedeBodyInstance)
{
	recycledItems.push(static_cast<CentipedeBody*>(centipedeBodyInstance));
}