#include "Bullet.h"
#include "BugBlaster.h"
#include "GameSettings.h"

Bullet::Bullet()
{
	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("Bullet"), 1, 1);
	mainSprite.SetAnimation(0, 0, false, false);
	mainSprite.setOrigin(mainSprite.getTextureRect().width / 2.0f, mainSprite.getTextureRect().height / 2.0f);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("Bullet");
	SetCollider(mainSprite, bitmap, true);
}

void Bullet::Initialize(sf::Vector2f location, BugBlaster* playerInstance)
{
	speed = GameSettings::BULLETSPEED;
	// setting up position and player ref
	pos = location;
	player = playerInstance;
	mainSprite.setPosition(pos);
	RegisterCollision<Bullet>(*this);
}

Bullet::~Bullet()
{

}

void Bullet::Freeze()
{
	speed = 0;
}

void Bullet::Update()
{
	pos.y -= speed;
	mainSprite.setPosition(pos);
	if (pos.y < 0) MarkForDestroy();
}

void Bullet::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

void Bullet::Destroy()
{
	player->Reload();
	DeregisterCollision<Bullet>(*this);
}

