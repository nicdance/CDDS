#include "CircleButton.h"


CircleButton::CircleButton() {
}
CircleButton::CircleButton(int number, std::string soundFile , float x, float y, float r, aie::Texture *newTexture)
{
	//Store the button's position, width, and height.
	posX = x;
	posY = y;
	radius = r;

	hover = false;
	press = false;
	btnImage = newTexture;
	btnNmber = number;

	buffer.loadFromFile(soundFile);
	sound.setVolume(50);
}

CircleButton::~CircleButton()
{
}
void CircleButton::PlaySound() {

	sound.setBuffer(buffer);
	sound.play();
}

void CircleButton::Draw(aie::Renderer2D* renderer, float xPos, float yPos)
{
	posX = xPos;
	posY = yPos;
	//Draw a coloured box for the button background.
	if (hover == true) {
		renderer->setRenderColour(red,green,blue,1.0f);
	}
	else {
		renderer->setRenderColour(red, green, blue, alpha);
	}

	renderer->drawSprite(btnImage, posX, posY, 0.0f, 0.0f, 0.0f, 0.0f, .5f, .5f);

	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
}


void CircleButton::HoverOn()
{
	hover = true;
}

void CircleButton::HoverOff()
{
	hover = false;
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
		return input->wasMouseButtonReleased(aie::INPUT_MOUSE_BUTTON_LEFT);
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