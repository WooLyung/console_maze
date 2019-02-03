#pragma once
#include "IScene.h"
#include "Player.h"

class GameScene
	: public IScene
{
public:
	GameScene(Camera* cam_);
	~GameScene();

	void Update();
	void Render();
	const char* SceneName();

	Player *player;
};