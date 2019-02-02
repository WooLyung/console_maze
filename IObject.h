#pragma once
#include "IPolygon.h"
#include "Vector.h"

class IObject
{
public:
	IObject(Vector _pos);
	~IObject();

	virtual void Update() = 0;
	virtual void Render() = 0;

	Vector pos;
};