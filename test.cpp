#include "menu.h"
#include "gamemode.h"
#include "Graphics.h"
#include <iostream>


int main()
{
    GameState* state1 = new Menu;
    GameState* state2 = new GameMode(state1);
    GameState* currentState = state1;

	while (1)
        currentState = currentState->run();

    return 0;
}

