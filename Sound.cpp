#include "Sound.h"
#include <SFML/Audio.hpp>
#include <iostream>

Sound::Sound()
{
	update();
}

void Sound::update()
{
	menuTheme = new sf::Music;
	mainTheme = new sf::Music;
	deadTheme = new sf::Music;
	jumpSingle = new sf::Music;
	deadSingle = new sf::Music;
	moveSingle = new sf::Music;
	menuTheme->openFromFile("Mario_Theme.ogg");
}

bool Sound::PlayMainTheme()
{
	return mainTheme->getStatus();
}

bool Sound::PlayMenuTheme()
{
	if (!menuTheme->getStatus())
	menuTheme->play();
	return menuTheme->getStatus();
}

bool Sound::PlayDeadTheme()
{
	return deadTheme->getStatus();
}

bool Sound::PlayJumpSingle()
{
	return jumpSingle->getStatus();
}

bool Sound::PlayDeadSingle()
{
	return deadSingle->getStatus();
}

bool Sound::PlayMoveSingle()
{
	return moveSingle->getStatus();
}

PlayFile::PlayFile()
{
	music = new sf::Music;
}

bool PlayFile::loadFromFile(sf::String name)
{
	return music->openFromFile(name);
}

void PlayFile::Play()
{
	music->play();
}

bool PlayFile::getStatus()
{
	return music->getStatus();
}

void PlayFile::pause()
{
	music->pause();
}