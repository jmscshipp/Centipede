// WindowManager.cpp
// Andre Berthiaume, June 2012
// July 2019: memory clean up
//
// General Window controls and settings
// (Future versions will include View managements as well)

#include "WindowManager.h"

WindowManager* WindowManager::windowInstance = NULL;

WindowManager::WindowManager()
{
	windowWidth = 480;
	windowHeight = 512;
	windowCaption = "Centipede";
	backgroundColor = sf::Color::Black;
	captionMsg = "";
}

void WindowManager::Initialize()
{
	Instance().MainWindow.create( sf::VideoMode( Instance().windowWidth, Instance().windowHeight), Instance().windowCaption + ": " + Instance().captionMsg );
	Instance().MainWindow.setKeyRepeatEnabled(false);
	Instance().MainWindow.setFramerateLimit(60);
	Instance().MainWindow.setMouseCursorVisible(true);
}

void WindowManager::SetWindowSize(int widthinPx, int heightInPx) 
{ 
	Instance().windowWidth = widthinPx; 
	Instance().windowHeight = heightInPx; 
	Instance().MainWindow.setSize( sf::Vector2u(widthinPx,heightInPx) );
	Instance().MainWindow.setView(sf::View( sf::FloatRect(0, 0, (float) widthinPx, (float) heightInPx)));
}


void WindowManager::Terminate()
{
	Instance().MainWindow.close();
	delete windowInstance;
}

void WindowManager::Clear()
{
	Instance().MainWindow.clear(Instance().backgroundColor);
}

void WindowManager::Display()
{
	Instance().MainWindow.display();
}



