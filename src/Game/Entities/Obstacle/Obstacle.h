#pragma once

#include "raylib.h"

#include "Game/Math/Form/Form.h"

namespace obstacle
{
	struct Obstacle
	{
		form::Rectangle hitbox;
		Color color = {};
	};

		
	Obstacle init(float width, float height, Vector2 pos, Color color);

	void update();
	void draw();
}

