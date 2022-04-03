#include "TurnDownToLeft.h"
#include "CentipedeFSM.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"
#include "CentipedeHead.h"
#include "MoveLeftDown.h"
#include "TurnDownToRight.h"
#include "TurnUpToRight.h"
#include "PoisonDownRight.h"

TurnDownToLeft::TurnDownToLeft()
{
	int stepSize = GameSettings::TILESIZE / GameSettings::FRAMESPERTILE; // setting up array of offsets
	float rotationIncrement = 180.0f / (float)GameSettings::FRAMESPERTILE;
	for (int i = 0; i < GameSettings::FRAMESPERTILE; i++)
	{
		positionOffset[i] = sf::Vector2f(0.0f, (float)(i * stepSize + stepSize));
		rotationOffset[i] = rotationIncrement * i + rotationIncrement;
	}
}

const CentipedeState* TurnDownToLeft::GetNextState(CentipedeHead* head) const
{
	const CentipedeState* nextState;
	sf::Vector2f pos = head->GetPos();
	// checks (x - 1, y)
	MushroomField::ObstacleStatus obstacleCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridObstacle(sf::Vector2i((int)pos.x - GameSettings::TILESIZE, (int)pos.y)); // true if blocked
	// checks (x, y - 1)
	bool verticalCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridVerticalBounds(sf::Vector2i((int)pos.x, (int)pos.y - GameSettings::TILESIZE), false); // true if blocked (false to check down)
	if (obstacleCheck == MushroomField::ObstacleStatus::PoisonMushroom)
		nextState = &CentipedeFSM::statePoisonDownRight;
	else if (obstacleCheck != MushroomField::ObstacleStatus::Clear && verticalCheck)
		nextState = &CentipedeFSM::stateTurnUpToRight;
	else if (obstacleCheck != MushroomField::ObstacleStatus::Clear)
		nextState = &CentipedeFSM::stateTurnDownToRight;
	else
		nextState = &CentipedeFSM::stateMoveLeftDown;

	return nextState;
}

sf::Vector2f TurnDownToLeft::GetPositionOffset(int index) const
{
	return positionOffset[index];
}

float TurnDownToLeft::GetRotationOffset(int index) const
{
	return rotationOffset[index];
}

void TurnDownToLeft::DebugName() const
{
	Trace::out("TurnDownLeft\n");
}