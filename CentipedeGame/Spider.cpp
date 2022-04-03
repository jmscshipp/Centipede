#include "Spider.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "GameSettings.h"
#include "ScoreManager.h"
#include "CommandScore.h"
#include "PlayerManager.h"
#include "ExplosionSingleTileFactory.h"
#include "SoundManager.h"

Spider::Spider()
{
	tileSize = GameSettings::TILESIZE;

	deathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);

	upperBoundary = (int)WindowManager::Window().getView().getSize().y;
	lowerBoundary = (GameSettings::GRIDHEIGHT - GameSettings::PSPACESIZE) * tileSize;

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);
	mainSprite.SetAnimation(0, 7, true, true);
	mainSprite.setOrigin(mainSprite.getTextureRect().width / 2.0f, mainSprite.getTextureRect().height / 2.0f);
	mainSprite.setScale(sf::Vector2f(2.0f, 2.0f)); // scale sprite
	mainSprite.SetLoopSpeed(15.0f);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("Spider");
	SetCollider(mainSprite, bitmap, true);

	SetDrawOrder(500);
}

void Spider::Initialize(sf::Vector2f location, int newSpeed, SpiderSpawner* spawner)
{
	speed = newSpeed;
	health = GameSettings::SPIDERHEALTH;
	mySpawner = spawner;
	frameCounter = 0;
	mainSprite.Play();
	currentAddedDir = sf::Vector2f(0.0f, 0.0f);

	// setting up right / left distinction
	if (location.x == 0.0f) // left side going right
	{
		oppositeBoundary = WindowManager::Window().getView().getSize().x;
		dir = 1.0f; // going right
	}
	else // right side going left
	{
		oppositeBoundary = 0.0f;
		dir = -1.0f; // going left
	}

	// setting up position
	pos = location;
	mainSprite.setPosition(pos);

	RegisterCollision<Spider>(*this);
}

Spider::~Spider()
{
	delete deathScore;
}

void Spider::Freeze()
{
	currentAddedDir = sf::Vector2f(0.0f, 0.0f);
	frameCounter = -1000;
	mainSprite.Pause();
}

void Spider::SetNextMove()
{
	frameCounter = 0;
	nextDirFrameCount = 0;
	int randNum;
	if ((int)pos.y + speed > upperBoundary)
		randNum = rand() % 2;
	else if ((int)pos.y - speed < lowerBoundary)
		randNum = 2 + rand() % 2;
	else
		randNum = rand() % 4;

	if (randNum == 0) // up
		currentAddedDir = sf::Vector2f(0.0f, -speed);
	else if (randNum == 1) // up diagonal
		currentAddedDir = sf::Vector2f(speed * dir, -speed);
	else if (randNum == 2) // down
		currentAddedDir = sf::Vector2f(0.0f, speed);
	else if (randNum == 3) // down diagonal
		currentAddedDir = sf::Vector2f(speed * dir, speed);

	randNum = rand() % tileSize + tileSize;
	for (int i = 0; i < randNum; i++)
	{
		if (((int)pos.y + (int)currentAddedDir.y * nextDirFrameCount < upperBoundary) && ((int)pos.y + (int)currentAddedDir.y * nextDirFrameCount > lowerBoundary))
			nextDirFrameCount++;
		else
			break;
	}
}

void Spider::Update()
{
	if (frameCounter > nextDirFrameCount)
		SetNextMove();
	frameCounter++;
	pos += currentAddedDir;
	mainSprite.Update();
	mainSprite.setPosition(pos);
	if ((dir == 1.0f && pos.x > oppositeBoundary) || (dir == -1.0f && pos.x < oppositeBoundary)) MarkForDestroy(); // ran into other side of screen
}

void Spider::Collision(Mushroom* other)
{
	other->Kill();
}

void Spider::Collision(Bullet* other)
{
	SoundManager::EnemyKilled();
	ExplosionSingleTileFactory::CreateExplosionSingleTile(pos);
	deathScore->SetDistance(PlayerManager::GetBlasterPos(), pos);
	ScoreManager::SendScoreCmd(deathScore);
	other->MarkForDestroy();
	MarkForDestroy();
}

void Spider::Destroy()
{
	DeregisterCollision<Spider>(*this);
}

void Spider::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

