#pragma once
#include "Vector2.h"
class MObject
{
public:
	MObject();
	~MObject();

	virtual void update();
	virtual void render();

	Vector2 position;
};

