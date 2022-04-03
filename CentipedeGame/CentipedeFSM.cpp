#include "CentipedeFSM.h"
#include "MoveLeftDown.h"
#include "MoveRightDown.h"
#include "TurnDownToLeft.h"
#include "TurnDownToRight.h"
#include "MoveLeftUp.h"
#include "MoveRightUp.h"
#include "TurnUpToLeft.h"
#include "TurnUpToRight.h"
#include "PoisonDownRight.h"
#include "PoisonDownLeft.h"

const MoveLeftDown CentipedeFSM::stateMoveLeftDown;
const MoveRightDown CentipedeFSM::stateMoveRightDown;
const TurnDownToLeft CentipedeFSM::stateTurnDownToLeft;
const TurnDownToRight CentipedeFSM::stateTurnDownToRight;
const MoveLeftUp CentipedeFSM::stateMoveLeftUp;
const MoveRightUp CentipedeFSM::stateMoveRightUp;
const TurnUpToLeft CentipedeFSM::stateTurnUpToLeft;
const TurnUpToRight CentipedeFSM::stateTurnUpToRight;
const PoisonDownRight CentipedeFSM::statePoisonDownRight;
const PoisonDownLeft CentipedeFSM::statePoisonDownLeft;