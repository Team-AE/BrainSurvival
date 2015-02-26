#pragma once
#include "Menu.h"
#include "gamestate.h"
#include "Graphics.h"

class NewPlayer : public Menu
{

public:
	
	NewPlayer(GameState*);

protected:
	void update(float);
	void draw();
	void eventProc(sf::Event);
};
