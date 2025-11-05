#include "Game/Button/Button.h"

namespace button
{
	const MouseButton actionButton = MOUSE_LEFT_BUTTON;

	Sound Button::onSelect;

	Button init(float width, float height, Vector2 pos, std::string text, float fontSize, float spacing, Color textColor, Color bckgColor)
	{
		Button newButton;

		Button::onSelect = LoadSound("res/sound/sfx/ui/selectSound.ogg");
		newButton.body.width = width;
		newButton.body.height = height;
		newButton.body.pos = pos;
		newButton.text.pos = newButton.body.pos;
		newButton.text.text = text;
		newButton.text.fontSize = fontSize;
		newButton.text.spacing = spacing;
		newButton.text.color = textColor;
		newButton.color = bckgColor;
		newButton.isPressed = false;

		return newButton;
	}

	void update(Button& button)
	{
		button.isPressed = false;

		if (IsMouseButtonDown(actionButton))
		{
			if (form::isPointCollidingRect(GetMousePosition(), button.body))
			{
				button.isPressed = true;
				PlaySound(Button::onSelect);
			}
		}
	}

	void draw(Button button)
	{
		DrawRectangle(int(button.body.pos.x), int(button.body.pos.y), int(button.body.width), int(button.body.height), button.color);
		DrawTextEx(GetFontDefault(), button.text.text.c_str(), button.text.pos, button.text.fontSize, button.text.spacing, button.text.color);
	}
}