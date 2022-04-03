#ifndef _Flea
#define _Flea

#include "TEAL/CommonElements.h"

// forward declaration
class WaveManager;
class Bullet;
class CommandScore;

class Flea : public GameObject
{
public:
	Flea(); // big four
	Flea(const Flea&) = delete;
	Flea& operator = (const Flea&) = delete;
	~Flea();

	void Initialize(sf::Vector2f location, int dropChance, WaveManager* manager);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

	void Freeze(); // called by gamemanager before mushroom roundup

private:
	int health;
	int speed;
	int tileSize; // pulled from game settings
	int dropChance; // pulled from game settings, % chance to drop mushroom on a tile
	int lowerBoundary; // limit flea spawning shrooms to above bottom row of tiles
	sf::Vector2f pos;
	sf::Vector2i lastTile; // pos of the most recent tile flea passed through
	AnimatedSprite mainSprite;
	CollisionTools::TextureBitmap bitmap;
	WaveManager* myManager;

	CommandScore* deathScore;
};

#endif _Flea