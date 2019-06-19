#include "Button.h"
#include <string.h>


Button::Button(const char* newButtonText, float x, float y, float _width, float _height)
{
	//Store the text that will appear on the button.
	strcpy_s(buttonText, 64, newButtonText);
	//Load a font to use to display the text.
	currentFont = new aie::Font("./font/consolas.ttf", 24);
	//Store the button's position, width, and height.
	posX = x;
	posY = y;
	width = _width;
	height = _height;
}


Button::~Button()
{
	delete currentFont;
}

void Button::Draw(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.0f, 0.5f, 0.7f, 1.0f);
	renderer->drawBox(posX, posY, width, height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Calculating the centred text position is a bit fiddly.
	float textWidth = currentFont->getStringWidth(buttonText);
	float textHeight = currentFont->getStringHeight(buttonText);
	float centredPosX = posX - (textWidth * 0.5f) + 2;
	float centredPosY = posY - (textHeight * 0.5f) + 5;
	//Draw text on the button.
	renderer->drawText(currentFont, buttonText, centredPosX, centredPosY);
}

bool Button::Update()
{
	aie::Input* input = aie::Input::getInstance();
	//Get mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();
	//Calculate the 4 sides of the button
	float left = posX - (width * 0.5f);
	float right = posX + (width * 0.5f);
	float bottom = posY - (height * 0.5f);
	float top = posY + (height * 0.5f);
	//Check if the mouse is inside the box made by the 4 sides.
	if (mouseX > left && mouseX < right &&
		mouseY > bottom && mouseY < top)
	{
		//Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	return false;
}
