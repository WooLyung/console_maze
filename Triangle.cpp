#include "Triangle.h"

Triangle::Triangle(Vector vec1, Vector vec2, Vector vec3, Color color_)
	: IPolygon(), point1(vec1), point2(vec2), point3(vec3), color(color_)
{
}

Triangle::~Triangle()
{
}

int Triangle::Dimension()
{
	return 3;
}