#include "menu.h"
#include "NewPlayer.h"
#include "gamemode.h"
#include "Graphics.h"
#include <iostream>

int main()
{

    GameState* state1 = new Menu;
    GameState* state2 = new GameMode(state1);
	GameState* newPlayerMenu = new NewPlayer(state1);

	GameState* currentState = state1;

	while (Graphics::Instance().Window.isOpen())
        currentState = currentState->run();

    return 0;
}

