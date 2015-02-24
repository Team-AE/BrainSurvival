#include "Graphics.h"
#include<SFML/Graphics.hpp>

Graphics::Graphics()
{
	settings.antialiasingLevel = 10;

	Window.create(sf::VideoMode(Widht, Height), "Brain survival", sf::Style::Default, settings);

}

void Graphics::update()
{
	for (int i = 0; i < Sprites.size(); i++)
	{
		Window.draw(*Sprites[i]);
	}
		Sprites.clear();
		
	for (int i = 0; i < Texts.size(); i++)
	{
		Window.draw(*Texts[i]);
	}
		Texts.clear();
}

void Graphics::onDisplay()
{
	Window.clear();
	update();
	Window.display();
}

void Graphics::draw(sf::Sprite &inSprite)
{
	
Sprites.push_back (&inSprite);

}

void Graphics::draw(sf::Text &inText)
{
	Texts.push_back(&inText);
}




