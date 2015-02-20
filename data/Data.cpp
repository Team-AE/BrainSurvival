#include <fstream>
#include <iostream>
#include "Data.h"

const std::string Data::Map::NAME_OF_FILE = "Maps.txt";

Data::Map::Map() : number_of_map(0), map(0)
{
	std::cout << "Fatal error. Don't use default constructor of Map\n";
	std::abort();
}

Data::Map::Map(int nom) : number_of_map(nom)
{
	std::ifstream file;
	file.open(NAME_OF_FILE.c_str());
	if (!file.is_open()) 
	{
		std::cout << "Could not open the file " << NAME_OF_FILE << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string n;
	getline(file, n);
	while (n!="\0")
	{
		map.push_back(n);
		getline(file, n);
	}
	file.close();
}

void Data::Map::show()const
{
	for (unsigned int i = 0; i < map.size(); i++)
	{
		for (unsigned int j = 0; j < map[0].getSize(); j++)
		{
			std::cout << (char)map[i][j];
		};
		std::cout << "\n";
	};
}

sf::String & Data::Map::operator [] (int i)
{
	if (0>i || get_height() <= i)
	{
		std::cout << "Fatal error. Get correct map[index]\n";
		std::abort();
	}
return map[i];
};

const sf::String & Data::Map::operator [] (int i) const
{
	if (0>i || get_height() <= i)
	{
		std::cout << "Fatal error. Get correct map[index]\n";
		std::abort();
	}
	return map[i];
};
