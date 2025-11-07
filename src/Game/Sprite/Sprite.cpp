#include "Game/Sprite/Sprite.h"

namespace sprite
{
	Sprite init(Texture2D texture, Vector2 pos, Color color, float scale, float rotation)
	{
		Sprite sprite;

		sprite.texture = texture;
		sprite.pos = pos;
		sprite.color = color;
		sprite.scale = scale;
		sprite.rotation = rotation;

		return sprite;
	}

	void deinit(Sprite sprite)
	{
		UnloadTexture(sprite.texture);
	}

	void draw(Sprite sprite)
	{
		DrawTextureEx(sprite.texture, sprite.pos, sprite.rotation, sprite.scale, sprite.color);
	}
}