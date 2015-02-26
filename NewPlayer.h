#pragma once
#include "Menu.h"
#include "gamestate.h"
#include "Graphics.h"

class NewPlayer : public Menu
{

public:
	
	NewPlayer(GameState*);
	

private:
	sf::Image imgTextField;
	sf::Texture TextField;
	sf::Sprite spriteTextField;
	sf::Text EnterPlaerName;
	sf::Text EnteredText;

protected:

	void update(float);
	void draw();
	void eventProc(sf::Event);
	
	void setTexts();
	void setTexures();
	void setImages();
	void setSprites();
	
};
