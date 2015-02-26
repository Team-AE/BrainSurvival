#include "NewPlayer.h"

NewPlayer::NewPlayer(GameState* parent)
{
	nextState = parent;
	parent->addChild(this);

	setImages();
	
	setTexures();
	
	setSprites();

	setTexts();
}

void NewPlayer::setTexts()
{

}

void NewPlayer::setTexures()
{
	TextField.loadFromImage(imgTextField);
}

void NewPlayer::setImages()
{
	imgTextField.create(500, 100);
}

void NewPlayer::setSprites()
{
	spriteTextField.setTexture(TextField);
	spriteTextField.setColor(sf::Color::Blue);
	spriteTextField.setPosition((Graphics::Instance().Widht  - TextField.getSize().x)/2, Graphics::Instance().Height / 2 - TextField.getSize().y);
}



void NewPlayer::update(float)
{
	activeState = true;
	draw();
}

void NewPlayer::draw()
{
	Graphics::Instance().draw(Menu::SpriteBackground);
	Graphics::Instance().draw(spriteTextField);
	Graphics::Instance().onDisplay();
}

void NewPlayer::eventProc(sf::Event event)
{
	while (Graphics::Instance().Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			Graphics::Instance().Window.close();
	}
}

