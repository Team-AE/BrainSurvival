#ifndef MENU_H
#define MENU_H
#include "gamestate.h"
#include <vector>

class Menu : public GameState
{
    std::vector<GameState*> children;

public:
    void addChild(GameState*);

protected:
    void update(float);
    void draw();
    void eventProc(int);
};

#endif // MENU_H
