#include "MushroomFactory.h"
#include "Mushroom.h"

MushroomFactory* MushroomFactory::instance = nullptr;

Mushroom* MushroomFactory::privCreateMushroom(bool pSpaceCheck, sf::Vector2f pos, MushroomField* fieldInstance)
{
	Mushroom* shroomInstance = myMushroomPool.GetMushroom();
	shroomInstance->SetExternalManagement(RecycleMushroom);
	shroomInstance->Initialize(pSpaceCheck, pos, fieldInstance);
	return shroomInstance;
}

void MushroomFactory::privRecycleMushroom(GameObject* mushroomInstance)
{
	myMushroomPool.ReturnMushroom(static_cast<Mushroom*>(mushroomInstance));
}

void MushroomFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
