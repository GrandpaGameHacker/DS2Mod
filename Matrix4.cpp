#include "Matrix4.h"

Matrix4::Matrix4()
{
	identity();
}

Matrix4::Matrix4(const float* m)
{
	memcpy_s((void*)this->m, 16 * sizeof(float), m, 16 * sizeof(float));
}

Matrix4::Matrix4(float f)
{
	constant(f);
}

void Matrix4::constant(float f)
{
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++) 
		{
			this->m[i][j] = f;
		}
	}
}

void Matrix4::identity()
{
	constant(0);
	m[0][0] = 1.0f;
	m[1][1] = 1.0f;
	m[2][2] = 1.0f;
	m[3][3] = 1.0f;
}
