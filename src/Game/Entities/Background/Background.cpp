#include "Background.h"

#include <string>

#include "Game/Math/Vector/Vector.h"

namespace background
{
	const BackgroundElementConfig backgroundConfig[backgroundElements]
	{
		{																			//Element 1
			{																		//SpriteConfig
				"res/Sprites/Background/City/cyberpunk_street_background.png",		//TextureRoute
				{0,0},																//InitialPos
				WHITE,																//Color
				4.0f,																//Scale
				0.0f																//Rotation
			},
			{-1,0},																	//Dir
			10.0f																	//Speed
		},
		{
			{
				"res/Sprites/Background/City/cyberpunk_street_midground.png",
				{0,0},
				WHITE,
				4.0f,
				0.0f
			},
			{-1,0},
			50.0f
		},
		{
			{
				"res/Sprites/Background/City/cyberpunk_street_foreground.png",
				{0,0},
				WHITE,
				4.0f,
				0.0f
			},
			{-1,0},
			100.0f
		},
	};

	static void scroll(BackgroundElement background[], float delta);
	static void move(BackgroundElement& element, float delta);
	static void repeat(BackgroundElement& element, int i);

	static void scroll(BackgroundElement background[], float delta)
	{
		for (int i = 0; i < backgroundElements; i++)
		{
			move(background[i], delta);
			repeat(background[i], i);
		}
	}

	static void move(BackgroundElement& element, float delta)
	{
		element.sprite.pos = vector::getVectorSum(element.sprite.pos, vector::getVectorMult(element.dir, element.speed * delta));
	}

	static void repeat(BackgroundElement& element, int i)
	{
		if (element.sprite.pos.x <= -(element.sprite.texture.width/2 * element.sprite.scale))
		{
			element.sprite.pos.x = backgroundConfig[i].sprite.pos.x;
		}
	}

	BackgroundElement initBackground(int i)
	{
		BackgroundElement backgroundElement;
		backgroundElement.sprite.texture = LoadTexture((backgroundConfig[i].sprite.textureRoute).c_str());
		backgroundElement.sprite.pos = backgroundConfig[i].sprite.pos;
		backgroundElement.sprite.color = backgroundConfig[i].sprite.color;
		backgroundElement.sprite.scale = backgroundConfig[i].sprite.scale;
		backgroundElement.sprite.rotation = backgroundConfig[i].sprite.rotation;
		backgroundElement.dir = backgroundConfig[i].dir;
		backgroundElement.speed = backgroundConfig[i].speed;

		return backgroundElement;
	}

	void deinitBackground(BackgroundElement background[])
	{
		for (int i = 0; i < backgroundElements; i++)
		{
			sprite::deinit(background[i].sprite);
		}
	}

	void update(BackgroundElement background[], float delta)
	{
		scroll(background, delta);
	}

	void draw(BackgroundElement background[])
	{
		for (int i = 0; i < backgroundElements; i++)
		{
			sprite::draw(background[i].sprite);
		}
	}

	void reset(BackgroundElement background[])
	{
		for (int i = 0; i < backgroundElements; i++)
		{
			background[i].sprite.pos = backgroundConfig[i].sprite.pos;
			background[i].sprite.color = backgroundConfig[i].sprite.color;
			background[i].sprite.scale = backgroundConfig[i].sprite.scale;
			background[i].sprite.rotation = backgroundConfig[i].sprite.rotation;
			background[i].dir = backgroundConfig[i].dir;
			background[i].speed = backgroundConfig[i].speed;
		}
	}
}
