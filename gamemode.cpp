#include "gamemode.h"
#include <iostream>

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
}
