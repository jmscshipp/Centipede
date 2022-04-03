#ifndef _TurnDownToLeft
#define _TurnDownToLeft

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class TurnDownToLeft : public CentipedeState
{
public:
	TurnDownToLeft(); // big four
	TurnDownToLeft(const TurnDownToLeft&) = delete;
	TurnDownToLeft& operator = (const TurnDownToLeft&) = delete;
	~TurnDownToLeft() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _TurnDownToLeft