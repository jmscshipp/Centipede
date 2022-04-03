#ifndef _ExplosionSingleTile
#define _ExplosionSingleTile

#include "TEAL/CommonElements.h"
#include "Explosion.h"

class ExplosionSingleTile : public Explosion
{
public:
	ExplosionSingleTile(); // big four
	ExplosionSingleTile(const ExplosionSingleTile&) = delete;
	ExplosionSingleTile& operator = (const ExplosionSingleTile&) = delete;
	~ExplosionSingleTile();

	void Initialize(sf::Vector2f location);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();

private:
	int frame; // required because spritesheet is backwards
};

#endif _ExplosionSingleTile