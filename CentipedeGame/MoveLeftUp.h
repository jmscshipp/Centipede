#ifndef _MoveLeftUp
#define _MoveLeftUp

#include "TEAL/CommonElements.h"
#include "CentipedeState.h"

class MoveLeftUp : public CentipedeState
{
public:
	MoveLeftUp(); // big four
	MoveLeftUp(const MoveLeftUp&) = delete;
	MoveLeftUp& operator = (const MoveLeftUp&) = delete;
	~MoveLeftUp() = default;

	virtual const CentipedeState* GetNextState(CentipedeHead* head) const override;
	virtual sf::Vector2f GetPositionOffset(int index) const override;
	virtual float GetRotationOffset(int index) const override;
	virtual void DebugName() const override;
};

#endif _MoveLeftUp