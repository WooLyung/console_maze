#include "Vector.h"
#include "Matrix.h"

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::~Vector()
{
}

Vector Vector::operator+(Vector &vec)
{
	return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector Vector::operator-(Vector &vec)
{
	return Vector(this->x - vec.x, this->y - vec.y, this->z - vec.z);
}

Vector Vector::operator*(float i)
{
	return Vector(this->x * i, this->y * i, this->z * i);
}

Vector Vector::operator/(float i)
{
	return Vector(this->x / i, this->y / i, this->z / i);
}

Vector Vector::Normalize()
{
	return *this / Scale();
}

float Vector::Scale()
{
	return sqrt(ScaleSq());
}

float Vector::ScaleSq()
{
	return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

Vector Vector::PseudoCrossProduct()
{
	return Vector(-y, x, z);
}

float Vector::InnerProduct(Vector &vec1, Vector &vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Vector Vector::CrossProduct(Vector &vec1, Vector &vec2)
{
	return Vector(vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
}

Vector operator*(Vector &vec, const Matrix matrix)
{
	return Vector(vec.x * matrix.item[0] + vec.y * matrix.item[3] + vec.z * matrix.item[6]
		, vec.x * matrix.item[1] + vec.y * matrix.item[4] + vec.z * matrix.item[7]
		, vec.x * matrix.item[2] + vec.y * matrix.item[5] + vec.z * matrix.item[8]);
}

Vector operator*(const Matrix matrix, Vector &vec)
{
	return Vector(vec.x * matrix.item[0] + vec.y * matrix.item[3] + vec.z * matrix.item[6]
		, vec.x * matrix.item[1] + vec.y * matrix.item[4] + vec.z * matrix.item[7]
		, vec.x * matrix.item[2] + vec.y * matrix.item[5] + vec.z * matrix.item[8]);
}

Vector Vector::GetAxisX()
{
	return Vector(1, 0, 0);
}

Vector Vector::GetAxisY()
{
	return Vector(0, 1, 0);
}

Vector Vector::GetAxisZ()
{
	return Vector(0, 0, 1);
}