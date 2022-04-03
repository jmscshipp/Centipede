#ifndef _Explosion
#define _Explosion

#include "TEAL/CommonElements.h"

class Explosion : public GameObject
{
public:
	Explosion()= default; // big four
	Explosion(const Explosion&) = delete;
	Explosion& operator = (const Explosion&) = delete;
	~Explosion() = default;

	virtual void Initialize(sf::Vector2f location) = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;

protected:
	AnimatedSprite mainSprite;
};

#endif _Explosion