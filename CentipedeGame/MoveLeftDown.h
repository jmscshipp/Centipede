#ifndef _MoveLeftDown
#define _MoveLeftDown

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class MoveLeftDown : public CentipedeState
{
public:
	MoveLeftDown(); // big four
	MoveLeftDown(const MoveLeftDown&) = delete;
	MoveLeftDown& operator = (const MoveLeftDown&) = delete;
	~MoveLeftDown() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _MoveLeftDown