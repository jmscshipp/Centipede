#ifndef _SoundManager
#define _SoundManager

#include "TEAL/CommonElements.h"

// forward declaration
class CommandSound;
class AudioSource;

class SoundManager
{
private:
	static SoundManager* instance;

	SoundManager(); // big four
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator = (const SoundManager&) = delete;
	~SoundManager();

	static SoundManager& Instance()
	{
		if (!instance)
			instance = new SoundManager;
		return *instance;
	};

	AudioSource* unMuted;
	AudioSource* muted;
	AudioSource* currentAudioSource;

	void privMushBonus();
	void privCentiLoopPlay();
	void privCentiLoopStop();
	void privSpiderLoopPlay();
	void privSpiderLoopStop();
	void privScorpLoopPlay();
	void privScorpLoopStop();
	void privEnemyKilled();
	void privFleaPlay();
	void privFleaStop();
	void privPlayerDeath();
	void privBulletFired();
	void privExtraLife();

	void privSwitchSource();

public:
	// events
	enum class SoundEvents { playCentiLoop, stopCentiLoop, playSpiderLoop, stopSpiderLoop, playScorpLoop, stopScorpLoop, killedEnemy, playFlea, stopFlea, playerDied, bulletFired, extraLife };

	static void MushBonus() { Instance().privMushBonus(); };
	static void CentiLoopPlay() { Instance().privCentiLoopPlay(); };
	static void CentiLoopStop() { Instance().privCentiLoopStop(); };
	static void SpiderLoopPlay() { Instance().privSpiderLoopPlay(); };
	static void SpiderLoopStop() { Instance().privSpiderLoopStop(); };
	static void ScorpLoopPlay() { Instance().privScorpLoopPlay(); };
	static void ScorpLoopStop() { Instance().privScorpLoopStop(); };
	static void EnemyKilled() { Instance().privEnemyKilled(); };
	static void FleaPlay() { Instance().privFleaPlay(); };
	static void FleaStop() { Instance().privFleaStop(); };
	static void PlayerDeath() { Instance().privPlayerDeath(); };
	static void BulletFired() { Instance().privBulletFired(); };
	static void ExtraLife() { Instance().privExtraLife(); };

	static void SwitchSource() { Instance().privSwitchSource(); };

	static void Terminate();
};

#endif _SoundManager