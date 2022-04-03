#ifndef _CommandScore
#define _CommandScore

#include "TEAL/CommonElements.h"

class CommandScore
{
public:
	CommandScore() = default; // big four
	CommandScore(const CommandScore&) = delete;
	CommandScore& operator = (const CommandScore&) = delete;
	~CommandScore() = default;

	virtual void Execute() = 0;
	virtual void SetDistance(sf::Vector2f playerPos, sf::Vector2f spiderPos) = 0; // this is only used by commandScoreDistance but needs to be part of parent class
};

#endif _CommandScore