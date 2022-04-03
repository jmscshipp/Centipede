#include "CommandScoreDistance.h"
#include "ScoreManager.h"

CommandScoreDistance::CommandScoreDistance(int dn, int dm, int df, int vn, int vm, int vf)
	: dNear(dn), dMed(dm), dFar(df), vNear(vn), vMed(vm), vFar(vf), distance(0.0f)
{
	Trace::out("Score by distance command created\n");
	Trace::out("\tdist <= %i  is worth %i points\n", dNear, vNear);
	Trace::out("\tdist <= %i  is worth %i points\n", dMed, vMed);
	Trace::out("\tdist <= %i  is worth %i points\n", dFar, vFar);
}

void CommandScoreDistance::SetDistance(sf::Vector2f playerPos, sf::Vector2f spiderPos)
{
	sf::Vector2f difVect = playerPos - spiderPos;
	distance = std::sqrt(difVect.x * difVect.x + difVect.y * difVect.y);
}

void CommandScoreDistance::Execute()
{
	// processing distance to score:
	if (distance <= dNear)
	{
		Trace::out("\t\tNear range detected:\n");
		ScoreManager::AddScore(vNear);
	}
	else if (distance <= dMed)
	{
		Trace::out("\t\tMedium range detected:\n");
		ScoreManager::AddScore(vMed);
	}
	else
	{
		Trace::out("\t\tFar range detected:\n");
		ScoreManager::AddScore(vFar);
	}
}