#ifndef _Player
#define _Player

// forward declaration
class MushroomField;

class Player
{
public:
	Player(); // big four
	Player(const Player&) = delete;
	Player& operator = (const Player&) = delete;
	~Player();

	MushroomField* GetMushrooomField();
	int GetWaveNum(); // called by wavemanager
	void IncrementWaveNum();
	void AddToScore(int val);
	int GetScore();

	// called by gamemanager
	void Initialize();
	int LoseLife(); // returns remaining health

private:
	int score;
	int life;
	int waveNum;
	MushroomField* myMushroomField;
};

#endif _Player