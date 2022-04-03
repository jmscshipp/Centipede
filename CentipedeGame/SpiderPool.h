#ifndef _SpiderPool
#define _SpiderPool

#include <stack>

// forward declaration
class Spider;

class SpiderPool
{
private:
	std::stack<Spider*> recycledItems;

public:
	SpiderPool(); // big four
	SpiderPool(const SpiderPool&) = delete;
	SpiderPool& operator=(const SpiderPool&) = delete;
	~SpiderPool();

	Spider* GetSpider();
	void ReturnSpider(Spider* spiderInstance);
};


#endif _SpiderPool
