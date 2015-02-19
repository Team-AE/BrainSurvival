#ifndef GAMEMODE_H
#define GAMEMODE_H
#include "gamestate.h"

class GameMode : public GameState
{
public:
    GameMode(GameState*);

    virtual void addChild(GameState *) {}

protected:
    void update(float);
    void draw();
    void eventProc(int);
};

#endif // GAMEMODE_H
