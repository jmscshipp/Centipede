#ifndef _CommandScoreValue
#define _CommandScoreValue

#include "CommandScore.h"

class CommandScoreValue : public CommandScore
{
protected:
	int points;	// points to add

public:
	CommandScoreValue() = delete; // big four
	CommandScoreValue(int val);
	CommandScoreValue(const CommandScoreValue&) = delete;
	CommandScoreValue& operator = (const CommandScoreValue&) = delete;
	~CommandScoreValue() = default;

	virtual void Execute() override;
	virtual void SetDistance(sf::Vector2f playerPos, sf::Vector2f spiderPos) override {}; // not used here
};

#endif _CommandScoreValue