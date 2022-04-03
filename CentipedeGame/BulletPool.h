#ifndef _BulletPool
#define _BulletPool

#include <stack>

// forward declaration
class Bullet;

class BulletPool
{
private:
	std::stack<Bullet*> recycledItems;

public:
	BulletPool(); // big four
	BulletPool(const BulletPool&) = delete;
	BulletPool& operator=(const BulletPool&) = delete;
	~BulletPool();

	Bullet* GetBullet();
	void ReturnBullet(Bullet* bulletInstance);
};


#endif _BulletPool
