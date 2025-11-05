#include "Game/Entities/Bird/Bird.h"

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Screen/Screen.h"

namespace bird
{

	static const float birdSpeed = 300.0f;
	static const float birdFallSpeed = 0.3f;
	static const float birdFallSpeedCap = 1.0f;
	static const KeyboardKey jumpButton = KEY_SPACE;
	static const Color birdIniColor = WHITE;
	static const Vector2 birdHitboxIniPos = { 0.0f, 0.0f };
	static const float birdHitboxIniRadius = 5.0f;
	static const Vector2 birdIniDir = { 0.05f,0 };

	static float jumpSpeed = 500.0f;

	static void move(Bird& bird, float delta);

	static void move(Bird& bird, float delta)
	{
		bird.velocity = birdIniDir;

		if (IsKeyDown(KEY_W))
		{
			bird.velocity.y = -1 * birdSpeed * delta;
		}
		if (IsKeyDown(KEY_S))
		{
			bird.velocity.y = 1 * birdSpeed * delta;
		}

		bird.hitbox.pos = vector::getVectorSum(bird.hitbox.pos, bird.velocity);

		outBounds(bird);
	}

	Bird init()
	{
		Bird bird;

		bird.hitbox.pos = birdHitboxIniPos;
		bird.hitbox.radius = birdHitboxIniRadius;
		bird.color = birdIniColor;
		bird.velocity = {};
		bird.hasLost = false;

		return bird;
	}

	void reset(Bird& bird)
	{
		bird.hitbox.pos = birdHitboxIniPos;
		bird.velocity = {};
		bird.hasLost = false;
	}

	void update(Bird& bird, float delta)
	{
		move(bird, delta);
	}

	void draw(Bird bird)
	{
		DrawCircle(static_cast<int>(bird.hitbox.pos.x), static_cast<int>(bird.hitbox.pos.y), bird.hitbox.radius, bird.color);
	}

	void outBounds(Bird& bird)
	{
		if (bird.hitbox.pos.x >= screen::screenWidth)
		{
			if (bird.hitbox.pos.x >= screen::screenWidth)
			{
				bird.hitbox.pos.x = 0;
			}
		}
	}
}