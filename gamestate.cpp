#include "GameState.h"
#include <SFML/Graphics.hpp>

const int Widht = 800;
const int Height = 600;

GameState* GameState::run()
{
    activeState = true;
	bool GameState::gameOver = true;
    while(activeState)
    {
//        if(event)
//            eventProc(event); // need know how implemented processing event in SFML
        update(0.0f);
    }
    return nextState;
}
