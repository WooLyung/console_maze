#pragma once
#include "IScene.h"
#include "IPolygon.h"
#include "pch.h"

typedef struct _RenderBuffer {
	Color color;
	float depth;
} RenderBuffer;

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
	RenderBuffer** renderBuffer;
	RenderBuffer** lastRenderBuffer;
	double deltaTime = 0;
	int keyState[128];

	static Engine* instance;

private:
	void DeltaTimeUpdate();
	void PolygonRender();
	void KeyUpdate();

	int leftTime = 0;
};