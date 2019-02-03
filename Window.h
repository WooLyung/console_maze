#pragma once
#include <Windows.h>
#include "pch.h"

class Window
{
public:
	Window();
	~Window();

	static void Goto(int x, int y);
	static void Draw(int x, int y, Color color);
	static void SetSize(int x, int y);
	static void ReName(const char*);

	const static int width = 300, height = 150;
};

