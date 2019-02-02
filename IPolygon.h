#pragma once
class IPolygon
{
public:
	IPolygon();
	~IPolygon();

	virtual int Dimension() = 0;
};

