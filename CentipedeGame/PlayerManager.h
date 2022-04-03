#ifndef _PlayerManager
#define _PlayerManager

//forward declaration
class Player;
class BugBlaster;
class InputManager;

#include "TEAL/CommonElements.h"

class PlayerManager
{
private:
	static PlayerManager* instance; // set up as singleton

	PlayerManager(); // big four
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator=(const PlayerManager&) = delete;
	~PlayerManager();

	static PlayerManager& Instance()
	{
		if (!instance)
			instance = new PlayerManager();
		return *instance;
	};

	BugBlaster* blaster;
	InputManager* blasterControl; // going to be keyboard, AI, etc

	Player* currentPlayer;
	Player* player1;

	void privSwap();
	Player* privGetCurrentPlayer();
	void privWaveComplete();
	
	// accessing bugblaster
	sf::Vector2f privGetBlasterPos();
	void privResetBlaster();
	void privLockBlaster(); // called during mushroom roundup to prevent shooting

	int privPlayerLoseHealth();

	void privInitialize();

public:
	static void Initialize() { Instance().privInitialize(); };
	static void Swap() { Instance().privSwap(); };
	static Player* GetCurrentPlayer() { return Instance().privGetCurrentPlayer(); };
	static void WaveComplete() { Instance().privWaveComplete(); }; // called by gamemanager
	
	static sf::Vector2f GetBlasterPos() { return Instance().privGetBlasterPos(); }; // called by spider to calculate for score
	static void ResetBlaster() { Instance().privResetBlaster(); };
	static void LockBlaster() { Instance().privLockBlaster(); };
	static int PlayerLoseHealth() { return Instance().privPlayerLoseHealth(); };
	static void Terminate();
};


#endif _PlayerManager