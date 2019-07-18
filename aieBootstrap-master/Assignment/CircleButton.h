#pragma once
#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"

class CircleButton
{
public:
	CircleButton();
	CircleButton(int number, float x, float y, float r, aie::Texture *newTexture);
	~CircleButton();


	// Used to Draw the Button
	void Draw(aie::Renderer2D* renderer);
	
	// Check if Button was presed
	bool Update();
	void HoverOn();
	void HoverOff();

	int getNumber();

	void setColour(float r, float g, float b, float a);

private:
	bool hover;
	bool press;

	//Button's position, width, and height.
	float posX;
	float posY;
	float radius;

	float red, blue, green, alpha;

	int btnNmber;

	aie::Texture*		btnImage;
};

