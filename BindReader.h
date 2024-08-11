#ifndef BINDINGS_H
#define BINDINGS_H

//IDEA FROM FRIEND OF MINE:
// 
// WILL probably rewrtite this class into Data class, 
// which will be reading data from config and translating it into 
// Keyboard,mouse, gamepad classes 
// 
//BTW nice idea, because it will be way easier to use keys in main menu cycle

//sfml includes
#include "SFML/Window/Keyboard.hpp"//includes for keyboard
#include "SFML/Window/Joystick.hpp"//includes for gamapd
#include "SFML/Window/Mouse.hpp"//includes for mouse

//featured includes
#include <fstream>
#include <string>
#include <iostream>
#include <map>

class BindReader
{
public:
	//functions
	void UpdateCfg(std::map<std::string, int> Binds,std::string bindTitle);
	void ReadCfg(std::map<std::string, int> *Binds, std::string bindTitle);
private:
	//functions
	//values
	std::ofstream in_stream;//wiritng down the data
	std::ifstream out_stream;//reading data from file

	std::string FileTitle{ "BindingsConfig.cfg" };//title for window cfg
	//void Read_Data(std::map<std::string, int> Binds, std::string bindTitle);
};

#endif