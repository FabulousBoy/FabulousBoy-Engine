#include "Game.h"

Game::Game()
{
	initGame();
}

Game::~Game()
{
	//will pay more attention latter
	delete CurrentState.top();
}

void Game::runGame()
{
	while (window.getWindow()->isOpen())
	{
		if(!CurrentState.empty())
			while (window.getWindow()->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					//will be checking if window closed
					window.getWindow()->close();
				}

				if (sf::Event::KeyPressed)
				{
					//will be checking if key was pressed
					CurrentState.top()->isKeyPressed(window.getWindow(), &event);
				}
				if (sf::Event::JoystickButtonPressed)
				{
					//will check if gamepad button was pressed
					CurrentState.top()->isGamePadButtonPressed(window.getWindow(), &event);
				}
				if (sf::Event::MouseButtonPressed)
				{
					//will check if mouse button pressed
					CurrentState.top()->isMousePressed(window.getWindow(), &event);
				}

				if (sf::Event::JoystickConnected | sf::Event::JoystickButtonPressed | sf::Event::JoystickMoved)
				{
					//will be checking if gamepad conected or you've pressed any buttons on it or moved one of the sticks
					//window.getWindow()->close();
				}
				if (sf::Event::KeyPressed | sf::Event::MouseButtonPressed | sf::Event::MouseMoved)
				{
					//will check if some action like this happend(like key presed or some action with mouse done) 
				}

			}
			updateGame();
	}
}

void Game::initGame()
{
	CurrentState.push(new MainMenuState);
}

void Game::updateGame()
{
	window.UpdateWindow();
}
