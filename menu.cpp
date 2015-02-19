#include "menu.h"
#include <iostream>

void Menu::addChild(GameState* child)
{
    children.push_back(child);
}

void Menu::draw()
{
    std::cout << "test: Menu" << std::endl;
}

void Menu::update(float)
{
    draw();
    nextState = *children.begin();
    activeState = false;
}

void Menu::eventProc(int)
{
}
