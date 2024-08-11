#include "BindReader.h"

#define SUMM_LENGTH(a,b)(a.length()+b.length())

void BindReader::UpdateCfg(std::map<std::string, int> Binds, std::string bindTitle)
{
	in_stream.open(FileTitle);
	if (in_stream.is_open())
	{
		for (const auto& [title, bind] : Binds) 
		{
			in_stream << bindTitle << title << bind << std::endl;
		}
	}
	in_stream.close();
}

void BindReader::ReadCfg(std::map<std::string, int>* Binds, std::string bindTitle)
{
	out_stream.open(FileTitle);
	if (out_stream.is_open())
	{
		std::string line{};//will be writing data from file here
		std::string ValReader{};

		while (!out_stream.eof())
		{
			std::getline(out_stream, line);
				for (auto& [title, bind] : *Binds)
				{
					if (line.compare(0, (bindTitle + title).length(), bindTitle + title) == 0)
					{
						ValReader = line.substr(line.find(bindTitle + title) + SUMM_LENGTH(bindTitle, title), 3);
						Binds->at(title) = std::stoi(ValReader);
					}
					//finally working
				}
		}

	}

	if (!out_stream.is_open())
	{
		UpdateCfg(*Binds, bindTitle);
	}

	out_stream.close();
}