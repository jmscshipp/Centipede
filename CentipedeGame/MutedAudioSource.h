#ifndef _MutedAudioSource
#define _MutedAudioSource

#include "TEAL/CommonElements.h"

#include "AudioSource.h"
// forward declaration

class MutedAudioSource : public AudioSource
{
private:

public:
	MutedAudioSource() = default; // big four
	MutedAudioSource(const MutedAudioSource&) = delete;
	MutedAudioSource& operator = (const MutedAudioSource&) = delete;
	~MutedAudioSource() = default;

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

#endif _MutedAudioSource