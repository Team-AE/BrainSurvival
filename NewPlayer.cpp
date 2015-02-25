#include "NewPlayer.h"


NewPlayer::NewPlayer()
{
	
}

void NewPlayer::update(float)
{

}

void NewPlayer::draw()
{
	Graphics::Instance().draw(Menu::SpriteBackground);
}

void NewPlayer::eventProc(sf::Event)
{

}

void NewPlayer::addChild(GameState* child)
{
	children.push_back(child);
}
