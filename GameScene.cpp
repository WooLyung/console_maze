#include "pch.h"
#include "GameScene.h"
#include "Block.h"

GameScene::GameScene(Camera* cam_)
	: IScene(cam_)
{
	objectList->push_back(new Block(Vector(0, -500, -100)));
	objectList->push_back(new Block(Vector(500, -500, 0)));
	objectList->push_back(new Block(Vector(-500, -500, 100)));
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