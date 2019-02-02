#pragma once
#include "IPolygon.h"
#include "Vector.h"
#include "pch.h"

class Triangle :
	public IPolygon
{
public:
	Triangle(Vector, Vector, Vector);
	~Triangle();

	Vector point[3];
	Color color;
};