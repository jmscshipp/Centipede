#include "ExplosionTwoTiles.h"

ExplosionTwoTiles::ExplosionTwoTiles()
{
	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("ExplosionTwoTiles"), 4, 2);
	mainSprite.SetAnimation(0, 7, true, false);
	mainSprite.setOrigin((float)mainSprite.getTextureRect().width / 2.0f, (float)mainSprite.getTextureRect().height / 2.0f);
	mainSprite.SetLoopSpeed(15.0f);
	SetDrawOrder(1000);
}

void ExplosionTwoTiles::Initialize(sf::Vector2f location)
{
	// setting up position
	mainSprite.SetFrame(0);
	mainSprite.Play();
	mainSprite.setPosition(location);
}

ExplosionTwoTiles::~ExplosionTwoTiles()
{

}

void ExplosionTwoTiles::Update()
{
	mainSprite.Update();
	if (mainSprite.IsLastAnimationFrame())
		MarkForDestroy();
}

void ExplosionTwoTiles::Destroy()
{
}

void ExplosionTwoTiles::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

