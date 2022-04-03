#include "CentipedeBody.h"
#include "Bullet.h"
#include "GameSettings.h"
#include "MushroomField.h"
#include "CentipedeFSM.h"
#include "CentipedeState.h"
#include "CentipedeHead.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "ScoreManager.h"
#include "ExplosionSingleTileFactory.h"
#include "SoundManager.h"

CentipedeBody::CentipedeBody()
{
	tileSize = GameSettings::TILESIZE;

	deathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiBodyKilled);

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeBody"), 8, 2);
	mainSprite.SetAnimation(0, 7, true, true);
	mainSprite.setOrigin(mainSprite.getTextureRect().width / 2.0f, mainSprite.getTextureRect().height / 2.0f);
	mainSprite.setScale(sf::Vector2f(2.0f, 2.0f));
	mainSprite.SetLoopSpeed(15.0f);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("CentipedeBody");
	SetCollider(mainSprite, bitmap, true);
}

void CentipedeBody::Initialize(sf::Vector2i location, Centipede* front, int centipedeLength, int frame, MushroomField* field)
{
	speed = front->GetSpeed();
	myMushroomField = field;
	mainSprite.SetFrame(frame);
	mainSprite.Play();

	// setting state
	frontReference = front;
	currentState = front->GetState();
	nextState = currentState;
	frameCounter = 0;
	frameIncrement = 1;

	// FOR TESTING ONLY
	NODENUM = centipedeLength;

	// setting up position
	pos = sf::Vector2f((float)location.x, (float)location.y);
	lastTile = location; // last saved tile pos
	mainSprite.setPosition(pos);
	
	// setting up rotation
	rot = 0.0f;
	mainSprite.setRotation(rot);
	lastRot = front->GetLastRot() + 180.0f; // offset because it turns an extra time on spawn
	if (lastRot != 0.0f && (int)lastRot % 180 == 0)
		lastRot = -180.0f;
	else
		lastRot = 0.0f;

	if (centipedeLength > 1)
	{
		int nextFrame = (frame + 1 == 8) ? 0 : frame + 1;
		backReference = CentipedeBodyFactory::CreateCentipedeBody(sf::Vector2i(location.x, location.y - tileSize), this, --centipedeLength, nextFrame, myMushroomField);
	}
	else
		backReference = nullptr;

	RegisterCollision<CentipedeBody>(*this);
}

CentipedeBody::~CentipedeBody()
{
	delete deathScore;
}

float CentipedeBody::GetLastRot()
{
	return lastRot;
}

int CentipedeBody::GetSpeed()
{
	return speed;
}

const CentipedeState* CentipedeBody::GetState()
{
	return currentState;
}

void  CentipedeBody::SetNextState(const CentipedeState* state)
{
	nextState = state;
}

void CentipedeBody::Freeze()
{
	frameIncrement = 0;
	mainSprite.Pause();
	if (backReference != nullptr)
		backReference->Freeze();
}

void CentipedeBody::DestroyEntireBody()
{
	if (backReference != nullptr)
		backReference->DestroyEntireBody();
	MarkForDestroy();
}

void CentipedeBody::Death()
{
	SoundManager::EnemyKilled();
	ScoreManager::SendScoreCmd(deathScore);

	// place mushroom down where killed segment was
	float dirTemp = abs(rot);
	if (dirTemp >= 90.0f) // facing right
		dirTemp = 1;
	else // facing left
		dirTemp = -1;
	myMushroomField->PlaceMushroom(myMushroomField->WorldToGrid(sf::Vector2i(lastTile.x + tileSize * dirTemp, lastTile.y)));

	// fix references, turn back node into new head
	if (frontReference != nullptr)
		frontReference->backReference = nullptr;
	if (backReference != nullptr)
		static_cast<CentipedeBody*>(backReference)->BecomeHead();

	MarkForDestroy();
}

void CentipedeBody::BecomeHead()
{
	frontReference = nullptr;
	// make new head
	CentipedeHead* newHead = CentipedeHeadFactory::CreateCentipedeHead(lastTile, speed, 1, myMushroomField);
	// fix references and values
	newHead->SetHeadInfo(backReference, currentState, pos, frameCounter, lastRot);
	if (backReference != nullptr)
	{
		backReference->frontReference = newHead;
		static_cast<CentipedeBody*>(newHead->backReference)->SetNextState(currentState);
	}
	MarkForDestroy();
}

void CentipedeBody::Update()
{
	if (frameCounter == 8)
	{
		// geting ready for next move
		currentState = nextState;
		nextState = frontReference->GetState();
		lastTile = sf::Vector2i((int)pos.x, (int)pos.y);
		lastRot = rot;
		if (abs(lastRot) == 360.0f) // if it made a full rotation, reset to 0
			lastRot = 0.0f;
		frameCounter = 0;
	}

	pos.x = (float)lastTile.x + currentState->GetPositionOffset(frameCounter).x;
	pos.y = (float)lastTile.y + currentState->GetPositionOffset(frameCounter).y;
	rot = lastRot + currentState->GetRotationOffset(frameCounter);

	frameCounter += frameIncrement;

	mainSprite.Update();
	mainSprite.setPosition(pos);
	mainSprite.setRotation(rot);
}

void CentipedeBody::Collision(Bullet* other)
{
	ExplosionSingleTileFactory::CreateExplosionSingleTile(pos);
	other->MarkForDestroy();
	Death();
}

void CentipedeBody::Destroy()
{
	DeregisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

