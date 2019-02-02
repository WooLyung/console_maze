#pragma once
#include "IObject.h"
#include "pch.h"

class Block :
	public IObject
{
public:
	Block();
	~Block();

	void Update();
	void Render();

	Color color;
};

