#include <ctime>
#include <conio.h>
#include "pch.h"
#include "Engine.h"
#include "Window.h"
#include "Triangle.h"
#include "Line.h"

Engine* Engine::instance;

Engine::Engine()
{
	instance = this;
	leftTime = clock();

	renderBuffer = new RenderBuffer*[Window::width];
	lastRenderBuffer = new RenderBuffer*[Window::width];
	for (int i = 0; i < Window::width; i++)
	{
		renderBuffer[i] = new RenderBuffer[Window::height];
		lastRenderBuffer[i] = new RenderBuffer[Window::height];
		for (int j = 0; j < Window::height; j++)
		{
			lastRenderBuffer[i][j].color = LightBlue;
		}
	}
}

Engine::~Engine()
{
	for (int i = 0; i < Window::width; i++)
	{
		delete[] renderBuffer[i];
		delete[] lastRenderBuffer[i];
	}
	delete[] renderBuffer;
	delete[] lastRenderBuffer;
}

void Engine::Update()
{
	nowScene->Update();
	DeltaTimeUpdate();
	KeyUpdate();
}

void Engine::Render()
{
	nowScene->Render();
	PolygonRender();
}

void Engine::Clear()
{
	for_each(renderList.begin(), renderList.end(), [](IPolygon* pol) {
		free(pol);
	});
	renderList.clear();

	for (int x = 0; x < Window::width; x++)
	{
		for (int y = 0; y < Window::height; y++)
		{
			renderBuffer[x][y].depth = 1;
			renderBuffer[x][y].color = LightBlue;
		}
	}
}

void Engine::DeltaTimeUpdate()
{
	deltaTime = (clock() - leftTime)/1000.;
	leftTime = clock();
}

void Engine::PolygonRender()
{
	for_each(renderList.begin(), renderList.end(), [this](IPolygon* pol) {
		Triangle* triangle = dynamic_cast<Triangle*>(pol);
		Line* line = dynamic_cast<Line*>(pol);

		if (triangle != nullptr)
		{
			Vector pos1 = Vector(triangle->point1.x / (triangle->point1.y / 50), triangle->point1.y, triangle->point1.z / (triangle->point1.y / 50)) + Vector(Window::width / 2, 0, Window::height / 2);
			Vector pos2 = Vector(triangle->point2.x / (triangle->point2.y / 50), triangle->point2.y, triangle->point2.z / (triangle->point2.y / 50)) + Vector(Window::width / 2, 0, Window::height / 2);
			Vector pos3 = Vector(triangle->point3.x / (triangle->point3.y / 50), triangle->point3.y, triangle->point3.z / (triangle->point3.y / 50)) + Vector(Window::width / 2, 0, Window::height / 2);

			Vector Max(max(max(pos1.x, pos2.x), pos3.x), 0, max(max(pos1.z, pos2.z), pos3.z));
			Vector Min(min(min(pos1.x, pos2.x), pos3.x), 0, min(min(pos1.z, pos2.z), pos3.z));
			if (Min.x <= 0) Min.x = 0;
			if (Min.z <= 0) Min.z = 0;
			if (Max.x >= Window::width) Max.x = Window::width;
			if (Max.z >= Window::height) Max.z = Window::height;

			if (Max.x >= 0 && Max.y >= 0 && Min.x <= Window::width - 1 && Min.z <= Window::height - 1
				&& pos1.y <= 0 && pos2.y <= 0 && pos3.y <= 0)
			{
				for (int x = (int)Min.x; x <= (int)Max.x; x++)
				{
					if (x >= 0 && x <= Window::width - 1)
					{
						for (int y = (int)Min.z; y <= (int)Max.z; y++)
						{
							if (y >= 0 && y <= Window::height - 1)
							{
								if ((Vector::CrossProduct(Vector(x - pos1.x, y - pos1.z, 0), Vector(pos2.x - pos1.x, pos2.z - pos1.z, 0)).z >= 0
									&& Vector::CrossProduct(Vector(x - pos2.x, y - pos2.z, 0), Vector(pos3.x - pos2.x, pos3.z - pos2.z, 0)).z >= 0
									&& Vector::CrossProduct(Vector(x - pos3.x, y - pos3.z, 0), Vector(pos1.x - pos3.x, pos1.z - pos3.z, 0)).z >= 0) ||
									(Vector::CrossProduct(Vector(x - pos1.x, y - pos1.z, 0), Vector(pos2.x - pos1.x, pos2.z - pos1.z, 0)).z <= 0
										&& Vector::CrossProduct(Vector(x - pos2.x, y - pos2.z, 0), Vector(pos3.x - pos2.x, pos3.z - pos2.z, 0)).z <= 0
										&& Vector::CrossProduct(Vector(x - pos3.x, y - pos3.z, 0), Vector(pos1.x - pos3.x, pos1.z - pos3.z, 0)).z <= 0))
								{
									float A = pos1.z * (pos2.y - pos3.y) + pos2.z * (pos3.y - pos1.y) + pos3.z * (pos1.y - pos2.y);
									float B = pos1.y * (pos2.x - pos3.x) + pos2.y * (pos3.x - pos1.x) + pos3.y * (pos1.x - pos2.x);
									float C = pos1.x * (pos2.z - pos3.z) + pos2.x * (pos3.z - pos1.z) + pos3.x * (pos1.z - pos2.z);
									float _D = pos1.x * (pos2.z * pos3.y - pos3.z * pos2.y) + pos2.x * (pos3.z * pos1.y - pos1.z * pos3.y) + pos3.x * (pos1.z * pos2.y - pos2.z * pos1.y);

									if ((-A * x - B * y + _D) / C <= 0 && (this->renderBuffer[x][y].depth <= (-A * x - B * y + _D) / C || this->renderBuffer[x][y].depth >= 0))
									{
										this->renderBuffer[x][y].depth = (-A * x - B * y + _D) / C;
										this->renderBuffer[x][y].color = triangle->color;
									}
								}
							}
						}
					}
				}
			}
		}
		else if (line != nullptr)
		{

		}
	});

	for (int x = 0; x < Window::width; x++)
	{
		for (int y = 0; y < Window::height; y++)
		{
			if (renderBuffer[x][y].color != lastRenderBuffer[x][y].color)
			{
				Window::Draw(x, y, renderBuffer[x][y].color);
				lastRenderBuffer[x][y].color = renderBuffer[x][y].color;
			}
		}
	}
}

void Engine::PushPolygon(IPolygon* pol)
{
	Engine::instance->renderList.push_back(pol);
}

void Engine::KeyUpdate()
{
	int key;
	if (_kbhit()) key = _getch();
	else key = 0;

	for (int i = 0; i < 128; i++)
	{
		if (keyState[i] == None || keyState[i] == Exit)
		{
			if (key == i)
			{
				keyState[i] = Enter;
			}
			else
			{
				keyState[i] = None;
			}
		}
		else if (keyState[i] == Enter || keyState[i] == Stay)
		{
			if (key == i)
			{
				keyState[i] = Stay;
			}
			else
			{
				keyState[i] = Exit;
			}
		}
	}
}