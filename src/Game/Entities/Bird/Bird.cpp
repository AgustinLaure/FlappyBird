#include "Game/Entities/Bird/Bird.h"

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Screen/Screen.h"

namespace bird
{
	static const float ceilingOffset = 0.01f;

	static const float birdSpeed = 300.0f;
	static const float birdFallSpeed = 150000.0f;
	static const float birdFallSpeedCap = 1200.0f;
	static const KeyboardKey jumpKey = KEY_SPACE;
	static const Color birdIniColor = WHITE;
	static const Vector2 birdHitboxIniPos = { 0.0f, 0.0f };
	static const float birdHitboxIniRadius = 5.0f;
	static const Vector2 birdIniDir = { 0.05f,0 };

	static void move(Bird& bird, float delta);

	static float jumpSpeed = -500.0f;

	static void move(Bird& bird, float delta)
	{
		if (bird.velocity.y < birdFallSpeedCap)
		{
			float toAdd = birdFallSpeed;

			if (toAdd > birdFallSpeedCap)
			{
				toAdd = birdFallSpeedCap;
			}

			bird.velocity.y += toAdd * delta;
		}

		if (IsKeyPressed(jumpKey))
		{
			bird.velocity.y = 0;
			bird.velocity.y = jumpSpeed;
		}

		bird.hitbox.pos = vector::getVectorSum(bird.hitbox.pos, vector::getVectorMult(bird.velocity, delta));

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
		if (bird.hitbox.pos.y >= screen::screenHeight)
		{
			bird.hasLost = true;
		}
		else if (bird.hitbox.pos.y <= 0.0f)
		{
			bird.hitbox.pos.y = 0.f + ceilingOffset;
			bird.velocity.y = 0.0f;
		}
	}
}