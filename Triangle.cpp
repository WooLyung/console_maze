#include "Triangle.h"

Triangle::Triangle(Vector vec1, Vector vec2, Vector vec3)
{
	point[0] = vec1;
	point[1] = vec2;
	point[2] = vec3;
}

Triangle::~Triangle()
{
}
