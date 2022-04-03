#ifndef _AudioSource
#define _AudioSource

#include "TEAL/CommonElements.h"

// forward declaration
class CommandSound;

class AudioSource
{
private:

public:
	AudioSource() = default; // big four
	AudioSource(const AudioSource&) = delete;
	AudioSource& operator = (const AudioSource&) = delete;
	~AudioSource() = default;

	virtual void MushBonus() = 0;
	virtual void CentiLoopPlay() = 0;
	virtual void CentiLoopStop() = 0;
	virtual void SpiderLoopPlay() = 0;
	virtual void SpiderLoopStop() = 0;
	virtual void ScorpLoopPlay() = 0;
	virtual void ScorpLoopStop() = 0;
	virtual void EnemyKilled() = 0;
	virtual void FleaPlay() = 0;
	virtual void FleaStop() = 0;
	virtual void PlayerDeath() = 0;
	virtual void BulletFired() = 0;
	virtual void ExtraLife() = 0;
};

#endif _AudioSource