#ifndef _AttractorScene
#define _AttractorScene
#include "TEAL\CommonElements.h"

// forward declaration
class AttractorInput;

class AttractorScene : public Scene
{
public:
	virtual void Initialize();
	virtual void Terminate();

private:
	AttractorInput* input;
};

#endif _AttractorScene