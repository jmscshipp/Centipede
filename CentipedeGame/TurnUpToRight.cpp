#include "TurnUpToRight.h"
#include "CentipedeFSM.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"
#include "CentipedeHead.h"
#include "MoveRightUp.h"
#include "TurnDownToLeft.h"
#include "TurnUpToLeft.h"

TurnUpToRight::TurnUpToRight()
{
	int stepSize = GameSettings::TILESIZE / GameSettings::FRAMESPERTILE; // setting up array of offsets
	float rotationIncrement = 180.0f / (float)GameSettings::FRAMESPERTILE;
	for (int i = 0; i < GameSettings::FRAMESPERTILE; i++)
	{
		positionOffset[i] = sf::Vector2f(0.0f, -(float)(i * stepSize + stepSize));
		rotationOffset[i] = rotationIncrement * i + rotationIncrement;
	}
}

const CentipedeState* TurnUpToRight::GetNextState(CentipedeHead* head) const
{
	const CentipedeState* nextState;
	sf::Vector2f pos = head->GetPos();
	// checks (x + 1, y)
	MushroomField::ObstacleStatus obstacleCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridObstacle(sf::Vector2i((int)pos.x + GameSettings::TILESIZE, (int)pos.y)); // true if blocked
	// checks (x, y - 1)
	bool verticalCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridVerticalBounds(sf::Vector2i((int)pos.x, (int)pos.y - GameSettings::TILESIZE), true); // true if blocked (true to check up)

	if (obstacleCheck != MushroomField::ObstacleStatus::Clear && verticalCheck)
		nextState = &CentipedeFSM::stateTurnDownToLeft;
	else if (obstacleCheck != MushroomField::ObstacleStatus::Clear)
		nextState = &CentipedeFSM::stateTurnUpToLeft;
	else
		nextState = &CentipedeFSM::stateMoveRightUp;

	return nextState;
}

sf::Vector2f TurnUpToRight::GetPositionOffset(int index) const
{
	return positionOffset[index];
}

float TurnUpToRight::GetRotationOffset(int index) const
{
	return rotationOffset[index];
}

void TurnUpToRight::DebugName() const
{
	Trace::out("TurnUpRight\n");
}