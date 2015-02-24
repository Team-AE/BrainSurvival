#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Graphics.h"

const int Widht = 800;
const int Height = 600;
bool GameState::gameOver;


GameState* GameState::run()
{
    activeState = true;
	gameOver = true; 

    while(activeState)
    {
		sf::Event event;
		while (Graphics::Instance().Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Graphics::Instance().Window.close();
		}
	   
        eventProc(event); // need know how implemented processing event in SFML

        update(0.0f);
    }
    return nextState;
}
