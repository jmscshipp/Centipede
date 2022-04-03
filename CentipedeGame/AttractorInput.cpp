#include "AttractorInput.h"
#include "BugBlaster.h"
#include "TEAL/CommonElements.h"
#include "GameManager.h"
#include "MainScene.h"

AttractorInput::AttractorInput()
{
	RegisterInput(InputFlags::KeyPressed); // Recieve single-presses events
}

AttractorInput::~AttractorInput()
{

}

void AttractorInput::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::Enter)
		SceneManager::ChangeScene(new MainScene());
}

void AttractorInput::Destroy()
{
	DeregisterInput();
}
