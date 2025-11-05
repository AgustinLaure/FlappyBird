#pragma once

#include "raylib.h"

#include "Game/Math/Form/Form.h"

namespace bird
{

	struct Bird
	{
		form::Circle hitbox;
		Color color = {};
		Vector2 velocity = {};
		bool hasLost = false;
	};

	Bird init();
	void reset(Bird& bird);
	void update(Bird& bird, float delta);
	void draw(Bird bird);
	void outBounds(Bird& bird);
}
