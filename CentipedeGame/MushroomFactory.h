#ifndef _MushroomFactory
#define _MushroomFactory

#include "TEAL/CommonElements.h"
#include "MushroomPool.h"

// forward declaration
class GameObject;
class MushroomField;

class MushroomFactory
{
private:
	static MushroomFactory* instance; // set up as singleton

	MushroomFactory() = default; // big four
	MushroomFactory(const MushroomFactory&) = delete;
	MushroomFactory& operator=(const MushroomFactory&) = delete;
	~MushroomFactory() = default;

	static MushroomFactory& Instance()
	{
		if (!instance)
			instance = new MushroomFactory();
		return *instance;
	};

	MushroomPool myMushroomPool;

	Mushroom* privCreateMushroom(bool pSpaceCheck, sf::Vector2f pos, MushroomField* fieldInstance);
	void privRecycleMushroom(GameObject* shroomInstance);

public:
	static Mushroom* CreateMushroom(bool pSpaceCheck, sf::Vector2f pos, MushroomField* fieldInstance) { return Instance().privCreateMushroom(pSpaceCheck, pos, fieldInstance); };
	static void RecycleMushroom(GameObject* shroomInstance) { Instance().privRecycleMushroom(shroomInstance); };
	static void Terminate();
};


#endif _MushroomFactory