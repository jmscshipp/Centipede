#include "PoisonDownRight.h"
#include "CentipedeFSM.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "Player.h"
#include "CentipedeHead.h"
#include "MoveRightDown.h"
#include "PoisonDownLeft.h"

PoisonDownRight::PoisonDownRight()
{
	int stepSize = GameSettings::TILESIZE / GameSettings::FRAMESPERTILE; // setting up array of offsets
	float rotationIncrement = 180.0f / (float)GameSettings::FRAMESPERTILE;
	for (int i = 0; i < GameSettings::FRAMESPERTILE; i++)
	{
		positionOffset[i] = sf::Vector2f(0.0f, (float)(i * stepSize + stepSize));
		rotationOffset[i] = -(rotationIncrement * i + rotationIncrement);
	}
}

const CentipedeState* PoisonDownRight::GetNextState(CentipedeHead* head) const
{
	const CentipedeState* nextState;
	sf::Vector2f pos = head->GetPos();
	// checks (x, y + 1)
	bool verticalCheck = PlayerManager::GetCurrentPlayer()->GetMushrooomField()->CheckGridVerticalBounds(sf::Vector2i((int)pos.x, (int)pos.y + GameSettings::TILESIZE), false); // true if blocked (false to check down)
	if (verticalCheck)
		nextState = &CentipedeFSM::stateMoveRightDown;
	else
		nextState = &CentipedeFSM::statePoisonDownLeft;

	return nextState;
}

sf::Vector2f PoisonDownRight::GetPositionOffset(int index) const
{
	return positionOffset[index];
}

float PoisonDownRight::GetRotationOffset(int index) const
{
	return rotationOffset[index];
}

void PoisonDownRight::DebugName() const
{
	Trace::out("PoisonDownRight\n");
}