#include "Obstacle.h"

namespace obstacle
{
	Obstacle init(float width, float height, Vector2 pos, Color color)
	{
		Obstacle obstacle;
		obstacle.hitbox.width = width;
		obstacle.hitbox.height = height;
		obstacle.hitbox.pos = pos;
		obstacle.color = color;

		return obstacle;
	}

	void update()
	{

	}

	void draw()
	{

	}
}