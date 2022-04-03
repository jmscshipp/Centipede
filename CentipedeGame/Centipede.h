#ifndef _Centipede
#define _Centipede

#include "TEAL/CommonElements.h"

// forward declaration
class MushroomField;
class Mushroom;
class Bullet;
class CentipedeState;
class CentipedeBody;
class CommandScore;

class Centipede : public GameObject
{
public:
	Centipede() = default; // big four
	Centipede(const Centipede&) = delete;
	Centipede& operator = (const Centipede&) = delete;
	~Centipede() = default;

	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;
	virtual void Collision(GameObject* other) = 0;
	virtual void Collision(Bullet* other) = 0;

	virtual float GetLastRot() = 0;
	virtual int GetSpeed() = 0;
	virtual const CentipedeState* GetState() = 0;
	virtual void Freeze() = 0; // called through gamemanager when player dies
	virtual void DestroyEntireBody() = 0; // called through gamemanager when player dies
	Centipede* frontReference;
	Centipede* backReference;
	int NODENUM; // for debugging!!

protected:
	virtual void Death() = 0;
	int speed;
	int tileSize; // pulled from game settings
	int frameCounter;
	int frameIncrement; // how much counter goes up every frame

	CommandScore* deathScore;

	const CentipedeState* currentState;
	sf::Vector2f pos;
	sf::Vector2i lastTile;
	float rot;
	float lastRot;
	AnimatedSprite mainSprite;
	CollisionTools::TextureBitmap bitmap;
	MushroomField* myMushroomField;
};

#endif _Centipede