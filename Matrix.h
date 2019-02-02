#pragma once
#include "Vector.h"

class Matrix
{
public:
	Matrix(float*);
	~Matrix();

	const Matrix operator*(const Matrix &matrix);
	static const Matrix GetRotationMatrix(const Vector &axis, float angle);
	static const Matrix GetRotationMatrix3Axis(float angleX, float angleY, float angleZ);

	float item[9];
};

