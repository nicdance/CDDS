#pragma once
#include "Renderer2D.h"
#include "Input.h"
class CircleButton
{
public:
	CircleButton(int number, float x, float y, float r);
	~CircleButton();


	// Used to Draw the Button
	void Draw(aie::Renderer2D* renderer);

	// Check if Button was presed
	bool Update();

	int getNumber();

	void setColour(float r, float g, float b, float a);

private:
	bool hover;

	//Button's position, width, and height.
	float posX;
	float posY;
	float radius;

	float red, blue, green, alpha;

	int btnNmber;
};

