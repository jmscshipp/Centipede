#ifndef _Bullet
#define _Bullet

#include "TEAL/CommonElements.h"

// forward declaration
class BugBlaster;

class Bullet : public GameObject
{
public:
	Bullet(); // big four
	//Bullet(BugBlaster* playerObject);
	Bullet(const Bullet&) = delete;
	Bullet& operator = (const Bullet&) = delete;
	~Bullet();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};

	void Freeze();
	void Initialize(sf::Vector2f pos, BugBlaster* playerInstance);
	BugBlaster* player;

private:
	float speed;
	sf::Vector2f pos;
	AnimatedSprite mainSprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif _Bullet