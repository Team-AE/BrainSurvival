#pragma once
#include <SFML/Graphics.hpp>
class BasicClass_PhysicAll
{
public:
	BasicClass_PhysicAll();
	~BasicClass_PhysicAll();
	void SetTime(float);
	void SetWeight(float);
	void SetStartSpeed(float);
	void SetX(float);
	void SetY(float);

	

protected:

	virtual float FreeFall() = 0;// свободное падение
	virtual float JumpUp() = 0;// подпрыгивание вертикально вверх

	virtual float JumpRunXR() = 0;// под углом к горизонту вправо по оси Х
	virtual float JumpRunYR() = 0;// под углом к горизонту вправо по оси Y

	virtual float JumpRunXL() = 0;// под углом к горизонту влево по оси Х
	virtual float JumpRunYL() = 0;// под углом к горизонту влево по оси Y

	virtual float JumpFallXR() = 0;// горизонтально вправо по оси Х
	virtual float JumpFallYR() = 0;// горизонтально вправо по оси Y

	virtual float JumpFallXL() = 0;// горизонтально влево по оси Х
	virtual float JumpFallYL() = 0;// горизонтально влево по оси Y

	virtual float TimeofJumpUp() = 0;// время броска вверх
	virtual float TimeofJumpRun() = 0;// время броска под углом
	
	const float g = 9.81;// ускорение свободного падения
	float weight;// масса тела
	float time;// время, прошедшее от начала события
	float startspeed;// начальная скорость
	float x;// начальная координата Х
	float y;// начальная координата Y
	float angle;//угол броска
	

};

