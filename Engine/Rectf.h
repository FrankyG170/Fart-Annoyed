#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& topLeft, const Vec2& botRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool IsOverlappingWith (const RectF& other) const;
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	// TODO: Funciton to expand and create padding for bricks
	void GetExpanded(RectF& rect) const;
public:
	float left;
	float right;
	float top;
	float bottom;
};
