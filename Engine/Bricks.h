#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Bricks 
{
public:
	Bricks() = default;
	Bricks(const RectF& rect_in, const Color& color_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);

public:
	// TODO: add member variable for padding on brick
	static constexpr float padding = 0.7f;
	RectF rect;
	Color color;
	bool destroyed = false;
};