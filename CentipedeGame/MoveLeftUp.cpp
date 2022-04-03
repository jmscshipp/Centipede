#include "MoveLeftUp.h"
#include "CentipedeFSM.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"
#include "CentipedeHead.h"
#include "TurnUpToRight.h"
#include "TurnDownToRight.h"

MoveLeftUp::MoveLeftUp()
{
	int stepSize = GameSettings::TILESIZE / GameSettings::FRAMESPERTILE; // setting up array of offsets
	for (int i = 0; i < GameSettings::FRAMESPERTILE; i++)
	{
		positionOffset[i] = sf::Vector2f(-(float)(i * stepSize + stepSize), 0.0f);
		rotationOffset[i] = 0.0f;
	}
}

const CentipedeState* MoveLeftUp::GetNextState(CentipedeHead* head) const
{
	const CentipedeState* nextState;
	sf::Vector2f pos = head->GetPos();

	// checks (x - 1, y)
	MushroomField::ObstacleStatus obstacleCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridObstacle(sf::Vector2i((int)pos.x - GameSettings::TILESIZE, (int)pos.y)); // true if blocked
	// checks (x, y + 1)
	bool verticalCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridVerticalBounds(sf::Vector2i((int)pos.x, (int)pos.y + GameSettings::TILESIZE), true ); // true if blocked (true to check up)

	if (obstacleCheck != MushroomField::ObstacleStatus::Clear && verticalCheck)
		nextState = &CentipedeFSM::stateTurnDownToRight;
	else if (obstacleCheck != MushroomField::ObstacleStatus::Clear)
		nextState = &CentipedeFSM::stateTurnUpToRight;
	else
		nextState = &CentipedeFSM::stateMoveLeftUp;

	return nextState;
}

sf::Vector2f MoveLeftUp::GetPositionOffset(int index) const
{
	return positionOffset[index];
}

float MoveLeftUp::GetRotationOffset(int index) const
{
	return rotationOffset[index];
}

void MoveLeftUp::DebugName() const
{
	Trace::out("MoveLeftUp\n");
}