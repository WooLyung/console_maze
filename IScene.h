#pragma once
#include "pch.h"
#include "IObject.h"

using namespace std;

class IScene
{
public:
	IScene();
	~IScene();

	void Update();
	void Render();

	vector<IObject*>* objectList;
};