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

	virtual float FreeFall() = 0;// ��������� �������
	virtual float JumpUp() = 0;// ������������� ����������� �����

	virtual float JumpRunXR() = 0;// ��� ����� � ��������� ������ �� ��� �
	virtual float JumpRunYR() = 0;// ��� ����� � ��������� ������ �� ��� Y

	virtual float JumpRunXL() = 0;// ��� ����� � ��������� ����� �� ��� �
	virtual float JumpRunYL() = 0;// ��� ����� � ��������� ����� �� ��� Y

	virtual float JumpFallXR() = 0;// ������������� ������ �� ��� �
	virtual float JumpFallYR() = 0;// ������������� ������ �� ��� Y

	virtual float JumpFallXL() = 0;// ������������� ����� �� ��� �
	virtual float JumpFallYL() = 0;// ������������� ����� �� ��� Y

	virtual float TimeofJumpUp() = 0;// ����� ������ �����
	virtual float TimeofJumpRun() = 0;// ����� ������ ��� �����
	
	const float g = 9.81;// ��������� ���������� �������
	float weight;// ����� ����
	float time;// �����, ��������� �� ������ �������
	float startspeed;// ��������� ��������
	float x;// ��������� ���������� �
	float y;// ��������� ���������� Y
	float angle;//���� ������
	

};

