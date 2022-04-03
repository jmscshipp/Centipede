#ifndef _BulletFactory
#define _BulletFactory

#include "TEAL/CommonElements.h"
#include <list>
#include "BulletPool.h"

// forward declaration
class GameObject;
class BugBlaster;

class BulletFactory
{
private:
	static BulletFactory* instance; // set up as singleton

	BulletFactory(); // big four
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory() = default;

	static BulletFactory& Instance()
	{
		if (!instance)
			instance = new BulletFactory();
		return *instance;
	};

	BulletPool myBulletPool;
	std::list <Bullet*> activeBullets;

	void privCreateBullet(sf::Vector2f pos, BugBlaster* playerInstance);
	void privRecycleBullet(GameObject* b);

	// end of level roundup, called by gamemanager
	void privFreezeActiveBullets();
	void privDestroyActiveBullets();

public:
	static void CreateBullet(sf::Vector2f pos, BugBlaster* playerInstance) { Instance().privCreateBullet(pos, playerInstance); };
	static void RecycleBullet(GameObject* bulletInstance) { Instance().privRecycleBullet(bulletInstance); };
	
	// end of level roundup, called by gamemanager
	static void FreezeActiveBullets() { Instance().privFreezeActiveBullets(); };
	static void DestroyActiveBullets() { Instance().privDestroyActiveBullets(); };
	
	static void Terminate();
};


#endif _BulletFactory