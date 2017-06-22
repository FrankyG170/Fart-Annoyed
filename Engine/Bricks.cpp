#include "Bricks.h"

Bricks::Bricks(const RectF & rect_in, const Color & color_in)
	:
	rect(rect_in),
	color(color_in)
{
}

void Bricks::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, color);
}
