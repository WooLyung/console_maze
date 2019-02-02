#pragma once
#include "IObject.h"
#include "pch.h"

class Block :
	public IObject
{
public:
	Block(Vector _pos);
	~Block();

	void Update();
	void Render();

	Color color;
};

