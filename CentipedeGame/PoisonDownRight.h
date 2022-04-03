#ifndef _PoisonDownRight
#define _PoisonDownRight

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class PoisonDownRight : public CentipedeState
{
public:
	PoisonDownRight(); // big four
	PoisonDownRight(const PoisonDownRight&) = delete;
	PoisonDownRight& operator = (const PoisonDownRight&) = delete;
	~PoisonDownRight() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _PoisonDownRight