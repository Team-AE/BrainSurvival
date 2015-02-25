#include <SFML/Graphics.hpp>
#pragma once
class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	
	sf:: RenderWindow window;
	sf::Image img;
	sf::Texture rectangle;
	sf::Sprite player;
	void Update();
	void ProcessEvents(); 
	void KeyPressed();
	void DisplayDraw();
};

