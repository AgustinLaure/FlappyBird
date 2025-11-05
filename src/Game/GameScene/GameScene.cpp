#include "Game/GameScene/GameScene.h"

#include "Game/Entities/Bird/Bird.h"
#include "Game/Entities/Obstacle/Obstacle.h"
#include "Game/Screen/Screen.h"
#include "Game/Button/Button.h"

namespace gameScene
{
	namespace mainMenu
	{
		enum class MainMenuScenes
		{
			MainMenu = -1,
			Play,
			Credits,
			Exit
		};

		static MainMenuScenes currentMainMenuScene = MainMenuScenes::MainMenu;

		namespace credits
		{
			static const Color bckgColor = BLACK;

			static const button::Button backButtonConfig =
			{
				{
					60.0f,							//Width	
					25.0f,							//Height
					{300.0f, 600.0f}				//Pos
				},
				//Text
				{
					{0.0f,0.0f},					//Pos
					"Back",							//Text
					30,								//FontSize
					2,								//Spacing
					WHITE							//Color
				},

				RED,								//Color
				false								//isPressed
			};

			static const int maxCreditsLines = 1;
			static const text::Text creditsLines[maxCreditsLines] =
			{
				//Line1
{
	{425, 350},								//Pos
	"Agustin Laure",						//Text
	25.0f,									//FontSize
	2.0f,									//Spacing
	WHITE									//Color
}
			};

			static void creditsScene();
			static button::Button initButton();
			static void update();
			static void draw();
			static void drawCredits();

			static button::Button backButton = initButton();

			static void creditsScene()
			{
				update();
				draw();
			}

			static button::Button initButton()
			{
				button::Button newButton = {};

				float width = backButtonConfig.body.width;
				float height = backButtonConfig.body.height;
				Vector2 pos = backButtonConfig.body.pos;
				std::string text = backButtonConfig.text.text;
				float fontSize = backButtonConfig.text.fontSize;
				float spacing = backButtonConfig.text.spacing;
				Color textColor = backButtonConfig.text.color;
				Color buttonBckgColor = backButtonConfig.color;

				newButton = button::init(width, height, pos, text, fontSize, spacing, textColor, buttonBckgColor);

				return newButton;
			}

			static void update()
			{
				button::update(backButton);

				if (backButton.isPressed)
				{
					currentMainMenuScene = MainMenuScenes::MainMenu;
				}
			}

			static void draw()
			{
				BeginDrawing();

				ClearBackground(bckgColor);

				drawCredits();

				button::draw(backButton);

				EndDrawing();
			}

			static void drawCredits()
			{
				for (int i = 0; i < maxCreditsLines; i++)
				{
					std::string text = creditsLines[i].text;
					int posX = static_cast<int>(creditsLines[i].pos.x);
					int posY = static_cast<int>(creditsLines[i].pos.y);
					int fontSize = static_cast<int>(creditsLines[i].fontSize);
					Color color = creditsLines[i].color;

					DrawText(text.c_str(), posX, posY, fontSize, color);
				}
			}
		}

		static const Color bckgColor = BLACK;

		static const int maxButtons = 3;
		static const button::Button buttonsConfig[maxButtons] =
		{
			//Button1
			{										//Body
				{
					60.0f,							//Width	
					25.0f,							//Height
					{400.0f, 500.0f}				//Pos
				},
			//Text
{
	{0.0f,0.0f},					//Pos
	"Play",							//Text
	30,								//FontSize
	2,								//Spacing
	WHITE							//Color
},

RED,								//Color
false								//isPressed
},


{
	{
		105.0f,
		25.0f,
		{500.0f, 500.0f}
	},

	{
		{0.0f,0.0f},
		"Credits",
		30,
		2,
		WHITE
	},

	RED,
	false
},
//Button1
			{										//Body
				{
					60.0f,							//Width	
					25.0f,							//Height
					{50.0f, 50.0f}				//Pos
				},
			//Text
{
	{0.0f,0.0f},					//Pos
	"Exit",							//Text
	30,								//FontSize
	2,								//Spacing
	WHITE							//Color
},

RED,								//Color
false								//isPressed
},
		};

		static void update(GameScene& currentScene);
		static void draw();
		button::Button initButtons(int i);
		static void drawButtons();
		static void updateButtons();

		static button::Button buttons[maxButtons] =
		{
			initButtons(0),
			initButtons(1),
			initButtons(2)
		};

		static void mainMenuScene(GameScene& currentScene)
		{
			update(currentScene);
			draw();
		}

		void mainMenu(GameScene& currentGameScene)
		{
			switch (currentMainMenuScene)
			{
			case MainMenuScenes::MainMenu:
				mainMenuScene(currentGameScene);
				break;

			case MainMenuScenes::Credits:
				credits::creditsScene();
				break;

			default:
				break;
			}
		}

		static void update(GameScene& currentGameScene)
		{
			updateButtons();

			if (buttons[static_cast<int>(MainMenuScenes::Play)].isPressed)
			{
				currentGameScene = GameScene::Playing;
			}
			else if (buttons[static_cast<int>(MainMenuScenes::Credits)].isPressed)
			{
				currentMainMenuScene = MainMenuScenes::Credits;
			}
			else if (buttons[static_cast<int>(MainMenuScenes::Exit)].isPressed)
			{
				currentGameScene = GameScene::Exit;
			}
		}

		static void draw()
		{
			BeginDrawing();
			ClearBackground(bckgColor);

			drawButtons();
			DrawText("V0.2", screen::screenWidth - 100, screen::screenHeight - 100, 25, WHITE);

			EndDrawing();
		}

		button::Button initButtons(int i)
		{
			button::Button newButton = {};

			float width = buttonsConfig[i].body.width;
			float height = buttonsConfig[i].body.height;
			Vector2 pos = buttonsConfig[i].body.pos;
			std::string text = buttonsConfig[i].text.text;
			float fontSize = buttonsConfig[i].text.fontSize;
			float spacing = buttonsConfig[i].text.spacing;
			Color textColor = buttonsConfig[i].text.color;
			Color buttonBckgColor = buttonsConfig[i].color;

			newButton = button::init(width, height, pos, text, fontSize, spacing, textColor, buttonBckgColor);

			return newButton;
		}

		static void drawButtons()
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(buttons[i]);
			}
		}

		static void updateButtons()
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::update(buttons[i]);
			}
		}
	}

	namespace playing
	{
		static const text::Text loseText =
		{
			{245, 350},																//Pos
			"R para reiniciar, E para salir al menu",								//Text
			25.0f,																	//FontSize
			2.0f,																	//Spacing
			WHITE																	//Color
		};

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
		static obstacle::Obstacle obstacle = obstacle::init(100.0f, 3000.0f, { screen::screenWidth,screen::screenHeight / 2 }, WHITE);

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
				DrawText(loseText.text.c_str(), static_cast<int>(loseText.pos.x), static_cast<int>(loseText.pos.y), static_cast<int>(loseText.fontSize), loseText.color);
			}
		}
	}
}