#ifndef _Spider
#define _Spider

#include "TEAL/CommonElements.h"

// forward declaration
class SpiderSpawner;
class Mushroom;
class Bullet;
class CommandScore;

class Spider : public GameObject
{
public:
	Spider(); // big four
	Spider(const Spider&) = delete;
	Spider& operator = (const Spider&) = delete;
	~Spider();

	void Initialize(sf::Vector2f location, int speed, SpiderSpawner* spawner);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Bullet* other);

	void Freeze(); // called by gamemanager before mushroom roundup

private:
	float dir; // -1 = left, true = 1
	int health;
	float speed;
	int tileSize; // pulled from game settings
	float oppositeBoundary; // to delete if it crosses whole screen
	int upperBoundary, lowerBoundary; // vertical bounds
	sf::Vector2f pos;
	int frameCounter;
	int nextDirFrameCount;
	sf::Vector2f currentAddedDir;
	AnimatedSprite mainSprite;
	CollisionTools::TextureBitmap bitmap;
	SpiderSpawner* mySpawner;

	void SetNextMove();

	CommandScore* deathScore;
};

#endif _Spider