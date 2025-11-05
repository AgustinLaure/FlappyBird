#include "Obstacle.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Screen/Screen.h"

namespace obstacle
{
	const Vector2 obstacleIniDir = { -0.05f, 0.0f };
	const float obstacleIniSpeed = 3400.0f;

	static void move(Obstacle& obstacle, float delta);
	static void outBounds(Obstacle& obstacle);
	static void hitBird(Obstacle obstacle, bird::Bird& bird);

	Obstacle init(float width, float height, Vector2 pos, Color color)
	{
		Obstacle obstacle;
		obstacle.iniPos = pos;
		obstacle.hitbox.width = width;
		obstacle.hitbox.height = height;
		obstacle.hitbox.pos = pos;
		obstacle.color = color;

		return obstacle;
	}

	void reset(Obstacle& obstacle)
	{
		obstacle.hitbox.pos = obstacle.iniPos;
	}

	void update(Obstacle& obstacle, bird::Bird& bird, float delta)
	{
		move(obstacle, delta);
		hitBird(obstacle, bird);
	}

	void draw(Obstacle obstacle)
	{
		Vector2 drawPos = form::centerToTopLeft(obstacle.hitbox);

		int intPosX = static_cast<int>(drawPos.x);
		int intPosY = static_cast<int>(drawPos.y);
		int intWidth = static_cast<int>(obstacle.hitbox.width);
		int intHeight = static_cast<int>(obstacle.hitbox.height);

		DrawRectangle(intPosX, intPosY, intWidth, intHeight, obstacle.color);
	}

	static void move(Obstacle& obstacle, float delta)
	{
		obstacle.velocity = vector::getVectorMult(obstacleIniDir, obstacleIniSpeed *delta);

		obstacle.hitbox.pos = vector::getVectorSum(obstacle.hitbox.pos, obstacle.velocity);

		outBounds(obstacle);
	}

	static void outBounds(Obstacle& obstacle)
	{
		if (obstacle.hitbox.pos.x <= 0)
		{
			obstacle.hitbox.pos.x = screen::screenWidth;

			obstacle.hitbox.pos.y = static_cast<float>(GetRandomValue(0, static_cast<int>(screen::screenHeight)));
		}
	}

	static void hitBird(Obstacle obstacle, bird::Bird& bird)
	{
		if (form::isRectColCircle(obstacle.hitbox, bird.hitbox))
		{
			bird.hasLost = true;
		}
	}
}