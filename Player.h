#pragma once
#include "IObject.h"
#include "pch.h"

class Player :
	public IObject
{
public:
	Player(Vector _pos);
	~Player();

	void Update();
	void Render();

	float rot;
};