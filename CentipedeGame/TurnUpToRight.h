#ifndef _TurnUpToRight
#define _TurnUpToRight

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class TurnUpToRight : public CentipedeState
{
public:
	TurnUpToRight(); // big four
	TurnUpToRight(const TurnUpToRight&) = delete;
	TurnUpToRight& operator = (const TurnUpToRight&) = delete;
	~TurnUpToRight() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _TurnUpToRight