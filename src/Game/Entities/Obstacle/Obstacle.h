#pragma once

#include "raylib.h"

#include "Game/Math/Form/Form.h"
#include "Game/Entities/Bird/Bird.h"

namespace obstacle
{
	struct Obstacle
	{
		Vector2 iniPos = {};
		form::Rectangle hitbox;
		Color color = {};
		Vector2 velocity = {};
	};

		
	Obstacle init(float width, float height, Vector2 pos, Color color);
	void reset(Obstacle& obstacle);
	void update(Obstacle& obstacle, bird::Bird& bird, float delta);
	void draw(Obstacle obstacle);
}

