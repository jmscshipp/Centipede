#include "BulletPool.h"
#include "TEAL\CommonElements.h"
#include "Bullet.h"

BulletPool::BulletPool()
{

}

BulletPool::~BulletPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletPool::GetBullet()
{
	Bullet* bulletInstance;

	if (recycledItems.empty())
	{
		bulletInstance = new Bullet();
	}
	else
	{
		bulletInstance = recycledItems.top();
		recycledItems.pop();
		bulletInstance->RegisterToCurrentScene();
	}
	return bulletInstance;
}

void BulletPool::ReturnBullet(Bullet* bulletInstance)
{
	recycledItems.push(static_cast<Bullet*>(bulletInstance));

	//ConsoleMsg::WriteLine("recycled bullet stack size: " + Tools::ToString(recycledItems.size()));

}