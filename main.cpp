#pragma once
#include "pch.h"
#include "Engine.h"
#include "IScene.h"
#include "GameScene.h"
#include "Window.h"

bool isGameover = false;
Engine* engine;

int main()
{
	engine = new Engine();
	engine->nowScene = new GameScene(new Camera(Vector(0, 500, 0), Vector(0, 0, 0)));

	Window::SetSize(Window::width, Window::height);
	Window::ReName("Maze!");
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 0;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	// 메인 루프
	while (!isGameover)
	{
		engine->Clear();
		engine->Update();
		engine->Render();
	}
}