#include "CentipedeHeadPool.h"
#include "TEAL\CommonElements.h"
#include "CentipedeHead.h"

CentipedeHeadPool::CentipedeHeadPool()
{

}

CentipedeHeadPool::~CentipedeHeadPool()
{
	Trace::out("heads being delted\n");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeHead* CentipedeHeadPool::GetCentipedeHead()
{
	CentipedeHead* centipedeHeadInstance;

	if (recycledItems.empty())
		centipedeHeadInstance = new CentipedeHead();
	else
	{
		centipedeHeadInstance = recycledItems.top();
		recycledItems.pop();
		centipedeHeadInstance->RegisterToCurrentScene();
	}
	return centipedeHeadInstance;
}

void CentipedeHeadPool::ReturnCentipedeHead(CentipedeHead* centipedeHeadInstance)
{
	recycledItems.push(static_cast<CentipedeHead*>(centipedeHeadInstance));
}