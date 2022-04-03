#ifndef _InputManager
#define _InputManager

#include "TEAL/CommonElements.h"

class BugBlaster;

class InputManager : public GameObject
{
public:
	InputManager(); // big four
	InputManager(const InputManager&) = delete;
	InputManager& operator = (const InputManager&) = delete;
	~InputManager();

	virtual void Update();

protected:
	BugBlaster* player;
};

#endif _InputManager