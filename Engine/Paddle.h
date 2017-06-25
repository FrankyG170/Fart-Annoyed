#pragma once

#include "Ball.h"
#include "Colors.h"
#include "Keyboard.h"
#include "Rectf.h"
#include "Graphics.h"
#include "Vec2.h"

// TODO: Add neseccary dependencies

class Paddle
{
public:
	// TODO: Contructor
	Paddle() = default;
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	// TODO: Draw function
	void Draw(Graphics& gfx) const;
	// TODO: Ball collision function
	bool DoBallCollision(Ball& ball) const;
	// TODO: Wall collision function
	bool DoWallCollision(const RectF& walls);
	// TODO: Update function, uses a keybord object
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
private:
	// TODO: add neseccary members to give color, pos, create rectangle with 2 floats, paddle wings, paddle wing color, and speed (7 members required)
	Color color = Colors::White;
	Vec2 pos;
	float halfWidth;
	float halfHeight;
	float paddleWingWidth = 10.0f;
	Color paddleWingColor = Colors::Red;
	float speed = 300.0f;
};