#include "WindowClass.h"

WindowClass::WindowClass()
{
	InitWindow();
}
//will be writing data to cfg file each time it was called
void WindowClass::UpdateCfg()
{
	in_stream.open(FileTitle);
	if(in_stream.is_open())
	{
		in_stream << titleWidth << winWidth << std::endl << titleHeight << winHeight << std::endl<<titleStyle<<windowStyle<<std::endl;
	}
	in_stream.close();
}

void WindowClass::UpdateWindow()
{
	window->clear(sf::Color::Black);
	window->display();
}

//reading data from cfg file
void WindowClass::InitWindow()
{
	//emplacing window style of our window from file
	winStyle.emplace("FullScreen",sf::Style::Fullscreen);
	winStyle.emplace("Default", sf::Style::Default);

	out_stream.open(FileTitle);
	if (out_stream.is_open()) 
	{
		std::string line;//will be writing data from file here

		while (!out_stream.eof())
		{
			std::getline(out_stream, line);
			if (line.compare(0, titleWidth.length(), titleWidth) == 0)
			{
				ValReader = line.substr(line.find(titleWidth) + titleWidth.length(), 4);
				winWidth = std::stoi(ValReader);
			}
			if (line.compare(0, titleHeight.length(), titleHeight) == 0)
			{
				ValReader = line.substr(line.find(titleHeight) + titleHeight.length(), 4);
				winHeight = std::stoi(ValReader);
			}
			if (line.compare(0, titleStyle.length(), titleStyle) == 0)
			{
				windowStyle = line.substr(line.find(titleHeight) + titleHeight.length(), 20);
			}
		}

	}

	if (!out_stream.is_open())
	{
		//making cfg file and saving default presets
		UpdateCfg();
	}
	out_stream.close();
	window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight),windowTitle,winStyle[windowStyle]);
}
