#include "Game/Screen/Screen.h"

#include <string>

namespace screen
{
	static const std::string screenName = "Asteroids";

	void openWindow()
	{
		InitWindow(screenWidth, screenHeight, screenName.c_str());
	}

	void closeWindow()
	{
		CloseWindow();
	}
}