#include "CentipedeBodyFactory.h"
#include "CentipedeBody.h"
#include "GameManager.h"

CentipedeBodyFactory* CentipedeBodyFactory::instance = nullptr;

CentipedeBody* CentipedeBodyFactory::privCreateCentipedeBody(sf::Vector2i pos, Centipede* front, int count, int frame, MushroomField* field)
{
	CentipedeBody* centipedeBodyInstance = myCentipedeBodyPool.GetCentipedeBody();
	centipedeBodyInstance->SetExternalManagement(RecycleCentipedeBody);
	centipedeBodyInstance->Initialize(pos, front, count, frame, field);
	return centipedeBodyInstance;
}

void CentipedeBodyFactory::privRecycleCentipedeBody(GameObject* centipedeBodyInstance)
{
	GameManager::DecrementSegmentNum(); // update gamemanager count so it knows when wave ends
	myCentipedeBodyPool.ReturnCentipedeBody(static_cast<CentipedeBody*>(centipedeBodyInstance));
}

void CentipedeBodyFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
