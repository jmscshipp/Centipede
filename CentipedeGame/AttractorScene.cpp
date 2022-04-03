#include "AttractorScene.h"
#include "GameManager.h"
#include "AttractorInput.h"

// collisions
#include "BugBlaster.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "Flea.h"
#include "Scorpion.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "Spider.h"

void AttractorScene::Initialize()
{
	GameManager::InitializeAttractorScene();

	input = new AttractorInput();

	CollisionTestPair<BugBlaster, Mushroom>();
	CollisionTestPair<BugBlaster, Flea>();
	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Bullet, CentipedeHead>();
	CollisionTestPair<Bullet, CentipedeBody>();
	CollisionTestPair<Spider, Bullet>();
	CollisionTestPair<Spider, Mushroom>();
	CollisionTestPair<Spider, BugBlaster>();
}

void AttractorScene::Terminate()
{  
	//delete(input);
}