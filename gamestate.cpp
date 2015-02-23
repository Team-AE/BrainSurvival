#include "gamestate.h"

GameState* GameState::run()
{
    activeState = true;

    while(activeState)
    {
//        if(event)
//            eventProc(event); // need know how implemented processing event in SFML
        update(0.0f);
    }
    return nextState;
}
