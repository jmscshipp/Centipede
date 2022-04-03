#ifndef _TurnDownToRight
#define _TurnDownToRight

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class TurnDownToRight : public CentipedeState
{
public:
	TurnDownToRight(); // big four
	TurnDownToRight(const TurnDownToRight&) = delete;
	TurnDownToRight& operator = (const TurnDownToRight&) = delete;
	~TurnDownToRight() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _TurnDownToRight