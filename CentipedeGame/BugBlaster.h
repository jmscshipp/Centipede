#ifndef _BugBlaster
#define _BugBlaster

#include "TEAL/CommonElements.h"

// forward declarations
class Bullet;
class Mushroom;
class Flea;
class Spider;
class CentipedeHead;
class CentipedeBody;

class BugBlaster : public GameObject
{
public:
	BugBlaster(); // big four
	BugBlaster(const BugBlaster&) = delete;
	BugBlaster& operator = (const BugBlaster&) = delete;
	~BugBlaster();
	
	virtual void Update();
	virtual void Draw();
	void Destroy();
	virtual void Collision(GameObject* other) {};
	void Collision(Mushroom* other);
	void Collision(Flea* other);
	void Collision(CentipedeHead* other);
	void Collision(CentipedeBody* other);
	void Collision(Spider* other);

	void Move(sf::Vector2i dir);
	void Shoot();
	void LockShooting(); // called by gamemanager (thru playermanager) during mushroom roundup
	void Reload(); // called by bullet when it dies
	void Death();

	sf::Vector2f GetPos();

	void Reset();

private:
	sf::Vector2f pos;
	AnimatedSprite mainSprite;
	int tileSize; // pulled from game settings

	// movement
	int speed;
	float friction;
	sf::Vector2i impulse;

	// borders
	float leftBorder; // should these be organized in vectors or something?
	float rightBorder;
	float topBorder;
	float bottomBorder;

	// collisions
	sf::Vector2i savedPos;
	CollisionTools::TextureBitmap bitmap;
	
	// shooting
	bool canFire;
};

#endif _BugBlaster