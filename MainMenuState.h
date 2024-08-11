#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "State.h"

class MainMenuState:public State
{
public:
	MainMenuState();
	void isKeyPressed(sf::RenderWindow* wind, sf::Event* evnt) override;
	void isMousePressed(sf::RenderWindow* wind, sf::Event* evnt) override;
	void isGamePadButtonPressed(sf::RenderWindow* wind, sf::Event* evnt) override;
private:
	void initMainMenu();
};

#endif