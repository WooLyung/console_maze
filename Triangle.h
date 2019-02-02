#pragma once
#include "IPolygon.h"
#include "Vector.h"
#include "pch.h"

class Triangle :
	public IPolygon
{
public:
	Triangle(Vector, Vector, Vector, Color color);
	~Triangle();
	int Dimension();

	Vector point1, point2, point3;
	Color color;
};