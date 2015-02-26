#include <iostream>
#include <fstream>
#include "Data.h"

//Data Data::p_Data = 0;

const std::string Data::FILE_B = "Board.txt";
//const char Data::FILE_B[] = { "Board.txt\0" };
//'B','o','a','r','d','.','t','x','t','\0'

void Data::set_board(const Player & pl)
{
	std::vector<Player> n = get_board();
	if (n.size() <= 0)n.push_back(pl);
	else {
		
		for (int i = 0; i < n.size(); i++)
		{
			if (n[i].get_name() == pl.get_name() && n[i].get_score() <= pl.get_score())
			{
				n.erase(n.begin() + i);
				break;
			}
			else if (n[i].get_name() == pl.get_name() && n[i].get_score() > pl.get_score())
			{
				break;
			}
		}
		
		for (int i = 0; i < n.size(); i++)
		{
			if (pl.get_score() > n[i].get_score())
			{
				n.insert((n.begin()+i),pl);
				break;
			}
			else if (pl.get_score() == n[i].get_score())
			{
				n.insert((n.begin() + i), pl);
				break;
			}
			else if (pl.get_score() < n[i].get_score() && i == n.size()-1 && i < 9)
			{
				n.push_back(pl);
				break;
			}
		}
	}

	std::ofstream file1(FILE_B, std::ios::out);
	std::ofstream file;
	file.open(FILE_B);
	if (!file.is_open())
	{
		std::cout << "Could not open the file " << FILE_B << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n.size(); i++)
	{
		file << n[i].get_name()<<"\n";
		file << n[i].get_score()<< "\n";
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
	std::vector<Player> mass;
	std::string n;
	int s;

	for (int i = 0; i < 10 && file; i++)
	{
		getline(file, n);
		if (n == "\0") break;
		file >> s;
		mass.push_back(Player(n, s));
		file.get();
	}
	file.close();
	return mass;
}
