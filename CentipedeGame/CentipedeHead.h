#ifndef _CentipedeHead
#define _CentipedeHead

#include "TEAL/CommonElements.h"
#include "Centipede.h"

// forward declaration
class MushroomField;
class Bullet;
class CentipedeState;

class CentipedeHead : public Centipede
{
public:
	CentipedeHead(); // big four
	CentipedeHead(const CentipedeHead&) = delete;
	CentipedeHead& operator = (const CentipedeHead&) = delete;
	~CentipedeHead();

	void Initialize(sf::Vector2i location, int centipedeSpeed, int centipedeLength, MushroomField* field);
	virtual void Draw();
	virtual void Update();
	virtual void Destroy();
	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

	sf::Vector2f GetPos(); // called by states
	float GetLastRot();
	int GetSpeed();
	const CentipedeState* GetState();
	void SetHeadInfo(Centipede* backRef, const CentipedeState* curState, sf::Vector2f pos, int frameCount, float lastRotation);
	int GetFrameCounter(); // ONLY FOR DEBUGGING, CAN DELETE

	// these are called by gamemanager before mushroom roundup
	void Freeze();
	void DestroyEntireBody();
private:
	void Death();

	int bottomBoundary; // vertical boundaries
	int playerSpaceBoundary;
};

#endif _CentipedeHead