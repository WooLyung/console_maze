#pragma once
#include "IPolygon.h"
#include "Vector.h"
#include "pch.h"

class Line :
	public IPolygon
{

public:
	Line(Vector, Vector);
	~Line();

	Vector point[2];
	Color color;
};

