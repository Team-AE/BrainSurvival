#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "BasicClass_PhysicAll.h"
#include "BallPhysic.h"
#include "math.h"


using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML works!");
	
	Texture herotexture;
	herotexture.loadFromFile("hero.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 282, 109, 141));//получили нужный нам прямоугольник 
	herosprite.setPosition(10, 100);

	float time = 1;

	bool a = 0;
	bool b = 0;
	bool c = 0;
	bool d = 0;
	bool e = 0;

	BallPhysic A = *new BallPhysic(0, 0, 40, 0, 0, 30);

	Clock clock;

	while (window.isOpen())
	{
		Event event;
 		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			/*if (event.type == sf::Event::KeyPressed)
			{	
			}*/

		}


		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			herosprite.move(0.5, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			herosprite.move(0, 0.1);
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			herosprite.move(-0.5, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			herosprite.move(0, -0.1);
		}


		if (Keyboard::isKeyPressed(Keyboard::Space) && a == 0 )
		{
			a = 1;
			A.SetX(herosprite.getPosition().x);
			A.SetY(herosprite.getPosition().y);
			clock.restart();
		}
		
		if (a == 1)
		{
			time = clock.getElapsedTime().asSeconds() * 4;
			if (time >= A.TimeofJumpUp())
			{
				a = 0;
			}
			else
			{
				A.SetTime(time);
				herosprite.setPosition(herosprite.getPosition().x, A.JumpUp());
			}
		}
	

		if (Keyboard::isKeyPressed(Keyboard::E) && b == 0)
		{
				b = 1;
				A.SetX(herosprite.getPosition().x);
				A.SetY(herosprite.getPosition().y);
				clock.restart();
		}


		if (b == 1)
		{
			time = clock.getElapsedTime().asSeconds() * 4;
			if (time >= A.TimeofJumpRun())
			{
				b = 0;
			}
			else
			{
				A.SetTime(time);
				herosprite.setPosition(A.JumpRunXR(), A.JumpRunYR());
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Q) && c == 0)
		{
			c = 1;
			A.SetX(herosprite.getPosition().x);
			A.SetY(herosprite.getPosition().y);
			clock.restart();
		}


		if (c == 1)
		{
			time = clock.getElapsedTime().asSeconds() * 4;
			if (time >= A.TimeofJumpRun())
			{
				c = 0;
			}
			else
			{
				A.SetTime(time);
				herosprite.setPosition(A.JumpRunXL(), A.JumpRunYL());
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::D) && d == 0)
		{
			d = 1;
			A.SetX(herosprite.getPosition().x);
			A.SetY(herosprite.getPosition().y);
			clock.restart();
		}


		if (d == 1)
		{
			time = clock.getElapsedTime().asSeconds() * 4;
			
			 
			if (herosprite.getPosition().y >= 400)
			{
				d = 0;
			}
			else
			{
				A.SetTime(time);
				herosprite.setPosition(A.JumpFallXR(), A.JumpFallYR());
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::A) && e == 0)
		{
			e = 1;
			A.SetX(herosprite.getPosition().x);
			A.SetY(herosprite.getPosition().y);
			clock.restart();
		}


		if (e == 1)
		{
			time = clock.getElapsedTime().asSeconds() * 4;


			if (herosprite.getPosition().y >= 400)
			{
				e = 0;
			}
			else
			{
				A.SetTime(time);
				herosprite.setPosition(A.JumpFallXL(), A.JumpFallYL());
			}
		}


		
			

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}