// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "AttractorScene.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new AttractorScene() );

	AddTexture("BugBlaster", "blaster.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Bullet", "bullet.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Scorpion", "scorpion.png");
	AddTexture("Spider", "spider.png");
	AddTexture("CentipedeHead", "centipede_head.png");
	AddTexture("CentipedeBody", "centipede_segment.png");
	AddTexture("ArcadeFont", "FONTwPLAYER.bmp");
	AddTexture("ExplosionTwoTiles", "death.png");
	AddTexture("ExplosionSingleTile", "spawn.png");

	AddSound("CentiFootStep", "beat.wav");
	AddSound("MushBonus", "bonus.wav");
	AddSound("PlayerDeath", "death.wav");
	AddSound("BulletFired", "fire1.wav");
	AddSound("EnemyDeath", "kill.wav");
	AddSound("ScorpionLoop", "scorpion_new.wav");
	AddSound("SpiderLoop", "spider_new.wav");
	AddSound("FleaDrop", "flea_new.wav");
	AddSound("ExtraLife", "extraLife.wav");

	AddFont("MyDefaultFont", "../Game Components/TEAL/Arial.ttf");
}

