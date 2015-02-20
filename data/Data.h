#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace Data
{
	class Map
	{
	private:
		static const std::string NAME_OF_FILE;
		const int number_of_map; //first, second, ...
		std::vector<sf::String> map;
	public:
		Map();
		Map(int nom);
		int get_height()const { return map.size(); };
		unsigned int get_length()const { return map[0].getSize(); };
		void show() const;
		const sf::String & operator [] (int i) const;
		sf::String & operator[](int i);
		//bool delete_map(int i);
	};

	class Player
	{
	private:
		std::string name;
		int score;
	public:
		Player(std::string n="NuN", int i=-1) : name(n), score(i){};
		int get_score() const { return score; }
		std::string get_name() const { return name; }
		bool set_score(int i){ score = i; }
	};
}
