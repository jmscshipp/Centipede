#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory

#include "TEAL/CommonElements.h"
#include "CentipedeBodyPool.h"

// forward declaration
class GameObject;
class MushroomField;
class Centipede;

class CentipedeBodyFactory
{
private:
	static CentipedeBodyFactory* instance; // set up as singleton

	CentipedeBodyFactory() = default; // big four
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator=(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() = default;

	static CentipedeBodyFactory& Instance()
	{
		if (!instance)
			instance = new CentipedeBodyFactory();
		return *instance;
	};

	CentipedeBodyPool myCentipedeBodyPool;

	CentipedeBody* privCreateCentipedeBody(sf::Vector2i pos, Centipede* front, int count, int frame, MushroomField* field);
	void privRecycleCentipedeBody(GameObject* centipeadBodyInstance);

public:
	static CentipedeBody* CreateCentipedeBody(sf::Vector2i pos, Centipede* front, int count, int frame, MushroomField* field) { return Instance().privCreateCentipedeBody(pos, front, count, frame, field); };
	static void RecycleCentipedeBody(GameObject* centipeadBodyInstance) { Instance().privRecycleCentipedeBody(centipeadBodyInstance); };
	static void Terminate();
};


#endif _CentipedeHeadFactory