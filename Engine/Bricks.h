#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
#include <assert.h>

class Bricks 
{
public:
	Bricks() = default;
	Bricks(const RectF& rect_in, const Color& color_in);
	void Draw(Graphics& gfx) const;
	bool checkBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter();
public:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color color;
	bool destroyed = false;
};