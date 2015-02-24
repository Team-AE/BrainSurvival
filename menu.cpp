#include "menu.h"
#include <iostream>
#include <SFMl/Graphics.hpp>
#include "Graphics.h"

const int Weight = 800;
const int Height = 600;

Menu::Menu()
{
	setImages();
	
	setTexures();
	
	setSprites();
	
	setTexts();

}

void Menu::setSprites()
{
	SpriteButton = new sf::Sprite[2];
	SpriteButton[0].setTexture(Button);
	SpriteButton[1].setTexture(Button);
	SpriteBackground.setTexture(Backgound);

	SpriteBackground.setPosition(0, 0);

	SpriteButton[0].setPosition((Weight - Button.getSize().x) / 2, 120);
	SpriteButton[1].setPosition((Weight - Button.getSize().x) / 2, 100 + Button.getSize().y + 100);
}

void Menu::setTexts()
{
	buttom_text = new sf::Text[2];
	buttom_text[0].setFont(font);
	buttom_text[1].setFont(font);

	if (!font.loadFromFile("Pyxidium Caps.ttf"))
	{
		std::cout << "Error";
	}

	textMenu.setFont(font);
	buttom_text[0].setFont(font);
	buttom_text[1].setFont(font);

	if (gameOver)
		buttom_text[0].setString("Start");
	else
		buttom_text[0].setString("Next");

	buttom_text[1].setString("Exit");

	textMenu.setString("Menu");

	buttom_text[0].setCharacterSize(24);
	buttom_text[1].setCharacterSize(24);

	buttom_text[0].setColor(sf::Color::Black);
	buttom_text[1].setColor(sf::Color::Black);

	buttom_text[0].setStyle(sf::Text::Bold);
	buttom_text[1].setStyle(sf::Text::Bold);

	buttom_text[0].setPosition(SpriteButton[0].getPosition().x + Button.getSize().x / 2 - buttom_text[0].getCharacterSize(), Button.getSize().y / 2 + SpriteButton[0].getPosition().y - 20);
	buttom_text[1].setPosition(SpriteButton[1].getPosition().x + Button.getSize().x / 2 - buttom_text[1].getCharacterSize(), Button.getSize().y / 2 + SpriteButton[1].getPosition().y - 20);

	textMenu.setCharacterSize(40);
	textMenu.setColor(sf::Color::Yellow);
	textMenu.setStyle(sf::Text::Bold);
	textMenu.setPosition(Weight / 2 - 50, 30);
}

void Menu::setTexures()
{
	Backgound.loadFromImage(imgBackgound);
	Button.loadFromImage(imgButton);

	Button.setSmooth(true);
}

void Menu::setImages()
{
	//imgButton.create(400, 50, sf::Color::Blue);
	imgButton.loadFromFile("button.png");
	imgButton.createMaskFromColor(sf::Color(255,255,255), 0);

	imgBackgound.loadFromFile("background.png");
	//imgBackgound.createMaskFromColor(sf::Color::Blue, 50);
}



void Menu::addChild(GameState* child)
{
    children.push_back(child);
}

void Menu::draw()
{	
	Graphics::Instance().draw(SpriteBackground);
	Graphics::Instance().draw(SpriteButton[0]);
	Graphics::Instance().draw(SpriteButton[1]);
	Graphics::Instance().draw(textMenu);
	Graphics::Instance().draw(buttom_text[0]);
	Graphics::Instance().draw(buttom_text[1]);
	Graphics::Instance().onDisplay();

}

void Menu::update(float)
{
    draw();
    nextState = *children.begin();
    activeState = false;
}

void Menu::eventProc(sf::Event)
{

	if (sf::Mouse::getPosition(Graphics::Instance().Window).x >= SpriteButton[0].getPosition().x &&
		sf::Mouse::getPosition().x <= SpriteButton[0].getPosition().x + Button.getSize().x &&
		sf::Mouse::getPosition(Graphics::Instance().Window).y >= SpriteButton[0].getPosition().y &&
		sf::Mouse::getPosition().y <= SpriteButton[0].getPosition().y + Button.getSize().y)
		std::cout << "Buttom";
}
