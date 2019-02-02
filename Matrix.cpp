#include "Matrix.h"

Matrix::Matrix(float* item)
{
	for (int i = 0; i < 9; i++)
	{
		this->item[i] = item[i];
	}
}

Matrix::~Matrix()
{
}

const Matrix Matrix::operator*(const Matrix &matrix)
{
	float item[9] = {
		item[0] * matrix.item[0] + item[1] * matrix.item[3] + item[2] * matrix.item[6],
		item[0] * matrix.item[1] + item[1] * matrix.item[4] + item[2] * matrix.item[7],
		item[0] * matrix.item[2] + item[1] * matrix.item[5] + item[2] * matrix.item[8],
		item[3] * matrix.item[0] + item[4] * matrix.item[3] + item[5] * matrix.item[6],
		item[3] * matrix.item[1] + item[4] * matrix.item[4] + item[5] * matrix.item[7],
		item[3] * matrix.item[2] + item[4] * matrix.item[5] + item[5] * matrix.item[8],
		item[6] * matrix.item[0] + item[7] * matrix.item[3] + item[8] * matrix.item[6],
		item[6] * matrix.item[1] + item[7] * matrix.item[4] + item[8] * matrix.item[7],
		item[6] * matrix.item[2] + item[7] * matrix.item[5] + item[8] * matrix.item[8]
	};

	return Matrix(item);
}

const Matrix operator*(const Matrix &matrix1, const Matrix &matrix2)
{
	float item[9] = {
		matrix1.item[0] * matrix2.item[0] + matrix1.item[1] * matrix2.item[3] + matrix1. item[2] * matrix2.item[6],
		matrix1.item[0] * matrix2.item[1] + matrix1.item[1] * matrix2.item[4] + matrix1.item[2] * matrix2.item[7],
		matrix1.item[0] * matrix2.item[2] + matrix1.item[1] * matrix2.item[5] + matrix1.item[2] * matrix2.item[8],
		matrix1.item[3] * matrix2.item[0] + matrix1.item[4] * matrix2.item[3] + matrix1.item[5] * matrix2.item[6],
		matrix1.item[3] * matrix2.item[1] + matrix1.item[4] * matrix2.item[4] + matrix1.item[5] * matrix2.item[7],
		matrix1.item[3] * matrix2.item[2] + matrix1.item[4] * matrix2.item[5] + matrix1.item[5] * matrix2.item[8],
		matrix1.item[6] * matrix2.item[0] + matrix1.item[7] * matrix2.item[3] + matrix1.item[8] * matrix2.item[6],
		matrix1.item[6] * matrix2.item[1] + matrix1.item[7] * matrix2.item[4] + matrix1.item[8] * matrix2.item[7],
		matrix1.item[6] * matrix2.item[2] + matrix1.item[7] * matrix2.item[5] + matrix1.item[8] * matrix2.item[8]
	};

	return Matrix(item);
}

const Matrix Matrix::GetRotationMatrix(const Vector &axis, float angle)
{
	float c = cos(angle);
	float s = sin(angle);

	float item[9] = {
		c + (1 - c) * pow(axis.x, 2),
		(1 - c) * axis.x * axis.y - s * axis.z,
		(1 - c) * axis.x * axis.z + s * axis.y,
		(1 - c) * axis.x * axis.y + s * axis.z,
		c + (1 - c) * pow(axis.y, 2),
		(1 - c) * axis.y * axis.z - s * axis.x,
		(1 - c) * axis.x * axis.z - s * axis.y,
		(1 - c) * axis.y * axis.z + s * axis.x,
		c + (1 - c) * pow(axis.z, 2)
	};

	return Matrix(item);
}

const Matrix Matrix::GetRotationMatrix3Axis(float angleX, float angleY, float angleZ)
{
	return (Matrix::GetRotationMatrix(Vector::GetAxisX(), angleX) * Matrix::GetRotationMatrix(Vector::GetAxisY(), angleY) * Matrix::GetRotationMatrix(Vector::GetAxisZ(), angleZ));
}