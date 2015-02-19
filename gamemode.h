#ifndef GAMEMODE_H
#define GAMEMODE_H
#include "gamestate.h"

class GameMode : public GameState
{
public:
    GameMode(GameState*);

    virtual void addChild(GameState *) {}

protected:
    virtual void update(float);
    virtual void draw();
    virtual void eventProc(int);
};

#endif // GAMEMODE_H
