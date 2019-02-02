#include "Window.h"
using namespace std::string_literals;

Window::Window()
{
}

Window::~Window()
{
}

void Window::Goto(int x, int y)
{
	if (x >= 0 && x <= width - 1 && y >= 0 && y <= height - 1)
	{
		COORD pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
}

void Window::Draw(int x, int y, Color color)
{
	if (x >= 0 && x <= width - 1 && y >= 0 && y <= height - 1)
	{
		Goto(x, y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color * 17);
		std::cout << "  ";
	}
}

void Window::SetSize(int x, int y)
{
	system(("mode con cols="s + std::to_string(x * 2) + " lines="s + std::to_string(y)).c_str());
}

void Window::ReName(const char* name)
{
	system(("title "s + name).c_str());
}