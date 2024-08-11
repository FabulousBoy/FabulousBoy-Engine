#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

//sfml includes
#include "SFML/Graphics/RenderWindow.hpp"
//features includes
#include <fstream>
#include <map>
class WindowClass
{
public:
	//constructor and destructor
	WindowClass();
	~WindowClass() 
	{
		UpdateCfg();
		delete window;
	}
	void UpdateCfg();

	//returns window for more interactions between classes
	sf::RenderWindow* getWindow()
	{
		return window;
	}
	void UpdateWindow();
private:
	//functions
	void InitWindow();
	//values
	sf::RenderWindow *window;
	int winWidth = 640;//default window width is 640
	int winHeight = 480;//default window height is 480
	std::string windowStyle{"Default"};
	std::string windowTitle{ "Fabulous Boy Engine" };//title of our window

	std::string ValReader{};//value to get and transfer data from line to values

	std::string FileTitle{ "WinConfig.cfg" };//title for window cfg
	std::string titleWidth{ "Window_Width=" };//title for window width
	std::string titleHeight{ "Window_Height=" };//title for window height
	std::string titleStyle{"Window_Style="};//title for window style

	std::ofstream in_stream;//wiritng down the data
	std::ifstream out_stream;//reading data from file

	std::map < std::string, int > winStyle;
};

#endif