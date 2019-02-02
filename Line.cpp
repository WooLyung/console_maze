#include "Line.h"

Line::Line(Vector vec1, Vector vec2)
{
	point[0] = vec1;
	point[1] = vec2;
}

Line::~Line()
{
}
