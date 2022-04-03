#include "KeyboardInput.h"
#include "BugBlaster.h"
#include "TEAL/CommonElements.h"
#include "SoundManager.h"

// TEMPORARY FOR DEBUGGING
#include "GameManager.h"

KeyboardInput::KeyboardInput(BugBlaster* playerObject)
{
	player = playerObject;
	RegisterInput(InputFlags::KeyPressed); // Recieve single-presses events
}

KeyboardInput::~KeyboardInput()
{

}

void KeyboardInput::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // might need to correct diagonal speed, we'll see
	{
		player->Move(sf::Vector2i(-1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->Move(sf::Vector2i(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player->Move(sf::Vector2i(0, -1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player->Move(sf::Vector2i(0, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		SoundManager::SwitchSource();
	}

	// TEMPORARY FOR DEBUGGING
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		GameManager::PlayerDeath();
	}
}

void KeyboardInput::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::S)
	{
		player->Shoot();
	}
}

void KeyboardInput::Destroy()
{
	DeregisterInput();
}
