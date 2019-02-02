#pragma once
#include "IScene.h"

IScene::IScene()
{
	objectList = new vector<IObject*>();
}

IScene::~IScene()
{
	for_each(objectList->begin(), objectList->end(), [](IObject *obj) {
		free(obj);
	});
	free(objectList);
}

void IScene::Update()
{
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