#pragma once

#include <string>

#include "raylib.h"

#include "Game/Sprite/Sprite.h"

namespace background
{
	struct BackgroundElementConfig
	{
		sprite::SpriteConfig sprite;
		Vector2 dir = {};
		float speed = 0.0f;
	};

	struct BackgroundElement
	{
		sprite::Sprite sprite;
		Vector2 dir = {};
		float speed = 0.0f;
	};

	const int backgroundElements = 3;
	
	BackgroundElement initBackground(int i);
	void deinitBackground(BackgroundElement background[]);
	void update(BackgroundElement background[], float delta);
	void draw(BackgroundElement background[]);
	void reset(BackgroundElement background[]);
}
