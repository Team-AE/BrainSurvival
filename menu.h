#ifndef MENU_H
#define MENU_H
#include "gamestate.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "NewPlayer.h"

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
	sf::Image imgBackgound;
	sf::Texture Backgound;
	sf::Sprite SpriteBackground;

private:
	sf::Image imgButton;
	sf::Texture Button;
	sf::Text* buttom_text;
	sf::Text textMenu;
	sf::Sprite* SpriteButton;
	
	sf::Font font;

	void setTexts();
	void setTexures();
	void setImages();
	void setSprites();
	void nextText();
	void buttonClick();
	void enterNamePlayer();
};


#endif // MENU_H
