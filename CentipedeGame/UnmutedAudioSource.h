#ifndef _UnmutedAudioSource
#define _UnmutedAudioSource

#include "TEAL/CommonElements.h"
#include "AudioSource.h"

// forward declaration

class UnmutedAudioSource : public AudioSource
{
private:
	sf::Sound centiFootstep;
	sf::Sound mushBonus;
	sf::Sound playerDeath;
	sf::Sound bulletFired;
	sf::Sound enemyDeath;
	sf::Sound scorpionLoop;
	sf::Sound spiderLoop;
	sf::Sound fleaDrop;
	sf::Sound extraLife;

	bool centiLoopOn;
	bool scorpLoopOn;
	bool spiderLoopOn;

public:
	UnmutedAudioSource(); // big four
	UnmutedAudioSource(const UnmutedAudioSource&) = delete;
	UnmutedAudioSource& operator = (const UnmutedAudioSource&) = delete;
	~UnmutedAudioSource() = default;

	virtual void MushBonus();
	virtual void CentiLoopPlay();
	virtual void CentiLoopStop();
	virtual void SpiderLoopPlay();
	virtual void SpiderLoopStop();
	virtual void ScorpLoopPlay();
	virtual void ScorpLoopStop();
	virtual void EnemyKilled();
	virtual void FleaPlay();
	virtual void FleaStop();
	virtual void PlayerDeath();
	virtual void BulletFired();
	virtual void ExtraLife();
};

#endif _UnmutedAudioSource