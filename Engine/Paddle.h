#pragma once

#include "Ball.h"
#include "Colors.h"
#include "Keyboard.h"
#include "Rectf.h"
#include "Graphics.h"
#include "Vec2.h"


class Paddle
{
public:
	Paddle() = default;
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball) const;
	bool DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
private:
	Color color = Colors::White;
	Vec2 pos;
	float halfWidth;
	float halfHeight;
	float paddleWingWidth = 10.0f;
	Color paddleWingColor = Colors::Red;
	float speed = 300.0f;
};