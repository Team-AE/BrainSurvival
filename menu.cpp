#include "menu.h"
#include <iostream>
#include <SFMl/Graphics.hpp>
#include "Graphics.h"
#include "Sound.h"
#include "NewPlayer.h"

const int Weight = 800;
const int Height = 600;
bool Menu::subMenu=false;

Menu::Menu(GameState* parent)
{
	nextState = parent;
	parent->addChild(this);
}

Menu::Menu()
{
	setImages();
	
	setTexures();
	
	setSprites();
	
	setTexts();

}

void Menu::enterNamePlayer()
{
	subMenu = true;
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

	buttom_text[0].setPosition((SpriteButton[0].getPosition().x + Button.getSize().x / 2 )-40, Button.getSize().y / 2 + SpriteButton[0].getPosition().y - 20);
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
	imgButton.loadFromFile("button.png");
	imgButton.createMaskFromColor(sf::Color(255,255,255), 0);

	imgBackgound.loadFromFile("background.png");
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

void Menu::nextText()
{
	if (gameOver)
		buttom_text[0].setString("Start");
	else
		buttom_text[0].setString("Next");
}

void Menu::update(float)
{
	nextText();
    draw();
	Sound::Instance().PlayMenuTheme();
	if (subMenu)
	{	
		std::cout<<children.size();
		nextState = children[1];
		activeState = false;
	}
	else
	{
	activeState = true;
    nextState = *children.begin();
	}
}

void Menu::buttonClick()
{
	

	if (sf::Mouse::getPosition(Graphics::Instance().Window).x >= SpriteButton[0].getPosition().x &&
		sf::Mouse::getPosition(Graphics::Instance().Window).x < SpriteButton[0].getPosition().x + Button.getSize().x &&
		sf::Mouse::getPosition(Graphics::Instance().Window).y >= SpriteButton[0].getPosition().y &&
		sf::Mouse::getPosition(Graphics::Instance().Window).y < SpriteButton[0].getPosition().y + Button.getSize().y)
	{
		SpriteButton[0].setScale(1.1f, 1.1f);
		SpriteButton[0].setPosition((Weight - Button.getSize().x *1.1) / 2, 120 * 1.1);
		buttom_text[0].setCharacterSize(24 * 1.1);
		buttom_text[0].setPosition(SpriteButton[0].getPosition().x + Button.getSize().x / 2 - buttom_text[0].getCharacterSize(), Button.getSize().y / 2 + SpriteButton[0].getPosition().y - 20);
	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			enterNamePlayer();
		}
	}

	else
	{
		SpriteButton[0].setScale(1.0f, 1.0f);
		SpriteButton[0].setPosition((Weight - Button.getSize().x) / 2, 120);
		buttom_text[0].setCharacterSize(24);
		buttom_text[0].setPosition(SpriteButton[0].getPosition().x + Button.getSize().x / 2 - 40, Button.getSize().y / 2 + SpriteButton[0].getPosition().y - 20);
	}
	if (sf::Mouse::getPosition(Graphics::Instance().Window).x >= SpriteButton[1].getPosition().x &&
		sf::Mouse::getPosition(Graphics::Instance().Window).x < SpriteButton[1].getPosition().x + Button.getSize().x &&
		sf::Mouse::getPosition(Graphics::Instance().Window).y >= SpriteButton[1].getPosition().y &&
		sf::Mouse::getPosition(Graphics::Instance().Window).y <= SpriteButton[1].getPosition().y + Button.getSize().y)
	{
		SpriteButton[1].setScale(1.1f, 1.1f);
		SpriteButton[1].setPosition((Weight - Button.getSize().x*1.1) / 2, 100 + Button.getSize().y + 100 * 1.1);
		buttom_text[1].setCharacterSize(24 * 1.1);
		buttom_text[1].setPosition(SpriteButton[1].getPosition().x + Button.getSize().x*1.1 / 2 - buttom_text[1].getCharacterSize(), Button.getSize().y / 2 + SpriteButton[1].getPosition().y - 20);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Graphics::Instance().Window.close();
		}
	}
	else
	{
		SpriteButton[1].setScale(1.0f, 1.0f);
		SpriteButton[1].setPosition((Weight - Button.getSize().x) / 2, 100 + Button.getSize().y + 100);
		buttom_text[1].setCharacterSize(24);
		buttom_text[1].setPosition(SpriteButton[1].getPosition().x + Button.getSize().x / 2 - buttom_text[1].getCharacterSize(), Button.getSize().y / 2 + SpriteButton[1].getPosition().y - 20);
	}

}

void Menu::eventProc(sf::Event)
{
	buttonClick();

	while (Graphics::Instance().Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			Graphics::Instance().Window.close();
	}
}
