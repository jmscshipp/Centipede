#ifndef _MoveRightDown
#define _MoveRightDown

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class MoveRightDown : public CentipedeState
{
public:
	MoveRightDown(); // big four
	MoveRightDown(const MoveRightDown&) = delete;
	MoveRightDown& operator = (const MoveRightDown&) = delete;
	~MoveRightDown() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _MoveRightDown