#pragma once
#include "MObject.h"
class Star : public MObject
{
public:
	Star() {};
	~Star() {};

	void update() override;
	void render() override;

	float r;
	float g;
	float b;
};

