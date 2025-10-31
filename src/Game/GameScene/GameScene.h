#pragma once

namespace gameScene
{
	enum class GameScene
	{
		MainMenu,
		Playing
	};

	namespace mainMenu
	{
		void mainMenu();
	}

	namespace playing
	{
		void playing(float delta);
	}
}

