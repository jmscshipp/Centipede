#include "MushroomField.h"
#include "MushroomFactory.h"
#include "GameSettings.h"
#include "FleaSpawner.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBody.h"
#include "GameManager.h"
#include "WaveManager.h"
#include "SoundManager.h"

MushroomField::MushroomField()
{
	tileSize = GameSettings::TILESIZE;
	gridWidth = GameSettings::GRIDWIDTH;
	gridHeight = GameSettings::GRIDHEIGHT;
	mushTotalCount = 0;
	mushInPSpaceCount = 0;
	theWaveManager = GameManager::GetWaveManager();

	for (int i = 0; i < gridWidth; i++) // reset grid to all empty (false)
	{
		for (int j = 0; j < gridHeight; j++)
			grid[i][j] = nullptr;
	}

	srand((unsigned int)time(NULL)); // random seed scramble
	for (int i = 0; i < GameSettings::SPAWNSIZE; i++)
	{
		int xTemp = rand() % gridWidth;
		int yTemp = rand() % gridHeight;

		// if spot is already taken, is in the first 3 rows, the last row, or is in the playerspace when the max has been reached, reroll
		if (grid[xTemp][yTemp] != nullptr || yTemp < GameSettings::TOPSPACESIZE || yTemp == gridHeight - 1 || (yTemp >= gridHeight - GameSettings::PSPACESIZE - 1 && mushInPSpaceCount >= GameSettings::MUSHINPSPACE))
			i--;
		else
			PlaceMushroom(sf::Vector2i(xTemp, yTemp));
	}
	theWaveManager->FleaReturned(); // cheating to set canSpawn to true for flea only after field is made
}

void MushroomField::TurnInvisible() // TEMPORARY FUNCTION FOR TESTING
{
	for (int i = 0; i < gridWidth; i++) 
	{
		for (int j = 0; j < gridHeight; j++) // turn every mushroom invisible
			if (grid[i][j] != nullptr)
				grid[i][j]->TurnInvisible();
	}
}

void MushroomField::TurnVisible() // TEMPORARY
{
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++) // turn every mushroom visible
			if (grid[i][j] != nullptr)
				grid[i][j]->TurnVisible();
	}
}

sf::Vector2i MushroomField::WorldToGrid(sf::Vector2i pos) // converts a position from screen pixels to our grid units
{
	return sf::Vector2i((pos.x - tileSize / 2) / tileSize, (pos.y - tileSize / 2) / tileSize);
}

sf::Vector2i MushroomField::GridToWorld(sf::Vector2i pos) // converts a position from grid units to screen pixels
{
	return sf::Vector2i(pos.x * tileSize + tileSize / 2, pos.y * tileSize + tileSize / 2);
}

MushroomField::ObstacleStatus MushroomField::CheckGridObstacle(sf::Vector2i pos) // called by centipede to see if it needs to turn, pos passed in world space
{
	sf::Vector2i gridLocation = WorldToGrid(pos);
	// if there's a mushroom next tile, or its the left or right side of screen

	if (pos.x <= 0 || gridLocation.x >= gridWidth)
		return MushroomField::ObstacleStatus::HorizontalBounds;
	else if (grid[gridLocation.x][gridLocation.y] != nullptr)
		if (grid[gridLocation.x][gridLocation.y]->GetPoisonStatus())
			return MushroomField::ObstacleStatus::PoisonMushroom;
		else
			return MushroomField::ObstacleStatus::Mushroom;
	return MushroomField::ObstacleStatus::Clear;
}

bool MushroomField::CheckGridVerticalBounds(sf::Vector2i pos, bool checkDir) // called by centi, pos passed in world space, checkDir = true for up, false for down
{
	sf::Vector2i gridLocation = WorldToGrid(pos);

	if (checkDir) // if location is top of player space 
		return gridLocation.y <= gridHeight - GameSettings::PSPACESIZE;
	else // if location is bottom of screen
		return gridLocation.y >= gridHeight;
}

void MushroomField::PlaceMushroom(sf::Vector2i pos) // pos comes in as grid location
{
	if (grid[pos.x][pos.y] != nullptr) return;

	mushTotalCount++;
	sf::Vector2f worldLocation = sf::Vector2f((float)GridToWorld(pos).x, (float)GridToWorld(pos).y);
	if (pos.y >= gridHeight - GameSettings::PSPACESIZE) // if mushroom is in playerspace
	{
		mushInPSpaceCount++;
		theWaveManager->UpdateMushroomCount(mushInPSpaceCount);
		grid[pos.x][pos.y] = MushroomFactory::CreateMushroom(true, worldLocation, this);
	}
	else
		grid[pos.x][pos.y] = MushroomFactory::CreateMushroom(false, worldLocation, this);
}

void MushroomField::RemoveMushroom(bool pSpaceCheck, sf::Vector2i pos) // called by mushroom on death, pos comes in as world coordinates
{
	sf::Vector2i gridLocation = WorldToGrid(pos);

	grid[gridLocation.x][gridLocation.y] = nullptr;
	if (pSpaceCheck)
	{
		mushInPSpaceCount--;
		theWaveManager->UpdateMushroomCount(mushInPSpaceCount);
	}
	mushTotalCount--;
}

void MushroomField::RepairField()
{
	for (int i = 0; i < gridWidth; i++) // go through whole grid to check health
	{
		for (int j = 0; j < gridHeight; j++)
			if (grid[i][j] != nullptr && !grid[i][j]->IsHealthy())
				damagedMushrooms.push(grid[i][j]);
	}
	SetAlarm(1, GameSettings::MUSHREPAIRTIME);
}

void MushroomField::Alarm1()
{
	if (!damagedMushrooms.empty())
	{
		SoundManager::MushBonus();
		damagedMushrooms.front()->Heal();
		damagedMushrooms.pop();
		SetAlarm(1, GameSettings::MUSHREPAIRTIME);
	}
	else
		GameManager::RestartWave();
}

MushroomField::~MushroomField()
{

}

void MushroomField::Destroy()
{

}
