#include "gamemode.h"
#include <iostream>
#include "Graphics.h"

GameMode::GameMode(GameState* parent)
{
    nextState = parent;
    parent->addChild(this);
}


void GameMode::draw()
{
   std::cout << "Game: here performed physical computations and graphics refresh." << std::endl;
}


void GameMode::update(float)
{
    static int count = 0;

	gameOver = true;

    if(count > 3)
        activeState = false;
    else
    {
        draw();
        ++count;
    }
}


void GameMode::eventProc(sf::Event)
{
	while (Graphics::Instance().Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			Graphics::Instance().Window.close();
	}
}
