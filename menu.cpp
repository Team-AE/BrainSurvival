#include "menu.h"
#include <iostream>
#include <SFMl/Graphics.hpp>
#include "Graphics.h"

const int Weight = 800;
const int Height = 600;

Menu::Menu()
{
	imgButton.create(400, 50, sf::Color (0, 0 , 255));
	
	imgBackgound.create(Weight, Height, sf::Color(0, 0, 255));
	imgBackgound.createMaskFromColor(sf::Color(0, 0, 255), 150);

	Backgound.loadFromImage(imgBackgound);
	Button.loadFromImage(imgButton);

	Button.setSmooth(true);
	
	SpriteButton = new sf::Sprite [2];
	SpriteButton[0].setTexture(Button);
	SpriteButton[1].setTexture(Button);
	SpriteBackground.setTexture(Backgound);

	buttom_text = new sf::Text[2];
	buttom_text[0].setFont(font);
	buttom_text[1].setFont(font);

	SpriteBackground.setPosition(0, 0);

	SpriteButton[0].setPosition(Weight - Button.getSize().x/2, 100);
	SpriteButton[1].setPosition(Weight - Button.getSize().x / 2, 100 + Button.getSize().y + 100);
	
	font.loadFromFile("Pyxidium Caps.ttf");

	textMenu.setFont(font);
	buttom_text[0].setFont(font);
	buttom_text[1].setFont(font);

	if (gameOver)
		buttom_text[0].setString("Start");
	else
		buttom_text[0].setString("Next");

	buttom_text[1].setString("Exit");

	textMenu.setString("Menu");

	buttom_text[0].setCharacterSize(20);
	buttom_text[1].setCharacterSize(20);
	
	buttom_text[0].setColor(sf::Color::Black);
	buttom_text[1].setColor(sf::Color::Black);
	
	buttom_text[0].setStyle(sf::Text::Bold);
	buttom_text[1].setStyle(sf::Text::Bold);

	buttom_text[0].setPosition(SpriteButton[0].getPosition().x + 50, SpriteButton[0].getPosition().y + 50);
	buttom_text[1].setPosition(SpriteButton[1].getPosition().x + 50, SpriteButton[1].getPosition().y + 50);
	
	textMenu.setCharacterSize(24);
	textMenu.setColor(sf::Color::Black);
	textMenu.setStyle(sf::Text::Bold);
	textMenu.setPosition(Weight / 2, 50);
}

void Menu::addChild(GameState* child)
{
    children.push_back(child);
}

void Menu::draw()
{
	//Window.clear();
	//Window.draw(SpriteBackground);
	//Window.draw(SpriteButton[0]);
	//Window.draw(SpriteButton[1]);
	//Window.draw(textMenu);
	//Window.draw(buttom_text[0]);
	//Window.draw(buttom_text[1]);
	//Window.display();

    std::cout << "test: Menu" << std::endl;
}

void Menu::update(float)
{
    draw();
    nextState = *children.begin();
    activeState = false;
}

void Menu::eventProc(sf::Event)
{
}
