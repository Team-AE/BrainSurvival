#ifndef MENU_H
#define MENU_H
#include "gamestate.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Menu : public GameState
{
    std::vector<GameState*> children;
	

public:
    void addChild(GameState*);
	Menu();

protected:
    void update(float);
    void draw();
    void eventProc(sf::Event);

	sf::Image imgButton, imgBackgound;
	sf::Texture Backgound, Button;
	sf::Text* buttom_text;
	sf::Text textMenu;
	sf::Sprite* SpriteButton;
	sf::Sprite SpriteBackground;
	sf::Font font;
};

#endif // MENU_H
