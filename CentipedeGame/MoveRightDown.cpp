#include "MoveRightDown.h"
#include "CentipedeFSM.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"
#include "CentipedeHead.h"
#include "TurnUpToLeft.h"
#include "TurnDownToLeft.h"
#include "PoisonDownLeft.h"

MoveRightDown::MoveRightDown()
{
	int stepSize = GameSettings::TILESIZE / GameSettings::FRAMESPERTILE; // setting up array of offsets
	for (int i = 0; i < GameSettings::FRAMESPERTILE; i++)
	{
		positionOffset[i] = sf::Vector2f((float)(i * stepSize + stepSize), 0.0f);
		rotationOffset[i] = 0.0f;
	}
}

const CentipedeState* MoveRightDown::GetNextState(CentipedeHead* head) const
{
	const CentipedeState* nextState;
	sf::Vector2f pos = head->GetPos();
	// checks (x + 1, y)
	MushroomField::ObstacleStatus obstacleCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridObstacle(sf::Vector2i((int)pos.x + GameSettings::TILESIZE, (int)pos.y)); // true if blocked
	// checks (x, y + 1)
	bool verticalCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridVerticalBounds(sf::Vector2i((int)pos.x, (int)pos.y + GameSettings::TILESIZE), false); // true if blocked (false to check down)
	if (obstacleCheck == MushroomField::ObstacleStatus::PoisonMushroom)
		nextState = &CentipedeFSM::statePoisonDownLeft;
	else if (obstacleCheck != MushroomField::ObstacleStatus::Clear && verticalCheck)
		nextState = &CentipedeFSM::stateTurnUpToLeft;
	else if (obstacleCheck != MushroomField::ObstacleStatus::Clear)
		nextState = &CentipedeFSM::stateTurnDownToLeft;
	else
		nextState = &CentipedeFSM::stateMoveRightDown;

	return nextState;
}

sf::Vector2f MoveRightDown::GetPositionOffset(int index) const
{
	return positionOffset[index];
}

float MoveRightDown::GetRotationOffset(int index) const
{
	return rotationOffset[index];
}

void MoveRightDown::DebugName() const
{
	Trace::out("MoveRightDown\n");
}