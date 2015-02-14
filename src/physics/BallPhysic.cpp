#include "BallPhysic.h"
#include <SFML/Graphics.hpp>
#include "math.h"


BallPhysic::BallPhysic(float WEGHT, float TIME, float STARTSPEED, float X, float Y, float ANGLE)
{
	weight = WEGHT;
	time = TIME;
	startspeed = STARTSPEED;
	x = X;
	y = Y;
	angle = ANGLE;
}


BallPhysic::~BallPhysic()
{
}


float BallPhysic::FreeFall()
{
	return y + g * time * time / 2;
}

float BallPhysic::JumpUp()
{
	return y + (g * time * time / 2) - startspeed*time;
}

float BallPhysic::JumpRunXR()
{
	return x + startspeed*time*cos(angle * 3.14 / 180);
	
}

float BallPhysic::JumpRunYR()
{
	return y + (g * time * time / 2) - startspeed*time*sin(angle * 3.14 / 180);
}

float BallPhysic::JumpRunXL()
{
	return x - startspeed*time*cos(angle * 3.14 / 180);
}

float BallPhysic::JumpRunYL()
{
	return y + (g * time * time / 2) - startspeed*time*sin(angle * 3.14 / 180);
}

float BallPhysic::TimeofJumpUp()
{
	return 2 * startspeed / g;
}

float BallPhysic::TimeofJumpRun()
{
	return 2 * startspeed * sin(angle * 3.14 / 180) / g;
}

float BallPhysic::JumpFallXR()
{
	return x + startspeed * time;
}

float BallPhysic::JumpFallYR()
{
	return y + g * time * time / 2;
}

float BallPhysic::JumpFallXL()
{
	return x - startspeed * time;
}

float BallPhysic::JumpFallYL()
{
	return y + g * time * time / 2;
}











