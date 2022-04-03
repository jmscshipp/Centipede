#ifndef _CentipedeFSM
#define _CentipedeFSM

#include "TEAL/CommonElements.h"

// forward declarations
class MoveLeftDown;
class MoveRightDown;
class TurnDownToLeft;
class TurnDownToRight;
class MoveLeftUp;
class MoveRightUp;
class TurnUpToLeft;
class TurnUpToRight;
class PoisonDownRight;
class PoisonDownLeft;

class CentipedeFSM
{
public:
	CentipedeFSM() = default; // big four
	CentipedeFSM(const CentipedeFSM&) = delete;
	CentipedeFSM& operator = (const CentipedeFSM&) = delete;
	~CentipedeFSM() = default;

	static const MoveLeftDown stateMoveLeftDown;
	static const MoveRightDown stateMoveRightDown;
	static const TurnDownToLeft stateTurnDownToLeft;
	static const TurnDownToRight stateTurnDownToRight;
	static const MoveLeftUp stateMoveLeftUp;
	static const MoveRightUp stateMoveRightUp;
	static const TurnUpToLeft stateTurnUpToLeft;
	static const TurnUpToRight stateTurnUpToRight;
	static const PoisonDownRight statePoisonDownRight;
	static const PoisonDownLeft statePoisonDownLeft;
};

#endif _CentipedeFSM