#pragma once
#include "Rectf.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(float center_in, Vec2 width, Vec2 height);
	void Draw(Graphics& gfx) const;
public:
	float center;
	Vec2 width;
	Vec2 height;
};