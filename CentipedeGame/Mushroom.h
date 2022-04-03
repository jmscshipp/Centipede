#ifndef _Mushroom
#define _Mushroom

#include "TEAL/CommonElements.h"

// forward declaration
class MushroomField;
class Bullet;
class CommandScore;

class Mushroom : public GameObject
{
public:
	Mushroom(); // big four
	Mushroom(const Mushroom&) = delete;
	Mushroom& operator = (const Mushroom&) = delete;
	~Mushroom();
	
	void Initialize(bool pSpaceCheck, sf::Vector2f location, MushroomField* field);
	bool GetPoisonStatus();
	void TurnPoison();
	void Kill(); // separate from destroy to avoid spawning flea after game window closes
	bool IsHealthy(); // called by field during repair
	void Heal();

	void TurnInvisible(); // TEMPORARY FUNCTION FOR TESTING
	void TurnVisible(); // TEMPORARY

	virtual void Draw();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

private:
	int health;
	bool poisoned;
	bool inPSpace; // did this mushroom spawn in the player area?
	sf::Vector2f pos;
	AnimatedSprite mainSprite;
	CollisionTools::TextureBitmap bitmap;
	MushroomField* thisField;

	virtual void Alarm1();

	CommandScore* regularDeathScore;
	CommandScore* regenDeathScore;
};

#endif _Mushroom