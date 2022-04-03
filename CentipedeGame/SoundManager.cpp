#include "SoundManager.h"
#include "CommandScoreValue.h"
#include "CommandScoreDistance.h"
#include "PlayerManager.h"
#include "Player.h"

#include "UnmutedAudioSource.h"
#include "MutedAudioSource.h"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
	unMuted = new UnmutedAudioSource();
	muted = new MutedAudioSource();
	currentAudioSource = unMuted;
}

SoundManager::~SoundManager()
{
	delete muted;
	delete unMuted;
}

void SoundManager::privSwitchSource()
{
	if (currentAudioSource == muted)
	{

		currentAudioSource = unMuted;
	}
	else
	{
		CentiLoopStop();
		ScorpLoopStop();
		SpiderLoopStop();
		currentAudioSource = muted;
	}
}

void SoundManager::privMushBonus()
{
	currentAudioSource->MushBonus();
}

void SoundManager::privCentiLoopPlay()
{
	currentAudioSource->CentiLoopPlay();
}

void SoundManager::privCentiLoopStop()
{
	currentAudioSource->CentiLoopStop();
}

void SoundManager::privSpiderLoopPlay()
{
	currentAudioSource->SpiderLoopPlay();
}

void SoundManager::privSpiderLoopStop()
{
	currentAudioSource->SpiderLoopStop();
}

void SoundManager::privScorpLoopPlay()
{
	currentAudioSource->ScorpLoopPlay();
}

void SoundManager::privScorpLoopStop()
{
	currentAudioSource->ScorpLoopStop();
}

void SoundManager::privEnemyKilled()
{
	currentAudioSource->EnemyKilled();
}

void SoundManager::privFleaPlay()
{
	currentAudioSource->FleaPlay();
}

void SoundManager::privFleaStop()
{
	currentAudioSource->FleaStop();
}

void SoundManager::privPlayerDeath()
{
	currentAudioSource->PlayerDeath();
}

void SoundManager::privBulletFired()
{
	currentAudioSource->BulletFired();
}

void SoundManager::privExtraLife()
{
	currentAudioSource->ExtraLife();
}

void SoundManager::Terminate()
{
	delete instance;
	instance = nullptr;
}