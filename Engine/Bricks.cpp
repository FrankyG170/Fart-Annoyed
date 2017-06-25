#include "Bricks.h"

Bricks::Bricks(const RectF & rect_in, const Color & color_in)
	:
	rect(rect_in),
	color(color_in)
{
}

void Bricks::Draw(Graphics & gfx) const
{
	if (!destroyed) 
	{
		gfx.DrawRect(rect, color);
	}
	 // TODO: use GetExpanded to have padding for bricks
}

bool Bricks::DoBallCollision(Ball& ball)
{
	if (rect.IsOverlappingWith(ball.GetRect()) && !destroyed)
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}


