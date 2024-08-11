#include "MainMenuState.h"

MainMenuState::MainMenuState():State()
{	
	this->initMainMenu();
}

void MainMenuState::isKeyPressed(sf::RenderWindow* wind, sf::Event * evnt)
{
	if (evnt->key.code == keyBoard.GetKey("ActionButton="))
		wind->setTitle("ActionButton is Active");
	if (evnt->key.code == keyBoard.GetKey("PauseButton="))
		wind->close();
}

void MainMenuState::isMousePressed(sf::RenderWindow* wind, sf::Event* evnt)
{
	
}

void MainMenuState::isGamePadButtonPressed(sf::RenderWindow* wind, sf::Event* evnt)
{

}

void MainMenuState::initMainMenu()
{

}
