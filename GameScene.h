#pragma once
#include "IScene.h"

class GameScene
	: public IScene
{
public:
	GameScene(Camera* cam_);
	~GameScene();

	void Update();
	void Render();
};