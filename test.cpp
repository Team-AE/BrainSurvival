#include "menu.h"
#include "gamemode.h"


int main()
{
    GameState* state1 = new Menu;
    GameState* state2 = new GameMode(state1);
    GameState* currentState = state1;

    for(int i = 0; i < 5; ++i)
        currentState = currentState->run();

    return 0;
}

