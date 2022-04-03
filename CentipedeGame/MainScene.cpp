#include "MainScene.h"
#include "GameManager.h"

// collisions
#include "BugBlaster.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "Flea.h"
#include "Scorpion.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "Spider.h"

void MainScene::Initialize()
{
	GameManager::InitializeGameScene();

	CollisionTestPair<BugBlaster, Mushroom>();
	CollisionTestPair<BugBlaster, CentipedeHead>();
	CollisionTestPair<BugBlaster, CentipedeBody>();
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

void MainScene::Terminate()
{

}