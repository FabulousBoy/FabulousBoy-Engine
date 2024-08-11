#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"

#include "KeyboardBindings.h"
//TO DO: will rewrite it into abstract class so there will be a class for KeyBoard Keys and GamePad Buttons

class State
{
public:
	//will be checking if jey is pressed
	virtual void isKeyPressed(sf::RenderWindow* wind, sf::Event* evnt) = 0;
	//will check if mouse button pressed
	virtual void isMousePressed(sf::RenderWindow* wind, sf::Event* evnt) = 0;
	//will chek if gamepad button pressed
	virtual void isGamePadButtonPressed(sf::RenderWindow* wind, sf::Event* evnt) = 0;
protected:
	KeyboardBindings keyBoard;
};

#endif