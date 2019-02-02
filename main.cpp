#pragma once
#include "pch.h"
#include "Engine.h"
#include "IScene.h"
#include "GameScene.h"

bool isGameover = false;
Engine* engine;

int main()
{
	engine = new Engine();
	engine->nowScene = new GameScene();

	// 메인 루프
	while (!isGameover)
	{
		engine->Clear();
		engine->Update();
		engine->Render();
	}
}