#ifndef _CommandScoreDistance
#define _CommandScoreDistance

#include "CommandScore.h"

class CommandScoreDistance : public CommandScore
{
private:
	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;

	float distance; // between spider and player, set on spider death

public:
	CommandScoreDistance() = delete; // big four
	CommandScoreDistance(int dNear, int dMed, int dFar, int vNear, int vMed, int vFar);
	CommandScoreDistance(const CommandScoreDistance&) = delete;
	CommandScoreDistance& operator = (const CommandScoreDistance&) = delete;
	~CommandScoreDistance() = default;

	virtual void Execute() override;
	virtual void SetDistance(sf::Vector2f playerPos, sf::Vector2f spiderPos) override; // called by spider on death
};

#endif _CommandScoreDistance