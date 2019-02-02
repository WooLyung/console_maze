#include "pch.h"
#include "IObject.h"
#include "Engine.h"

IObject::IObject(Vector _pos)
	: pos(_pos)
{
}

IObject::~IObject()
{
}

void IObject::PushPolygon(IPolygon pol)
{
	Engine::instance->renderList.push_back(&pol);
}