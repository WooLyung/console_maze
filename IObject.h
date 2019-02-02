#pragma once
#include "IPolygon.h"
#include "Vector.h"

class IObject
{
public:
	IObject();
	~IObject();

	virtual void Update() = 0;
	virtual void Render() = 0;
	void PushPolygon(IPolygon);

	Vector pos;
};