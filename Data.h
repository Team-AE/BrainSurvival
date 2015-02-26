#include <string>
#include <vector>

class Player
{
private:
	std::string name;
	int score;
public:
	
	Player(std::string n="NuN", int i=-1) : name(n), score(i){};
	int get_score() const { return score; }
	std::string get_name() const { return name; }
	void set_score(int i){ score = i; }
	void set_name(std::string n){ name = n; }
};

class Data
{
private:
	
	static const std::string FILE_B;
	static Data p_Data;
	Player pl;
	Data(){};
	Data(const Data&);
	Data& operator=(Data&);
public:
	int get_pl_score() const { return pl.get_score(); }
	std::string get_pl_name() const { return pl.get_name(); }
	void set_pl_score(int i){return pl.set_score(i); }
	void set_pl_name(std::string n){return pl.set_name(n); }

	void set_board();
	std::vector<Player> get_board();

	static Data & instance() 
	{
		static Data p_Data;
		return p_Data;
	}
};
