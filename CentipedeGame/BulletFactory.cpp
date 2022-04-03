#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory* BulletFactory::instance = nullptr;

BulletFactory::BulletFactory()
{
	activeBullets = {};
}

void BulletFactory::privCreateBullet(sf::Vector2f pos, BugBlaster* playerInstance)
{
	Bullet* bulletInstance = myBulletPool.GetBullet();
	bulletInstance->SetExternalManagement(RecycleBullet);
	bulletInstance->Initialize(pos, playerInstance);
	activeBullets.push_front(bulletInstance);
}

void BulletFactory::privRecycleBullet(GameObject* bulletInstance)
{
	activeBullets.remove(static_cast<Bullet*>(bulletInstance));
	myBulletPool.ReturnBullet(static_cast<Bullet*>(bulletInstance));
}

void BulletFactory::privFreezeActiveBullets()
{
	for (std::list<Bullet*>::const_iterator it = activeBullets.begin(); it != activeBullets.end(); it++)
		(*it)->Freeze();
}

void BulletFactory::privDestroyActiveBullets()
{
	for (std::list<Bullet*>::const_iterator it = activeBullets.begin(); it != activeBullets.end(); it++)
		(*it)->MarkForDestroy();
}

void BulletFactory::Terminate()
{
	delete instance;
	instance = nullptr;
}
