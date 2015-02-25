#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

const int widht = 800, height = 600;

const Time FPS = sf::seconds(1.0f / 60.0f);

Game::Game()
{
	ContextSettings settings;

	settings.antialiasingLevel = 10;

	window.create(VideoMode(widht, height), "Brain survival", Style::Default, settings);
	
	img.create(20, 20, Color (0, 0, 255));
	img.createMaskFromColor(Color(0, 0, 255), 255);
	
	rectangle.loadFromImage(img);
	
	player.setTexture(rectangle);
}

//Time time_per_frame = seconds(1.f / 100.f);

Game::~Game()
{
}

void Game::Run()
{
	//Clock clock, clockGame;
	//float time, gametime;
	//Time time_since_last_update = Time::Zero;

	while (window.isOpen())
	{

		//time = clock.getElapsedTime().asMicroseconds();
		//gametime = clockGame.getElapsedTime().asMicroseconds();
		//.restart();

		//gametime /= 600;

		//time_since_last_update += clock.restart();

		while (1/*time_since_last_update > time_per_frame*/)
		{
			//time_since_last_update -= time_per_frame;
			Update(/*gametime*/);
			ProcessEvents();
			KeyPressed();
		}
		DisplayDraw();
	}
}
void Game::Update()
{
	Event event;

	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
}
void Game::ProcessEvents()
{
	window.clear(Color::White);
	window.draw(player);
	window.display();
}
void Game::KeyPressed()
{

}

void Game::DisplayDraw()
{
	sleep(FPS);
}
