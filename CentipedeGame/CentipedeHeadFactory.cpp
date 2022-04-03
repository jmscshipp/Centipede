#include "CentipedeHeadFactory.h"
#include "CentipedeHead.h"
#include "GameManager.h"
#include "SoundManager.h"

CentipedeHeadFactory* CentipedeHeadFactory::instance = nullptr;

CentipedeHeadFactory::CentipedeHeadFactory()
{
	activeCentipedeHeads = {};
}

CentipedeHead* CentipedeHeadFactory::privCreateCentipedeHead(sf::Vector2i pos, int speed, int count, MushroomField* field)
{
	GameManager::IncrementSegmentNum(count); // update gamemanager count so it knows when wave ends
	CentipedeHead* centipedeHeadInstance = myCentipedeHeadPool.GetCentipedeHead();
	centipedeHeadInstance->SetExternalManagement(RecycleCentipedeHead);
	centipedeHeadInstance->Initialize(pos, speed, count, field);
	activeCentipedeHeads.push_front(centipedeHeadInstance);
	SoundManager::CentiLoopPlay();
	return centipedeHeadInstance;
}

void CentipedeHeadFactory::privRecycleCentipedeHead(GameObject* centipedeHeadInstance)
{
	activeCentipedeHeads.remove(static_cast<CentipedeHead*>(centipedeHeadInstance));
	if (activeCentipedeHeads.size() < 1)
		SoundManager::CentiLoopStop();
	GameManager::DecrementSegmentNum(); // update gamemanager count so it knows when wave ends
	myCentipedeHeadPool.ReturnCentipedeHead(static_cast<CentipedeHead*>(centipedeHeadInstance));
}

void CentipedeHeadFactory::privFreezeActiveCentipedeHeads()
{
	for (std::list<CentipedeHead*>::const_iterator it = activeCentipedeHeads.begin(); it != activeCentipedeHeads.end(); it++)
		(*it)->Freeze();
	SoundManager::CentiLoopStop();
}

void CentipedeHeadFactory::privDestroyActiveCentipedeHeads()
{
	for (std::list<CentipedeHead*>::const_iterator it = activeCentipedeHeads.begin(); it != activeCentipedeHeads.end(); it++)
		(*it)->DestroyEntireBody();
}

void CentipedeHeadFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
