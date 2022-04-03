#ifndef _KeyboardInput
#define _KeyboardInput

#include "TEAL/CommonElements.h"
#include "InputManager.h"

class BugBlaster;

class KeyboardInput : public InputManager
{
public:
	KeyboardInput() = delete; // big four
	KeyboardInput(BugBlaster* playerObject);
	KeyboardInput(const KeyboardInput&) = delete;
	KeyboardInput& operator = (const KeyboardInput&) = delete;
	~KeyboardInput();

	virtual void Update();
	virtual void Destroy();

private:
	void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};

#endif _KeyboardInput