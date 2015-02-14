#pragma once
#include "BasicClass_PhysicAll.h"
class BallPhysic :
	public BasicClass_PhysicAll
{
public:
	BallPhysic(float, float, float, float, float, float);
	~BallPhysic();

	float FreeFall();
	float JumpUp();
	float JumpRunXR();
	float JumpRunYR();
	float JumpRunXL();
	float JumpRunYL();
	float TimeofJumpUp();
	float TimeofJumpRun();
	float JumpFallXR();
	float JumpFallYR();
	float JumpFallXL();
	float JumpFallYL();




};

