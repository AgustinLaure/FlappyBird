#include "Game/Entities/Bird/Bird.h"

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"

namespace bird
{

	static const float birdSpeed = 300.0f;
	static const float birdFallSpeed = 0.3f;
	static const float birdFallSpeedCap = 1.0f;
	static const KeyboardKey jumpButton = KEY_SPACE;
	static const Color birdIniColor = WHITE;
	static const Vector2 birdHitboxIniPos = { 0.0f, 0.0f };
	static const float birdHitboxIniRadius = 5.0f;
	static const Vector2 birdIniVel = { 0,0 };

	static float jumpSpeed = 500.0f;

	static void move(Bird& bird, float delta);

	static void move(Bird& bird, float delta)
	{
		if (bird.velocity.y < birdFallSpeedCap)
		{
			bird.velocity = vector::getVectorSum(bird.velocity, { 0, birdFallSpeed * delta });
		}

		if (IsKeyPressed(jumpButton))
		{
			bird.velocity.y = 0;
			bird.velocity.y -= jumpSpeed * delta;
		}

		bird.hitbox.pos = vector::getVectorSum(bird.hitbox.pos, bird.velocity);
	}

	Bird init()
	{
		Bird bird;

		bird.hitbox.pos = birdHitboxIniPos;
		bird.hitbox.radius = birdHitboxIniRadius;
		bird.color = birdIniColor;
		bird.velocity = birdIniVel;

		return bird;
	}

	void update(Bird& bird, float delta)
	{
		move(bird, delta);
	}

	void draw(Bird bird)
	{
		DrawCircle(static_cast<int>(bird.hitbox.pos.x), static_cast<int>(bird.hitbox.pos.y), bird.hitbox.radius, bird.color);
	}
}