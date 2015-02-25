#include <iostream>
#include <fstream>
#include "Data.h"

Data* Data::p_Data = 0;

const std::string Data::FILE_B = "Board.txt";
//const char Data::FILE_B[] = { "Board.txt\0" };
//'B','o','a','r','d','.','t','x','t','\0'
bool Data::set_board(const Player & pl)
{
	std::ofstream file;
	file.open(FILE_B);
	if (!file.is_open())
	{
		std::cout << "Could not open the file " << FILE_B << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string n;
	//getline(file, n);
	while (n != "\0")
	{
		//getline(file, n);
	}
	file.close();
}
std::vector<Player> Data::get_board()
{
	using std::string;
	std::ifstream file;
	file.open(FILE_B);
	if (!file.is_open())
	{
		std::cout << "Could not open the file " << FILE_B << std::endl;
		exit(EXIT_FAILURE);
	}
	std::vector<Player> mass(10);
	std::string n;
	int s;
	for (int i = 0; i < 10 && file; i++)
	{
		getline(file, n);
		mass[i].set_name(n);
		file >> s;
		mass[i].set_score(s);
		file.get();
	}
	file.close();
	return mass;
}
