#include "Game/GameScene/GameScene.h"

#include "Game/Entities/Bird/Bird.h"

namespace gameScene
{
	namespace mainMenu
	{
		void mainMenu();
	}

	namespace playing
	{
		static bird::Bird bird = bird::init();
		
		void playing();

		static void update();
		static void draw();

		static void update()
		{
			bird::update(bird, delta);
		}

		static void draw()
		{
			bird::draw(bird);
		}
	}
}