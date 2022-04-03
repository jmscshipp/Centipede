#ifndef _TurnUpToLeft
#define _TurnUpToLeft

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class TurnUpToLeft : public CentipedeState
{
public:
	TurnUpToLeft(); // big four
	TurnUpToLeft(const TurnUpToLeft&) = delete;
	TurnUpToLeft& operator = (const TurnUpToLeft&) = delete;
	~TurnUpToLeft() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _TurnUpToLeft