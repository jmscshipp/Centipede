#include "CentipedeHead.h"
#include "Bullet.h"
#include "GameSettings.h"
#include "CentipedeFSM.h"
#include "CentipedeState.h"
#include "TurnDownToRight.h"
#include "CentipedeBody.h"
#include "MushroomField.h"
#include "CentipedeBodyFactory.h"
#include "ScoreManager.h"
#include "ExplosionSingleTileFactory.h"
#include "SoundManager.h"

CentipedeHead::CentipedeHead()
{
	tileSize = GameSettings::TILESIZE;
	deathScore = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiHeadKilled);
	bottomBoundary = GameSettings::GRIDHEIGHT * tileSize;
	playerSpaceBoundary = bottomBoundary - GameSettings::PSPACESIZE;

	// setting up sprite
	mainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2);
	mainSprite.SetAnimation(0, 7, true, true);
	mainSprite.setOrigin((float)mainSprite.getTextureRect().width / 2.0f, (float)mainSprite.getTextureRect().height / 2.0f);
	mainSprite.setScale(sf::Vector2f(2.0f, 2.0f));
	mainSprite.SetLoopSpeed(15.0f);

	// setting up collisions
	bitmap = ResourceManager::GetTextureBitmap("CentipedeHead");
	SetCollider(mainSprite, bitmap, true);
}

void CentipedeHead::Initialize(sf::Vector2i location, int centipedeSpeed, int centipedeLength, MushroomField* field)
{
	speed = centipedeSpeed;
	myMushroomField = field;
	frameCounter = 0;
	frameIncrement = 1;
	mainSprite.Play();
	// FOR TESTING ONLY
	NODENUM = centipedeLength;

	// default state, will get overriden by old body if this head isn't there on start
	currentState = &CentipedeFSM::stateTurnDownToRight;

	// setting up position + rotation
	pos = sf::Vector2f((float)location.x, (float)location.y);
	lastTile = location; // last saved tile pos
	mainSprite.setPosition(pos);
	rot = 0.0f;
	lastRot = 0.0f;

	frontReference = nullptr;
	if (centipedeLength > 1)
		backReference = CentipedeBodyFactory::CreateCentipedeBody(sf::Vector2i(location.x, location.y - tileSize), this, --centipedeLength, 1, myMushroomField);
	else
		backReference = nullptr;

	SetUpdateOrder(-1); // need this so new centipede head is in front when splitting happens
	RegisterCollision<CentipedeHead>(*this);
}

CentipedeHead::~CentipedeHead()
{
	delete deathScore;
	Trace::out("!! deleted head command score!\n");
}

sf::Vector2f CentipedeHead::GetPos()
{
	return pos;
}

// called by body when it's turning into a head
void CentipedeHead::SetHeadInfo(Centipede* backRef, const CentipedeState* curState, sf::Vector2f newPos, int frameCount, float lastRotation)
{
	backReference = backRef;
	currentState = curState;
	pos = newPos;
	frameCounter = frameCount;
	lastRot = lastRotation;
}

float CentipedeHead::GetLastRot()
{
	return lastRot;
}

int CentipedeHead::GetSpeed()
{
	return speed;
}

const CentipedeState* CentipedeHead::GetState()
{
	return currentState;
}

// THIS IS ONLY FOR DEBUGGING, CAN DELETE
int CentipedeHead::GetFrameCounter()
{
	return frameCounter;
}

void CentipedeHead::Freeze()
{
	frameIncrement = 0;
	mainSprite.Pause();
	if (backReference != nullptr)
		backReference->Freeze();
}

void CentipedeHead::DestroyEntireBody()
{
	if (backReference != nullptr)
		backReference->DestroyEntireBody();
	MarkForDestroy();
}

void CentipedeHead::Death()
{
	SoundManager::EnemyKilled();
	ScoreManager::SendScoreCmd(deathScore);

	// place mushroom where killed segment was
	float dirTemp = abs(rot);
	dirTemp = (dirTemp >= 90.0f) ? 1 : -1; // determine which dir we're facing
	myMushroomField->PlaceMushroom(myMushroomField->WorldToGrid(sf::Vector2i(lastTile.x + tileSize * dirTemp, lastTile.y)));
	
	// fix references, turn back node into new head
	if (backReference != nullptr)
		static_cast<CentipedeBody*>(backReference)->BecomeHead();
	MarkForDestroy();
}

void CentipedeHead::Update()
{
	if (frameCounter >= 8)
	{
		currentState = currentState->GetNextState(this);
		lastTile = sf::Vector2i((int)pos.x, (int)pos.y);
		lastRot = rot;
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

void CentipedeHead::Collision(Bullet* other)
{
	ExplosionSingleTileFactory::CreateExplosionSingleTile(pos);
	Death();
	other->MarkForDestroy();
}

void CentipedeHead::Destroy()
{
	DeregisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Draw()
{
	WindowManager::Window().draw(mainSprite);
}

