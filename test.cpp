#include "menu.h"
#include "NewPlayer.h"
#include "gamemode.h"
#include "Graphics.h"
#include <iostream>

GameState* States()
{
	GameState* state1 = new Menu;
	GameState* state2 = new GameMode(state1);
	GameState* newPlayerMenu = new NewPlayer(state1);

	return state1;
}

int main()
{
	GameState* currentState = States();

	while (Graphics::Instance().Window.isOpen())
        currentState = currentState->run();

    return 0;
}

