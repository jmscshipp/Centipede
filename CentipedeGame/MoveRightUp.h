#ifndef _MoveRightUp
#define _MoveRightUp

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class MoveRightUp : public CentipedeState
{
public:
	MoveRightUp(); // big four
	MoveRightUp(const MoveRightUp&) = delete;
	MoveRightUp& operator = (const MoveRightUp&) = delete;
	~MoveRightUp() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif __MoveRightUp