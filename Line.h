#pragma once
#include "IPolygon.h"
#include "Vector.h"
#include "pch.h"

class Line :
	public IPolygon
{

public:
	Line(Vector, Vector, Color color);
	~Line();
	int Dimension();

	Vector point1, point2;
	Color color;
};

