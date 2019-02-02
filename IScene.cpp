#pragma once
#include "IScene.h"

IScene::IScene(Camera* cam_)
	: cam(cam_)
{
	objectList = new vector<IObject*>();
}

IScene::~IScene()
{
	for_each(objectList->begin(), objectList->end(), [](IObject *obj) {
		free(obj);
	});
	free(objectList);
	free(cam);
}

void IScene::Update()
{
	cam->Update();
	for_each(objectList->begin(), objectList->end(), [](IObject *obj) {
		obj->Update();
	});
}

void IScene::Render()
{
	for_each(objectList->begin(), objectList->end(), [](IObject *obj) {
		obj->Render();
	});
}