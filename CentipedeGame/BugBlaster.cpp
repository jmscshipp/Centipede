#include "BugBlaster.h"
#include "Mushroom.h"
#include "BulletFactory.h"
#include "Flea.h"
#include "Spider.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "GameSettings.h"
#include "KeyboardInput.h"
#include "GameManager.h"
#include "ExplosionTwoTilesFactory.h"
#include "SoundManager.h"

BugBlaster::BugBlaster()
{
	speed = GameSettings::PLAYERSPEED;
	friction = GameSettings::PLAYERFRICTION;
	tileSize = GameSettings::TILESIZE;
	canFire = true;

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("BugBlaster"), 1, 1);
	mainSprite.SetAnimation(0, 0, false, false);
	mainSprite.setOrigin((float)mainSprite.getTextureRect().width / 2.0f, (float)mainSprite.getTextureRect().height / 2.0f);

	// setting up position
	pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, WindowManager::Window().getView().getSize().y - (float)(tileSize / 2));
	savedPos = sf::Vector2i((int)pos.x, (int)pos.y);
	mainSprite.setPosition(pos);
	impulse = sf::Vector2i(0, 0);

	// borders of window set so you can't move offscreen
	leftBorder = (float)tileSize / 2.0f; // 0 is far left on x axis
	rightBorder = WindowManager::Window().getView().getSize().x - leftBorder;
	topBorder = WindowManager::Window().getView().getSize().y - leftBorder; // 0 is top on y axis, so windowsize() is the bottom of the screen
	bottomBorder = topBorder - (float)(tileSize * GameSettings::PSPACESIZE);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("BugBlaster");
	SetCollider(mainSprite, bitmap, true);
	RegisterCollision<BugBlaster>(*this);

	SetDrawOrder(1000);
}

BugBlaster::~BugBlaster()
{

}

sf::Vector2f BugBlaster::GetPos()
{
	return pos;
}

void BugBlaster::Reset() // called by player manager when player dies
{
	pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, WindowManager::Window().getView().getSize().y - (float)(tileSize / 2));
	savedPos = sf::Vector2i((int)pos.x, (int)pos.y);
	mainSprite.setPosition(pos);
	impulse = sf::Vector2i(0, 0);
	mainSprite.setScale(sf::Vector2f(1.0f, 1.0f));
	canFire = true;
}

void BugBlaster::Move(sf::Vector2i dir)
{
	savedPos = sf::Vector2i((int)pos.x, (int)pos.y);
	impulse += dir * speed;
	pos += sf::Vector2f((float)impulse.x, (float)impulse.y);
	Tools::Clamp<float>(pos.x, leftBorder, rightBorder);
	Tools::Clamp<float>(pos.y, bottomBorder, topBorder); // NEED THIS BACK
	mainSprite.setPosition(pos);

	impulse *= (int)friction;
}

void BugBlaster::Shoot()
{
	if (canFire)
	{
		SoundManager::BulletFired();
		BulletFactory::CreateBullet(pos, this);
		canFire = false;
	}
}

void BugBlaster::Update()
{
	
}

void BugBlaster::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

void BugBlaster::Destroy()
{
	DeregisterCollision<BugBlaster>(*this);
}

void BugBlaster::LockShooting()
{
	canFire = false;
}

void BugBlaster::Reload()
{
	canFire = true;
}

void BugBlaster::Death()
{
	SoundManager::PlayerDeath();
	ExplosionTwoTilesFactory::CreateExplosionTwoTiles(pos);
	mainSprite.setScale(sf::Vector2f(0.0f, 0.0f));
	GameManager::PlayerDeath();
}

void BugBlaster::Collision(Mushroom* other)
{
	impulse = sf::Vector2i(0, 0);
	pos = sf::Vector2f((float)savedPos.x, (float)savedPos.y);
}

void BugBlaster::Collision(Flea* other)
{
	other->MarkForDestroy();
	Death();
}

void BugBlaster::Collision(CentipedeHead* other)
{
	Death();
}

void BugBlaster::Collision(CentipedeBody* other)
{
	Death();
}

void BugBlaster::Collision(Spider* other)
{
	other->MarkForDestroy();
	Death();
}
