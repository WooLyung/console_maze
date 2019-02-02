#pragma once
#include "pch.h"

class Vector
{
public:
	Vector(float, float, float);
	~Vector();

	Vector operator+(Vector &vec);
	Vector operator-(Vector &vec);
	Vector operator*(float i);
	Vector operator/(float i);
	Vector Normalize();
	Vector PseudoCrossProduct();
	float Scale();
	float ScaleSq();
	static float InnerProduct(Vector &vec1, Vector &vec2);
	static Vector CrossProduct(Vector &vec1, Vector &vec2);
	static Vector GetAxisX();
	static Vector GetAxisY();
	static Vector GetAxisZ();

	float x, y, z;
};