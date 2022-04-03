#ifndef _GameManager
#define _GameManager

// forward declarations
class WaveManager;
class HighScoreManager;

class GameManager
{
private:
	static GameManager* instance; // set up as singleton

	GameManager(); // big four
	GameManager(const GameManager&) = delete;
	GameManager& operator = (const GameManager&) = delete;
	~GameManager();

	static GameManager& Instance()
	{
		if (!instance)
			instance = new GameManager();
		return *instance;
	};

	WaveManager* myWaveManager;
	//HighScoreManager* myHighScoreManager;
	int activeCentipedeSegments;
	bool roundUpHappening; // to prevent manager from thinking centipede was killed after roundup

	WaveManager* privGetWaveManager();
	//HighScoreManager* privGetHighScoreManager();
	void NextWave(); // called by self when activeCentipedeSegments = 0
	void privPlayerDeath();
	void privRestartWave();
	void privIncrementSegmentNum(int numAdded);
	void privDecrementSegmentNum();

	void privInitializeAttractorScene();
	void privInitializeGameScene();

public:
	static WaveManager* GetWaveManager() { return Instance().privGetWaveManager(); };
	//static HighScoreManager* GetHighScoreManager() { return Instance().privGetHighScoreManager(); };

	static void InitializeAttractorScene() { Instance().privInitializeAttractorScene(); };
	static void InitializeGameScene() { Instance().privInitializeGameScene(); };

	static void PlayerDeath() { Instance().privPlayerDeath(); };
	static void RestartWave() { Instance().privRestartWave(); };
	static void IncrementSegmentNum(int numAdded) { Instance().privIncrementSegmentNum(numAdded); }; // called by factories
	static void DecrementSegmentNum() { Instance().privDecrementSegmentNum(); };

	static void Terminate();
};

#endif _GameManager