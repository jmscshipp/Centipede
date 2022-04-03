#ifndef _GameSettings
#define _GameSettings

class GameSettings
{
public:
	GameSettings() {}; // big four
	GameSettings(const GameSettings&) = delete;
	GameSettings& operator = (const GameSettings&) = delete;
	~GameSettings() {};

	// grid manager settings
	static const int TILESIZE = 16;  // number of pixels per tile
	static const int SPAWNSIZE = 45; // number of mushrooms spawned at start
	static const int TOPSPACESIZE = 3; // area at the top of the screen where mushrooms don't spawn at start
	static const int PSPACESIZE = 6; // height of playerspace at bottom of screen
	static const int MUSHINPSPACE = 5; // number of mushrooms spawned in playerspace at start

	static const int GRIDWIDTH = 30;
	static const int GRIDHEIGHT = 32;

	// player settings
	static const int PLAYERSTARTHEALTH = 2;

	// bug blaster settings
	static constexpr int PLAYERSPEED = 3; // movement speed of player
	static constexpr float PLAYERFRICTION = 0.5f; // friction applied to force on player

	// bullet settings
	static const int BULLETSPEED = 15; // speed of bullet

	// mushroom settings
	static const int SHROOMHEALTH = 4;
	static constexpr float MUSHREPAIRTIME = 0.2f; // time inbetween mushrooms being repaired by field

	// flea settings
	static const int FLEAHEALTH = 2;
	static const int FLEASPEED = 5;

	// scorpion settings
	static const int SCORPHEALTH = 1;

	// spider settings
	static const int SPIDERHEALTH = 1;
	
	// centipede settings
	static const int FRAMESPERTILE = 8; // how many frames it takes for centi to traverse a tile
};

#endif _GameSettings