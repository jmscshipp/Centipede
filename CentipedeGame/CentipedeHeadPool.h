#ifndef _CentipedeHeadPool
#define _CentipedeHeadPool

#include <stack>

// forward declaration
class CentipedeHead;

class CentipedeHeadPool
{
private:
	std::stack<CentipedeHead*> recycledItems;

public:
	CentipedeHeadPool(); // big four
	CentipedeHeadPool(const CentipedeHeadPool&) = delete;
	CentipedeHeadPool& operator=(const CentipedeHeadPool&) = delete;
	~CentipedeHeadPool();

	CentipedeHead* GetCentipedeHead();
	void ReturnCentipedeHead(CentipedeHead* centipedeHeadInstance);
};


#endif _CentipedeHeadPool
