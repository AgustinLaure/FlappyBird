#pragma once

#include "raylib.h"

#include "Game/Math/Form/Form.h"

namespace bird
{

	struct Bird
	{
		form::Circle hitbox;
		Color color;
		Vector2 velocity;
	};

	Bird init();
	void update(Bird& bird, float delta);
	void draw(Bird bird);
}
