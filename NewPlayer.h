#pragma once
#include "Menu.h"
#include "gamestate.h"
#include "Graphics.h"

class NewPlayer : public Menu
{
std::vector<GameState*> children;


public:
	void addChild(GameState*);
	NewPlayer();

protected:
	void update(float);
	void draw();
	void eventProc(sf::Event);
};
