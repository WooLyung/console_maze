#include "Line.h"

Line::Line(Vector vec1, Vector vec2, Color color_)
	: IPolygon(), point1(vec1), point2(vec2), color(color_)
{
}

Line::~Line()
{
}

int Line::Dimension()
{
	return 3;
}