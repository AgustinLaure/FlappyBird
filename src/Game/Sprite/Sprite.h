#pragma once

#include <iostream>

#include "raylib.h"

namespace sprite
{
	struct SpriteConfig
	{
		std::string textureRoute;
		Vector2 pos;
		Color color;
		float scale = 0.0f;
		float rotation = 0.0f;
	};

	struct Sprite
	{
		Texture2D texture;
		Vector2 pos;
		Color color;
		float scale = 0.0f;
		float rotation = 0.0f;
	};

	Sprite init(Texture2D texture, Vector2 pos, Color color, float scale, float rotation);
	void deinit(Sprite sprite);
	void draw(Sprite sprite);
}