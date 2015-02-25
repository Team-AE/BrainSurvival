#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics.hpp>

class GameState
{
public:
    GameState* run();
    virtual void addChild(GameState*) = 0;     //add new child
    virtual ~GameState(){}

protected:
    virtual void update(float) = 0;  //perform an action necessary to the current time
    virtual void draw() = 0;
    virtual void eventProc(sf::Event) = 0;

    GameState* nextState;
    bool activeState;
	static bool gameOver;
	static sf::Event event;
};

#endif // GAMESTATE_H
