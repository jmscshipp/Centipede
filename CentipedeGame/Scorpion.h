#ifndef _Scorpion
#define _Scorpion

#include "TEAL/CommonElements.h"

// forward declaration
class ScorpionSpawner;
class Mushroom;
class Bullet;
class CommandScore;

class Scorpion : public GameObject
{
public:
	Scorpion(); // big four
	Scorpion(const Scorpion&) = delete;
	Scorpion& operator = (const Scorpion&) = delete;
	~Scorpion();

	void Initialize(sf::Vector2f location, int speed, ScorpionSpawner* manager);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Bullet* other);

	void Freeze(); // called by gamemanager before mushroom roundup

private:
	int health;
	int speed;
	int tileSize; // pulled from game settings
	sf::Vector2f pos;
	AnimatedSprite mainSprite;
	CollisionTools::TextureBitmap bitmap;
	ScorpionSpawner* mySpawner;

	bool frozen;
	CommandScore* deathScore;
};

#endif _Scorpion