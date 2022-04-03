#ifndef _AttractorInput
#define _AttractorInput

#include "TEAL/CommonElements.h"

// forward declaration
class MainScene;

class AttractorInput : public GameObject
{
public:
	AttractorInput(); // big four
	AttractorInput(const AttractorInput&) = delete;
	AttractorInput& operator = (const AttractorInput&) = delete;
	~AttractorInput();

	virtual void Destroy();

private:
	MainScene* nextScene;
	void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};

#endif _AttractorInput