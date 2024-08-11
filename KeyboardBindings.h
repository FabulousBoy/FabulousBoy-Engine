#ifndef KEYBOARD_BINDS_H
#define KEYBOARD_BINDS_H

#include "BindReader.h"

class KeyboardBindings
{
public:
	KeyboardBindings();
	~KeyboardBindings() 
	{
		UpdateKeys();
	}
	int GetKey(std::string keyTitle);
	//updates key binds
	void UpdateKeys();
private:
	//map
	std::map<std::string, int> KeyBoardMap
	{
		{"ActionButton=",sf::Keyboard::Key::E},//default action button
		{"PauseButton=",sf::Keyboard::Key::Escape}//default pause button
	};
	//functions
	void initKeyBoard();
	std::string BindTitle{"[Keyboard_Keys]"};
};

#endif