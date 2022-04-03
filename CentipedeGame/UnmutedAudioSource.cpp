#include "UnmutedAudioSource.h"

UnmutedAudioSource::UnmutedAudioSource()
{
	centiFootstep.setBuffer(ResourceManager::GetSound("CentiFootStep"));
	mushBonus.setBuffer(ResourceManager::GetSound("MushBonus"));
	playerDeath.setBuffer(ResourceManager::GetSound("PlayerDeath"));
	bulletFired.setBuffer(ResourceManager::GetSound("BulletFired"));
	enemyDeath.setBuffer(ResourceManager::GetSound("EnemyDeath"));
	scorpionLoop.setBuffer(ResourceManager::GetSound("ScorpionLoop"));
	spiderLoop.setBuffer(ResourceManager::GetSound("SpiderLoop"));
	fleaDrop.setBuffer(ResourceManager::GetSound("FleaDrop"));
	extraLife.setBuffer(ResourceManager::GetSound("ExtraLife"));

	centiLoopOn = false;
	scorpLoopOn = false;
	spiderLoopOn = false;
}

void UnmutedAudioSource::MushBonus()
{
	mushBonus.setVolume(15.0f);
	mushBonus.play();
}

void UnmutedAudioSource::CentiLoopPlay()
{
	if (!centiLoopOn)
	{
		centiFootstep.setLoop(true);
		centiFootstep.setVolume(15.0f);
		centiFootstep.play();
		centiLoopOn = true;
	}
}

void UnmutedAudioSource::CentiLoopStop()
{
	if (centiLoopOn)
	{
		centiFootstep.stop();
		centiLoopOn = false;
	}
}

void UnmutedAudioSource::SpiderLoopPlay()
{
	if (!spiderLoopOn)
	{
		spiderLoop.setLoop(true);
		spiderLoop.setVolume(15.0f);
		spiderLoop.play();
		spiderLoopOn = true;
	}
}

void UnmutedAudioSource::SpiderLoopStop()
{
	if (spiderLoopOn)
	{
		spiderLoop.stop();
		spiderLoopOn = false;
	}
}

void UnmutedAudioSource::ScorpLoopPlay()
{
	if (!scorpLoopOn)
	{
		scorpionLoop.setLoop(true);
		scorpionLoop.setVolume(15.0f);
		scorpionLoop.play();
		scorpLoopOn = true;
	}
}

void UnmutedAudioSource::ScorpLoopStop()
{
	if (scorpLoopOn)
	{
		scorpionLoop.stop();
		scorpLoopOn = false;
	}
}

void UnmutedAudioSource::EnemyKilled()
{
	enemyDeath.setVolume(15.0f);
	enemyDeath.play();
}

void UnmutedAudioSource::FleaPlay()
{
	fleaDrop.setVolume(15.0f);
	fleaDrop.play();
}

void UnmutedAudioSource::FleaStop()
{
	fleaDrop.stop();
}

void UnmutedAudioSource::PlayerDeath()
{
	playerDeath.setVolume(15.0f);
	playerDeath.play();
}

void UnmutedAudioSource::BulletFired()
{
	bulletFired.setVolume(15.0f);
	bulletFired.play();
}

void UnmutedAudioSource::ExtraLife()
{
	extraLife.setVolume(15.0f);
	extraLife.play();
}
