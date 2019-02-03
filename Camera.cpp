#include "Camera.h"
#include "Engine.h"
#include "pch.h"

Camera::Camera(Vector pos_, Vector angle_)
	: pos(pos_), angle(angle_)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	angle.y += Engine::instance->deltaTime * PI / 30;
}
