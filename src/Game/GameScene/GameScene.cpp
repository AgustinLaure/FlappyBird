#include "Game/GameScene/GameScene.h"

#include "Game/Entities/Bird/Bird.h"
#include "Game/Entities/Obstacle/Obstacle.h"
#include "Game/Screen/Screen.h"

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
		static void update(float delta, GameScene& currentScene);
		static void draw();
		static void resetGame();

		namespace lost
		{
			static void update(GameScene& currentScene);
			static void draw();
		}

		//Entitites
		static bird::Bird bird = bird::init();
		static obstacle::Obstacle obstacle = obstacle::init(100.0f, 150.0f, { screen::screenWidth,screen::screenHeight / 2 }, WHITE);

		static const Color bckgColor = BLACK;

		static void update(float delta, GameScene& currentScene)
		{
			if (!bird.hasLost)
			{
				bird::update(bird, delta);
				obstacle::update(obstacle, bird, delta);
			}
			else
			{
				lost::update(currentScene);
			}
		}

		static void draw()
		{
			BeginDrawing();
			ClearBackground(bckgColor);

			if (!bird.hasLost)
			{
				bird::draw(bird);
				obstacle::draw(obstacle);
			}
			else
			{
				lost::draw();
			}

			DrawText("V0.1", screen::screenWidth-100, screen::screenHeight-100, 25, WHITE);

			EndDrawing();
		}

		void playing(float delta, GameScene& currentScene)
		{
			update(delta, currentScene);
			draw();
		}

		static void resetGame()
		{
			bird::reset(bird);
			obstacle::reset(obstacle);
		}

		namespace lost
		{
			static void update(GameScene& currentScene)
			{
				if (IsKeyDown(KEY_R))
				{
					resetGame();
				}

				if (IsKeyDown(KEY_E))
				{
					currentScene = GameScene::MainMenu;
				}
			}

			static void draw()
			{
				DrawText("R para reiniciar, E para salir al menu(vacio)", screen::screenWidth / 2, screen::screenHeight / 2, 20, WHITE);
			}
		}
	}
}