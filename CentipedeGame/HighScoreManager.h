#ifndef _HighScoreManager
#define _HighScoreManager

class HighScoreManager
{
private:
	int scores[10];

public:
	HighScoreManager(); // big four
	HighScoreManager(const HighScoreManager&) = delete;
	HighScoreManager& operator=(const HighScoreManager&) = delete;
	~HighScoreManager() = default;

	int GetScoreAt(int i);
	int GetHighestScore();
	void AddNewScore(int newScore);
};

#endif _HighScoreManager