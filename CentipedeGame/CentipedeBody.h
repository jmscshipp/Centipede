#ifndef _CentipedeBody
#define _CentipedeBody

#include "TEAL/CommonElements.h"
#include "Centipede.h"

// forward declaration
class MushroomField;
class Bullet;
class CentipedeState;

class CentipedeBody : public Centipede
{
public:
	CentipedeBody(); // big four
	CentipedeBody(const CentipedeBody&) = delete;
	CentipedeBody& operator = (const CentipedeBody&) = delete;
	~CentipedeBody();

	void Initialize(sf::Vector2i location, Centipede* front, int centipedeLength, int frame, MushroomField* field);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

	void SetLastRot(float rot) {}; // only for head
	float GetLastRot();
	int GetSpeed();
	const CentipedeState* GetState();

	// specific to body
	void SetNextState(const CentipedeState* state);
	void BecomeHead();

	// these are called through gamemanager before mushroom roundup
	void Freeze();
	void DestroyEntireBody();

private:

	void Death();
	const CentipedeState* nextState;
};

#endif _CentipedeBody