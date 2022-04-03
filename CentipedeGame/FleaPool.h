#ifndef _FleaPool
#define _FleaPool

#include <stack>

// forward declaration
class Flea;

class FleaPool
{
private:
	std::stack<Flea*> recycledItems;

public:
	FleaPool(); // big four
	FleaPool(const FleaPool&) = delete;
	FleaPool& operator=(const FleaPool&) = delete;
	~FleaPool();

	Flea* GetFlea();
	void ReturnFlea(Flea* fleaInstance);
};


#endif _FleaPool
