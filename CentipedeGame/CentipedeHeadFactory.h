#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include "TEAL/CommonElements.h"
#include <list>
#include "CentipedeHeadPool.h"

// forward declaration
class GameObject;
class MushroomField;

class CentipedeHeadFactory
{
private:
	static CentipedeHeadFactory* instance; // set up as singleton

	CentipedeHeadFactory(); // big four
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;
	CentipedeHeadFactory& operator=(const CentipedeHeadFactory&) = delete;
	~CentipedeHeadFactory() = default;

	static CentipedeHeadFactory& Instance()
	{
		if (!instance)
			instance = new CentipedeHeadFactory();
		return *instance;
	};

	CentipedeHeadPool myCentipedeHeadPool;
	std::list<CentipedeHead*> activeCentipedeHeads;

	CentipedeHead* privCreateCentipedeHead(sf::Vector2i pos, int speed, int count, MushroomField* field);
	void privRecycleCentipedeHead(GameObject* centipeadHeadInstance);

	// end of level roundup, called by gamemanager
	void privFreezeActiveCentipedeHeads();
	void privDestroyActiveCentipedeHeads();

public:
	static CentipedeHead* CreateCentipedeHead(sf::Vector2i pos, int speed, int count, MushroomField* field) { return Instance().privCreateCentipedeHead(pos, speed, count, field); };
	static void RecycleCentipedeHead(GameObject* centipeadHeadInstance) { Instance().privRecycleCentipedeHead(centipeadHeadInstance); };
	
	// end of level roundup, called by gamemanager
	static void FreezeActiveCentipedeHeads() { Instance().privFreezeActiveCentipedeHeads(); };
	static void DestroyActiveCentipedeHeads() { Instance().privDestroyActiveCentipedeHeads(); };

	static void Terminate();
};


#endif _CentipedeHeadFactory