#pragma once
#include "IScene.h"
#include "IPolygon.h"
#include "pch.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Update();
	void Render();
	void Clear();
	static void PushPolygon(IPolygon* pol);

	IScene* nowScene;
	vector<IPolygon*> renderList;
	double deltaTime = 0;

	static Engine* instance;

private:
	void DeltaTimeUpdate();
	void PolygonRender();

	int leftTime = 0;
};

