#include "Game/Game.h"

#include "raylib.h"

#include "Screen/Screen.h"
#include "Game/GameScene/GameScene.h"

namespace game
{
	enum class gameScene
	{
		MainMenu,
		Playing
	};

	static bool isGameRunning = true;
	static gameScene currentScene = gameScene::MainMenu;

	static float delta = 0.0f;

	static void game();
	static void update();
	static void draw();

	static void game()
	{
		InitWindow(screen::screenWidth, screen::screenHeight, screen::windowName.c_str());
		
		while (!WindowShouldClose() && isGameRunning)
		{
			delta = GetFrameTime();

			update();
			draw();
		}
	}
	
	static void update()
	{
		switch (currentScene)
		{
		case game::gameScene::MainMenu:

			break;

		case game::gameScene::Playing:

			break;

		default:
			break;
		}
	}

	static void draw()
	{
		BeginDrawing();

		switch (currentScene)
		{
		case game::gameScene::MainMenu:

			break;

		case game::gameScene::Playing:

			break;

		default:
			break;
		}

		EndDrawing();
	}

	void runGame()
	{
		game();
	}
}
