#ifndef _MushroomField
#define _MushroomField

#include "TEAL/CommonElements.h"
#include "Mushroom.h"
#include "GameSettings.h"
#include <queue>

// forward declaration
class WaveManager;

// mushroomfield is created by Player
// inherits from gameobject so it can use alarms
class MushroomField : public GameObject
{
public:
	MushroomField(); // big four
	MushroomField(const MushroomField&) = delete;
	MushroomField& operator = (const MushroomField&) = delete;
	~MushroomField();

	enum class ObstacleStatus { PoisonMushroom, Mushroom, HorizontalBounds, Clear };

	ObstacleStatus CheckGridObstacle(sf::Vector2i location); // called by centipede states
	bool CheckGridVerticalBounds(sf::Vector2i location, bool checkDir); // called by centipede states

	void PlaceMushroom(sf::Vector2i location); // called by flea
	void RemoveMushroom(bool pSpaceCheck, sf::Vector2i location); // called by mushroom to remove itself

	sf::Vector2i WorldToGrid(sf::Vector2i pos); // public to be used by flea and centi to spawn shrooms
	sf::Vector2i GridToWorld(sf::Vector2i pos);

	void TurnInvisible(); // TEMPORARY FOR TESTING
	void TurnVisible(); // TEMPORARY

	void RepairField();
	virtual void Destroy();

private:
	int tileSize;
	Mushroom* grid[GameSettings::GRIDWIDTH][GameSettings::GRIDHEIGHT]; // each cell is nullptr or has a reference to a shroom
	int mushTotalCount;
	int mushInPSpaceCount; // keeps track of # of mush currently in playerspace

	int gridWidth; // saved to store value from game settings
	int gridHeight; // saved to store value from game settings

	std::queue<Mushroom*> damagedMushrooms;
	virtual void Alarm1();
	WaveManager* theWaveManager;
};

#endif _MushroomField