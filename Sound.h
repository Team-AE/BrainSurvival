#pragma once
#include<SFML/Audio.hpp>
//#include <iostream>

class PlayFile
{

public:
	PlayFile();

	bool loadFromFile(sf::String);
	void Play();
	bool getStatus();
	void pause();
private:
	sf::Music* music;
};

class Sound
{
public:
	static Sound Instance()
	{
		static Sound theSingleInstance;
		return theSingleInstance;
	}

	Sound();

	void update();

	bool PlayMainTheme();
	bool PlayMenuTheme();
	bool PlayDeadTheme();
	bool PlayJumpSingle();
	bool PlayDeadSingle();
	bool PlayMoveSingle();

	bool status;

	PlayFile* File;

private:
	sf::Music* mainTheme;
	sf::Music* menuTheme;
	sf::Music* deadTheme;
	sf::Music* jumpSingle;
	sf::Music* deadSingle;
	sf::Music* moveSingle;
};

