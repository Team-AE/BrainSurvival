#include "NewPlayer.h"

NewPlayer::NewPlayer(GameState* parent)
{
	nextState = parent;
	parent->addChild(this);

}

void NewPlayer::update(float)
{
	activeState = true;
	draw();
}

void NewPlayer::draw()
{
	Graphics::Instance().draw(Menu::SpriteBackground);
	Graphics::Instance().onDisplay();
}

void NewPlayer::eventProc(sf::Event)
{
	while (Graphics::Instance().Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			Graphics::Instance().Window.close();
	}
}

