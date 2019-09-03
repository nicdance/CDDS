#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Input.h"
#include "Texture.h"
/*
*	Contains details for the rectangle buttons in game
*/

class Button
{
public:
	Button();
	Button(aie::Texture *newTexture, float x, float y);
	~Button();

	// Used to Draw the Button
	void Draw(aie::Renderer2D* renderer);

	// Check if Button was presed
	bool Update();

protected:
	bool hover;

	aie::Texture*		btnImage;
	
		//Button's position, width, and height.
	float posX;
	float posY;
	float width;
	float height;
};

