#pragma once
#include "Vector.h"

class Camera
{
public:
	Camera(Vector, Vector);
	~Camera();
	void Update();

	Vector pos, angle;
};

