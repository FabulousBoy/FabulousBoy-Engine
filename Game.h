#ifndef GAME_H
#define GAME_H

#include "WindowClass.h"
#include "MainMenuState.h"

#include <stack>

class Game
{
public:
	//constructor and destructor
	Game();
	~Game();
	//functions
	void runGame();
private:
	//functions
	void initGame();
	void updateGame();
	//value
	WindowClass window;
	sf::Event event;

	std::stack<State*>CurrentState;//will be managing our states
};

#endif