#include "Mushroom.h"
#include "MushroomField.h"
#include "Bullet.h"
#include "GameSettings.h"
#include "ScoreManager.h"

Mushroom::Mushroom()
{
	regularDeathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
	regenDeathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomRegenKilled);

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	mainSprite.SetAnimation(0, 3, false, false);
	mainSprite.setOrigin(mainSprite.getTextureRect().width / 2.0f, mainSprite.getTextureRect().height / 2.0f);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(mainSprite, bitmap, true);
}

void Mushroom::Initialize(bool pSpaceCheck, sf::Vector2f location, MushroomField* field)
{
	inPSpace = pSpaceCheck;
	thisField = field;

	// set stats to default
	health = GameSettings::SHROOMHEALTH;
	mainSprite.SetAnimation(0, 3, false, false);
	poisoned = false;

	// setting up position, registering collision
	pos = location;
	mainSprite.setPosition(pos);
	RegisterCollision<Mushroom>(*this);
}

Mushroom::~Mushroom()
{
	delete regenDeathScore;
	delete regularDeathScore;
}

void Mushroom::TurnInvisible() // TEMPORARY FUNCTION FOR TESTING
{
	mainSprite.setScale(sf::Vector2f(0.0f, 0.0f));
}

void Mushroom::TurnVisible() // TEMPORARY
{
	mainSprite.setScale(sf::Vector2f(1.0f, 1.0f));
}

bool Mushroom::GetPoisonStatus()
{
	return poisoned;
}

void Mushroom::TurnPoison()
{
	mainSprite.SetAnimation(4, 7, false, false);
	mainSprite.Update();
	poisoned = true;
}

void Mushroom::Kill()
{
	thisField->RemoveMushroom(inPSpace, sf::Vector2i((int)pos.x, (int)pos.y));
	MarkForDestroy();
}

bool  Mushroom::IsHealthy()
{
	return !(poisoned || health < GameSettings::SHROOMHEALTH);
}

void Mushroom::Heal()
{
	ScoreManager::SendScoreCmd(regenDeathScore);
	mainSprite.setColor(sf::Color::Yellow);
	SetAlarm(1, 0.1f);
}

void Mushroom::Alarm1()
{
	mainSprite.setColor(sf::Color::Yellow);
	health = GameSettings::SHROOMHEALTH;
	poisoned = false;
	//mainsprite.update() ???
	mainSprite.SetAnimation(0, 3, false, false);
	mainSprite.setColor(sf::Color::White);
}

void Mushroom::Collision(Bullet* other)
{
	other->MarkForDestroy();
	health--;
	if (health <= 0)
	{
		ScoreManager::SendScoreCmd(regularDeathScore);
		Kill();
	}
	else
		mainSprite.NextFrame();
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);
}

void Mushroom::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

