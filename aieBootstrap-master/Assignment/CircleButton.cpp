#include "CircleButton.h"

CircleButton::CircleButton(int number, float x, float y, float r)
{
	//Store the button's position, width, and height.
	posX = x;
	posY = y;
	radius = r;

	hover = false;

	btnNmber = number;
}

CircleButton::~CircleButton()
{
}

void CircleButton::Draw(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	if (hover == true) {
		renderer->setRenderColour(red,green,blue,1.0f);
	}
	else {
		renderer->setRenderColour(red, green, blue, alpha);
	}
	renderer->drawCircle(posX, posY, radius, 0.0f);
	//renderer->drawBox(posX, posY, width, height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

}

bool CircleButton::Update()
{
	aie::Input* input = aie::Input::getInstance();
	//Get mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();
	//Check if the mouse is inside the box made by the 4 sides.
	if ((mouseX - posX) * (mouseX - posX) +
		(mouseY - posY) * (mouseY - posY) <= radius * radius)
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

int CircleButton::getNumber() {
	return btnNmber;
}


void CircleButton::setColour(float r, float g, float b, float a) {
	red = r;
	green = g;
	blue = b;
	alpha = a;
}