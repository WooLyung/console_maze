#include "pch.h"
#include "Engine.h"
#include <ctime>

Engine* Engine::instance;

Engine::Engine()
{
	instance = this;
	leftTime = clock();
}

Engine::~Engine()
{
}

void Engine::Update()
{
	nowScene->Update();
	DeltaTimeUpdate();
}

void Engine::Render()
{
	nowScene->Render();
	PolygonRender();
}

void Engine::Clear()
{
	renderList.clear();
}

void Engine::DeltaTimeUpdate()
{
	deltaTime = (clock() - leftTime)/1000.;
	leftTime = clock();
}

void Engine::PolygonRender()
{

}