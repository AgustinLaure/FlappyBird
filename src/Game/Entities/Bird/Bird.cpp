#include "Game/Entities/Bird/Bird.h"

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"

namespace bird
{
	static const Color birdIniColor = WHITE;
	static const Vector2 birdHitboxIniPos = {0.0f, 0.0f};
	static const float birdHitboxIniRadius = 5.0f;
	static const Vector2 birdIniVel = birdConstVel;

	static const float birdSpeed = 50.0f;
	static const Vector2 birdConstVel = {-15.0f, 15.0f};
	static const KeyboardKey jumpButton = KEY_SPACE;
	static float jumpSpeed = 10.0f;

	static void move(Bird& bird, float delta);

	static void move(Bird& bird, float delta)
	{
		bird.velocity = vector::getVectorMult(birdConstVel, delta);

		if (IsKeyDown(jumpButton))
		{
			bird.velocity.y += jumpSpeed * delta;
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
		DrawCircle(bird.hitbox.pos.x, bird.hitbox.pos.y, bird.hitbox.radius, bird.color);
	}
}