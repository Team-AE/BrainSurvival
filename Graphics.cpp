#include "Graphics.h"
#include<SFML/Graphics.hpp>

Graphics::Graphics()
{
	settings.antialiasingLevel = 10;

	Window.create(sf::VideoMode(Widht, Height), "Brain survival", sf::Style::Default, settings);

	WindowRun();
}

void Graphics::update()
{
	Window.clear();
}

void Graphics::WindowRun()
{
	while (Window.isOpen())
	{
		update();
	}
}

void Graphics::draw(sf::Sprite sprite)
{
	Window.draw(sprite);
	onDisplay();
}

void Graphics::draw(sf::Text text)
{
	Window.draw(text);
	onDisplay();
}

void Graphics::onDisplay()
{
	Window.display();
}


