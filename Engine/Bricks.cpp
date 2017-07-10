#include "Bricks.h"

Bricks::Bricks(const RectF & rect_in, const Color & color_in)
	:
	rect(rect_in),
	color(color_in),
	destroyed(false)
{
}

void Bricks::Draw(Graphics & gfx) const
{
	if (!destroyed) 
	{
		gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Bricks::CheckBallCollision(const Ball & ball) const
{
	return rect.IsOverlappingWith(ball.GetRect()) && !destroyed;
}

void Bricks::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));

	const Vec2 ballPos = ball.GetPosition();
	if (std::signbit(ball.GetVelocity().x) == std::signbit(Vec2(ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else 
	{
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Bricks::GetCenter()
{
	return rect.GetCenter();
}