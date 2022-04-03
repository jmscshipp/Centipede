#ifndef _ExplosionTwoTiles
#define _ExplosionTwoTiles

#include "TEAL/CommonElements.h"
#include "Explosion.h"

class ExplosionTwoTiles : public Explosion
{
public:
	ExplosionTwoTiles(); // big four
	ExplosionTwoTiles(const ExplosionTwoTiles&) = delete;
	ExplosionTwoTiles& operator = (const ExplosionTwoTiles&) = delete;
	~ExplosionTwoTiles();

	void Initialize(sf::Vector2f location);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();

private:

};

#endif _ExplosionTwoTiles