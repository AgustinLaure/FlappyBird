#include "Game/Game.h"

#include "raylib.h"

#include "Screen/Screen.h"
#include "Game/GameScene/GameScene.h"

using namespace gameScene;

namespace game
{
	static bool isGameRunning = true;
	static GameScene currentScene = GameScene::Playing;
	static float delta = 0.0f;

	static void game();

	static void game()
	{
		InitWindow(screen::screenWidth, screen::screenHeight, screen::windowName.c_str());
		
		while (!WindowShouldClose() && isGameRunning)
		{
			delta = GetFrameTime();

			switch (currentScene)
			{
			case gameScene::GameScene::MainMenu:
				mainMenu::mainMenu();
				break;
			case gameScene::GameScene::Playing:
				playing::playing(delta);
				break;
			default:
				break;
			}
		}
	}
	
	void runGame()
	{
		game();
	}
}
