#ifndef _CentipedeState
#define _CentipedeState

#include "TEAL/CommonElements.h"
#include "GameSettings.h"

// forward declaration
class CentipedeHead;

class CentipedeState
{
public:
	CentipedeState() {}; // big four
	CentipedeState(const CentipedeState&) = delete;
	CentipedeState& operator = (const CentipedeState&) = delete;
	~CentipedeState() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const = 0;
	virtual sf::Vector2f GetPositionOffset(int index) const = 0;
	virtual float GetRotationOffset(int index) const = 0;
	virtual void DebugName() const = 0;

protected:
	sf::Vector2f positionOffset[GameSettings::FRAMESPERTILE];
	float rotationOffset[GameSettings::FRAMESPERTILE];
};

#endif _CentipedeState