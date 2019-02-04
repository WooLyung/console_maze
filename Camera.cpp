#include "Camera.h"
#include "Engine.h"
#include "pch.h"
#include "GameScene.h"

Camera::Camera(Vector pos_, Vector angle_)
	: pos(pos_), angle(angle_)
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	GameScene* gameScene = dynamic_cast<GameScene*>(Engine::instance->nowScene);

	if (gameScene != nullptr)
	{
		pos.x = gameScene->player->pos.x;
		pos.y = gameScene->player->pos.y;
		angle.z = gameScene->player->rot;
	}
}
