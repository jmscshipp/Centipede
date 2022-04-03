#ifndef _CentipedeBodyPool
#define _CentipedeBodyPool

#include <stack>

// forward declaration
class CentipedeBody;

class CentipedeBodyPool
{
private:
	std::stack<CentipedeBody*> recycledItems;

public:
	CentipedeBodyPool(); // big four
	CentipedeBodyPool(const CentipedeBodyPool&) = delete;
	CentipedeBodyPool& operator=(const CentipedeBodyPool&) = delete;
	~CentipedeBodyPool();

	CentipedeBody* GetCentipedeBody();
	void ReturnCentipedeBody(CentipedeBody* centipedeBodyInstance);
};


#endif _CentipedeBodyPool
