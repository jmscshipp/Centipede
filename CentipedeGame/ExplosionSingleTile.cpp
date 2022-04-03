#include "ExplosionSingleTile.h"

ExplosionSingleTile::ExplosionSingleTile()
{
	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionSingleTile"), 3, 2);
	mainSprite.SetAnimation(5, 0, true, false);
	mainSprite.setOrigin((float)mainSprite.getTextureRect().width / 2.0f, (float)mainSprite.getTextureRect().height / 2.0f);
	mainSprite.setScale(sf::Vector2f(2.0f, 2.0f));
	SetDrawOrder(1000);
}

void ExplosionSingleTile::Initialize(sf::Vector2f location)
{
	frame = 5;
	mainSprite.SetFrame(5);
	mainSprite.setPosition(location);
}

ExplosionSingleTile::~ExplosionSingleTile()
{

}

void ExplosionSingleTile::Update()
{
	
	frame--;
	mainSprite.SetFrame(frame);
	if (frame < 0)
		MarkForDestroy();
}

void ExplosionSingleTile::Destroy()
{
}

void ExplosionSingleTile::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

