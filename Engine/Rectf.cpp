#include "Rectf.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2& topLeft, const Vec2& botRight)
{
	RectF(topLeft.x, topLeft.y, botRight.x, botRight.y);
}

RectF::RectF(const Vec2& topLeft, float width, float height)
{
	RectF(topLeft, topLeft + Vec2(width, height));
}

bool RectF::IsOverlappingWith(const RectF & other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}
