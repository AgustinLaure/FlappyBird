#include "Game/GameScene/GameScene.h"

#include "Game/Entities/Bird/Bird.h"

namespace gameScene
{
	namespace mainMenu
	{
		static const Color bckgColor = BLACK;

		static void update();
		static void draw();

		static void update()
		{

		}

		static void draw()
		{
			BeginDrawing();
			ClearBackground(bckgColor);

			EndDrawing();
		}

		void mainMenu()
		{
			update();
			draw();
		}
	}

	namespace playing
	{
		static bird::Bird bird = bird::init();
		static const Color bckgColor = BLACK;
		
		static void update(float delta);
		static void draw();

		static void update(float delta)
		{
			bird::update(bird, delta);
		}

		static void draw()
		{
			BeginDrawing();
			ClearBackground(bckgColor);

			bird::draw(bird);

			EndDrawing();
		}

		void playing(float delta)
		{
			update(delta);
			draw();
		}
	}
}