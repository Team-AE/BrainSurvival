#pragma once
#include<SFML/Graphics.hpp>
#include <vector>

class Graphics 
{
public:
	static Graphics& Instance()
	{
		static Graphics theSingleInstance;
		return theSingleInstance;
	}

	Graphics();

	void update();

	void draw(sf::Sprite&);
	void draw(sf::Text&);
	void onDisplay();
	void windowClear();

	std::vector<sf::Sprite*> Sprites;
	std::vector<sf::Text*> Texts;
	sf::RenderWindow Window;

private:
	
	sf::ContextSettings settings;
	
	const int Widht = 800;
	const int Height = 600;
};


