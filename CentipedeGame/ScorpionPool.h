#ifndef _ScorpionPool
#define _ScorpionPool

#include <stack>

// forward declaration
class Scorpion;

class ScorpionPool
{
private:
	std::stack<Scorpion*> recycledItems;

public:
	ScorpionPool(); // big four
	ScorpionPool(const ScorpionPool&) = delete;
	ScorpionPool& operator=(const ScorpionPool&) = delete;
	~ScorpionPool();

	Scorpion* GetScorpion();
	void ReturnScorpion(Scorpion* scorpionInstance);
};


#endif _ScorpionPool
