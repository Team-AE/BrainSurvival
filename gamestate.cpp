#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Graphics.h"

bool GameState::gameOver = true;
sf::Event GameState::event;

GameState* GameState::run()
{
    activeState = true;
	gameOver = true; 

    while(activeState)
    {
		eventProc(event); // need know how implemented processing event in SFML

        update(0.0f);
    }
    return nextState;
}
