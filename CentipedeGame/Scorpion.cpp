#include "Scorpion.h"
#include "ScorpionSpawner.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "GameSettings.h"
#include "ScoreManager.h"
#include "ExplosionSingleTileFactory.h"
#include "SoundManager.h"

Scorpion::Scorpion()
{
	tileSize = GameSettings::TILESIZE;

	deathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled);

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1);
	mainSprite.SetAnimation(0, 3, true, true);
	mainSprite.setOrigin((float)mainSprite.getTextureRect().width / 2.0f, (float)mainSprite.getTextureRect().height / 2.0f);
	mainSprite.SetLoopSpeed(15.0f);

	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	SetCollider(mainSprite, bitmap, true);

	SetDrawOrder(500);
}

void Scorpion::Initialize(sf::Vector2f location, int newSpeed, ScorpionSpawner* spawner)
{
	frozen = false;
	health = GameSettings::SCORPHEALTH;
	mySpawner = spawner;
	mainSprite.Play();
	// setting up right / left distinction
	if (location.x == tileSize / 2.0f) // left side going right
	{
		speed = newSpeed;
		mainSprite.setScale(sf::Vector2f(-1.0f, 1.0f)); // flip sprite
	}
	else // right side going left
	{
		speed = -newSpeed;
		mainSprite.setScale(sf::Vector2f(1.0f, 1.0f)); // flip sprite
	}

	// setting up position
	pos = location;
	mainSprite.setPosition(pos);

	RegisterCollision<Scorpion>(*this);
}

Scorpion::~Scorpion()
{
	delete deathScore;
}

void Scorpion::Freeze()
{
	frozen = true;
	speed = 0;
	mainSprite.Pause();
	DeregisterCollision<Scorpion>(*this);
}

void Scorpion::Update()
{
	pos.x += speed; // speed is + or - depending on dir
	mainSprite.Update();
	mainSprite.setPosition(pos);

	if (pos.x > WindowManager::Window().getView().getSize().x || pos.x < 0) MarkForDestroy();
}

void Scorpion::Collision(Mushroom* other)
{
	other->TurnPoison();
}

void Scorpion::Collision(Bullet* other)
{
	SoundManager::EnemyKilled();
	ExplosionSingleTileFactory::CreateExplosionSingleTile(pos);
	ScoreManager::SendScoreCmd(deathScore);
	other->MarkForDestroy();
	MarkForDestroy();
}

void Scorpion::Destroy()
{
	if (!frozen)
		DeregisterCollision<Scorpion>(*this);
}

void Scorpion::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

