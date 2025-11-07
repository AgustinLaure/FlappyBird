#include "Obstacle.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Screen/Screen.h"

namespace obstacle
{
	const Vector2 obstacleIniDir = { -1, 0.0f };
	const float obstacleIniSpeed = 340.0f;
	const float distanceBetweenParts = 1590.0f;

	static void move(Obstacle& obstacle, float delta);
	static void outBounds(Obstacle& obstacle);
	static void hitBird(Obstacle obstacle, bird::Bird& bird);

	Obstacle init(float width, float height, Vector2 pos, Color color)
	{
		Obstacle obstacle;
		obstacle.iniPos = pos;
		obstacle.pos = pos;

		obstacle.upperHitbox.width = width;
		obstacle.upperHitbox.height = height;
		obstacle.upperHitbox.pos = obstacle.pos;
		obstacle.upperHitbox.pos.y -= distanceBetweenParts;

		obstacle.lowerHitBox.width = width;
		obstacle.lowerHitBox.height = height;
		obstacle.lowerHitBox.pos = obstacle.pos;
		obstacle.lowerHitBox.pos.y += distanceBetweenParts;

		obstacle.color = color;

		return obstacle;
	}

	void reset(Obstacle& obstacle)
	{
		obstacle.pos = obstacle.iniPos;
		obstacle.upperHitbox.pos = { obstacle.pos.x, obstacle.pos.y-distanceBetweenParts };
		obstacle.lowerHitBox.pos = { obstacle.pos.x, obstacle.pos.y+distanceBetweenParts };
		obstacle.velocity = {};
	}

	void update(Obstacle& obstacle, bird::Bird& bird, float delta)
	{
		move(obstacle, delta);
		hitBird(obstacle, bird);
	}

	void draw(Obstacle obstacle)
	{
		Vector2 drawPos = form::centerToTopLeft(obstacle.upperHitbox);

		int intPosX = static_cast<int>(drawPos.x);
		int intPosY = static_cast<int>(drawPos.y);
		int intWidth = static_cast<int>(obstacle.upperHitbox.width);
		int intHeight = static_cast<int>(obstacle.upperHitbox.height);

		DrawRectangle(intPosX, intPosY, intWidth, intHeight, obstacle.color);

		drawPos = form::centerToTopLeft(obstacle.lowerHitBox);

		intPosX = static_cast<int>(drawPos.x);
		intPosY = static_cast<int>(drawPos.y);
		intWidth = static_cast<int>(obstacle.lowerHitBox.width);
		intHeight = static_cast<int>(obstacle.lowerHitBox.height);

		DrawRectangle(intPosX, intPosY, intWidth, intHeight, obstacle.color);
	}

	static void move(Obstacle& obstacle, float delta)
	{
		obstacle.velocity = vector::getVectorMult(obstacleIniDir, obstacleIniSpeed *delta);

		obstacle.pos = vector::getVectorSum(obstacle.pos, obstacle.velocity);

		obstacle.upperHitbox.pos = { obstacle.pos.x, obstacle.pos.y - distanceBetweenParts };
		obstacle.lowerHitBox.pos = { obstacle.pos.x, obstacle.pos.y + distanceBetweenParts };
		
		outBounds(obstacle);
	}

	static void outBounds(Obstacle& obstacle)
	{
		if (obstacle.pos.x <= 0)
		{
			obstacle.pos.x = screen::screenWidth;

			obstacle.pos.y = static_cast<float>(GetRandomValue(static_cast<int>(distanceBetweenParts/2), static_cast<int>(screen::screenHeight - distanceBetweenParts / 2)));
		}
	}

	static void hitBird(Obstacle obstacle, bird::Bird& bird)
	{
		if (form::isRectColCircle(obstacle.upperHitbox, bird.hitbox))
		{
			bird.hasLost = true;
		}

		if (form::isRectColCircle(obstacle.lowerHitBox, bird.hitbox))
		{
			bird.hasLost = true;
		}
	}
}