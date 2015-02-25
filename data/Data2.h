#include <SFML/Graphics.hpp>
#include <string>
#include <vector>



typedef std::vector<sf::Vector2f *> Map;
class Player
{
private:
	std::string name;
	int score;
public:
	//Player(){};
	Player(std::string n="NuN", int i=-1) : name(n), score(i){};
	int get_score() const { return score; }
	std::string get_name() const { return name; }
	void set_score(int i){ score = i; }
	void set_name(std::string n){ name = n; }
};

class Data
{
private:
	//static const char FILE_B[11] ;
	static const std::string FILE_B;
	static Data * p_Data;
	Player pl;
	Data(){};
	Data(const Data&);
	Data& operator=(Data&);
public:
	int get_pl_score() const { return pl.get_score(); }
	std::string get_pl_name() const { return pl.get_name(); }
	void set_pl_score(int i){return pl.set_score(i); }
	void set_pl_name(std::string n){return pl.set_name(n); }

	bool set_board(const Player & pl);
	std::vector<Player> get_board();

	static Data * instance() {
		if (!p_Data)
			p_Data = new Data();
		return p_Data;
	}
};
