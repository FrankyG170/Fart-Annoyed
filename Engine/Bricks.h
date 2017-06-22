#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"

class Bricks 
{
public:
	Bricks() = default;
	Bricks(const RectF& rect_in, const Color& color_in);
	void Draw(Graphics& gfx) const;
public:
	RectF rect;
	Color color;
	bool destroyed = false;
};