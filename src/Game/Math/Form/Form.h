#pragma once

#include "raylib.h"

namespace form
{
	struct Circle
	{
		float radius = 0.0f;
		Vector2 pos = {0,0};
	};

	struct Rectangle
	{
		float width = 0.0f;
		float height = 0.0f;
		Vector2 pos = { 0,0 };
	};

	bool isCircleCollidingCircle(Circle c1, Circle c2);
	bool isPointCollidingRect(Vector2 p, Rectangle rect);
	Vector2 centerToTopLeft(Rectangle rect);
	bool isRectColCircle(Rectangle rect, Circle circ);
}

