#pragma once
#include <Windows.h>
class Matrix4
{
public:
	//Class Members
	float m[4][4];

	//Class Constructors
	Matrix4();
	Matrix4(const float* m);
	Matrix4(float f);
	
	//Class Functions
	void constant(float f);
	void identity();
};