#include "WaveManager.h"
#include "CentipedeSpawner.h";
#include "SoloCentipedeHeadSpawner.h";
#include "FleaSpawner.h";
#include "SpiderSpawner.h";
#include "ScorpionSpawner.h";
#include "PlayerManager.h"
#include "Player.h"
#include "MushroomField.h"
#include <fstream>

CentipedeSpawner* WaveManager::myCentipedeSpawner = nullptr;
SoloCentipedeHeadSpawner* WaveManager::mySoloCentipedeHeadSpawner = nullptr;
FleaSpawner* WaveManager::myFleaSpawner = nullptr;
SpiderSpawner* WaveManager::mySpiderSpawner = nullptr;
ScorpionSpawner* WaveManager::myScorpionSpawner = nullptr;

WaveManager::WaveManager()
{
	LoadWaveData();
}

void WaveManager::Initialize()
{
	mySpiderSpawner = new SpiderSpawner();
	myScorpionSpawner = new ScorpionSpawner();
	myFleaSpawner = new FleaSpawner(this);
	myCentipedeSpawner = new CentipedeSpawner();
	mySoloCentipedeHeadSpawner = new SoloCentipedeHeadSpawner();
	fleaCanSpawn = true;
	currentMushroomCount = 0;
}

void WaveManager::DisableSpawners()
{
	mySpiderSpawner->Disable();
	myScorpionSpawner->Disable();
	myFleaSpawner->Disable();
}

FleaSpawner* WaveManager::GetFleaSpawner() // called by player when mushroomfield is created to send ref
{
	return myFleaSpawner;
}

void WaveManager::UpdateMushroomCount(int newCount) // called by mushroom field
{
	currentMushroomCount = newCount;
	if (currentMushroomCount < myFleaSpawner->GetMushroomThreshold() && fleaCanSpawn)
	{
		myFleaSpawner->SpawnFlea();
		fleaCanSpawn = false;
	}
}

void WaveManager::FleaReturned() // called by flea when it dies
{
	fleaCanSpawn = true;
	UpdateMushroomCount(currentMushroomCount); // doesn't change value but rechecks if it's time to spawn again
}

void WaveManager::LoadWaveData() // loads wave data from text file into wave array
{
	std::ifstream waveDataFile;
	std::string nonDataLine;
	WaveData newWave;
	waveDataFile.open("resources\\wave_data.txt");

	int waveNum = 0; // current wave being edited

	while (!waveDataFile.eof())
	{
		waveDataFile >> nonDataLine;

		if (nonDataLine == "WAVE") // changes wave we're editing
		{
			waveDataFile >> waveNum;
			waveNum--; // since index starts at 0
		}
		if (nonDataLine == "mainCentipedeLength")
			waveDataFile >> newWave.mainCentiLength;
		else if (nonDataLine == "mainCentipedeSpeed")
			waveDataFile >> newWave.mainCentiSpeed;
		else if (nonDataLine == "soloCentipedeCount")
			waveDataFile >> newWave.soloCentiCount;
		else if (nonDataLine == "soloCentipedeSpeed")
			waveDataFile >> newWave.soloCentiSpeed;
		else if (nonDataLine == "fleaOn(1=true/false=0)")
			waveDataFile >> newWave.fleaOn;
		else if (nonDataLine == "fleaMushroomTriggerNumber")
			waveDataFile >> newWave.fleaMushTriggerNum;
		else if (nonDataLine == "fleaMushroomSpawnChance")
			waveDataFile >> newWave.fleaMushSpawnChance;
		else if (nonDataLine == "scorpionOn(1=true/false=0)")
			waveDataFile >> newWave.scorpOn;
		else if (nonDataLine == "scorpionSpeed")
			waveDataFile >> newWave.scorpSpeed;
		else if (nonDataLine == "scorpionSpawnRate")
			waveDataFile >> newWave.scorpSpawnRate;
		else if (nonDataLine == "spiderOn(1=true/false=0)")
			waveDataFile >> newWave.spiderOn;
		else if (nonDataLine == "spiderSpeed")
			waveDataFile >> newWave.spiderSpeed;
		else if (nonDataLine == "spiderSpawnRate")
			waveDataFile >> newWave.spiderSpawnRate;
		else if (nonDataLine == "ENDWAVE")
			waves[waveNum] = newWave;
	 }
	waveDataFile.close();
}

void WaveManager::StartNewWave()
{
	mySpiderSpawner->Enable();
	myScorpionSpawner->Enable();
	myFleaSpawner->Enable();
	int currentWave = PlayerManager::GetCurrentPlayer()->GetWaveNum();
	Trace::out("starting wave %d\n", currentWave);
	mySpiderSpawner->SetValues(waves[currentWave].spiderOn, waves[currentWave].spiderSpeed, waves[currentWave].spiderSpawnRate);
	myScorpionSpawner->SetValues(waves[currentWave].scorpOn, waves[currentWave].scorpSpeed, waves[currentWave].scorpSpawnRate);
	myFleaSpawner->SetValues(waves[currentWave].fleaOn, waves[currentWave].fleaMushTriggerNum, waves[currentWave].fleaMushSpawnChance);
	mySoloCentipedeHeadSpawner->SetValues(waves[currentWave].soloCentiSpeed, waves[currentWave].soloCentiCount);
	myCentipedeSpawner->SetValues(waves[currentWave].mainCentiSpeed, waves[currentWave].mainCentiLength);
}

WaveManager::~WaveManager()
{

}

