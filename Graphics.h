#pragma once
#include<SFML/Graphics.hpp>

class Graphics 
{
public:
	static const Graphics& Instance()
	{
		static Graphics theSingleInstance;
		return theSingleInstance;
	
	}
private:

	Graphics();

	void update();
	void WindowRun();

	void draw(sf::Sprite);
	void draw(sf::Text);
	void onDisplay();

	sf::RenderWindow Window;
	sf::ContextSettings settings;
	
	const int Widht = 800;
	const int Height = 600;
};