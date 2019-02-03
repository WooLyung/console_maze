#pragma once
#include "pch.h"
#include "IObject.h"
#include "Camera.h"

using namespace std;

class IScene
{
public:
	IScene(Camera* cam_);
	~IScene();

	void Update();
	void Render();
	virtual const char* SceneName() = 0;

	vector<IObject*>* objectList;
	Camera* cam;
};