#ifndef _HUDManager
#define _HUDManager

// forward declaration
class CurrentScoreText;
class PlayerLifeText;
class ScoreText;
//class HighScoreManager;

class HUDManager
{
private:
	static HUDManager* instance;

	HUDManager(); // big four
	HUDManager(const HUDManager&) = delete;
	HUDManager& operator=(const HUDManager&) = delete;
	~HUDManager() = default;

	static HUDManager& Instance()
	{
		if (!instance)
			instance = new HUDManager;
		return *instance;
	};

	//HighScoreManager* scoreManager;

	//ScoreText* highScores[10];
	CurrentScoreText* currentScore;
	PlayerLifeText* playerLife;
	void privInitialize(); // reset to start values
	void privUpdateCurrentScore(int val);
	void privUpdatePlayerLife(int val);

	//void privShowHighScores();
	//void privHideHighScores();

public:
	static void Initialize() { Instance().privInitialize(); };
	static void UpdateCurrentScore(int addedVal) { Instance().privUpdateCurrentScore(addedVal); };
	static void UpdatePlayerLife(int newVal) { Instance().privUpdatePlayerLife(newVal); };

	//static void ShowHighScores() { Instance().privShowHighScores(); };
	//static void HideHighScores() { Instance().privHideHighScores(); };

	static void Terminate();
};

#endif _HUDManager