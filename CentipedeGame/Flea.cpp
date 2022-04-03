#include "Flea.h"
#include "WaveManager.h"
#include "Bullet.h"
#include "GameSettings.h"
#include "PlayerManager.h"
#include "Player.h"
#include "MushroomField.h"
#include "ScoreManager.h"
#include "ExplosionSingleTileFactory.h"
#include "SoundManager.h"

Flea::Flea()
{
	tileSize = GameSettings::TILESIZE;

	deathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2);
	mainSprite.SetAnimation(0, 3, true, true);
	mainSprite.setOrigin(mainSprite.getTextureRect().width / 4.0f, mainSprite.getTextureRect().height / 2.0f);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("Flea");
	SetCollider(mainSprite, bitmap, true);

	SetDrawOrder(500);
}

void Flea::Initialize(sf::Vector2f location, int newDropChance, WaveManager* manager)
{
	dropChance = newDropChance;
	health = GameSettings::FLEAHEALTH;
	speed = GameSettings::FLEASPEED;
	lowerBoundary = (int)WindowManager::Window().getView().getSize().y - tileSize;
	mainSprite.Play();
	myManager = manager;
	// setting up position
	pos = location;
	lastTile = sf::Vector2i((int)location.x, (int)location.y);
	mainSprite.setPosition(pos);

	RegisterCollision<Flea>(*this);
}

Flea::~Flea()
{
	delete deathScore;
}

void Flea::Freeze()
{
	speed = 0;
	mainSprite.Pause();
}

void Flea::Update()
{
	pos.y += speed;
	mainSprite.Update();
	mainSprite.setPosition(pos);

	if (pos.y >= lastTile.y + tileSize && pos.y < lowerBoundary) // we just went through another tile
	{
		lastTile.y = lastTile.y + tileSize;
		int dropNum = rand() % 100;
		if (dropNum < dropChance)
		{
			PlayerManager::GetCurrentPlayer()->GetMushrooomField()->PlaceMushroom(sf::Vector2i((lastTile.x - GameSettings::TILESIZE / 2) / GameSettings::TILESIZE, (lastTile.y - GameSettings::TILESIZE / 2) / GameSettings::TILESIZE));
		}
	}

	if (pos.y > WindowManager::Window().getView().getSize().y) MarkForDestroy();
}

void Flea::Collision(Bullet* other)
{
	other->MarkForDestroy();
	health--;
	if (health <= 0)
	{
		SoundManager::EnemyKilled();
		ExplosionSingleTileFactory::CreateExplosionSingleTile(pos);
		ScoreManager::SendScoreCmd(deathScore);
		MarkForDestroy(); // kill flea
	}
	else
	{
		speed *= 2;
		lowerBoundary = 0; // sneaky way of stopping more shrooms from spawning
	}
}

void Flea::Destroy()
{
	myManager->FleaReturned();
	DeregisterCollision<Flea>(*this);
}

void Flea::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

