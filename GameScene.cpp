#include "pch.h"
#include "GameScene.h"
#include "Block.h"

GameScene::GameScene(Camera* cam_)
	: IScene(cam_)
{
	int maze[15][15] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			if (maze[x][y] == 1)
				objectList->push_back(new Block(Vector(x * 100, y * 100, 0)));
		}
	}
	player = new Player(Vector(100, 0, 0));
	objectList->push_back(player);
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	IScene::Update();
}

void GameScene::Render()
{
	IScene::Render();
}

const char* GameScene::SceneName()
{
	return "GameScene";
}