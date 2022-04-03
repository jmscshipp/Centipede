#ifndef _PoisonDownLeft
#define _PoisonDownLeft

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class PoisonDownLeft : public CentipedeState
{
public:
	PoisonDownLeft(); // big four
	PoisonDownLeft(const PoisonDownLeft&) = delete;
	PoisonDownLeft& operator = (const PoisonDownLeft&) = delete;
	~PoisonDownLeft() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _PoisonDownLeft