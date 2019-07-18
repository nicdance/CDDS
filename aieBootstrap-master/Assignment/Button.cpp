#include "Button.h"
#include <string.h>

Button::Button()
{
}

Button::Button(const char* newButtonText, float x, float y, float _width, float _height)
{
	//Store the text that will appear on the button.
	strcpy_s(buttonText, 64, newButtonText);
	//Load a font to use to display the text.
	currentFont = new aie::Font("../bin/font/consolas.ttf", 32);
	//Store the button's position, width, and height.
	posX = x;
	posY = y;
	width = _width;
	height = _height;

	hover = false;
}



Button::Button(aie::Texture *newTexture, float x, float y)
{
	//Store the button's position, width, and height.
	posX = x;
	posY = y;
	btnImage = newTexture;

	width = (float)btnImage->getWidth();
	height = (float)btnImage->getHeight();

	hover = false;
}


Button::~Button()
{
}

void Button::Draw(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	if (hover == true) {
		renderer->setRenderColour(1.0f, 0.5f, 0.4f, 1.0f);
	}
	else {
		renderer->setRenderColour(0.0f, 0.5f, 0.4f, 0.7f);
	}
	renderer->drawSprite(btnImage, posX, posY, 0.0f, 0.0f, 0.0f, 0.0f, .5f, .5f);
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
		hover = true;
		//Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	else {

		hover = false;
	}
	return false;
}
