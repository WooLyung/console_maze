#pragma once
#include "IScene.h"

class GameScene
	: public IScene
{
public:
	GameScene();
	~GameScene();

	void Update();
	void Render();
};